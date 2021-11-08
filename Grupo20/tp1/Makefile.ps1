bison -dyv Sintactico.y
flex Lexico.l
bison Sintactico.y
gcc lex.yy.c Sintactico.tab.c -o Primera
.\Primera.exe prueba.txt