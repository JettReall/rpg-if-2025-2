typedef struct {
    char nome[50];
    int hpatual,hpmax,deffis,defmag,speed,atqfis,atqmag; //status
    int custo;
    int habilidade(personagem player);
}item;

typedef struct{
    char nome[50];
   int tipo,valor;
   int contador;
}buff;

typedef struct {
    char nome[50];
    int hpatual,hpmax,deffis,defmag,speed,atqfis,atqmag,nivel,xp; //status
    baralhobaralho;
    item equipamentos[2]; //equipados
    iteminventario[6];
    int coordenada[2];
    int savepoint; //numero do ultimo checkpoint
    buff buffs[10];
}personagem;

typedef struct{
    char nome[50];
    item inventario[20];
}npc;

typedef struct{
    char nome[50];
    int tipo,valor;
}carta;

typedef struct{
    char nome[50];
    int acessos[10];
    int tipo;
    npc npcs[10];
    personagem inimigos[10];
}local;