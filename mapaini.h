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
int Escolhemapa(x)
{
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
        printf("Mapa ainda nao feito.");
        return -1;
    }
}