#include "structs.h"
#include "classes.h"
#include <stdio.h>
#include "varglobal.h"
#include "cartas.h"
#include "xp.h"
#include <time.h>
#include <stdlib.h>

int Entregar_XP(INIMIGOS Derrotados[]) {
    int XPTOTAL = 0;
        for (int i = 0; i < max_inimigo_sala; i++) {
            if (Derrotados[i].Xp != 0) {
                XPTOTAL += Derrotados[i].Xp;
            }
        }
    printf("Você ganhou %d de Exp.\n",XPTOTAL);
    return XPTOTAL;
   
}

void Upar_Nivel(PERSONAGEM *Player) {
    srand(time(NULL));
    int array_niveis[4] = {Nivel_1, Nivel_2, Nivel_3, Nivel_4};
    int NivelAtual = Player->Stat[NIVEL];
    
    if (NivelAtual < 4)
    {   
        if (Player->Xp >= array_niveis[NivelAtual]) {
            Player->Xp -= array_niveis[NivelAtual];
            Player->Stat[NIVEL]++;
            printf("Você subiu de Nível! Você agora está no Nível %d\n",Player->Stat[NIVEL]);
            int z = rand() % 3;
            //AdicionaCarta(CatalogoCartas[Player[0].Classe][z], &meuBaralho, &totalCartas);
            AumentaStatus(Player);
            printf("Stats aumentados\n");
        } else {
            printf("Consiga mais XP para upar de nível\n");
        }
    }
}

void AumentaStatus(PERSONAGEM *Player)
{
    for (int i = 0; i < MAX_STATS - 1; i++)
    {
        Player->Stat[i] += 5;
    }
    Player->Stat[HPMAX] += 15;
    Player->HpAtual = Player->Stat[HPMAX];
    printf("Status aumentados\n");
}