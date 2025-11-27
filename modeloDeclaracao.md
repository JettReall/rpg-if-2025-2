#define NOME_DO_DEFINE
#define MAX_VALOR
define LIMITE

enum Nome {
     ITEM_A = x,
     ITEM_B,
     ITEM_C
     OBJETO,
     COISA,
};

typedef struct {
     int VarInteira;
     float VarFloat;
     char[VALOR];
} NOMEPADRAO //declaração de struct é bom ser junto, tipo NOMEPADRAO DeckDoPlayer;

int Array[LIMITE];
int MatrizInformativa[LINHAS][COLUNAS] //pode usar numeros fixos também, no lugar de defines, sem problemas, caso esse numero só seja usado pra isso
int *Ponteiro;
var *CoisaPtr; //Coloque no nome da variável o "Ptr", seja no final ou no começo

int FuncaoParaAlgo(int Var);

Em relação a nome de arquivos... não há muito o que falar, os .h precisam ter o mesmo nome do aquivo .c referente, apenas.
ex.: batalha.c; batalha.h