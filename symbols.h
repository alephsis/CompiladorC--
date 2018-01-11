#ifndef SYMBOLS_H
#define SYMBOLS_H

/* Define a Node for the lists of parameters */
typedef struct NodeParam NodeParam;
struct NodeParam {
    char* data;
    NodeParam *next;
};


typedef struct _symbol{
    char id[32];
    int dir;
    char* type;
    char* var;
    int listLength;
    NodeParam list;
} symbol;


typedef struct _symbols_table{
    symbol syms[1000];
    int next;
} symbols_table;

/* Define a Node for the stack */
typedef struct Node Node;
struct Node {
    symbols_table data;
    Node *next;
};


Node STACK_TOP;

void init_table();

int search(char *id);

int searchLocal(char *id);

int insert(symbol sym);

void addParam(NodeParam* lista, char* data);

symbol* isFunction(char *id);

char* get_type(char *id);

int get_dir(char *id);

char* get_var(char *id);

NodeParam* get_list(char *id);

int set_type(char *id, char* type);

int set_dir(char *id, int dir);

int set_var(char *id, char* var);

void print_table();

void print_table2(symbols_table tab);

void pushST(symbols_table elem);

symbols_table popST();

#endif
