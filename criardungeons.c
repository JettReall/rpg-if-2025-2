#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "inimigos.h"
#include "varglobal.h"

void criardugeon(MODELO_SALA_DUNGEON mapa[6][6], int dificuldade, int tipodungeon){
    srand(time(NULL));
    selecionadungeon(tipodungeon);
    int inimigos_max = 0, x = 0, y = 0, z = 0, temp = 0;
    tipodungeon *= dificuldade;
    while (inimigos_max < dificuldade * tipodungeon)
    {
        if (temp < max_inimigo_sala)
        {
            if (mapa[x][y].Especiais == 0 && mapa[x][y].Lugar_Valido == 1)
            {
            z = 1 + rand() % max_inimigo_Dungeon + (dificuldade_max - dificuldade);
            if (z > max_inimigo_Dungeon) {temp ++; continue;}
            mapa[x][y].inimigos[temp] = inimigo[z];
            inimigos_max += inimigo[z].Dificuldade;
            temp++;
            }
            else temp = max_inimigo_sala;
        }
        else temp = 0, y++;
        if (y == 6) x++, y = 0;
        if (x == 6) break;
    }
}
void selecionadungeon(int tipodungeon)
{
    switch(tipodungeon)
    {
        case 0:
        criar_ini_vento();
        break;
        case 1:
        criar_ini_bosque();
        break;
        case 2:
        criar_ini_agua();
        break;
        case 3:
        criar_ini_fogo();
        break;
        default:
        printf("Erro ao criar inimigos da dungeon.");
        break;
    }
}