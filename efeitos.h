#include <stdio.h>

enum efeitotipos{
    dano=1,
    statmod
};

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
    int tipo,valor,stat,contador;
}efeito;

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

void aplicaEfeito(efeito efeito,personagem *personagem){
    int i=0;
    while(personagem->efeitos[i] > 0)i++;
    personagem->efeitos[i]=efeito;
    if(efeito.tipo==statmod){
        personagem->stat[efeito.tipo]+=efeito.valor;
    }
} 

void causaEfeito(personagem *player){
    for(int i=0;i<10;i++){
            if(player->efeitos[i].contador>0){
                switch(player->efeitos[i].tipo){
                    case dano:
                        player->hpatual-=player->efeitos[i].valor;
                        printf("%s %s %d de vida devido ao efeito de %s\n",player->nome,
                        player->efeitos[i].valor>0? "perdeu":"ganhou", player->efeitos[i].valor, player->efeitos[i].nome);
                        break;
                    case statmod:
                        if(player->efeitos[i].contador==0){
                            player->stat[player->efeitos[i].stat]+=player->efeitos[i].valor;
                            printf("%s perdeu o efeito de %s\n",player->nome, player->efeitos[i].nome);
                        }
                        break;
                }
                player->efeitos[i].contador--;
            }
        }
}


void funcefeito(personagem *player,personagem *inimigo[],int qtdinimigos){
    causaEfeito(player);
    for(int i=0;i<qtdinimigos;i++){
        causaEfeito(inimigo[i]);
    }
}