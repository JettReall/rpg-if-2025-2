
#include "criardungeons.h"
#include "Varglobal.h"
#include "structs.h"
#define LINHAS 2
#define COLUNAS 2


#define EFEITO_VAZIO {"\0",0,0,0,0}
#define ITEM_VAZIO {"\0","\0",{0},0}
#define INIMIGO_VAZIO {"\0",{0},0,0,{ITEM_VAZIO},{EFEITO_VAZIO}}
#define SALA_VAZIA {"\0",{"\0"},NADA,INVALIDO,{INIMIGO_VAZIO}}

MODELO_SALA_DUNGEON DungeonAtual[LINHAS][COLUNAS];
int InicializarDungeon(int DungeonEscolhida);
extern void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala);