#if !defined(CRIARDUNGEONS_H)
#define CRIARDUNGEONS_H

#include <stdio.h>
#include "structs.h"
#define CHANCE_SPAWN 70
#define CHANCE_MULTIPLA_SPAWN 70

enum Escolhido {
     N_ESCOLHIDO = 0,
     ESCOLHIDO = 1,
};

void CriarDungeon(MODELO_SALA_DUNGEON mapa[LINHAS][COLUNAS], int dificuldade, int tipodungeon);
void SelecionaInimigosDungeon(int tipodungeon);
void CriaSalaBoss();
void DificuldadeDungeon(int arr_dificuldade[], int dificuldade);
int PoeInimigoPorDificuldade(int Dif,int arr[]);
extern MODELO_SALA_DUNGEON *SalaBoss;


#endif // CRIARDUNGEONS_H