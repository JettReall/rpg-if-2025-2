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

typedef struct personagem personagem;

typedef struct {
    char nome[50];
    char descricao[200];
    int stat[7]; //status
    int custo; //dinheiro
}item;

typedef struct{
    char nome[50];
    char descricao[200];
    int tipo,valor;
}carta;

typedef struct {  //efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
    char nome[50];
    int tipo,valor,stat,contador;
}efeito;

typedef struct{ //baralho eh uma lista encadeada
    carta c;    //carta eh um struct carta
    nobaralho *prox;
}nobaralho;

typedef struct {
    char nome[50];//nome
    int stat[7];//stats max
    int hpatual,xp;//hp atual e xp atual
    nobaralho *baralho; //baralho lista encadeada
    carta cartas[200]; //todes as cartas do baralho total
    item equipados[2]; //equipados:: quantidade ainda a decidir
    item inventario[6];//itens guardados quantidade ainda a decidir
    int coordenada[2];//coordenada no mapa da dungeon
    int savepoint; //numero do ultimo checkpoint
    efeito efeitos[10];//efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
}personagem;

typedef struct{
    char nome[50];
    item inventario[20];
}npc;

typedef struct{
    char nome[50];
    int acessos[10];//possibilidades de caminhos q o player pode ir
    personagem inimigos[4];//inimigos presentes no quarto
}localDungeon;