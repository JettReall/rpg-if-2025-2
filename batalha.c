#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "batalha.h"

int main() {
     srand(time(NULL));
     PreencherBaralho(DeckDoPlayer);
     for (int i = 0; i < MAX_TAM_DECK_PLAYER;i++) {
          printf(" %d de %s\n Naipe: %c, Tipo: %d ID: %d\n---\n",
               DeckDoPlayer[i].Valor, DeckDoPlayer[i].NaipePorExtenso,
               DeckDoPlayer[i].Naipe, DeckDoPlayer[i].Tipo, DeckDoPlayer[i].ID);
     }


     return 0;
}

void PreencherBaralho(CARTA *Deck) { //Deck é um ponteiro pra receber qualquer baralho, daí eu só projetei para receber o do player
     int Contador = 0;
     char Naipes[3][8] = {"Espadas","Magia","Cura"};

          for (int val = 0; val < 3; val++) { //Esse primeiro for é pra preencher os tipos
               Contador = 0;
               for (int i = 0; i<MAX_TAM_DECK_PLAYER / 3 ;i++) { //Esse segundo é pra colocar os valores
                    Contador++;
                    Deck->Valor = Contador;
                    Deck->Tipo = val;
                    Deck->Naipe = Naipes[val][0];
                    strcpy(Deck->NaipePorExtenso,Naipes[val]);
                    Deck->ID = (val*10)+Contador;
                    Deck++;
               }
     }
     
}


