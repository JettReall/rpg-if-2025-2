#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "inimigos.h"
#include "varglobal.h"
#include "criardungeons.h"

void CriarDungeon(MODELO_SALA_DUNGEON mapa[6][6], int dificuldade, int tipodungeon){
    static int  arr_dificuldade[max_array_inimigo] = {0};
    srand(time(NULL));
    SelecionaInimigosDungeon(tipodungeon);
    CriaSalaBoss();
    DificuldadeDungeon(arr_dificuldade, dificuldade);

    int inimigos_max = 0, x = 0, y = 0, z = 0, temp = 0;
    while (inimigos_max < dificuldade * tipodungeon * modificador)  {
        if (temp < max_inimigo_sala) {

            if (mapa[x][y].Tipo_Especial == NADA && mapa[x][y].Lugar_Valido == VALIDO) {

                z = rand() % max_array_inimigo;
                if (arr_dificuldade[z] == BOSS) {
                    mapa[x][y].inimigos[temp] = Inimigo_Nulo;
                    temp++; 
                    continue;
                }
                mapa[x][y].inimigos[temp] = inimigo[arr_dificuldade[z]];
                inimigos_max += arr_dificuldade[z];
                temp++;

            } else temp = max_inimigo_sala;

        } else temp = 0, y++;
        if (y == 6) x++, y = 0;
        if (x == 6) break;
    }

}

void SelecionaInimigosDungeon(int tipodungeon) {
    INIMIGOS *InimigoPtr = NULL;
    switch(tipodungeon) {
        case VENTO:
            InimigoPtr = &CatalogoVento[0];
            break;
        case BOSQUE:
            //InimigoPtr = &CatalogoBosque[0];
            break;
        case AGUA:
            //InimigoPtr = &CatalogoAgua[0];
            break;
        case FOGO:
            //InimigoPtr = &CatalogoFogo[0];
            break;
        default:
            printf("Erro ao criar inimigos da dungeon.");
            break;
    }

    for (int i = 0; i < max_inimigo_Dungeon; i++) {
        inimigo[i] = *InimigoPtr;
        InimigoPtr++;
    }

}

void CriaSalaBoss() {
   SalaBoss->inimigos[0] = inimigo[BOSS];
}

void DificuldadeDungeon(int arr_dificuldade[], int dificuldade) {  
    int ApareceFacil = 0, ApareceMedio = 0, ApareceDificil = 0;
    switch (dificuldade) {
    case FACIL:
        ApareceFacil = 6; ApareceMedio = 3; ApareceDificil = 1;
        break;
    case MEDIO:
        ApareceFacil = 4; ApareceMedio = 6; ApareceDificil = 3;
        break;
    case DIFICIL:
        ApareceFacil = 2; ApareceMedio = 8; ApareceDificil = 6;
        break;
    default:
        printf("Erro na dificuldade.");
        break;
    }
    PreencheArray(arr_dificuldade, ApareceFacil, ApareceMedio, ApareceDificil);
}

void PreencheArray(int arr[], int Numero_Ini_F, int Numero_Ini_M, int Numero_Ini_D)
{
    int temp = 0;
    for (int i = 0; i < Numero_Ini_F ; i++) {
        arr[temp] = FACIL;
        temp++;
    }

    for (int i = 0; i < Numero_Ini_M ; i++) {
        arr[temp] = MEDIO;
        temp++;
    }

    for (int i = 0; i < Numero_Ini_D ; i++) {
        arr[temp] = DIFICIL;
        temp++;
    }
}