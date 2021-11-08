%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ErrorDim "La cantidad de tipos de variables es distinta a la cantidad de variables"

FILE *yyin;
FILE *fptr;

int dimVariable = 0;
int dimTipo = 0;
char dimVariableList[5][20];
char dimTipoList[5][20];
void yyerror(char *s);
int yylex(void);
int CheckDim(void);
void SaveInFile(void);

%}
%union{
    char name[20];
    int num;
}

%token STRING NUM ID WHILE PARAB PARCE CORAB CORCE OP_MAY IF ELSE OP_AS DIM AS COMA STRINGT INTEGER REAL CUAAB CUACE
%token FOR TO NEXT EQUMAX EQUMIN FIN OP_MEN OP_MAYIGU OP_MENIGU OP_IGU OP_DIST DISPLAY GET NOT AND OR

%type <name> ID
%type <num> NUM
%type <name> TIPO

%%
prog: lines;

lines: 
|   line lines;

line: W         {printf("Se ha analizado un WHILE\n\n\n");}
| I             {printf("Se ha analizado un IF\n\n\n");}
| A FIN         {printf("Se ha analizado una ASIGNACION\n\n\n");}
| DIS FIN       {printf("Se ha analizado un DISPLAY\n\n\n");}
| GET ID FIN    {printf("<line> --> GET ID ;\n"); printf("Se ha analizado un GET\n\n\n");}
| D FIN         {CheckDim(); printf("Se ha analizado un DIM\n\n\n")}
| F             {printf("Se ha analizado un FOR\n\n\n");};


//ITERACION
W: WHILE COMPARATION BODY {printf("<W> --> WHILE COMPARATION BODY\n");};


//DECISIONES
I: IF COMPARATION BODY              {printf("<I> --> IF COMPARATION BODY\n");}
| IF COMPARATION BODY ELSE BODY     {printf("<I> --> IF COMPARATION BODY ELSE BODY\n");};

COMPARATION: PARAB COND PARCE       {printf("<COMPARATION> --> ( COND )\n");};

COND: CONDFINAL                     {printf("<COND> --> CONDITIONFINAL\n");}
| NOT CONDFINAL                     {printf("<COND> --> ! CONDITIONFINAL\n");}
| CONDFINAL OR CONDFINAL            {printf("<COND> --> CONDITIONFINAL || CONDITIONFINAL\n");}
| CONDFINAL AND CONDFINAL           {printf("<COND> --> CONDITIONFINAL && CONDITIONFINAL\n");}
| E                                 {printf("<COND> --> E\n");};

CONDFINAL: ID CONDITION V           {printf("<CONDITIONFINAL> --> ID CONDITION V\n");};

CONDITION: OP_MAY                   {printf("<CONDITION> --> >\n");}
| OP_MEN                            {printf("<CONDITION> --> <\n");}
| OP_MAYIGU                         {printf("<CONDITION> --> >=\n");}
| OP_MENIGU                         {printf("<CONDITION> --> <=\n");}
| OP_IGU                            {printf("<CONDITION> --> ==\n");}
| OP_DIST                           {printf("<CONDITION> --> !=\n");};

BODY: CORAB lines CORCE             {printf("<BODY> --> { LINES }\n")};


//ASIGNACIONES
A: ID OP_AS V                       {printf("<A> --> ID := V\n");};


//DISPLAY
DIS: DISPLAY STRING                 {printf("<DIS> --> DISPLAY STRING\n");}
| DISPLAY ID                        {printf("<DIS> --> DISPLAY ID\n");};

//DECLARACIONES
D: DIM LISTAVARIABLE AS LISTATIPO   {printf("<D> --> DIM LISTAVARIABLE AS LISTATIPO\n");};

LISTAVARIABLE: CUAAB VARIABLES CUACE {printf("<LISTAVARIABLE> --> [ VARIABLES ]\n");};

VARIABLES: ID           {strcpy(dimVariableList[dimVariable++], $1); printf("<VARIABLES> --> ID\n");}
| VARIABLES COMA ID     {strcpy(dimVariableList[dimVariable++], $3); printf("<VARIABLES> --> VARIABLES , ID\n");};

LISTATIPO: CUAAB TIPOS CUACE        {printf("<LISTATIPO> --> [ TIPOS ]\n");};

TIPOS: TIPO             {strcpy(dimTipoList[dimTipo++], $1); printf("<TIPOS> --> TIPO\n");}
| TIPOS COMA TIPO       {strcpy(dimTipoList[dimTipo++], $3); printf("<TIPOS> --> TIPOS , TIPO\n");};

TIPO: STRINGT           {strcpy($$,"string"); printf("<TIPO> --> STRINGT\n");}
| REAL                  {strcpy($$,"real"); printf("<TIPO> --> REAL\n");}
| INTEGER               {strcpy($$,"integer"); printf("<TIPO> --> INTEGER\n");}; 


//TEMA ESPECIAL

//FOR
F: FOR ID OP_AS NUM TO NUM STEP lines NEXT ID   {printf("<F> --> FOR ID := NUM TO NUM STEP LINES NEXT ID\n");};

STEP: CUAAB CUACE                               {printf("<STEP> --> [ ]\n");}
| CUAAB NUM CUACE                               {printf("<STEP> --> [ NUM ]\n");};


//EQUMAX-EQUMIN
E: EQU PARAB EXPRESIONEQU FIN LISTAEQU PARCE    {printf("<E> --> EQU ( EXPRESIONEQU ; LISTAEQU )\n"); printf("Se ha analizado un EQUMAX/MIN\n\n");};

EQU: EQUMAX                                     {printf("<EQU> --> EQUMAX\n");}
| EQUMIN                                        {printf("<EQU> --> EQUMIN\n");}; 

EXPRESIONEQU: NUM CONDITION NUM                 {printf("<EXPRESIONEQU> --> NUM CONDITION NUM\n");};

LISTAEQU: CUAAB ELEMENTOEQU CUACE               {printf("<LISTAEQU> --> [ ELEMENTOEQU ]\n");};

ELEMENTOEQU: V                                  {printf("<ELEMENTOEQU> --> V\n");}
| ELEMENTOEQU COMA V                            {printf("<ELEMENTOEQU> --> ELEMENTOEQU COMA V\n");};

V: ID                                           {printf("<V> --> ID\n");}
| NUM                                           {printf("<V> --> NUM\n");};


%%

int main(int argc,char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
        while(feof(yyin) == 0)
        {
            yyparse();
        }
    }
    
    fclose(yyin);
    return 1;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int CheckDim()
{
    printf("Aca entro!\n");
    if(dimVariable != dimTipo)
    {
        printf(ErrorDim);
        return 1;
    }
    
    SaveInFile();
}

void SaveInFile()
{
    if ((fptr = fopen("ts.txt", "w")) == NULL)
    {
        printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
    }
    else
    {
        fprintf(fptr,"%-15s %-15s %-15s %-15s\n", "NOMBRE", "TIPODATO", "VALOR", "LONGITUD");

        int x = 0;
        for(x = 0; x < dimVariable; x++)
        {
            fprintf(fptr,"%-15s %-15s %-15s %-15s\n", dimVariableList[x], dimTipoList[x], "-", "-");
        }
    }
    
    fclose(fptr);
}