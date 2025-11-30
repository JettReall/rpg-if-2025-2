#include "structs.h"
#include <string.h>
personagem inimigo[22]= {0};

void criarinimigos()
{
    personagem inimigo[22]= {0};
    // INIMIGO 0
    strcpy(inimigo[0].nome, "Inimigo 1");
    inimigo[0].stat[HPMAX]  = 0; inimigo[0].stat[DEFFIS] = 0; inimigo[0].stat[DEFMAG] = 0;
    inimigo[0].stat[SPEED]  = 0; inimigo[0].stat[ATQFIS] = 0; inimigo[0].stat[ATQMAG] = 0;
    inimigo[0].stat[NIVEL]  = 0;
    inimigo[0].hpatual = 0; inimigo[0].xp = 0; inimigo[0].baralho = NULL;

    // INIMIGO 1
    strcpy(inimigo[1].nome, "Inimigo 2");
    inimigo[1].stat[HPMAX]  = 0; inimigo[1].stat[DEFFIS] = 0; inimigo[1].stat[DEFMAG] = 0;
    inimigo[1].stat[SPEED]  = 0; inimigo[1].stat[ATQFIS] = 0; inimigo[1].stat[ATQMAG] = 0;
    inimigo[1].stat[NIVEL]  = 0;
    inimigo[1].hpatual = 0; inimigo[1].xp = 0; inimigo[1].baralho = NULL;

    // INIMIGO 2
    strcpy(inimigo[2].nome, "Inimigo 3");
    inimigo[2].stat[HPMAX]  = 0; inimigo[2].stat[DEFFIS] = 0; inimigo[2].stat[DEFMAG] = 0;
    inimigo[2].stat[SPEED]  = 0; inimigo[2].stat[ATQFIS] = 0; inimigo[2].stat[ATQMAG] = 0;
    inimigo[2].stat[NIVEL]  = 0;
    inimigo[2].hpatual = 0; inimigo[2].xp = 0; inimigo[2].baralho = NULL;

    // INIMIGO 3
    strcpy(inimigo[3].nome, "Inimigo 4");
    inimigo[3].stat[HPMAX]  = 0; inimigo[3].stat[DEFFIS] = 0; inimigo[3].stat[DEFMAG] = 0;
    inimigo[3].stat[SPEED]  = 0; inimigo[3].stat[ATQFIS] = 0; inimigo[3].stat[ATQMAG] = 0;
    inimigo[3].stat[NIVEL]  = 0;
    inimigo[3].hpatual = 0; inimigo[3].xp = 0; inimigo[3].baralho = NULL;

    // INIMIGO 4
    strcpy(inimigo[4].nome, "Inimigo 5");
    inimigo[4].stat[HPMAX]  = 0; inimigo[4].stat[DEFFIS] = 0; inimigo[4].stat[DEFMAG] = 0;
    inimigo[4].stat[SPEED]  = 0; inimigo[4].stat[ATQFIS] = 0; inimigo[4].stat[ATQMAG] = 0;
    inimigo[4].stat[NIVEL]  = 0;
    inimigo[4].hpatual = 0; inimigo[4].xp = 0; inimigo[4].baralho = NULL;

    // INIMIGO 5
    strcpy(inimigo[5].nome, "Inimigo 6");
    inimigo[5].stat[HPMAX]  = 0; inimigo[5].stat[DEFFIS] = 0; inimigo[5].stat[DEFMAG] = 0;
    inimigo[5].stat[SPEED]  = 0; inimigo[5].stat[ATQFIS] = 0; inimigo[5].stat[ATQMAG] = 0;
    inimigo[5].stat[NIVEL]  = 0;
    inimigo[5].hpatual = 0; inimigo[5].xp = 0; inimigo[5].baralho = NULL;

    // INIMIGO 6
    strcpy(inimigo[6].nome, "Inimigo 7");
    inimigo[6].stat[HPMAX]  = 0; inimigo[6].stat[DEFFIS] = 0; inimigo[6].stat[DEFMAG] = 0;
    inimigo[6].stat[SPEED]  = 0; inimigo[6].stat[ATQFIS] = 0; inimigo[6].stat[ATQMAG] = 0;
    inimigo[6].stat[NIVEL]  = 0;
    inimigo[6].hpatual = 0; inimigo[6].xp = 0; inimigo[6].baralho = NULL;

    // INIMIGO 7
    strcpy(inimigo[7].nome, "Inimigo 8");
    inimigo[7].stat[HPMAX]  = 0; inimigo[7].stat[DEFFIS] = 0; inimigo[7].stat[DEFMAG] = 0;
    inimigo[7].stat[SPEED]  = 0; inimigo[7].stat[ATQFIS] = 0; inimigo[7].stat[ATQMAG] = 0;
    inimigo[7].stat[NIVEL]  = 0;
    inimigo[7].hpatual = 0; inimigo[7].xp = 0; inimigo[7].baralho = NULL;

    // INIMIGO 8
    strcpy(inimigo[8].nome, "Inimigo 9");
    inimigo[8].stat[HPMAX]  = 0; inimigo[8].stat[DEFFIS] = 0; inimigo[8].stat[DEFMAG] = 0;
    inimigo[8].stat[SPEED]  = 0; inimigo[8].stat[ATQFIS] = 0; inimigo[8].stat[ATQMAG] = 0;
    inimigo[8].stat[NIVEL]  = 0;
    inimigo[8].hpatual = 0; inimigo[8].xp = 0; inimigo[8].baralho = NULL;

    // INIMIGO 9
    strcpy(inimigo[9].nome, "Inimigo 10");
    inimigo[9].stat[HPMAX]  = 0; inimigo[9].stat[DEFFIS] = 0; inimigo[9].stat[DEFMAG] = 0;
    inimigo[9].stat[SPEED]  = 0; inimigo[9].stat[ATQFIS] = 0; inimigo[9].stat[ATQMAG] = 0;
    inimigo[9].stat[NIVEL]  = 0;
    inimigo[9].hpatual = 0; inimigo[9].xp = 0; inimigo[9].baralho = NULL;

    // INIMIGO 10
    strcpy(inimigo[10].nome, "Inimigo 11");
    inimigo[10].stat[HPMAX]  = 0; inimigo[10].stat[DEFFIS] = 0; inimigo[10].stat[DEFMAG] = 0;
    inimigo[10].stat[SPEED]  = 0; inimigo[10].stat[ATQFIS] = 0; inimigo[10].stat[ATQMAG] = 0;
    inimigo[10].stat[NIVEL]  = 0;
    inimigo[10].hpatual = 0; inimigo[10].xp = 0; inimigo[10].baralho = NULL;

    // INIMIGO 11
    strcpy(inimigo[11].nome, "Inimigo 12");
    inimigo[11].stat[HPMAX]  = 0; inimigo[11].stat[DEFFIS] = 0; inimigo[11].stat[DEFMAG] = 0;
    inimigo[11].stat[SPEED]  = 0; inimigo[11].stat[ATQFIS] = 0; inimigo[11].stat[ATQMAG] = 0;
    inimigo[11].stat[NIVEL]  = 0;
    inimigo[11].hpatual = 0; inimigo[11].xp = 0; inimigo[11].baralho = NULL;

    // INIMIGO 12
    strcpy(inimigo[12].nome, "Inimigo 13");
    inimigo[12].stat[HPMAX]  = 0; inimigo[12].stat[DEFFIS] = 0; inimigo[12].stat[DEFMAG] = 0;
    inimigo[12].stat[SPEED]  = 0; inimigo[12].stat[ATQFIS] = 0; inimigo[12].stat[ATQMAG] = 0;
    inimigo[12].stat[NIVEL]  = 0;
    inimigo[12].hpatual = 0; inimigo[12].xp = 0; inimigo[12].baralho = NULL;

    // INIMIGO 13
    strcpy(inimigo[13].nome, "Inimigo 14");
    inimigo[13].stat[HPMAX]  = 0; inimigo[13].stat[DEFFIS] = 0; inimigo[13].stat[DEFMAG] = 0;
    inimigo[13].stat[SPEED]  = 0; inimigo[13].stat[ATQFIS] = 0; inimigo[13].stat[ATQMAG] = 0;
    inimigo[13].stat[NIVEL]  = 0;
    inimigo[13].hpatual = 0; inimigo[13].xp = 0; inimigo[13].baralho = NULL;

    // INIMIGO 14
    strcpy(inimigo[14].nome, "Inimigo 15");
    inimigo[14].stat[HPMAX]  = 0; inimigo[14].stat[DEFFIS] = 0; inimigo[14].stat[DEFMAG] = 0;
    inimigo[14].stat[SPEED]  = 0; inimigo[14].stat[ATQFIS] = 0; inimigo[14].stat[ATQMAG] = 0;
    inimigo[14].stat[NIVEL]  = 0;
    inimigo[14].hpatual = 0; inimigo[14].xp = 0; inimigo[14].baralho = NULL;

    // INIMIGO 15
    strcpy(inimigo[15].nome, "Inimigo 16");
    inimigo[15].stat[HPMAX]  = 0; inimigo[15].stat[DEFFIS] = 0; inimigo[15].stat[DEFMAG] = 0;
    inimigo[15].stat[SPEED]  = 0; inimigo[15].stat[ATQFIS] = 0; inimigo[15].stat[ATQMAG] = 0;
    inimigo[15].stat[NIVEL]  = 0;
    inimigo[15].hpatual = 0; inimigo[15].xp = 0; inimigo[15].baralho = NULL;

    // INIMIGO 16
    strcpy(inimigo[16].nome, "Inimigo 17");
    inimigo[16].stat[HPMAX]  = 0; inimigo[16].stat[DEFFIS] = 0; inimigo[16].stat[DEFMAG] = 0;
    inimigo[16].stat[SPEED]  = 0; inimigo[16].stat[ATQFIS] = 0; inimigo[16].stat[ATQMAG] = 0;
    inimigo[16].stat[NIVEL]  = 0;
    inimigo[16].hpatual = 0; inimigo[16].xp = 0; inimigo[16].baralho = NULL;

    // INIMIGO 17
    strcpy(inimigo[17].nome, "Inimigo 18");
    inimigo[17].stat[HPMAX]  = 0; inimigo[17].stat[DEFFIS] = 0; inimigo[17].stat[DEFMAG] = 0;
    inimigo[17].stat[SPEED]  = 0; inimigo[17].stat[ATQFIS] = 0; inimigo[17].stat[ATQMAG] = 0;
    inimigo[17].stat[NIVEL]  = 0;
    inimigo[17].hpatual = 0; inimigo[17].xp = 0; inimigo[17].baralho = NULL;

    // INIMIGO 18
    strcpy(inimigo[18].nome, "Inimigo 19");
    inimigo[18].stat[HPMAX]  = 0; inimigo[18].stat[DEFFIS] = 0; inimigo[18].stat[DEFMAG] = 0;
    inimigo[18].stat[SPEED]  = 0; inimigo[18].stat[ATQFIS] = 0; inimigo[18].stat[ATQMAG] = 0;
    inimigo[18].stat[NIVEL]  = 0;
    inimigo[18].hpatual = 0; inimigo[18].xp = 0; inimigo[18].baralho = NULL;

    // INIMIGO 19
    strcpy(inimigo[19].nome, "Inimigo 20");
    inimigo[19].stat[HPMAX]  = 0; inimigo[19].stat[DEFFIS] = 0; inimigo[19].stat[DEFMAG] = 0;
    inimigo[19].stat[SPEED]  = 0; inimigo[19].stat[ATQFIS] = 0; inimigo[19].stat[ATQMAG] = 0;
    inimigo[19].stat[NIVEL]  = 0;
    inimigo[19].hpatual = 0; inimigo[19].xp = 0; inimigo[19].baralho = NULL;

    // INIMIGO 20
    strcpy(inimigo[20].nome, "Inimigo 21");
    inimigo[20].stat[HPMAX]  = 0; inimigo[20].stat[DEFFIS] = 0; inimigo[20].stat[DEFMAG] = 0;
    inimigo[20].stat[SPEED]  = 0; inimigo[20].stat[ATQFIS] = 0; inimigo[20].stat[ATQMAG] = 0;
    inimigo[20].stat[NIVEL]  = 0;
    inimigo[20].hpatual = 0; inimigo[20].xp = 0; inimigo[20].baralho = NULL;

    // INIMIGO 21
    strcpy(inimigo[21].nome, "Inimigo 22");
    inimigo[21].stat[HPMAX]  = 0; inimigo[21].stat[DEFFIS] = 0; inimigo[21].stat[DEFMAG] = 0;
    inimigo[21].stat[SPEED]  = 0; inimigo[21].stat[ATQFIS] = 0; inimigo[21].stat[ATQMAG] = 0;
    inimigo[21].stat[NIVEL]  = 0;
    inimigo[21].hpatual = 0; inimigo[21].xp = 0; inimigo[21].baralho = NULL;
}