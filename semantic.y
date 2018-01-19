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
int dirTemp;
int temporales;
int siginst;
char* tipoGlobal;
int dimGlobal;
NodeParam globalList;
int globalListLength;
 
void init();
int existe(char *id);
int existeLocal(char *id);
int getSize (char* s);
int isNumber(char* t);
int isInt(char* t);
int isFloat(char* t);
int isArray(char* t);
int isChar(char* t); 
char* tipoCorrecto (char* t1 ,char* t2, char*op);
expresion operacion(expresion e1, expresion e2, char *op);
expresion numero(int n);
expresion identificador(char *s);
expresion numeroReal(float n);
expresion character(char c);
expresion string(char* s);
expresion llamada(char* id);
expresion array(arrayUse arrayUse); 
condition relacional(expresion e1, expresion e2, char *oprel);
condition and(condition c1, condition c2);
condition or(condition c1, condition c2);
void newLabel(char *s);
char* getArrayType(int n, char* t);
int npEquals(NodeParam* n1,NodeParam* n2);
char* newTemp();
char* getWidth(char*t);
char* getArrayWidth(char*t);
 
%}

%union{
    char sval[32];
    char ssval[3];
    expresion eval;
    condition cval;  
    sentence stval;
    int nval;
    float fval;
    int line;
    type tval;
    arrayType arrtval;
    char charval;
    NodeParam paramlistval;
    arrayUse arrayuseval;
 }

%token <sval> ID STRING
%token <charval> CHARACTER
%token <nval> NUM
%token <fval> NUMR
%token <ssval> NOT
%token INT PRINT VOID
%token IF WHILE BREAK 
%token PYC
%token LKEY RKEY
%token TRUE FALSE
%token FLOAT CHAR
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
%token GTE LTE

%left ASIG
%left OR
%left AND
%left<ssval> EQUAL NE
%left<ssval> GT LT
%left<ssval> ADD SUB MOD
%left<ssval> MUL DIV
%nonassoc RPAR LPAR
%left IFX
%left ELSE

%type<eval> exp identificadores;
%type<cval> cond;
%type<tval> tipo idlist;
%type<arrtval> tipoarreglo arrayparam;
%type<stval> sents sent block goto_else
%type<ssval> rel
%type<paramlistval> parampasslist 
%type<arrayuseval> arrayuse

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
} idlist PYC
| ;

tipo: INT {
       $$.tipo = "int";
       $$.dim = 4;
	  }
| FLOAT  {
       $$.tipo = "float";
       $$.dim = 4;
	  }
| CHAR  {
       $$.tipo = "char";
       $$.dim = 1;
	  }
| VOID  {
       $$.tipo = "void";
       $$.dim = -1;
       }
| STRUCT LKEY decl RKEY {
  $$.tipo = "struct";
  $$.dim = -1;
	  } ;

idlist: idlist COMMA ID  tipoarreglo{
	     if(existeLocal($3)==-1){
	       printf("insertando %s\n",$3);
	       symbol sym;
	       strcpy(sym.id, $3);
	       sym.dir = dir;
	       sym.type = $4.tipo;
	       sym.var = "variable";
	       insert(sym);
	       dir+= $4.dim;
	     }else{
	       yyerror("Identificador duplicado");
	     }
           } 
| ID  tipoarreglo{
	   if(existeLocal($1)==-1){	     
	     printf("insertando %s \n",$1);	     
	     symbol sym;
	     strcpy(sym.id, $1);
	     sym.dir = dir;
	     sym.type = $2.tipo;
	     sym.var = "variable";
	     insert(sym);
	     dir += $2.dim;
	   }else{	     
	     yyerror("Identificador duplicado");
	   }	    
} ;

tipoarreglo: LBRACK NUM RBRACK tipoarreglo{
  if(dimGlobal == -1)
    yyerror("Tipo invalido para un arreglo");
  $$.tipo = getArrayType($2, $4.tipo);
  $$.dim = $2 * $4.dim;
  }
| {
  if(strcmp("void",tipoGlobal) == 0)
    yyerror("Tipo void válido solo a funciones");
  $$.tipo = tipoGlobal;
  $$.dim = dimGlobal;
  };


function: FUNC tipo ID {
              if(existe($3) != -1){
                  yyerror("Identificador duplicado");
              }else{
                  /* generate new symbols table */                  
                  symbols_table* sym_tab;
		  
		  sym_tab  = (symbols_table *)malloc(1000*sizeof(symbol)+5);
                  sym_tab->next = 0;
                  pushST(*sym_tab);
		  /* store the current dir (the method must be different for structs) */
		  dirTemp = dir;
		  dir = 0;		  
                  /* generate label of function */
                  gen_code("label","","",$3); 
              }
	  } LPAR paramlistdef RPAR LKEY decl block RKEY{
//Here the tipe of block and tipo must be the same, but for now block doesnt have type, begin that if here
char* endLabel = (char*)malloc(100 * sizeof(char));
    sprintf(endLabel,"%s end",$3);
    siginst = gen_code("label","","",endLabel);
    backpatch($10.lnext, siginst);
//end if here
    /* destroy sym table */
    popST();
    /* restore the previous dir */
    dir = dirTemp;
    /* insert id of function */
    printf("insertando %s\n",$3);
    symbol sym;
    strcpy(sym.id, $3);
    sym.dir = -1;
    sym.type = $2.tipo;
    sym.var =  "func";
    sym.listLength = globalListLength;
    sym.list = globalList;
    insert(sym);
} function
| {

  };

paramlistdef: paramlist {
}
| {
  globalListLength = 0;
};

paramlist: paramlist {

  } COMMA tipo{
            tipoGlobal = $4.tipo;
	    dimGlobal  = $4.dim;	    
	   }ID arrayparam{
             if(existeLocal($6) != -1){
                 yyerror("Identificador duplicado");
	     }
	     printf("insertando %s\n",$6);
	     symbol sym;
	     strcpy(sym.id, $6);
	     sym.dir = dir;
	     sym.type = $7.tipo;
	     sym.var = "param";
	     insert(sym);
	     dir = dir + $7.dim;
	     addParam(&globalList,$7.tipo);
	     globalListLength++;
	     }
| tipo{
  if(strcmp($1.tipo, "void") == 0)
    yyerror("Tipo void inválido para un parámetro de función");
  tipoGlobal = $1.tipo;
  dimGlobal  = $1.dim;
  }ID arrayparam{
	    if(existeLocal($3) != -1)
	      yyerror("Identificador duplicado");
	    printf("insertando %s\n",$3);
	    symbol sym;
	    strcpy(sym.id, $3);
	    sym.dir = dir;
	    sym.type = $4.tipo;
	    sym.var = "param";
	    insert(sym);
	    dir = dir + $4.dim;
	    /* $$.lista = newLista() */
	    NodeParam* nuevo;
	    nuevo = (NodeParam *)malloc(sizeof(NodeParam));
	    nuevo->data = $4.tipo;
	    nuevo->next = NULL;
	    globalList = *nuevo;
	    globalListLength = 1;
 
	  };

arrayparam: LBRACK NUM RBRACK arrayparam{
  $$.tipo = getArrayType($2, $4.tipo);
  $$.dim = $2 * $4.dim;
  }
| {
  if(dimGlobal == -1)
    yyerror("Tipo inválido para un arreglo");
  $$.tipo = tipoGlobal;
  $$.dim = dimGlobal;
	  };


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
	    $$.first = $1.first;
        };

sent:   identificadores ASIG exp PYC{
	  if(strcmp($3.type,$1.type) != 0){
	    char err[100];
	    sprintf(err,"Tipos incompatibles en asignación, se esperaba %s pero se obtuvo %s",$1.type,$3.type);
	    yyerror(err);
	  }
                siginst = gen_code("=", $3.dir, "", $1.dir);               
                if($3.first != -1)
                    $$.first = $3.first;
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
        |  WHILE LPAR cond RPAR LKEY block RKEY {                
                backpatch($6.lnext, $3.first);
                backpatch($3.ltrue, $6.first);
		for(int a = 0; a < $6.lnext.i;a++){
		  printf("lista tiene: %d\n",$6.lnext.items[a]);
		}
                $$.lnext = $3.lfalse;		
                char temp[15];
		sprintf(temp,"%d", $3.first);
                gen_code("goto", "", "", temp);
        }
        | BREAK PYC {
            $$.first = siginst;
            siginst = gen_code("goto", "", "", "");
            $$.lnext = create_list(siginst);
        };

        | RETURN exp PYC{
	  gen_code("return",$2.dir,"","");
	  $$.first = siginst;
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
        | exp MOD exp { $$ = operacion($1, $3,$2);}
        | NUM {$$= numero($1);}
        | NUMR {$$= numeroReal($1);}
        | CHARACTER {$$= character($1);}
        | STRING {$$= string($1);}
        | LPAR exp RPAR {$$ = $2;}
        | ID {
	  if(existe($1) == -1)
	    yyerror("Identificador no ha sido declarado");
	  if(isFunction($1) == NULL)
	    yyerror("El identificador no es una función");
	  } LPAR parampasslist RPAR{
	    if(!npEquals(&$4,get_list($1)))
	      yyerror("El tipo y número de argumentos no coincide");
	    $$ = llamada($1);
	} 
	| identificadores{$$ = $1;};

parampasslist: parampasslist{

	} COMMA exp{
	  siginst = gen_code("param", $4.dir, "", "");
	  addParam(&$$,$4.type);
	}
| exp{
  
  siginst = gen_code("param", $1.dir, "", "");
  NodeParam* nuevo;
  nuevo = (NodeParam*)malloc(sizeof(NodeParam));
  nuevo->data = $1.type;
  nuevo->next = NULL;
  $$ = *nuevo;
  };

identificadores: ID{$$ = identificador($1);}
| arrayuse {$$ = array($1);} ;


arrayuse: ID {
  char* type;
  type = (char* )malloc(1000);
  type = get_type($1);
  if(type == NULL){
    char *err = (char *)malloc(100);
    sprintf(err,"El id %s no ha sido declarado",$1);
    yyerror(err);
  }
  if(!isArray(type)){
    char *err = (char *)malloc(100);
    sprintf(err,"El id %s no corresponde a un arreglo",$1);
    yyerror(err);
  }
	  } LBRACK exp RBRACK{
	      char* type;
	      type = (char* )malloc(1000);
	      type = get_type($1);
	      $$.array = (char*)malloc(100);
	      strcpy($$.array,$1);
	      int digits;
	      digits = getSize(getArrayWidth(type));
	      $$.type = type + 17 + digits;
	      char* temp = newTemp();	      
	      strcpy($$.dir,temp);
	      $$.width = getWidth($$.type);
	      gen_code("*",$4.dir,$$.width,$$.dir);
	  }
| arrayuse LBRACK exp RBRACK{
              char* type;
	      type = (char* )malloc(1000);
	      type = $1.type;
	      $$.array = $1.array;

	      int digits;
	      digits = getSize(getArrayWidth(type));	      
	      $$.type = type + 17 + digits;

	      $$.width = getWidth($$.type);
	      
	      char* t = newTemp();
	      char* temp = newTemp();
	      strcpy($$.dir,temp);	      
	      gen_code("*",$3.dir,getWidth($$.type),t);
	      gen_code("+",$1.dir,t,$$.dir);
	  } ;
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

int existeLocal(char *id){
    return searchLocal(id);
}

char* newTemp(){
  temporales++;
  char num[5];
  char* ret = (char*)malloc(100);
  sprintf(num,"%d",temporales);
  strcpy(ret, "t");
  strcat(ret, num);
  return ret;
}

expresion operacion(expresion e1, expresion e2, char *op){
  temporales++;
  expresion e;    
  char num[5];
  sprintf(num,"%d",temporales);
  strcpy(e.dir, "t");
  strcat(e.dir, num);    
  e.type = tipoCorrecto(e1.type ,e2.type ,op);
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

/* regresa el tipo de la expresion resultante de una operacion
 según los tipos de los operadores */

char* tipoCorrecto (char* t1 ,char* t2, char*op){
  if(strcmp(op,"+") == 0 ||
     strcmp(op,"-") == 0 ||
     strcmp(op,"*") == 0  ){
    if(!isNumber(t1) || !isNumber(t2))
      yyerror("operadores deben ser numéricos");
    if(isFloat(t1) || isFloat(t2))
      return "float";
    else
      return "int";
  }else if(strcmp(op,"/") == 0){
    if(!isNumber(t1) || !isNumber(t2))
      yyerror("operadores deben ser numéricos");
    return "float";
  }else if(strcmp(op,"%") == 0){
    if(!isInt(t1) || !isInt(t2))
      yyerror("El módulo debe ser entre dos enteros");
    return "int";
  }else{
    return NULL;
  }
}

/* regresa 1 si el tipo es int o float,0 en otro caso */

int isNumber(char* t){
  if(strcmp(t,"int") == 0)
    return 1;
  if(strcmp(t,"float") == 0)
    return 1;
  return 0;
}

/* regresa 1 si el tipo es int ,0 en otro caso */

int isInt(char* t){
  if(strcmp(t,"int") == 0)
    return 1;
  return 0;
}

/* regresa 1 si el tipo es float, 0 en otro caso */

int isFloat(char* t){
  if(strcmp(t,"float") == 0)
    return 1;
  return 0;
}

/* regresa 1 si el tipo es char, 0 en otro caso */

int isChar(char* t){
  if(strcmp(t,"char") == 0)
    return 1;
  return 0;
}

/* regresa 1 si el tipo es un arreglo, 0 en otro caso */

int isArray(char* t){
  if(*t == 'a')
    return 1;
  return 0;
}
/* regresa el tamaño de un tipo, en caso de ser un arreglo regresa el número de sus registros */

char* getArrayWidth(char *t){

  if(isInt(t))
    return "4";
  if(isFloat(t))
    return "4";
  if(isChar(t))
    return "1";
  if(isArray(t)){
    int i = 7;
    int j = 0;
    char* ret = (char*)malloc(100);
    while(*(t + i) != ']'){
      *(ret + j) = *(t + i);
      i++;
      j++;
    }
    return ret ;
  }
  return NULL; 
}

char* getWidth(char *t){
  printf("entré con %s\n",t);
  if(isInt(t))
    return "4";
  if(isFloat(t))
    return "4";
  if(isChar(t))
    return "1";
  if(isArray(t)){
    int i = 7;
    int j = 0;
    char* ret = (char*)malloc(100);
    while(*(t + i) != ']'){
      *(ret + j) = *(t + i);
      i++;
      j++;
    }

    int digits;
    char* type;
    digits = getSize(ret);	      
    type = t + 17 + digits;    
    int size = atoi(getWidth(type)) * atoi(ret);
    char* trueRet = (char*)malloc(100);
    sprintf(trueRet,"%d",size);
    return trueRet ;
  }
  return NULL; 
}

 
int getSize (char* s){
  int i = 0;
  while(*(s+i) != '\0')
    i++;  
  return i;
}

expresion numero(int n){
    expresion e;
    sprintf(e.dir, "%d", n);
    e.first=-1;
    e.type = "int";
    return e;    
    }

expresion numeroReal(float n){
    expresion e;
    sprintf(e.dir, "%.3f", n);
    e.first=-1;
    e.type = "float";
    return e;    
    }

expresion character(char c){
    expresion e;
    sprintf(e.dir, "%c", c);
    e.first=-1;
    e.type = "char";
    return e;    
    }

expresion string(char* s){
    expresion e;
    sprintf(e.dir, "%s", s);
    e.first=-1;
    char* t = (char*)malloc(50*sizeof(char));
    t = getArrayType(getSize(s),"char");
    e.type = t;
    return e;    
    }

expresion llamada(char* id){
  symbol* fun = isFunction(id);
  //asignar a e.dir una nueva variable temporal
  temporales++;
  expresion e;    
  char num[5];
  sprintf(num,"%d",temporales);
  strcpy(e.dir, "t");
  strcat(e.dir, num);
  //generar la llamada y construir la expresion
  char len[5];
  sprintf(len,"%d",fun->listLength);
  siginst = gen_code("call", id, len , e.dir);
  e.type = fun->type;
  e.first = -1;
  return e;  
}

expresion array(arrayUse au){
  expresion* e = (expresion*)malloc(sizeof(expresion));
  e->type = au.type;
  e->first = -1;
  char* offset = au.dir;
  char* eDir = newTemp();
  char* arrDir = (char*)malloc(100);
  sprintf(arrDir,"%s[%s]",au.array,offset);
  gen_code("=",arrDir,"",eDir);
  strcpy(e->dir,eDir);
  return *e;
}

expresion identificador(char *s){
  expresion* e = (expresion*)malloc(sizeof(expresion));
  char* t = get_type(s);
  if(t != NULL){
    e->first=-1;
    strcpy(e->dir, s);
    e->type = t;
  }else{
    yyerror("El identificador no ha sido declarado");
  }
  return *e;
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

int npEquals(NodeParam* n1,NodeParam* n2){
  NodeParam* actual1 = n1;
  NodeParam* actual2 = n2;
  while(actual1 != NULL && actual2 != NULL){
    if(strcmp(actual1->data,actual2->data) != 0)
      return 0;
    actual1 = actual1->next;
    actual2 = actual2->next;
  }
  if(actual1 == NULL && actual2 == NULL)
    return 1;
  return 0;
}

/*
#include "attribs.h"
#include "intermediate_code.c"
#include "symbols.c"
*/
