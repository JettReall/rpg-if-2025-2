#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "inimigos.h"
#include "varglobal.h"
#include "criardungeons.h"
#include "mapaini.h"

void CriarDungeon(MODELO_SALA_DUNGEON mapa[6][6], int dificuldade, int tipodungeon){
    static int  arr_dificuldade[max_array_inimigo] = {0};
    srand(time(NULL));
    SelecionaDungeon(tipodungeon);
    CriaSalaBoss(mapa);
    DificuldadeDungeon(arr_dificuldade, dificuldade);
    int inimigos_max = 0, x = 0, y = 0, z = 0, temp = 0;
    while (inimigos_max < dificuldade * tipodungeon * modificador) 
    {
        if (temp < max_inimigo_sala)
        {
            if (mapa[x][y].Tipo_Especial == NADA && mapa[x][y].Lugar_Valido == VALIDO)
            {
            z = rand() % max_array_inimigo;
            if (arr_dificuldade[z] == BOSS) 
            {
                mapa[x][y].inimigos[temp] = Inimigo_Nulo[0];
                temp ++; 
                continue;
            }
            mapa[x][y].inimigos[temp] = inimigo[arr_dificuldade[z]];
            inimigos_max += arr_dificuldade[z];
            temp++;
            }
            else temp = max_inimigo_sala;
        }
        else temp = 0, y++;
        if (y == 6) x++, y = 0;
        if (x == 6) break;
    }
}
void SelecionaDungeon(int tipodungeon)
{
    criar_ini_nulo();
    switch(tipodungeon)
    {
        case VENTO:
            criar_ini_vento();
            break;
        case BOSQUE:
            criar_ini_bosque();
            break;
        case AGUA:
            criar_ini_agua();
            break;
        case FOGO:
            criar_ini_fogo();
            break;
        default:
            printf("Erro ao criar inimigos da dungeon.");
            break;
    }
}
void CriaSalaBoss(MODELO_SALA_DUNGEON mapa[6][6])
{
    for (int x = 0; x < 6; x++)
    {
            for (int y = 0; y < 6; y++)
        {
            if (mapa[x][y].Tipo_Especial == SALA_BOSS)
            {
                mapa[x][y].inimigos[0] = inimigo[BOSS];
            }
        }
    }
}
void DificuldadeDungeon(int arr_dificuldade[], int dificuldade)
{
    
    int ApareceFacil = 0, ApareceMedio = 0, ApareceDificil = 0;
    switch (dificuldade)
    {
    case FACIL:
        ApareceFacil = 6, ApareceMedio = 3, ApareceDificil = 1;
        break;
    case MEDIO:
        ApareceFacil = 4, ApareceMedio = 6, ApareceDificil = 3;
        break;
    case DIFICIL:
        ApareceFacil = 2, ApareceMedio = 8, ApareceDificil = 6;
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
    for (int i = 0; i < Numero_Ini_F ; i++)
    {
        arr[temp] = FACIL;
        temp++;
    }
    for (int i = 0; i < Numero_Ini_M ; i++)
    {
        arr[temp] = MEDIO;
        temp++;
    }
    for (int i = 0; i < Numero_Ini_D ; i++)
    {
        arr[temp] = DIFICIL;
        temp++;
    }
}