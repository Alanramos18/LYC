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
FILE *fasm;

int dimVariable = 0;
int dimTipo = 0;
int flag = 0;
int ifflag = 0;
int listflag = 0;
int body = 0;
int validation = 0;
char step[255];
char op[255];
char buffer[BUFFER_SIZE];
char dimVariableList[5][20];
char dimTipoList[5][20];
char idToAssign[30];
char valueConverted[30];
int value;
int lenght;
char condition[2];
char signoEqu[1];
char signo[1];
char equ[5];
char auxConvert[255];
char auxConvert2[255];
void yyerror(char *s);
int yylex(void);
int CheckDim(void);
void SaveValue(void);
void AddValue(char *str, const char *id, const int value);
void ResetTs();
void SaveInFile(int isDim);

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
void CheckExistingVariables();

void genera_asm();
void GeneraHeader();
void GeneraVariables();
void GeneraCode();

void ReadTreeForAsm(struct node* tree);
void AsmAsig(struct node* tree);
int ValidateComp(char *data);
int ValidateOp(char *data);

%}
%union{
    char name[20];
    int num;
}

%token STRING INT ID WHILE PARAB PARCE CORAB CORCE OP_MAY IF ELSE OP_AS DIM AS COMA STRINGT INTEGER REAL CUAAB CUACE
%token FOR TO NEXT EQUMAX EQUMIN FIN OP_MEN OP_MAYIGU OP_MENIGU OP_IGU OP_DIST DISPLAY GET NOT AND OR REA MAS MENOS POR DIV CONSTANT

%type <name> ID
%type <name> STRING
%type <num> INT
%type <name> TIPO

%%
prog: lines { progptr = linesptr; genera_asm();};

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
| GET ID FIN    {strcpy(idToAssign, $2); CheckExistingVariables(); lineptr = create_node("GET", NULL, create_leaf($2));}
| D FIN         {CheckDim();}
| F             {lineptr = Fptr};


//ITERACION
W: WHILE COMPARATION BODY { Wptr = create_node("WHILE", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0;};


//DECISIONES
I: IF COMPARATION BODY              {selPtr = create_node("IF", bodyPtr, condfinPtr); if(ifflag == 1) { linesptr = auxPtr; }; ifflag = 0;}
| IF COMPARATION BODY {accionPtr = bodyPtr;} ELSE BODY { elsePtr = bodyPtr;
                                                            bodyPtr = create_node("BODY", elsePtr, accionPtr);
                                                            selPtr = create_node("IF", bodyPtr, condfinPtr);};

COMPARATION: PARAB COND PARCE;

COND: CONDFINAL                     
| NOT CONDFINAL                     {condfinPtr = create_node("!", NULL, condfinPtr);}
| CONDFINAL {expPtr = condfinPtr;} OR CONDFINAL            { condfinPtr = create_node("||", condfinPtr, expPtr);}
| CONDFINAL {expPtr = condfinPtr;} AND CONDFINAL           { condfinPtr = create_node("&&", condfinPtr, expPtr);}
| E                                 {auxPtr = create_node("==", create_leaf("0"), create_leaf("@true")); condfinPtr = create_node("L", auxPtr, EPtr);};

CONDFINAL: ID CONDITION V           {condfinPtr = create_node(condition, Vptr, create_leaf($1));};

CONDITION: OP_MAY                   {strcpy(condition, ">");}
| OP_MEN                            {strcpy(condition, "<");}
| OP_MAYIGU                         {strcpy(condition, ">=");}
| OP_MENIGU                         {strcpy(condition, "<=");}
| OP_IGU                            {strcpy(condition, "==");}
| OP_DIST                           {strcpy(condition, "!=");};

BODY: CORAB {body = 1;} lines {body = 0;} CORCE;


//ASIGNACIONES
A: CONSTANT ID OP_AS V { strcpy(idToAssign, $2); SaveInFile(0); Aptr = create_node(":=", Vptr, create_leaf($2)); }
| CONSTANT ID OP_AS STRING { 
    strcpy(idToAssign, $2); strcpy(valueConverted, $4); lenght = strlen(valueConverted); SaveInFile(0); Aptr = create_node(":=", create_leaf(valueConverted), create_leaf($2)); 
}
| ID OP_AS V {
    strcpy(idToAssign, $1); CheckExistingVariables(); Aptr = create_node(":=", Vptr, create_leaf($1));
}
| ID OP_AS STRING {
    strcpy(idToAssign, $1); CheckExistingVariables(); Aptr = create_node(":=", create_leaf($3), create_leaf($1));
};

//DISPLAY
DIS: DISPLAY STRING                 { 
                    int counter = 0;
                    int x = 0;
                    strcpy(valueConverted, $2);
                    for(x = 0; x < 20; x++)
                    {
                        if(valueConverted[x] == '"')
                        {
                            counter++;
                        }

                        if(counter == 2)
                        {
                            valueConverted[++x] = '\0';
                            break; 
                        }
                    } disPtr = create_node("Display", NULL, create_leaf(valueConverted));}
| DISPLAY ID                        { disPtr = create_node("Display", NULL, create_leaf($2));};

//DECLARACIONES
D: DIM LISTAVARIABLE AS LISTATIPO;   

LISTAVARIABLE: CUAAB VARIABLES CUACE;

VARIABLES: ID           {strcpy(dimVariableList[dimVariable++], $1); }
| VARIABLES COMA ID     {strcpy(dimVariableList[dimVariable++], $3); };

LISTATIPO: CUAAB TIPOS CUACE ;

TIPOS: TIPO             {strcpy(dimTipoList[dimTipo++], $1); }
| TIPOS COMA TIPO       {strcpy(dimTipoList[dimTipo++], $3); };

TIPO: STRINGT           {strcpy($$,"string"); }
| REAL                  {strcpy($$,"real"); }
| INTEGER               {strcpy($$,"integer"); }; 


//TEMA ESPECIAL

//FOR
F: FOR ID OP_AS INT TO INT STEP {body = 1;} lines NEXT ID   {
        sprintf(auxConvert, "%d", $4);
        lineptr = create_node(":=", create_leaf(auxConvert), create_leaf($2)); 
        sprintf(auxConvert, "%d", $6);
        condfinPtr = create_node("<=", create_leaf(auxConvert), create_leaf($2));
        saltoPtr = create_node(":=", create_node("+", create_leaf(step), create_leaf($2)), create_leaf($2));
        body = 0;
        bodyPtr = create_node("BODYWHILE", saltoPtr, bodyPtr);
        Wptr = create_node("WHILE", bodyPtr, condfinPtr);
        Fptr = create_node("FOR", Wptr, lineptr);
    };

STEP: CUAAB CUACE                               
| CUAAB INT CUACE                               { sprintf(auxConvert, "%d", $2); strcpy(step, auxConvert); };


//EQUMAX-EQUMIN
E: EQU PARAB EXPRESIONEQU FIN LISTAEQU PARCE    {
    condfinPtr = create_node("==", create_leaf(equ), create_leaf("@num"));
    retFalsePtr = create_node(":=", create_leaf("0"), create_leaf("@true"));
    retTruePtr = create_node(":=", create_leaf("1"), create_leaf("@true"));
    expPtr = create_node("BODY", retFalsePtr, retTruePtr);
    selPtr = create_node("IF", expPtr, condfinPtr);
    EPtr = create_node("L", selPtr, EPtr);
};

EQU: EQUMAX {strcpy(signoEqu, ">"); strcpy(equ, "@max");}
| EQUMIN {strcpy(signoEqu, "<"); strcpy(equ, "@min");}; 

EXPRESIONEQU: INT SIGNO INT                 { 
    sprintf(auxConvert, "%d", $1);
    sprintf(auxConvert2, "%d", $3);
    expPtr = create_node(signo, create_leaf(auxConvert2), create_leaf(auxConvert));
    EPtr = create_node(":=", expPtr, create_leaf("@num"));
};

SIGNO: MAS                  {strcpy(signo, "+");}
| MENOS                     {strcpy(signo, "-");}
| POR                       {strcpy(signo, "*");}
| DIV                       {strcpy(signo, "/");};

LISTAEQU: CUAAB ELEMENTOEQU CUACE;

ELEMENTOEQU: V     {
        maxPtr = create_node(":=", Vptr, create_leaf(equ));
        EPtr = create_node("L", maxPtr, EPtr);
    }
| ELEMENTOEQU COMA V {
        auxPtr = create_node(":=", Vptr, create_leaf("@aux"));
        condfinPtr = create_node(signoEqu, create_leaf(equ), create_leaf("@aux"));
        expPtr = create_node(":=", create_leaf("@aux"), create_leaf(equ));
        selPtr = create_node("IF", expPtr, condfinPtr);
        auxPtr = create_node("L", selPtr, auxPtr);
        EPtr = create_node("L", auxPtr, EPtr);
};

V: ID                                           {Vptr = create_leaf($1);}
| INT                                           {itoa($1, valueConverted, 10); sprintf(auxConvert, "%d", $1); Vptr = create_leaf(auxConvert);};


%%

int main(int argc,char *argv[])
{
    if ((yyin = fopen(argv[1], "rt")) == NULL)
    {
        printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
    }
    else
    {
        ResetTs();

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

void ResetTs()
{
    FILE *fp;

    remove("ts.txt");
    remove("Final.asm");
    
    fp  = fopen ("ts.txt", "w");
    fprintf(fp,"%-15s %-15s %-15s %-15s\n", "NOMBRE", "TIPODATO", "VALOR", "LONGITUD");

    fclose(fp);
}

int CheckDim()
{
    if(dimVariable != dimTipo)
    {
        printf(ErrorDim);
        return 1;
    }
    
    SaveInFile(1);
}

void SaveInFile(int isDim)
{
    char *pos;
    if(isDim == 1)
    {
        if ((fptr = fopen("ts.txt", "r")) == NULL)
        {
            printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        }

        if ((ftemp = fopen("temp.txt", "w")) == NULL)
        {
            printf("\nNo se puede abrir el archivo temporal\n");
        }
        
        while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
        {
            int x = 0;
            for(x = 0; x < dimVariable; x++)
            {
                pos = strstr(buffer, dimVariableList[x]);
                if(pos != NULL)
                {
                    printf("No se puede declarar una variable ya existente\n");
                    exit(1);
                }    
            }            
        }

        fclose(fptr);

        if ((fptr = fopen("ts.txt", "a")) == NULL)
        {
            printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        }
        int x = 0;
        for(x = 0; x < dimVariable; x++)
        {
            fprintf(fptr,"%-15s %-15s %-15s %-15s\n", dimVariableList[x], dimTipoList[x], "-", "-");
        }
        
        fclose(fptr);
        dimVariable = 0;
        dimTipo = 0;
    } else {
        fptr = fopen("ts.txt", "r");
                
        if (fptr == NULL)
        {
            printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
            exit(1);
        }
        
        while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
        {
            pos = strstr(buffer, idToAssign);
            if(pos != NULL)
            {
                printf("No se puede declarar una variable ya existente\n");
                exit(1);
            }
        }

        fclose(fptr);

        if ((fptr = fopen("ts.txt", "a")) == NULL)
        {
            printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        }
        
        if(lenght != 0)
        {
            fprintf(fptr,"%-15s %-15s %-15s %-15d\n", idToAssign, "-", valueConverted, lenght);
            lenght = 0;
        } else {
            fprintf(fptr,"%-15s %-15s %-15s %-15s\n", idToAssign, "-", valueConverted, "-");
        }

        fclose(fptr);
    }    
}

void CheckExistingVariables()
{
    fptr = fopen("ts.txt", "r");
    char *pos;         
    int flag = 0;
    if (fptr == NULL)
    {
        printf("\nNo se puede abrir el archivo de la tabla de simbolo\n");
        exit(1);
    }

    while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
    {
        char id[30], tipo[30], valor[30], longi[30], aux[30];
        pos = strstr(buffer, idToAssign);

        if(pos != NULL)
        {
            fseek(fptr, -70, SEEK_CUR);
            fscanf(fptr, "%s %s %s %s", id, tipo, valor, longi);
            flag++;

            if(strcmp(valor, "-") != 0)
            {
                printf("No se puede modificar las constantes\n");
                exit(1);
            }

            break;
        }
    }

    if(flag == 0)
    {
        printf("La variable %s no se ha declarado previamente\n", idToAssign);
        exit(1);
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

void ReadTreeForAsm(struct node* tree)
{    
    if(tree != NULL)
    {
        ReadTreeForAsm(tree->left);
    
        if(strcmp(tree->data, "Display") == 0)
        {
            fprintf(fasm,"displayString %s\n", tree->left->data);
        }

        if(strcmp(tree->data, "GET") == 0)
        {
            fprintf(fasm,"GetInteger %s\n", tree->left->data);
        }

        if(strcmp(tree->data, "IF") == 0)
        {
            if(ValidateComp(tree->left->data) == 0)
            {
                fprintf(fasm,"FLD %s\n", tree->left->left->data);
                fprintf(fasm,"FCOMP %s\n", tree->left->right->data);
                fprintf(fasm,"FSTSW AX\n");
                fprintf(fasm,"SAHF\n");
            } else if(strcmp(tree->left->data, "L") == 0){
                fprintf(fasm,"FLD %s\n", tree->left->right->left->data);
                fprintf(fasm,"FCOMP %s\n", tree->left->right->right->data);
                fprintf(fasm,"FSTSW AX\n");
                fprintf(fasm,"SAHF\n");
            } else if(strcmp(tree->left->data, "||") == 0 || strcmp(tree->left->data, "&&") == 0)
            {
                if(ValidateComp(tree->left->left->data) == 0)
                {
                    fprintf(fasm,"FLD %s\n", tree->left->left->left->data);
                    fprintf(fasm,"FCOMP %s\n", tree->left->left->right->data);
                    fprintf(fasm,"FSTSW AX\n");
                    fprintf(fasm,"SAHF\n");
                    fprintf(fasm,"%s end_if\n", op);
                }
                
                if(ValidateComp(tree->left->right->data) == 0)
                {
                    fprintf(fasm,"FLD %s\n", tree->left->right->left->data);
                    fprintf(fasm,"FCOMP %s\n", tree->left->right->right->data);
                    fprintf(fasm,"FSTSW AX\n");
                    fprintf(fasm,"SAHF\n");
                }
            }
            else
            { exit(1); }

            if(strcmp(tree->right->data, "BODY") == 0)
            {
                fprintf(fasm,"%s else_part\n", op);
                fprintf(fasm,"then_part:\n");
            } else {
                fprintf(fasm,"%s end_if\n", op);                
            }
        } else if(ValidateOp(tree->data) == 0)
        {
            fprintf(fasm,"FLD %s\n", tree->left->data);
            fprintf(fasm,"FLD %s\n", tree->right->data);
            fprintf(fasm,"%s\n", op);
        } else if(strcmp(tree->data, "BODY") == 0)
        {
            fprintf(fasm,"else_part:\n");
        } else if(strcmp(tree->data, "WHILE") == 0)
        {
            if(ValidateComp(tree->left->data) == 0)
            {
                fprintf(fasm,"begin_while:\n");
                fprintf(fasm,"FLD %s\n", tree->left->left->data);
                fprintf(fasm,"FCOMP %s\n", tree->left->right->data);
                fprintf(fasm,"FSTSW AX\n");
                fprintf(fasm,"SAHF\n");
                fprintf(fasm,"%s end_while\n", op);
            } else { exit(1); }
        }

        ReadTreeForAsm(tree->right);

        if(strcmp(tree->data, ":=") == 0)
        {
            if(ValidateOp(tree->right->data) == 0)
            {
                fprintf(fasm,"FSTP %s\n", tree->left->data);
                fprintf(fasm,"FFREE\n");
            } else {
                AsmAsig(tree);
            }
        } else if(strcmp(tree->data, "IF") == 0)
        {
            fprintf(fasm,"end_if:\n");
        } else if(strcmp(tree->data, "WHILE") == 0)
        {
            fprintf(fasm,"JMP begin_while\n");
            fprintf(fasm,"end_while:\n");
        }
    }
}

int ValidateOp(char *data)
{
    if(strcmp(data, "+") == 0)
    {
        strcpy(op, "FADD");
        return 0;
    }
    
    if(strcmp(data, "-") == 0)
    {
        strcpy(op, "FSUB");
        return 0;
    }
    
    if(strcmp(data, "*") == 0)
    {
        strcpy(op, "FMUL");
        return 0;
    }

    if(strcmp(data, "/") == 0)
    {
        strcpy(op, "FDIV");
        return 0;
    }

    return 1;
}

int ValidateComp(char *data)
{
    if(strcmp(data, ">") == 0)
    {
        strcpy(op, "JNA");
        return 0;
    }

    if(strcmp(data, "<") == 0)
    {
        strcpy(op, "JG");
        return 0;
    }

    if(strcmp(data, "<=") == 0)
    {
        strcpy(op, "JG");
        return 0;
    }

    if(strcmp(data, "==") == 0)
    {
        strcpy(op, "JNE");
        return 0;
    }

    return 1;
}

void AsmAsig(struct node* tree)
{
    fprintf(fasm,"FILD %s\n", tree->right->data);
    fprintf(fasm,"FISTP %s\n", tree->left->data);
}

void genera_asm()
{
    GeneraHeader();
    GeneraVariables();
    GeneraCode();
}

void GeneraHeader()
{
    fasm = fopen("Final.asm", "w");
    
    if (fasm == NULL)
    {
        printf("\nNo se puede abrir el archivo assembler\n");
        exit(1);
    }

    fprintf(fasm,"include macros2.asm\n");
    fprintf(fasm,"include number.asm\n\n");
    fprintf(fasm,".MODEL LARGE\n.386\n.STACK200h\n\n");
    fclose(fasm);    
}

void GeneraVariables()
{
    fptr = fopen("ts.txt", "r");
    fasm = fopen("Final.asm", "a");

    if (fptr == NULL || fasm == NULL)
    {
        printf("\nError al abrir algun archivo\n");
        exit(1);
    }

    fprintf(fasm, ".DATA\n\n");

    while((fgets(buffer, BUFFER_SIZE, fptr)) != NULL)
    {
        char id[30], tipo[30], valor[30], longi[30], aux[30];
        fscanf(fptr, "%s %s %s %s", id, tipo, valor, longi);
        if(strcmp(aux, id) == 0)
            continue;
        strcpy(aux, id);
        
        if(strcmp(valor, "-") == 0)
            strcpy(valor, "?");

        fprintf(fasm,"%-10s %-10s %-10s\n", id, "dd", valor);
    }

    fprintf(fasm, "\n");

    fclose(fasm);    
    fclose(fptr);
}

void GeneraCode()
{
    fasm = fopen("Final.asm", "a");
    
    if (fasm == NULL)
    {
        printf("\nNo se puede abrir el archivo assembler\n");
        exit(1);
    }

    fprintf(fasm,".CODE\n\nmov AX, @DATA\nmov DS, AX\nmov es,ax\n\n");

    ReadTreeForAsm(progptr);

    fprintf(fasm,"\nmov ax, 4c00h\nint 21h\nEND");

    fclose(fasm);    
}