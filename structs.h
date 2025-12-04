//enuns:
typedef enum {
    HPMAX,
    DEFFIS,
    DEFMAG,
    SPEED,
    ATQFIS,
    ATQMAG,
    NIVEL
}Stats;


typedef enum{
    ATAQUEFIS,
    ATAQUEMAG,
    CURA,
}Tipo;


typedef enum {
    DANO,
    STATMOD
}Efeito_Tipos;

typedef enum {
    TEMPLO_BOSQUE,
    TEMPLO_VENTO,
    TEMPLO_AGUA,
    TEMPLO_FOGO,
    TEMPLO_FINAL
}Dungeons;


//-------------------------------------------------------------------------------------------------------------------
//structs:

typedef struct {
    char Nome[50];
    char Descricao[200];
    int Stat[7]; //status
    int Custo; //dinheiro
}ITEM;

typedef struct{
    char Nome[50];
    char Descricao[200];
    int Tipo,Valor;
}CARTA;

typedef struct {  //efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
    char Nome[50];
    int Tipo,Valor,Stat,Contador;
}EFEITO;

typedef struct NO_BARALHO{ //baralho eh uma lista encadeada
    CARTA Carta;    //carta eh um struct carta
    struct NO_BARALHO *PtrProx;
}NO_BARALHO;

typedef struct{
    int UltimoSavepoint;
    CARTA Cartas[100];
    int Dificuldade;
    int Dinheiro;
}SAVE_DADOS;

typedef struct {
    char Nome[50];//nome
    int Stat[7];//stats max
    int HpAtual,Xp;//hp atual e xp atual
    NO_BARALHO *Baralho; //baralho lista encadeada
    ITEM Equipados[2]; //equipados:: quantidade ainda a decidir
    ITEM Inventario[6];//itens guardados quantidade ainda a decidir
    EFEITO Efeitos[10];//efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
}PERSONAGEM;

typedef struct{
    char Nome[50];
    ITEM Inventario[20];
}NPC;

typedef struct{
    char Nome[50];
    int MapaDun[2][6][6];
    int Dificuldade_Base; //Cada dungeon vai ter um, que vai aumentar e isso é util pra setar a quantia de inimigos e na hora de escolher a dificuldade no começo do jogo.
    int Max_Inimigos;//inimigos presentes no quarto
}MODELO_SALA_DUNGEON;

typedef struct{
    char Nome[50];//nome
    int Stat[7];//stats max
    int HpAtual,Xp;//hp atual e xp atual
    ITEM Equipados[2]; //equipados:: quantidade ainda a decidir
    EFEITO Efeitos[10];//efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
    int Dungeon[5];//De qual dungeon ele faz parte. 0 = bosque, 1 = vento, 2 = água, 3 = fogo, 4 = Boss final.
    int Dificuldade[4];// 1 = facil, 2 = medio, 3 = dificil, 4 = boss.
}INIMIGOS;