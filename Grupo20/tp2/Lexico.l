%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#define STRING 258
#define INT 259
#define ID 260
#define PARAB 262
#define PARCE 263
#define CORAB 264
#define CORCE 265
#define WHILE 261
#define MAS 295
#define MENOS 296
#define POR 297
#define DIV 298
#define OP_MAY 266
#define IF 267
#define ELSE 268
#define OP_AS 269
#define DIM 270
#define AS 271
#define COMA 272
#define STRINGT 273
#define INTEGER 274
#define REAL 275
#define CUAAB 276
#define CUACE 277
#define FOR 278
#define TO 279
#define NEXT 280
#define EQUMAX 281
#define EQUMIN 282
#define FIN 283
#define OP_MEN 284
#define OP_MAYIGU 285
#define OP_MENIGU 286
#define OP_IGU 287
#define OP_DIST 288
#define DISPLAY 289
#define GET 290
#define NOT 291
#define AND 292
#define OR 293
#define REA 294
#define CONSTANT 299

void CheckStringLenght(char *);
void CheckInt(int num);
void CheckReal(char *num);
%}

%option noyywrap
%option yylineno

DIGITO      [0-9]
LETRA       [a-zA-Z]

ID          {LETRA}({LETRA}|{DIGITO})*
STRING      \"[^"]*\"
COMMENT     "*/".*"/*"
INT         {DIGITO}+
REAL        {DIGITO}*"."{DIGITO}*

%%
"const"         return (CONSTANT);
"NOT"           return (NOT);
"AND"           return (AND);
"OR"            return (OR);
"DISPLAY"       return (DISPLAY);
"GET"           return (GET);
"for"           return (FOR);
"to"            return (TO);
"next"          return (NEXT);
"EQUMAX"        return (EQUMAX);
"EQUMIN"        return (EQUMIN);
","             return (COMA);
"string"        return (STRINGT);
"integer"       return (INTEGER);
"real"          return (REAL);
"dim"           return (DIM);
"as"            return (AS);
":="            return (OP_AS);
"while"         return (WHILE);
"if"            return (IF);
"else"          return (ELSE);
"["             return (CUAAB);
"]"             return (CUACE);
"("             return (PARAB);
")"             return (PARCE);
"{"             return (CORAB);
"}"             return (CORCE);
"+"             return (MAS);
"-"             return (MENOS);
"*"             return (POR);
"/"             return (DIV);
">"             return (OP_MAY);
"<"             return (OP_MEN);
">="            return (OP_MAYIGU);
"<="            return (OP_MENIGU);
"=="            return (OP_IGU);
"!="            return (OP_DIST);
";"             return (FIN);
{STRING}        {CheckStringLenght(yytext); sscanf(yytext, "%[^|]|%s", yylval.name); return(STRING);};
{INT}           {CheckInt(atoi(yytext)); yylval.num = atoi(yytext); return (INT);};
{REAL}          {CheckReal(yytext); return (REA);};
{ID}            {sscanf(yytext, "%s", yylval.name); return (ID);};
{COMMENT}
"\n"
"\t"
"\n\t"
"\r\n"
","
" "
.               { printf("Caracter invalido!\n"); exit(1); }
%%

void CheckStringLenght(char *str)
{
    int cont = 0;
    while(str[cont] != '\0')
    {
        if(cont == 31)
        {
            printf("The string should have a max of 30 chars\n");
            exit(1);
        }
        cont++;
    }
}

void CheckInt(int num)
{
    if(num > 65535)
    {
        printf("El numero ingresado excede del valor maximo de un entero \(65535)\n");
        exit(1);
    }
}

void CheckReal(char *num)
{
    char *first = num;
    char second[255];
    int u = 0;
    int x = 0;
    while(num[u] != '.')
    {
        u++;
    }
    u++;
    while(num[u] != '\0')
    {
        second[x++] = num[u++];
    }
    CheckInt(atoi(first));
    CheckInt(atoi(second));
}