#ifndef ATTRIBS_H
#define ATTRIBS_H

#include "intermediate_code.h"

typedef struct _expresion{
    char dir[10];
    int type;
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

typedef struct _arrayType{
  char* tipo;  
  char* baseType;
  int dim;
  int baseDim;

} arrayType;

#endif
