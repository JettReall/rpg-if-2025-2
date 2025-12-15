#include "structs.h"
#include "classes.h"
#include <stdio.h>
#include "varglobal.h"
#include "cartas.h"
#include "xp.h"
#include <time.h>
#include <stdlib.h>

void Entregar_XP(MODELO_SALA_DUNGEON mapa[6][6], int X, int Y)
{
    //deve ser rodado depois do combate estar finalizado
    if (Player[0].HpAtual > 0)
    {
        for (int temp = 0; temp < max_inimigo_sala; temp++)
        {
            Player[0].Xp += mapa[X][Y].inimigos[temp].Xp;
        }
    }
}

void Upar_Nivel()
{
    srand(time(NULL));
    int array_niveis[] = {Nivel_1, Nivel_2, Nivel_3, Nivel_4};
    if (Player[0].Stat[NIVEL] < 4)
    {
        if (Player[0].Xp >= array_niveis[Player[0].Stat[NIVEL]])
        {
            Player[0].Xp -= array_niveis[Player[0].Stat[NIVEL]];
            Player[0].Stat[NIVEL]++;
            int z = rand() % 3;
            AdicionaCarta(CatalogoCartas[Player[0].Classe][z], &meuBaralho, &totalCartas);
            AumentaStatus();
        }
    }
}

void AumentaStatus()
{
    for (int i = 0; i < MAX_STATUS - 1; i++)
    {
        Player[0].Stat[i] += 5;
    }
    Player[0].Stat[HPMAX] += 15;
    Player[0].HpAtual = Player[0].Stat[HPMAX];
}