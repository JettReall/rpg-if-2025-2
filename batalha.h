#include "structs.h"
#define MAX_TAM_DECK_PLAYER 30
#define MAX_CARTAS_EM_MAO 5

CARTA DeckDoPlayer[MAX_TAM_DECK_PLAYER];
CARTA *CartaPtr = NULL;
CARTA MaoDoPlayer[MAX_CARTAS_EM_MAO];


//funcaos de efeitos overtime
void AplicaEfeito(EFEITO Efeito,PERSONAGEM *Personagem);
void CausaEfeito(PERSONAGEM *Player);
void FuncaoEfeito(PERSONAGEM *Player,PERSONAGEM *Inimigo[],int QtdInimigos);
//funcaos de efeitos overtime


//funcoes de calculo de dano
int ComboFlat(CARTA Carta[3]);
float ComboPorcento(CARTA Carta[3]);
int DecideTipo(CARTA Carta[3]);
void CausarDano(int DanoFis,int DanoMag,int Cura,PERSONAGEM *Atacante,PERSONAGEM *Defensor);
void Dano(CARTA Carta[3],PERSONAGEM *Atacante,PERSONAGEM *Defensor);
//funcoes de calculo de dano
