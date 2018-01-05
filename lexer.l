%{
#include <stdio.h>
#include "semantic.tab.h"
%}

%option noyywrap
%option yylineno


id [a-zA-Z_][a-zA-Z0-9_]*
numero [0-9]+(\.[0-9]+)?
espacio [ \t\n]
caracter[a-zA-Z_]
cadena  \"[^\"]*\"
%%
"," { 
       yylval.line = yylineno;
       return COMMA;
    }

";" { 
        yylval.line = yylineno;
        return PYC;
    }

int {
        yylval.line = yylineno;
        return INT;
    }

main { 
        yylval.line = yylineno;
        return MAIN;
    }

void { 
        yylval.line = yylineno;
        return VOID;
    }

print {
        yylval.line = yylineno;
        return PRINT;
    }

if  { 
        yylval.line = yylineno;
        return IF;
    }

else { 
        yylval.line = yylineno;
        return  ELSE;
    }

while {
        yylval.line = yylineno;
        return WHILE;}

break { 
        yylval.line = yylineno;
        return BREAK;
    }

"true" {
        yylval.line = yylineno;
        return TRUE;
    }

"false" { 
        yylval.line = yylineno;
        return  FALSE;
    }

"float" {
        yylval.line = yylineno;
        return FLOAT;
    }

"double" { 
        yylval.line = yylineno;
        return  DOUBLE;
    }

"char" { 
        yylval.line = yylineno;
        return  CHAR;
    }

"switch" { 
        yylval.line = yylineno;
        return  SWITCH;
    }

"for" { 
        yylval.line = yylineno;
        return  FOR;
    }
    
"func" { 
        yylval.line = yylineno;
        return  FUNC;
    }
"default" { 
        yylval.line = yylineno;
        return  DEFAULT;
    }

"return" { 
        yylval.line = yylineno;
        return  RETURN;
    }

"struct" { 
        yylval.line = yylineno;
        return  STRUCT;
    }

{id} {  
        yylval.line = yylineno;
        strcpy(yylval.sval, yytext);
        return ID;
    }
    
{numero} {
            yylval.line = yylineno;
            yylval.nval = atoi(yytext);
            return NUM;
        }
        

"{" { 
        yylval.line = yylineno;
        return LKEY;
    }

"}" {   
        yylval.line = yylineno;
        return RKEY;
}

"[" {   
        yylval.line = yylineno;
        return LBRACK;
    }

"]" {   
        yylval.line = yylineno;
        return RBRACK;
    }


"=" {   
        yylval.line = yylineno;
        return ASIG;
    }

"||" { 
        yylval.line = yylineno;
        return OR;
    }

"&&" { 
        yylval.line = yylineno; 
        return AND; 
    }

"==" {  
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return EQUAL;
    }
    
"!=" {  
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return NE;
    }
    
">" {   
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return GT;
    }
    
"<" {   
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return LT;
    }
 
">=" {   
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return GTE;
    }
    
"<=" {   
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return LTE;
    }
    
"+" { 
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return ADD;}

"-" { 
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return SUB;}

"*" {   
        yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return MUL;}

"/" {   yylval.line = yylineno;
        strcpy(yylval.ssval, yytext);
        return DIV;}

")" { 
        yylval.line = yylineno;
        return  RPAR;
    }

"(" {
        yylval.line = yylineno;
        return LPAR;
    }

"/*" { 
        yylval.line = yylineno;
        return  RLC;
    }

"*/" { 
        yylval.line = yylineno;
        return  LLC;
    } 

 "//" { 
        yylval.line = yylineno;
        return  SC;
    }
{espacio} {}

. { printf("ERROR: %s en la línea %d\n", yytext, yylineno);}

%%

