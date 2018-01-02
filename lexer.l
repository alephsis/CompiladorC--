%{
#include <stdio.h>
#include "semantic.tab.h"
%}

%option noyywrap
%option yylineno


id [a-zA-Z_][a-zA-Z0-9_]*
entero [0-9]+
espacio [ \t\n]

%%

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

{id} {  
        yylval.line = yylineno;
        strcpy(yylval.sval, yytext);
        return ID;
    }
    
{entero} {
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
    
{espacio} {}

. { printf("ERROR: %s en la línea %d\n", yytext, yylineno);}

%%


