#include "symbols.h"
#include <stdio.h>
#include <string.h>


void init_table(){ /* this sould be called init_stack xD */
    Node STACK_TOP;
    symbols_table sym_table;
    sym_table.next = 0;
    STACK_TOP.data = sym_table;
    STACK_TOP.next = NULL;
}


int search(char *id){
  Node* actual = &STACK_TOP;
  while(actual != NULL){
    for(int i = 0; i < actual->data.next; i++){
      if(strcmp(id, actual->data.syms[i].id)==0){
	return i;
      }
    }
    actual = actual->next;
  }
    return -1;
}

int searchLocal(char *id){

    for(int i = 0; i < STACK_TOP.data.next; i++){
      if(strcmp(id, STACK_TOP.data.syms[i].id)==0){
	return i;
      }
    }
    return -1;
    
}


int insert(symbol sym){
    int pos = searchLocal(sym.id);
    if(STACK_TOP.data.next<1000 && pos ==-1){        
        STACK_TOP.data.syms[STACK_TOP.data.next] = sym;
        STACK_TOP.data.next++;
        return STACK_TOP.data.next;
    }
    return -1;
}
    

char* get_type(char *id){
    int pos = searchLocal(id);
    if(pos != -1){
        return STACK_TOP.data.syms[pos].type;
    }
    return "";
}

int get_dir(char *id){
    int pos = searchLocal(id);
    if(pos != -1){
        return STACK_TOP.data.syms[pos].dir;
    }
    return -1;
}

char* get_var(char *id){
    int pos = searchLocal(id);
    if(pos != -1){
        return STACK_TOP.data.syms[pos].var;
    }
    return NULL;
}


int set_type(char *id, char* type){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].type = type;
        return pos;
    }
    return -1;
}
int set_dir(char *id, int dir){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].dir= dir;
        return pos;
    }
    return -1;
}

int set_var(char *id, char* var){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].var = var;
        return pos;
    }
    return -1;
}


void print_table(){
    printf("*** TABLA DE SIMBOLOS ***\n");
    printf("pos\tid\ttipo\tdir\tvar\n");
    for(int i = 0; i<STACK_TOP.data.next; i++){
        printf("%d\t%s\t%s\t%d\t%s\n",i,STACK_TOP.data.syms[i].id, STACK_TOP.data.syms[i].type, STACK_TOP.data.syms[i].dir, STACK_TOP.data.syms[i].var);
    }
}

void print_table2(symbols_table tab){
  printf("*** TABLA DE SIMBOLOS ***\n");
    printf("pos\tid\ttipo\tdir\tvar\n");
    for(int i = 0; i<tab.next; i++){
        printf("%d\t%s\t%s\t%d\t%s\n",i,tab.syms[i].id, tab.syms[i].type, tab.syms[i].dir, tab.syms[i].var);
    }
}

void pushST(symbols_table elem){
  Node temp;
  temp.data = STACK_TOP.data;
  temp.next = STACK_TOP.next;
  STACK_TOP.data = elem;
  STACK_TOP.next = &temp;
}

symbols_table popST(){
  symbols_table ret = STACK_TOP.data;
  Node temp;
  temp.data = STACK_TOP.next->data;
  temp.next = STACK_TOP.next->next;
  STACK_TOP = temp;
  return ret;
  
}

/* Añade un nuevo elemento(tipo) a una lista de parametros */
void addParam(NodeParam lista, char* tipo){
    
    NodeParam nuevo;
    nuevo.data = tipo;
    nuevo.next = NULL;
    lista.next = &nuevo;

}
