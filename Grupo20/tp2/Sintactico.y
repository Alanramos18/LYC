%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ErrorDim "La cantidad de tipos de variables es distinta a la cantidad de variables"
#define BUFFER_SIZE 1000

struct node 
{
    char data[255];
    struct node* left;
    struct node* right;
};

FILE *yyin;
FILE *fptr;
FILE *ftemp;

int dimVariable = 0;
int dimTipo = 0;
int flag = 0;
int ifflag = 0;
int listflag = 0;
int body = 0;
char step[255];
char buffer[BUFFER_SIZE];
char dimVariableList[5][20];
char dimTipoList[5][20];
char idToAssign[20];
int value;
char condition[2];
char signo[1];
char auxConvert[255];
char auxConvert2[255];
void yyerror(char *s);
int yylex(void);
int CheckDim(void);
void SaveInFile(void);
void SaveValue(void);
void AddValue(char *str, const char *id, const int value);

struct node* progptr; 
struct node* linesptr; 
struct node* lineptr; 
struct node* Aptr;
struct node* Fptr;
struct node* saltoPtr;
struct node* Vptr;
struct node* Wptr;
struct node* selPtr;
struct node* condfinPtr;
struct node* accionPtr;
struct node* bodyPtr;
struct node* elsePtr;
struct node* auxPtr;
struct node* disPtr;
struct node* getPtr;
struct node* retFalsePtr;
struct node* retTruePtr;
struct node* expPtr;
struct node* maxPtr;
struct node* EPtr;

struct node* create_leaf(char data[255]);
struct node* create_node(char data[255], struct node* right, struct node* left);
void ReadTree(struct node* tree);

%}
%union{
    char name[20];
    int num;
}

%token STRING INT ID WHILE PARAB PARCE CORAB CORCE OP_MAY IF ELSE OP_AS DIM AS COMA STRINGT INTEGER REAL CUAAB CUACE
%token FOR TO NEXT EQUMAX EQUMIN FIN OP_MEN OP_MAYIGU OP_MENIGU OP_IGU OP_DIST DISPLAY GET NOT AND OR REA MAS MENOS POR DIV

%type <name> ID
%type <name> STRING
%type <num> INT
%type <name> TIPO

%%
prog: lines { progptr = linesptr; };

lines: line { 
    if(body == 1) {
        if(ifflag == 0)
        {
            bodyPtr = lineptr;
        } else {
            bodyPtr = create_node("L", lineptr, linesptr);
        }
    } else {
        linesptr = create_node("L", lineptr, linesptr);
    }}
|   line {
        if(body == 1)
        {
            if(ifflag == 0)
            {
                ifflag = 1;
                auxPtr = linesptr;
                linesptr = lineptr;
            } else {
                bodyPtr = create_node("L", lineptr, linesptr);
            }
        } else {
            if(flag == 0)
            {
                flag = 1;
                linesptr = lineptr;
            } else {
                linesptr = create_node("L", lineptr, linesptr);
            }
        }
    } lines;

line: W         {lineptr = Wptr;}
| I             {lineptr = selPtr}
| A FIN         {lineptr = Aptr;}
| DIS FIN       {lineptr = disPtr;}
| GET ID FIN    {lineptr = create_node("GET", NULL, create_leaf($2));}
| D FIN         {CheckDim(); printf("Se ha analizado un DIM\n\n\n");}
| F             {lineptr = Fptr};


//ITERACION
W: WHILE COMPARATION BODY { Wptr = create_node("WHILE", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0;};


//DECISIONES
I: IF COMPARATION BODY              {selPtr = create_node("IF", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0; }
| IF COMPARATION BODY {accionPtr = bodyPtr;} ELSE BODY { elsePtr = bodyPtr;
                                                            bodyPtr = create_node("ELSE", elsePtr, accionPtr);
                                                            selPtr = create_node("IF", bodyPtr, condfinPtr);};

COMPARATION: PARAB COND PARCE;

COND: CONDFINAL                     
| NOT CONDFINAL                     {condfinPtr = create_node("!", NULL, condfinPtr);}
| CONDFINAL {expPtr = condfinPtr;} OR CONDFINAL            { condfinPtr = create_node("||", condfinPtr, expPtr);}
| CONDFINAL {expPtr = condfinPtr;} AND CONDFINAL           { condfinPtr = create_node("&&", condfinPtr, expPtr);}
| E                                 {condfinPtr = EPtr;};

CONDFINAL: ID CONDITION V           {condfinPtr = create_node(condition, Vptr, create_leaf($1));};

CONDITION: OP_MAY                   {strcpy(condition, ">");}
| OP_MEN                            {strcpy(condition, "<");}
| OP_MAYIGU                         {strcpy(condition, ">=");}
| OP_MENIGU                         {strcpy(condition, "<=");}
| OP_IGU                            {strcpy(condition, "==");}
| OP_DIST                           {strcpy(condition, "!=");};

BODY: CORAB {body = 1;} lines {body = 0;} CORCE;


//ASIGNACIONES
A: ID OP_AS V             {strcpy(idToAssign, $1); SaveValue(); Aptr = create_node(":=", Vptr, create_leaf($1));};


//DISPLAY
DIS: DISPLAY STRING                 {printf("<DIS> --> DISPLAY STRING\n"); disPtr = create_node("Display", NULL, create_leaf($2));}
| DISPLAY ID                        { disPtr = create_node("Display", NULL, create_leaf($2));};

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
F: FOR ID OP_AS INT TO INT STEP {body = 1;} lines NEXT ID   {
        sprintf(auxConvert, "%d", $4);
        lineptr = create_node("=", create_leaf(auxConvert), create_leaf($2)); 
        sprintf(auxConvert, "%d", $6);
        condfinPtr = create_node("<=", create_leaf(auxConvert), create_leaf($2));
        saltoPtr = create_node("=", create_node("+", create_leaf(step), create_leaf($2)), create_leaf($2));
        body = 0;
        bodyPtr = create_node("BODYWHILE", saltoPtr, bodyPtr);
        Wptr = create_node("WHILE-FOR", bodyPtr, condfinPtr);
        Fptr = create_node("FOR", Wptr, lineptr);
    };

STEP: CUAAB CUACE                               
| CUAAB INT CUACE                               { sprintf(auxConvert, "%d", $2); strcpy(step, auxConvert); };


//EQUMAX-EQUMIN
E: EQU PARAB EXPRESIONEQU FIN LISTAEQU PARCE    {
    condfinPtr = create_node("==", create_leaf("@max"), create_leaf("@num"));
    retFalsePtr = create_node("Return", NULL, create_leaf("False"));
    retTruePtr = create_node("Return", NULL, create_leaf("True"));
    expPtr = create_node("L", retFalsePtr, retTruePtr);
    selPtr = create_node("IF", expPtr, condfinPtr);
    EPtr = create_node("L", selPtr, EPtr);
};

EQU: EQUMAX
| EQUMIN; 

EXPRESIONEQU: INT SIGNO INT                 { 
    sprintf(auxConvert, "%d", $1);
    sprintf(auxConvert2, "%d", $3);
    expPtr = create_node(signo, create_leaf(auxConvert2), create_leaf(auxConvert));
    EPtr = create_node("=", expPtr, create_leaf("@num"));
};

SIGNO: MAS                  {strcpy(signo, "+");}
| MENOS                     {strcpy(signo, "-");}
| POR                       {strcpy(signo, "*");}
| DIV                       {strcpy(signo, "/");};

LISTAEQU: CUAAB ELEMENTOEQU CUACE;

ELEMENTOEQU: V     { 
        if (listflag == 0) {
            maxPtr = create_node("=", Vptr, create_leaf("@max"));
            listflag = 1;
        } else {
            expPtr = create_node("=", Vptr, create_leaf("@aux"));
            expPtr = create_node("L", expPtr, maxPtr);
            maxPtr = NULL;
            EPtr = create_node("L", expPtr, EPtr);
            condfinPtr = create_node(">", create_leaf("@max"), create_leaf("@aux"));
            expPtr = create_node("=", create_leaf("@aux"), create_leaf("@max"));
            selPtr = create_node("IF-EQU", expPtr, condfinPtr);
            EPtr = create_node("L", selPtr, EPtr);
        }
    }
| V COMA   {
    if (listflag == 0) {
        maxPtr = create_node("=", Vptr, create_leaf("@max"));
        listflag = 1;
    } else {
        expPtr = create_node("=", Vptr, create_leaf("@aux"));
        expPtr = create_node("L", expPtr, maxPtr);
        maxPtr = NULL;
        EPtr = create_node("L", expPtr, EPtr);
        condfinPtr = create_node(">", create_leaf("@max"), create_leaf("@aux"));
        expPtr = create_node("=", create_leaf("@aux"), create_leaf("@max"));
        selPtr = create_node("IF", expPtr, condfinPtr);
        EPtr = create_node("L", selPtr, EPtr);
    }
} ELEMENTOEQU;

V: ID                                           {Vptr = create_leaf($1);}
| INT                                           {sprintf(auxConvert, "%d", $1); Vptr = create_leaf(auxConvert);};


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
    
    if ((fptr = fopen("intermedia.txt", "w")) == NULL)
    {
        printf("\nNo se puede abrir el archivo intermedio\n");
    }
    else
    {
        ReadTree(progptr);
    }
    
    fclose(fptr);

    return 1;
}

void yyerror(char *s)
{
    fprintf(stderr, "%s\n", s);
}

int CheckDim()
{
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

void SaveValue()
{
    fptr = fopen("ts.txt", "r");
    ftemp = fopen("temp.txt", "w");

    if (fptr == NULL || ftemp == NULL)
    {
        printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        exit(1);
    }
    
    while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
    {
        AddValue(buffer, idToAssign, value);

        fputs(buffer, ftemp);
    }
    
    fclose(fptr);
    fclose(ftemp);

    remove("ts.txt");

    rename("temp.txt", "ts.txt");
}

void AddValue(char *str, const char *id, const int value)
{
    char *pos, temp[BUFFER_SIZE];
    int index = 0;
    int owlen, valen;
    char valueConverted[20];
    itoa(value, valueConverted, 10);

    owlen = strlen(id);
    valen = strlen(valueConverted);
    pos = strstr(str, id);
    if(pos != NULL)
    {
        strcpy(temp, str);
        index = pos - str + 32;
        str[index] = '\0';    
        strcat(str, valueConverted);
        strcat(str, temp + 32 + valen);
    }
}

struct node* create_leaf(char data[255])
{
    struct node* node = (struct node*) malloc(sizeof(struct node));

    strcpy(node->data, data);
    node->right = NULL;
    node->left = NULL;

    return node;
}

struct node* create_node(char data[255], struct node* right, struct node* left)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    strcpy(node->data, data);
    node->right = right;
    node->left = left;

    return node;
}

void ReadTree(struct node* tree)
{
    if(tree != NULL)
    {
        ReadTree(tree->left);
        if(strcmp(tree->data, "L"))
        {
            fprintf(fptr,"%s ", tree->data);
            printf("%s ", tree->data);            
        } else {
            fprintf(fptr,"\n");
            printf("\n");
        }    
        ReadTree(tree->right);
    }
}