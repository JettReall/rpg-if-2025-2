typedef struct {
    char nome[50];
    char descricao[200];
    int hpatual,hpmax,deffis,defmag,speed,atqfis,atqmag; //status
    int custo;
    int habilidade(personagem player);
}item;

typedef struct{
    char nome[50];
    char descricao[200];
    int tipo,valor;
}carta;

typedef struct{
    char nome[50];
    int tipo,valor;
    int contador;
}efeito;

typedef struct{
    carta c;
    nobaralho *prox;
}nobaralho;

enum Stats{
    hpmax,
    deffis,
    defmag,
    speed,
    atqfis,
    atqmag,
    nivel
};

typedef struct {
    char nome[50];
    int stat[7];
    int hpatual,xp;
    nobaralho *baralho;
    item equipamentos[2]; //equipados
    item inventario[6];
    int coordenada[2];
    int savepoint; //numero do ultimo checkpoint
    efeito efeitos[10];
}personagem;

typedef struct{
    char nome[50];
    item inventario[20];
}npc;

typedef struct{
    char nome[50];
    int acessos[10];
    personagem inimigos[10];
}localDungeon;