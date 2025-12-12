#include <stdio.h>
#include "structs.h"
void CriarDungeon(MODELO_SALA_DUNGEON mapa[6][6], int dificuldade, int tipodungeon);
void SelecionaDungeon(int tipodungeon);
void CriaSalaBoss(MODELO_SALA_DUNGEON mapa[6][6]);
void DificuldadeDungeon(int arr_dificuldade[], int dificuldade);
void PreencheArray(int arr[], int Numero_Ini_F, int Numero_Ini_M, int Numero_Ini_D);