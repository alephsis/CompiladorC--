%{
#include <stdio.h>
#include <stdlib.h>
#include "attribs.h"
#include "symbols.h"
#include "intermediate_code.h"

extern FILE *yyout;
extern FILE *yyin;
extern int yylex();
void yyerror(char *s);


int dir;
int temporales;
int siginst;
char* tipoGlobal;
int dimGlobal;
 
void init();
int existe(char *id);
expresion operacion(expresion e1, expresion e2, char *op);
expresion numero(int n);
expresion identificador(char *s);
condition relacional(expresion e1, expresion e2, char *oprel);
condition and(condition c1, condition c2);
condition or(condition c1, condition c2);
void newLabel(char *s);
char* getArrayType(int n, char* t);

%}

%union{
    char sval[32];
    char ssval[3];
    expresion eval;
    condition cval;  
    sentence stval;
    int nval;
    int line;
    type tval;
    arrayType arrtval;
}

%token <sval> ID
%token <nval> NUM
%token INT MAIN PRINT VOID
%token IF WHILE BREAK 
%token PYC
%token LKEY RKEY
%token TRUE FALSE
%token FLOAT DOUBLE CHAR
%token SWITCH
%token FOR
%token FUNC
%token DEFAULT
%token RETURN
%token STRUCT
%token RLC
%token LLC
%token SC
%token COMMA
%token LBRACK
%token RBRACK

%left ASIG
%left OR
%left AND
%left<ssval> EQUAL NE
%left<ssval> GT LT
%left<ssval> ADD SUB
%left<ssval> MUL DIV
%nonassoc RPAR LPAR
%left IFX
%left ELSE

%type<eval> exp;
%type<cval> cond;
%type<tval> tipo idlist;
%type<arrtval> tipoarreglo;
%type<stval> sents sent block goto_else
%type<ssval> rel 


%start program

%%

program : {init();} 
          decl function {
            print_table();
            print_code();
         };
         
decl: tipo{      
      tipoGlobal = $1.tipo;
      dimGlobal  = $1.dim;
} idlist
| decl decl
| ;

tipo: INT {
       $$.tipo = "int";
       $$.dim = 4;
	  }
| FLOAT  {
       $$.tipo = "float";
       $$.dim = 4;
	  }
| DOUBLE  {
       $$.tipo = "double";
       $$.dim = 8;
  }
| CHAR  {
       $$.tipo = "char";
       $$.dim = 1;
	  }
/*| VOID  {
       $$.tipo = "void";
       $$.dim = -1;
       }*/
| STRUCT LKEY decl RKEY {
  $$.tipo = "struct";
  $$.dim = -1;
	  } ;

idlist: idlist COMMA ID  tipoarreglo{
	     if(existe($3)==-1){
	       printf("insertando %s\n",$3);
	       symbol sym;
	       strcpy(sym.id, $3);
	       sym.dir = dir;
	       sym.type = $4.tipo;
	       sym.var = 0;
	       insert(sym);
	       dir+= $4.dim;
	     }else{
	       yyerror("Identificador duplicado");
	     }
           } PYC ;
| ID  tipoarreglo{
	   if(existe($1)==-1){
	     printf("insertando %s\n",$1);
	     symbol sym;
	     strcpy(sym.id, $1);
	     sym.dir = dir;
	     sym.type = $2.tipo;
	     sym.var = 0;
	     insert(sym);
	     dir += $2.dim;
	   }else{
	     yyerror("Identificador duplicado");
	   }	    
} PYC ;

tipoarreglo: LBRACK NUM RBRACK tipoarreglo{
  $$.tipo = getArrayType($2, $4.tipo);
  $$.dim = $2 * $4.dim;
  }
| {
  if(dimGlobal == -1)
    yyerror("Tipo inválido para un arreglo");
  $$.tipo = tipoGlobal;
  $$.dim = dimGlobal;
  };

function: VOID MAIN {gen_code("label","","","main");} LPAR RPAR LKEY block {
            siginst = gen_code("label","","","end");
            backpatch($7.lnext, siginst);
     } RKEY;
        
       
block:  sents {
            $$= $1;
        } 
        | {
            
        }
           ;

sents: sents sent {
            backpatch($1.lnext, $2.first);
            $$.lnext = $2.lnext;
            $$.first = $1.first;
        }
        | sent{
            $$.lnext = $1.lnext;
        };

sent:   ID {
            if(existe($1)==-1){
                yyerror("el identificador no ha sido declarado");
            }
        }        
        ASIG exp PYC{
                siginst = gen_code("=", $4.dir, "", $1);               
                if($4.first != -1)
                    $$.first = $4.first;
                else
                    $$.first = siginst;
        }
        |IF LPAR cond RPAR LKEY block RKEY %prec IFX{ 
                backpatch($3.ltrue, $6.first);
                $$.lnext = merge($3.lfalse, $6.lnext);
                $$.first = $3.first;                
        }
        | IF LPAR cond RPAR LKEY block RKEY ELSE goto_else LKEY block RKEY{
                backpatch($3.ltrue, $6.first);
                backpatch($3.lfalse, $11.first);
                label temp = merge($6.lnext, $9.lnext);
                $$.lnext = merge(temp, $11.lnext); 
        }
        | PRINT exp {
            siginst = gen_code("print", $2.dir, "", "");            
            if($2.first != -1)
                $$.first = $2.first;
            else
                $$.first = siginst;
        }
        | WHILE LPAR cond RPAR LKEY block RKEY {                
                backpatch($6.lnext, $3.first);
                backpatch($3.ltrue, $6.first);
                $$.lnext = $3.lfalse;
                char temp[15];
                sprintf(temp,"%d", $3.first);
                gen_code("goto", "", "", temp);
        }
        | BREAK PYC {
            $$.first = -1;
            siginst = gen_code("goto", "", "", "");
            $$.lnext = create_list(siginst);
        };
    
goto_else : {
                siginst = gen_code("goto","","", "");             
                $$.lnext = create_list(siginst);
                $$.first = -1;
            };

cond :  cond OR cond{
            $$ = or($1, $3);
        }
        | cond AND cond {
            $$ = and($1, $3);
        }
        | exp rel exp {
            $$ = relacional($1, $3, $2);
        }
        ;

rel : EQUAL {strcpy($$, $1);} 
        | NE{strcpy($$, $1);} 
        | GT{strcpy($$, $1);} 
        | LT{strcpy($$, $1);};

exp :  exp ADD exp { $$ = operacion($1, $3,$2);}        
        | exp SUB exp { $$ = operacion($1, $3,$2);}
        | exp MUL exp { $$ = operacion($1, $3,$2);}
        | exp DIV exp { $$ = operacion($1, $3,$2);}
        | NUM {$$= numero($1);}
        | ID{$$= identificador($1);}
        | LPAR exp RPAR {$$ = $2;};
        

        
%%

void yyerror(char* s){
    printf("ERROR:%s, en  la linea %d\n",s, yylval.line);
    exit(1);
}

void newLabel(char *s){
    
}

void init(){
    dir = 0;
    temporales = 0;    
    init_table();
}

int existe(char *id){
    return search(id);
}

expresion operacion(expresion e1, expresion e2, char *op){
    temporales++;
    expresion e;
    
    char num[5];
    sprintf(num,"%d",temporales);
    strcpy(e.dir, "t");
    strcat(e.dir, num);    
    e.type = 1;
    siginst = gen_code(op, e1.dir, e2.dir, e.dir);
    if(e1.first != -1){
        e.first = e1.first;
    }else{
        if(e2.first!=-1){
            e.first = e2.first;
        }else{
            e.first = siginst;
        }        
    }
    
    return e;
}

expresion numero(int n){
    expresion e;
    sprintf(e.dir, "%d", n);
    e.first=-1;
    return e;    
}

expresion identificador(char *s){
    expresion e;
    if(existe(s)!=-1){        
        e.first=-1;
        strcpy(e.dir, s);
    }else{
        yyerror("El identificador no ha sido declarado");
    }
    return e;
}

condition relacional(expresion e1, expresion e2, char *oprel){
    condition c;    
    char arg1[50];
    sprintf(arg1, "%s %s %s", e1.dir, oprel, e2.dir);
    siginst = gen_code("if",arg1, "goto", "");
    c.ltrue = create_list(siginst);
    siginst = gen_code("goto", "", "", "");
    c.lfalse = create_list(siginst);
    if(e1.first != -1){
        c.first = e1.first;
    }else{
        if(e2.first!=-1){
            c.first = e2.first;
        }else{
            c.first = siginst-1;
        }        
    }
    return c;
}

condition or(condition c1, condition c2){
    condition c;
    backpatch(c1.lfalse, c2.first);
    c.ltrue= merge(c1.ltrue, c2.ltrue);
    c.lfalse = c2.lfalse;
    return c;
}

condition and(condition c1, condition c2){
    condition c;
    backpatch(c1.ltrue, c2.first);
    c.ltrue= c2.ltrue;
    c.lfalse = merge(c1.lfalse,c2.lfalse);
    return c;
}

char* getArrayType(int n, char* t){
    char* ret= (char*)malloc(100*sizeof(char)); 
    sprintf(ret,"array [%d] of type %s",n,t);
    return ret;
}

int main(int argc, char** argv){
    if(argc>1){
        yyin = fopen(argv[1], "r");
        if(!yyin) return 1;
        yyparse();
        fclose(yyin);
    }
}
/*
#include "attribs.h"
#include "intermediate_code.c"
#include "symbols.c"
*/
