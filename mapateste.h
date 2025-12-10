#ifndef MAPATESTE_H
#define MAPATESTE_H
#include "structs.h"
#include <stdlib.h>

void criar_mapa_vento();
void criar_mapa_bosque();
void criar_mapa_agua();
int Escolhemapa();
int Escolhedificuldade();
extern MODELO_SALA_DUNGEON mapa[6][6];
#endif