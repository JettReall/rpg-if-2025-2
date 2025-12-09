
#include "criardungeons.h"
#include "Varglobal.h"
#include "structs.h"
#define LINHAS 6
#define COLUNAS 6


#define EFEITO_VAZIO {"\0",0,0,0,0}
#define ITEM_VAZIO {"\0","\0",{0},0}
#define SALA_VAZIA {"\0",{"\0"},NADA,INVALIDO,{INIMIGO_VAZIO}}

const INIMIGOS InimigoVazio = {"\0",{0},0,0,{ITEM_VAZIO},{EFEITO_VAZIO}};

MODELO_SALA_DUNGEON DungeonAtual[LINHAS][COLUNAS];
int InicializarDungeon(int DungeonEscolhida);
extern void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala);

