#include "explorardungeon.h"
#define MAXOPCOES_MAIOR 3
#define MAXDESTINOS 4
enum OpcoesCidade{
     SAIR_LOCAL = 1,
     SALVAR = 2, ENTRAR_DUNGEON = 2,
     MEXER_BARALHO = 3,
};

enum Destinos {
     CASA = 0,
     DUNGEON = 1,
     PRACA,
     TABERNA,
};

enum MaxOpcoes {
     CASA_OPT = 3,
     DUNGEON_OPT = 2,
     PRACA_OPT = 0,
     TABERNA_OPT = 0,
};

typedef struct {
     int ID;
     char Nome[30];
     char DescricaoLocal[MAX_TAM_DESCRICAO];
     LOCAL *Conexao;
     NPC *Figurante;
}LOCAL;

NPC NPC_Vazio = {"\0",{ITEM_VAZIO}};


const int OpcoesQtd[MAXDESTINOS] = {CASA_OPT,DUNGEON_OPT,PRACA_OPT,TABERNA_OPT};


int OpcoesLocal(int Local);
void OpcoesCasa(int Selecionada);
void OpcoesDungeon(int Selecionada);
void OpcoesPraca(int Selecionada);
void OpcoesTaberna(int Selecionada);
void (*OpcoesDeCadaLocal[MAXDESTINOS])(int Selecionada) = {
     OpcoesCasa,
     OpcoesDungeon,
     OpcoesPraca,
     OpcoesTaberna,
};
