#include "structs.h"
#define MAX_TAM_DECK_PLAYER 30
#define MAX_CARTAS_EM_MAO 5

CARTA DeckDoPlayer[MAX_TAM_DECK_PLAYER];
CARTA *CartaPtr = NULL;
CARTA MaoDoPlayer[MAX_CARTAS_EM_MAO];


void PreencherBaralho(CARTA *Deck);
void PreencherMao(CARTA *Mao, CARTA *Deck);






//funcaos de efeitos overtime
void aplicaEfeito(efeito efeito,personagem *personagem);
void causaEfeito(personagem *player);
void funcaoefeito(personagem *player,personagem *inimigo[],int qtdinimigos);
//funcaos de efeitos overtime






//funcoes de calculo de dano
int comboflat(carta carta[3]);
float comboporcento(carta carta[3]);
int decidetipo(carta carta[3]);
void causardano(int danofis,int danomag,int cura,personagem *atacante,personagem *defensor);
void dano(carta carta[3],personagem *atacante,personagem *defensor);
//funcoes de calculo de dano
