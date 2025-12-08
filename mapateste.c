#include "structs.h"
#include <stdio.h>
MODELO_SALA_DUNGEON mapa[6][6] = {0};
void criar_mapa_vento()
{
    mapa[0][2].Lugar_Valido = VALIDO; mapa[0][3].Lugar_Valido = VALIDO; mapa[0][4].Lugar_Valido = VALIDO;

    mapa[1][0].Lugar_Valido = VALIDO; mapa[1][2].Lugar_Valido = VALIDO; mapa[1][4].Lugar_Valido = VALIDO; mapa[1][5].Lugar_Valido = VALIDO;
    mapa[1][0].Tipo_Especial = ALAVANCA; mapa[1][5].Tipo_Especial = SALA_BOSS;

    mapa[2][0].Lugar_Valido = VALIDO; mapa[2][1].Lugar_Valido = VALIDO; mapa[2][2].Lugar_Valido = VALIDO; mapa[2][3].Lugar_Valido = VALIDO;
    mapa[2][4].Lugar_Valido = VALIDO;
    mapa[2][4].Tipo_Especial = ALAVANCA;

    mapa[3][0].Lugar_Valido = VALIDO; mapa[3][1].Lugar_Valido = VALIDO; mapa[3][2].Lugar_Valido = VALIDO; mapa[3][4].Lugar_Valido = VALIDO;
    mapa[3][4].Tipo_Especial = ALAVANCA;

    mapa[4][1].Lugar_Valido = VALIDO; mapa[4][2].Lugar_Valido = VALIDO; mapa[4][3].Lugar_Valido = VALIDO; mapa[4][4].Lugar_Valido = VALIDO;
    mapa[4][5].Lugar_Valido = VALIDO;
    mapa[4][1].Tipo_Especial = BAU;
   
    mapa[5][1].Lugar_Valido = VALIDO; mapa[5][2].Lugar_Valido = VALIDO; mapa[5][5].Lugar_Valido = VALIDO;
}
void criar_mapa_agua()
{
    mapa[0][2].Lugar_Valido = VALIDO; mapa[0][3].Lugar_Valido = VALIDO; mapa[0][4].Lugar_Valido = VALIDO; mapa[0][5].Lugar_Valido = VALIDO;
    mapa[0][2].Tipo_Especial = ALAVANCA; mapa[0][5].Tipo_Especial = SALA_BOSS;

    mapa[1][0].Lugar_Valido = VALIDO; mapa[1][1].Lugar_Valido = VALIDO; mapa[1][2].Lugar_Valido = VALIDO; mapa[1][3].Lugar_Valido = VALIDO;
    mapa[1][0].Tipo_Especial = BAU;

    mapa[2][1].Lugar_Valido = VALIDO; mapa[2][3].Lugar_Valido = VALIDO; mapa[2][4].Lugar_Valido = VALIDO; mapa[2][5].Lugar_Valido = VALIDO;
    mapa[2][2].Tipo_Especial = ALAVANCA;

    mapa[3][0].Lugar_Valido = VALIDO; mapa[3][1].Lugar_Valido = VALIDO; mapa[3][2].Lugar_Valido = VALIDO; mapa[3][4].Lugar_Valido = VALIDO;
    mapa[3][5].Lugar_Valido = VALIDO;

    mapa[4][0].Lugar_Valido = VALIDO; mapa[4][2].Lugar_Valido = VALIDO; mapa[4][4].Lugar_Valido = VALIDO;
   
    mapa[5][0].Lugar_Valido = VALIDO; mapa[5][1].Lugar_Valido = VALIDO; mapa[5][2].Lugar_Valido = VALIDO; mapa[5][3].Lugar_Valido = VALIDO;
    mapa[5][4].Lugar_Valido = VALIDO; mapa[5][5].Lugar_Valido = VALIDO;
    mapa[5][5].Tipo_Especial = ALAVANCA;
}
void criar_mapa_bosque()
{
    mapa[0][1].Lugar_Valido = VALIDO; mapa[0][3].Lugar_Valido = VALIDO; mapa[0][4].Lugar_Valido = VALIDO; mapa[0][5].Lugar_Valido = VALIDO;
    mapa[0][1].Tipo_Especial = BAU;

    mapa[1][0].Lugar_Valido = VALIDO; mapa[1][1].Lugar_Valido = VALIDO; mapa[1][2].Lugar_Valido = VALIDO; mapa[1][3].Lugar_Valido = VALIDO;
    mapa[1][5].Lugar_Valido = VALIDO; 
    mapa[1][5].Tipo_Especial = SALA_BOSS;

    mapa[2][0].Lugar_Valido = VALIDO; mapa[2][2].Lugar_Valido = VALIDO; mapa[2][3].Lugar_Valido = VALIDO;
    mapa[2][2].Tipo_Especial = ALAVANCA;

    mapa[3][0].Lugar_Valido = VALIDO; mapa[3][1].Lugar_Valido = VALIDO; mapa[3][2].Lugar_Valido = VALIDO;mapa[3][3].Lugar_Valido = VALIDO;
    mapa[3][4].Lugar_Valido = VALIDO; mapa[3][5].Lugar_Valido = VALIDO;
    mapa[3][5].Tipo_Especial = ALAVANCA;

    mapa[4][0].Lugar_Valido = VALIDO; mapa[4][1].Lugar_Valido = VALIDO; mapa[4][4].Lugar_Valido = VALIDO; mapa[4][5].Lugar_Valido = VALIDO;
   
    mapa[5][1].Lugar_Valido = VALIDO; mapa[5][2].Lugar_Valido = VALIDO; mapa[5][4].Lugar_Valido = VALIDO;
    mapa[5][3].Tipo_Especial = ALAVANCA; mapa[5][4].Tipo_Especial = BAU;
}
int Escolhemapa()
{
    int x = 0;
    printf("Que mapa voce deseja gerar? \n (1) Vento \t (2) Bosque \t (3) Agua \t (4) Fogo \n");
    scanf("%d", &x);
    switch (x)
    {
    case VENTO:
        criar_mapa_vento();
        return VENTO;
    case BOSQUE:
        criar_mapa_bosque();
        return BOSQUE;
    case AGUA:
        criar_mapa_agua();
        return AGUA;
    default:
        printf("Mapa ainda não feito.");
        return -1;
    }
}
int Escolhedificuldade()
{
    int x = 0;
    printf("\n Qual a dificuldade do jogo? \n (1) Facil \t (2) Medio \t (3) Dificil \n");
    scanf("%d", &x);
    if (x >= FACIL && x <= DIFICIL) return x;
    else
    {
        printf("Dificuldade invalida.");
        return -1;
    }
}