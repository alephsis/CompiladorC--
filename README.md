# CompiladorC--
Compilador de Lenguaje C-- implementado usando Lex y Yacc/Bison 

##Hecho por:
Estas bellas personas
>Rodríguez Hernández Alexis Arturo
>Rivera Paz Rodrigo

###Para compilar:
Para compilar solo debemos ejecutar:
```
lex lexer.l
bison -d semantic.y
```
Ahora copiamos lo siguiente en semantic.tab.h el archivo que creó bison:
```C
#include "attribs.h"
#include "intermediate_code.c"
#include "symbols.c"
```
Y por último ejecutamos:
```
gcc lex.yy.c semantic.tab.c -lfl -o exe
./exe pruebas/prueba

```
para obtener una prueba rápida
