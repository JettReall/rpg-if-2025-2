//enuns:
enum Stats{
    HPMAX,
    DEFFIS,
    DEFMAG,
    SPEED,
    ATQFIS,
    ATQMAG,
    NIVEL
};


typedef enum{
    ATAQUEFIS,
    ATAQUEMAG,
    CURA,
}Tipo;


enum efeitotipos{
    DANO,
    STATMOD
};



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

typedef struct{ //baralho eh uma lista encadeada
    CARTA IntelCarta;    //carta eh um struct carta
    NO_BARALHO *PtrProx;
}NO_BARALHO;

typedef struct{
    int UltimoSavepoint;
    CARTA Cartas[100];
    int Dificuldade;
    int Dinheiro;
}savedados;

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
    char nome[50];
    char *Acessos[4][20];//possibilidades de caminhos q o player pode ir
    PERSONAGEM inimigos[4];//inimigos presentes no quarto
}MODELO_SALA_DUNGEON;