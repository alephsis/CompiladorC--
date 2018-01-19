#ifndef ATTRIBS_H
#define ATTRIBS_H

#include "intermediate_code.h"

typedef struct _expresion{
    char dir[1000];
    char* type;
    int first;
} expresion;

typedef struct _condition{
    label ltrue;
    label lfalse;  
    int first;  
} condition;


typedef struct _num{
    int type;
    int ival;
    double dval;
} num;


typedef struct _sentence{
    label lnext;
    int first;    
} sentence;

typedef struct _type{
  char* tipo;
  int dim;
} type;

/* Estructura para manejar los tipos de los arreglos al ser declarados */

typedef struct _arrayType{
  char* tipo;  
  char* baseType;
  int dim;
  int baseDim;

} arrayType;

/* Estructura para manejar los arreglos al ser usados */

typedef struct _arrayUse{
  char *array;
  char* type;
  char dir[1000];
  char* width;
} arrayUse;

#endif
