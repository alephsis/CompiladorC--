#include "symbols.h"
#include <stdio.h>
#include <string.h>

/* Inicializa la pila de tablas de símbolos y una tabla con ella */

void init_table(){ /* this sould be called init_stack xD */
    Node STACK_TOP;
    symbols_table sym_table;
    sym_table.next = 0;
    STACK_TOP.data = sym_table;
    STACK_TOP.next = NULL;
}

/* regresa el symbolo con el id dado, si es función, NULL en otro caso */

symbol* isFunction(char *id){

  Node* actual = &STACK_TOP;
  while(actual != NULL){
    for(int i = 0; i < actual->data.next; i++){
      if(strcmp(id, actual->data.syms[i].id)==0){
	if(strcmp(actual->data.syms[i].var,"func") == 0)
	  return &(actual->data.syms[i]);
	else{
	  return NULL;
	}
      }
    }
    actual = actual->next;
  }
  return NULL;  
}

/* regresa la lista de tipos del id dado, busca en todas
   las tablas de símbolos, NULL en otro caso */

NodeParam* get_list(char *id){
 Node* actual = &STACK_TOP;
  while(actual != NULL){
    for(int i = 0; i < actual->data.next; i++){
      if(strcmp(id, actual->data.syms[i].id)==0){
	return &(actual->data.syms[i].list);
      }
    }
    actual = actual->next;
  }
  return NULL;
}

/* Busca un id en todas las tablas de simbolos de la pila */
 
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

/* Busca un id solo en la tabla al tope de la pila */

int searchLocal(char *id){

    for(int i = 0; i < STACK_TOP.data.next; i++){
      if(strcmp(id, STACK_TOP.data.syms[i].id)==0){
	return i;
      }
    }
    return -1;
    
}

/* Inserta un símbolo en la tabla al tope de la pila */

int insert(symbol sym){
    int pos = searchLocal(sym.id);
    if(STACK_TOP.data.next<1000 && pos ==-1){        
        STACK_TOP.data.syms[STACK_TOP.data.next] = sym;
        STACK_TOP.data.next++;
        return STACK_TOP.data.next;
    }
    return -1;
}

/* Regresa el tipo del id, buscandolo en todas las tablas de la pila */

char* get_type(char *id){
  Node* actual = &STACK_TOP;
  while(actual != NULL){
    for(int i = 0; i < actual->data.next; i++){
      if(strcmp(id, actual->data.syms[i].id)==0){
	return actual->data.syms[i].type;
      }
    }
    actual = actual->next;
  }
  return NULL;    
}
/* Regresa la dirección del id buscado en la tabla al tope de la pila */

int get_dir(char *id){
    int pos = searchLocal(id);
    if(pos != -1){
        return STACK_TOP.data.syms[pos].dir;
    }
    return -1;
}

/* Regresa meta-tipo del símbolo buscado en la tabla al tope de la pila */

char* get_var(char *id){
    int pos = searchLocal(id);
    if(pos != -1){
        return STACK_TOP.data.syms[pos].var;
    }
    return NULL;
}

/* Establece el tipo del id buscado en la tabla al tope de la pila */

int set_type(char *id, char* type){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].type = type;
        return pos;
    }
    return -1;
}

/* Establece la dirección del id buscado en la tabla al tope de la pila */

int set_dir(char *id, int dir){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].dir= dir;
        return pos;
    }
    return -1;
}

/* Establece el  meta-tipo del símbolo buscado en la tabla al tope de la pila */

int set_var(char *id, char* var){
    int pos = searchLocal(id);
    if(pos != -1){
        STACK_TOP.data.syms[pos].var = var;
        return pos;
    }
    return -1;
}

/* Construye y regresa todos los tipos en la lista cuya cabeza
   es el nodo dado como parámetro, en forma de cadena */

char* getTypes(NodeParam head){
  NodeParam* actual = &head;
  char* s = (char*)malloc(500*sizeof(char));
  while(actual != NULL){
    if(actual->data != NULL){
      strcat(s,actual->data);
      strcat(s,",");
    }
    actual = actual->next;
  }
  /* cut the last comma */
  int i = 0;
  while(*(s + i) != '\0'){
    i++;
  }
  *(s+i-1) = '\0';
  
  return s;  
}

/* Imprime la tabla al tope de la pila */

void print_table(){
    printf("*** TABLA DE SIMBOLOS ***\n");
    printf("pos\tid\ttipo\tdir\tvar\tLisLen\tParamList\n");
    for(int i = 0; i<STACK_TOP.data.next; i++){
      printf("%d\t%s\t%s\t%d\t%s\t%d\t%s\n",i,STACK_TOP.data.syms[i].id, STACK_TOP.data.syms[i].type, STACK_TOP.data.syms[i].dir, STACK_TOP.data.syms[i].var, STACK_TOP.data.syms[i].listLength,getTypes(STACK_TOP.data.syms[i].list));
    }
}

/* Imprime la tabla dada como parámetro */

void print_table2(symbols_table tab){
  printf("*** TABLA DE SIMBOLOS ***\n");
    printf("pos\tid\ttipo\tdir\tvar\tLisLen\tParamList\n");
    for(int i = 0; i<tab.next; i++){
      printf("%d\t%s\t%s\t%d\t%s\t%d\t%s\n",i,tab.syms[i].id, tab.syms[i].type, tab.syms[i].dir, tab.syms[i].var,tab.syms[i].listLength,getTypes(tab.syms[i].list));
    }
}

/* Inserta en la pila la tabla dada */

void pushST(symbols_table elem){
  Node temp;
  temp.data = STACK_TOP.data;
  temp.next = STACK_TOP.next;
  STACK_TOP.data = elem;
  STACK_TOP.next = &temp;
}

/* Saca un elemento de la pila y lo regresa */

symbols_table popST(){
  symbols_table ret = STACK_TOP.data;
  Node temp;
  temp.data = STACK_TOP.next->data;
  temp.next = STACK_TOP.next->next;
  STACK_TOP = temp;
  return ret;
  
}

/* Añade un nuevo elemento(tipo) a una lista de parametros */

void addParam(NodeParam* lista, char* tipo){
    
    NodeParam* nuevo;
    nuevo = (NodeParam*)malloc(sizeof(NodeParam));
    nuevo->data = tipo;
    nuevo->next = NULL;
    lista->next = nuevo;

}
