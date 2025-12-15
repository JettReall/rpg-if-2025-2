#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <time.h>

/*eh importante lembrar de criar um ponteiro (NO_BARALHO *x=NULL)que será o nome da head e toda vez q for necessario a primeira carta do baralho
este ponteiro para a head*/
void AdicionaCarta(CARTA n,NO_BARALHO **head);
void RetiraCarta(int carta,NO_BARALHO **head,int *qtd);
CARTA *listtoarray(NO_BARALHO *baralho, int *qtd);
void Embaralhar(NO_BARALHO **baralho);
void CriaBaralho(CARTA *array,NO_BARALHO **baralho,int qtdtotal,int *qtdatual);
void PrintBaralho(NO_BARALHO *b);
CARTA PuxarCarta(NO_BARALHO **baralho,int *qtd);
void RecarregaBaralho(NO_BARALHO **baralho,CARTA *array,int *qtdatual,int qtdtotal);