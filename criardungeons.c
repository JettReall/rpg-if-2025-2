#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "inimigos.h"
#include "varglobal.h"
#include "criardungeons.h"

void CriarDungeon(MODELO_SALA_DUNGEON mapa[LINHAS][COLUNAS], int dificuldade, int tipodungeon){
    int arr_dificuldade[DIFICULDADES];
    srand(time(NULL));
    SelecionaInimigosDungeon(tipodungeon);
    CriaSalaBoss();
    DificuldadeDungeon(arr_dificuldade, dificuldade);

     int InimigoEscolhido = 0, ChanceDeSpawn = 0, SlotInimigo = 0;
     int DifEscolhida = 0;
     int inimigos_max = dificuldade * tipodungeon * modificador;
     int X_Valido[TOTAL_SALAS] = {NULO};
     int Y_Valido[TOTAL_SALAS] = {NULO};
     int SalasValidas = 0;
     int X_Atual= 0, Y_Atual = 0;
    
    for (int x = 0; x < LINHAS; x++) {
            for (int y = 0; y < COLUNAS; y++) {
                if (mapa[x][y].Tipo_Especial == NADA && mapa[x][y].Lugar_Valido == VALIDO) {
                    X_Valido[SalasValidas] = x;
                    Y_Valido[SalasValidas] = y;
                    SalasValidas++;
                }
            }
    }

    while (inimigos_max > 0)  {
           for (int i = 0; i < SalasValidas; i++) {
                X_Atual = X_Valido[i];
                Y_Atual = Y_Valido[i];
                ChanceDeSpawn = (rand() % 100) + 1;
                if (ChanceDeSpawn <= CHANCE_SPAWN) {
                    DifEscolhida = rand() % CHANCE_TOTAL_SPAWN;
                    InimigoEscolhido = PoeInimigoPorDificuldade(DifEscolhida,arr_dificuldade);
                    if (InimigoEscolhido == MOB_NULO) {
                        continue;
                    } else {
                        mapa[X_Atual][Y_Atual].inimigos[SlotInimigo] = inimigo[InimigoEscolhido];
                        inimigos_max--;
                    }
                }
           } 
           SlotInimigo++;
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
    
    switch (dificuldade) {
    case FACIL:
        arr_dificuldade[FACIL-1] = 6;
        arr_dificuldade[MEDIO-1] = 3;
        arr_dificuldade[DIFICIL-1] = 1;
        break;
    case MEDIO:
        arr_dificuldade[FACIL-1] = 4;
        arr_dificuldade[MEDIO-1] = 6;
        arr_dificuldade[DIFICIL-1] = 3;
        break;
    case DIFICIL:
        arr_dificuldade[FACIL-1] = 2;
        arr_dificuldade[MEDIO-1] = 8;
        arr_dificuldade[DIFICIL-1] = 6;
        break;
    default:
        printf("Erro na dificuldade.");
        break;
    }
}

int PoeInimigoPorDificuldade(int Dif,int arr[]) {
    int Facil =arr[FACIL];
    int Medio = arr[MEDIO];
    int Dificil = arr[DIFICIL];

    Medio += Facil;
    Dificil += Medio;

    if (Dif <= Facil) {
        return FACIL;
    } else if (Dif <= Medio) {
        return MEDIO;
    } else if (Dif <= Dificil) {
        return DIFICIL;
    } 
    return MOB_NULO;
}