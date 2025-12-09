
#include "criardungeons.h"
#include "Varglobal.h"
#include "structs.h"
#define LINHAS 6
#define COLUNAS 6
#define MAX_OPCOES_EXPLORAR 2


#define EFEITO_VAZIO {"\0",0,0,0,0}
#define ITEM_VAZIO {"\0","\0",{0},0}
#define SALA_VAZIA {"\0",{"\0"},NADA,INVALIDO,{INIMIGO_VAZIO}}

enum OpcoesMenu {
     CAMINHAR = 1,
     INTERAGIR,
};



const INIMIGOS InimigoVazio = {"\0",{0},0,0,{ITEM_VAZIO},{EFEITO_VAZIO}};
MODELO_SALA_DUNGEON DungeonAtual[LINHAS][COLUNAS];
MODELO_SALA_DUNGEON *SalaAtual = NULL;

int Coordenadas[2] = {0};

FILE *ArqPtr = NULL;

void AbrirArquivoDungeon(int Dungeon);
int InicializarDungeon(int DungeonEscolhida);
void InteragirEmSala();
extern void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala);

void Andar();
void ValidarOpcaoSelecionada(int *Selecionada);

