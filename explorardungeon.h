
#include "criardungeons.h"
#include "Varglobal.h"
#include "structs.h"
#define LINHAS 6
#define COLUNAS 6
#define MAX_OPCOES_EXPLORAR 2
#define DIRECAO 4
#define TEMPLOS 4
#define ALAVANCAS_VENTO 3
#define MAX_ALAVANCAS 3


#define EFEITO_VAZIO {"\0",0,0,0,0}
#define ITEM_VAZIO {"\0","\0",{0},0}
#define SALA_VAZIA {"\0",{"\0"},NADA,INVALIDO,{INIMIGO_VAZIO}}

enum OpcoesMenu {
     CAMINHAR = 1,
     INTERAGIR,
};

enum Ativacao{
     NAO_ATIVADO,
     ATIVADO,
};

char DescParaObstaculo[TEMPLOS][100] = {
     "Uma corrente de vento muito forte  sai do chão, não deixando nada passar.",
     "As vinhas estão densas e amontoadas demais para passar por aqui.",
     "A sala está cheia de água, deve ser para mergulhar, mas não tem como passar assim.",
     "Há uma parede enorme de chamas me impedindo de sequer ver o que há do outro lado."

};

char DescDoObstaculo[100] = "\0";

typedef struct {
     int Alavanca_X;
     int Alavanca_Y; //Coordenadas da sala de alavanca
     int Ativada;
     MODELO_SALA_DUNGEON *SalaConectada; //A sala que ela está conectada
} SALAS_ALAVANCA;


const INIMIGOS InimigoVazio = {"\0",{0},0,0,{ITEM_VAZIO},{EFEITO_VAZIO}};
MODELO_SALA_DUNGEON DungeonAtual[LINHAS][COLUNAS];
MODELO_SALA_DUNGEON *SalaAtual = NULL;

SALAS_ALAVANCA Alavancas[TEMPLOS][MAX_ALAVANCAS] = {
    { //Vento
         {3,4,NAO_ATIVADO,&DungeonAtual[4][2]},
         {1,0,NAO_ATIVADO,&DungeonAtual[5][1]},//Erro presente
         {2,4,NAO_ATIVADO,&DungeonAtual[0][3]},
    },
    {//Bosque
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
    },
    {//Agua
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
    },
    {//Fogo
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
          {0,0,NAO_ATIVADO,NULL},
    },

};

SALAS_ALAVANCA AlavancasDungeon[MAX_ALAVANCAS] = {0,0,NAO_ATIVADO,NULL};

int Coordenadas[2] = {0};
int AlavancasQtd = 0;

FILE *ArqPtr = NULL;

void AbrirArquivoDungeon(int Dungeon);
int InicializarDungeon(int DungeonEscolhida);
void InteragirEmSala();
void ImprimirOpcoes();
void Andar();
void ValidarOpcaoSelecionada(int *Selecionada);
void EfeitoDeSala(int TipoDeSala);
void ChecarComAndar(int DirEscolhida,int Validado,int Calculo);
extern void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala);

