#include "explorardungeon.h"
#define MAXOPCOES_MAIOR 3
#define MAXDESTINOS 4
#define CONEXAO_NULA -1
enum OpcoesCidade{
     SAIR_LOCAL = 1,
     SALVAR = 2, ENTRAR_DUNGEON = 2, CONVERSAR =2,
     MEXER_BARALHO = 3, LOJISTA = 3,
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

enum Conexoes {
     CASA_CNX = 2,
     DUNGEON_CNX = 1,
     PRACA_CNX = 3,
     TABERNA_CNX = 2,
     CONECTADO = 1,
     N_CONECTADO = 0,
};



typedef struct {
     int ID;
     char Nome[30];
     char DescricaoLocal[MAX_TAM_DESCRICAO];
     char Opcoes[MAXOPCOES_MAIOR][30];
}LOCAL_DATA;

typedef struct local{
     LOCAL_DATA DadosLocal;
     int ConexaoID[MAXDESTINOS-1]; //Ele não pode apontar para si
     NPC *Figurante;
} LOCAL;

NPC NPC_Vazio = {"\0",{ITEM_VAZIO}};

LOCAL Locais[MAXDESTINOS] = {
     {
          CASA,
          "Casa do jogador","Uma clássica e genérica casa medieval de inicio de RPG... nada de muito novo",
          {"Sair para a cidade","Salvar","Mudar baralho"},
          {CONEXAO_NULA,CONEXAO_NULA,CONEXAO_NULA},
          NULL
     },
     {
          DUNGEON,
          "Caminho longo","Um caminho longo que sai da estrada com uma encruzilhada a frente, para cada caminho há uma placa apontando um templo.",
          {"Voltar para a cidade","Entrar em uma dungeon","\0"},
          {CONEXAO_NULA,CONEXAO_NULA,CONEXAO_NULA},
          NULL
     },
     {
          PRACA,
          "Praça","Uma praça genérica de cidade medieval, não há muita gente aqui",
          {"\0"},
          {CONEXAO_NULA,CONEXAO_NULA,CONEXAO_NULA},
          NULL
     },
     {
          TABERNA,
          "Taberna Basilisco","A taberna mais genérica que o estagiário pôde pensar... pelo menos foi bem feita, tem o bartenter, gente no palco, e muitos bêbados... e um encapuzado esquisito na bancada",
          {"Voltar à praça","Conversar com o encapuzado","Falar com o Lojista"},
          {CONEXAO_NULA,CONEXAO_NULA,CONEXAO_NULA},
          NULL
     },
};


LOCAL *LocalAtual = NULL;

const int OpcoesQtd[MAXDESTINOS] = {CASA_OPT,DUNGEON_OPT,PRACA_OPT,TABERNA_OPT};
int Loop = 1;


int OpcoesLocal(int Local);
void InicializarCidade();
void TrocarDeLugar(int ID_Atual);

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
