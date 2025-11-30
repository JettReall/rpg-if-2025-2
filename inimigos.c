#include "structs.h"
#include <string.h>

PERSONAGEM inimigo[22] = {0};

void criarinimigos()
{
    // INIMIGO 0
    strcpy(inimigo[0].Nome, "Inimigo 1");
    inimigo[0].Stat[HPMAX] = 0; inimigo[0].Stat[DEFFIS] = 0; inimigo[0].Stat[DEFMAG] = 0;
    inimigo[0].Stat[SPEED] = 0; inimigo[0].Stat[ATQFIS] = 0; inimigo[0].Stat[ATQMAG] = 0;
    inimigo[0].Stat[NIVEL] = 0;
    inimigo[0].HpAtual = 0; inimigo[0].Xp = 0; inimigo[0].Baralho = NULL;

    // INIMIGO 1
    strcpy(inimigo[1].Nome, "Inimigo 2");
    inimigo[1].Stat[HPMAX] = 0; inimigo[1].Stat[DEFFIS] = 0; inimigo[1].Stat[DEFMAG] = 0;
    inimigo[1].Stat[SPEED] = 0; inimigo[1].Stat[ATQFIS] = 0; inimigo[1].Stat[ATQMAG] = 0;
    inimigo[1].Stat[NIVEL] = 0;
    inimigo[1].HpAtual = 0; inimigo[1].Xp = 0; inimigo[1].Baralho = NULL;

    // INIMIGO 2
    strcpy(inimigo[2].Nome, "Inimigo 3");
    inimigo[2].Stat[HPMAX] = 0; inimigo[2].Stat[DEFFIS] = 0; inimigo[2].Stat[DEFMAG] = 0;
    inimigo[2].Stat[SPEED] = 0; inimigo[2].Stat[ATQFIS] = 0; inimigo[2].Stat[ATQMAG] = 0;
    inimigo[2].Stat[NIVEL] = 0;
    inimigo[2].HpAtual = 0; inimigo[2].Xp = 0; inimigo[2].Baralho = NULL;

    // INIMIGO 3
    strcpy(inimigo[3].Nome, "Inimigo 4");
    inimigo[3].Stat[HPMAX] = 0; inimigo[3].Stat[DEFFIS] = 0; inimigo[3].Stat[DEFMAG] = 0;
    inimigo[3].Stat[SPEED] = 0; inimigo[3].Stat[ATQFIS] = 0; inimigo[3].Stat[ATQMAG] = 0;
    inimigo[3].Stat[NIVEL] = 0;
    inimigo[3].HpAtual = 0; inimigo[3].Xp = 0; inimigo[3].Baralho = NULL;

    // INIMIGO 4
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0; inimigo[4].Baralho = NULL;

    // INIMIGO 5
    strcpy(inimigo[5].Nome, "Inimigo 6");
    inimigo[5].Stat[HPMAX] = 0; inimigo[5].Stat[DEFFIS] = 0; inimigo[5].Stat[DEFMAG] = 0;
    inimigo[5].Stat[SPEED] = 0; inimigo[5].Stat[ATQFIS] = 0; inimigo[5].Stat[ATQMAG] = 0;
    inimigo[5].Stat[NIVEL] = 0;
    inimigo[5].HpAtual = 0; inimigo[5].Xp = 0; inimigo[5].Baralho = NULL;

    // INIMIGO 6
    strcpy(inimigo[6].Nome, "Inimigo 7");
    inimigo[6].Stat[HPMAX] = 0; inimigo[6].Stat[DEFFIS] = 0; inimigo[6].Stat[DEFMAG] = 0;
    inimigo[6].Stat[SPEED] = 0; inimigo[6].Stat[ATQFIS] = 0; inimigo[6].Stat[ATQMAG] = 0;
    inimigo[6].Stat[NIVEL] = 0;
    inimigo[6].HpAtual = 0; inimigo[6].Xp = 0; inimigo[6].Baralho = NULL;

    // INIMIGO 7
    strcpy(inimigo[7].Nome, "Inimigo 8");
    inimigo[7].Stat[HPMAX] = 0; inimigo[7].Stat[DEFFIS] = 0; inimigo[7].Stat[DEFMAG] = 0;
    inimigo[7].Stat[SPEED] = 0; inimigo[7].Stat[ATQFIS] = 0; inimigo[7].Stat[ATQMAG] = 0;
    inimigo[7].Stat[NIVEL] = 0;
    inimigo[7].HpAtual = 0; inimigo[7].Xp = 0; inimigo[7].Baralho = NULL;

    // INIMIGO 8
    strcpy(inimigo[8].Nome, "Inimigo 9");
    inimigo[8].Stat[HPMAX] = 0; inimigo[8].Stat[DEFFIS] = 0; inimigo[8].Stat[DEFMAG] = 0;
    inimigo[8].Stat[SPEED] = 0; inimigo[8].Stat[ATQFIS] = 0; inimigo[8].Stat[ATQMAG] = 0;
    inimigo[8].Stat[NIVEL] = 0;
    inimigo[8].HpAtual = 0; inimigo[8].Xp = 0; inimigo[8].Baralho = NULL;

    // INIMIGO 9
    strcpy(inimigo[9].Nome, "Inimigo 10");
    inimigo[9].Stat[HPMAX] = 0; inimigo[9].Stat[DEFFIS] = 0; inimigo[9].Stat[DEFMAG] = 0;
    inimigo[9].Stat[SPEED] = 0; inimigo[9].Stat[ATQFIS] = 0; inimigo[9].Stat[ATQMAG] = 0;
    inimigo[9].Stat[NIVEL] = 0;
    inimigo[9].HpAtual = 0; inimigo[9].Xp = 0; inimigo[9].Baralho = NULL;

    // INIMIGO 10
    strcpy(inimigo[10].Nome, "Inimigo 11");
    inimigo[10].Stat[HPMAX] = 0; inimigo[10].Stat[DEFFIS] = 0; inimigo[10].Stat[DEFMAG] = 0;
    inimigo[10].Stat[SPEED] = 0; inimigo[10].Stat[ATQFIS] = 0; inimigo[10].Stat[ATQMAG] = 0;
    inimigo[10].Stat[NIVEL] = 0;
    inimigo[10].HpAtual = 0; inimigo[10].Xp = 0; inimigo[10].Baralho = NULL;

    // INIMIGO 11
    strcpy(inimigo[11].Nome, "Inimigo 12");
    inimigo[11].Stat[HPMAX] = 0; inimigo[11].Stat[DEFFIS] = 0; inimigo[11].Stat[DEFMAG] = 0;
    inimigo[11].Stat[SPEED] = 0; inimigo[11].Stat[ATQFIS] = 0; inimigo[11].Stat[ATQMAG] = 0;
    inimigo[11].Stat[NIVEL] = 0;
    inimigo[11].HpAtual = 0; inimigo[11].Xp = 0; inimigo[11].Baralho = NULL;

    // INIMIGO 12
    strcpy(inimigo[12].Nome, "Inimigo 13");
    inimigo[12].Stat[HPMAX] = 0; inimigo[12].Stat[DEFFIS] = 0; inimigo[12].Stat[DEFMAG] = 0;
    inimigo[12].Stat[SPEED] = 0; inimigo[12].Stat[ATQFIS] = 0; inimigo[12].Stat[ATQMAG] = 0;
    inimigo[12].Stat[NIVEL] = 0;
    inimigo[12].HpAtual = 0; inimigo[12].Xp = 0; inimigo[12].Baralho = NULL;

    // INIMIGO 13
    strcpy(inimigo[13].Nome, "Inimigo 14");
    inimigo[13].Stat[HPMAX] = 0; inimigo[13].Stat[DEFFIS] = 0; inimigo[13].Stat[DEFMAG] = 0;
    inimigo[13].Stat[SPEED] = 0; inimigo[13].Stat[ATQFIS] = 0; inimigo[13].Stat[ATQMAG] = 0;
    inimigo[13].Stat[NIVEL] = 0;
    inimigo[13].HpAtual = 0; inimigo[13].Xp = 0; inimigo[13].Baralho = NULL;

    // INIMIGO 14
    strcpy(inimigo[14].Nome, "Inimigo 15");
    inimigo[14].Stat[HPMAX] = 0; inimigo[14].Stat[DEFFIS] = 0; inimigo[14].Stat[DEFMAG] = 0;
    inimigo[14].Stat[SPEED] = 0; inimigo[14].Stat[ATQFIS] = 0; inimigo[14].Stat[ATQMAG] = 0;
    inimigo[14].Stat[NIVEL] = 0;
    inimigo[14].HpAtual = 0; inimigo[14].Xp = 0; inimigo[14].Baralho = NULL;

    // INIMIGO 15
    strcpy(inimigo[15].Nome, "Inimigo 16");
    inimigo[15].Stat[HPMAX] = 0; inimigo[15].Stat[DEFFIS] = 0; inimigo[15].Stat[DEFMAG] = 0;
    inimigo[15].Stat[SPEED] = 0; inimigo[15].Stat[ATQFIS] = 0; inimigo[15].Stat[ATQMAG] = 0;
    inimigo[15].Stat[NIVEL] = 0;
    inimigo[15].HpAtual = 0; inimigo[15].Xp = 0; inimigo[15].Baralho = NULL;

    // INIMIGO 16
    strcpy(inimigo[16].Nome, "Inimigo 17");
    inimigo[16].Stat[HPMAX] = 0; inimigo[16].Stat[DEFFIS] = 0; inimigo[16].Stat[DEFMAG] = 0;
    inimigo[16].Stat[SPEED] = 0; inimigo[16].Stat[ATQFIS] = 0; inimigo[16].Stat[ATQMAG] = 0;
    inimigo[16].Stat[NIVEL] = 0;
    inimigo[16].HpAtual = 0; inimigo[16].Xp = 0; inimigo[16].Baralho = NULL;

    // INIMIGO 17
    strcpy(inimigo[17].Nome, "Inimigo 18");
    inimigo[17].Stat[HPMAX] = 0; inimigo[17].Stat[DEFFIS] = 0; inimigo[17].Stat[DEFMAG] = 0;
    inimigo[17].Stat[SPEED] = 0; inimigo[17].Stat[ATQFIS] = 0; inimigo[17].Stat[ATQMAG] = 0;
    inimigo[17].Stat[NIVEL] = 0;
    inimigo[17].HpAtual = 0; inimigo[17].Xp = 0; inimigo[17].Baralho = NULL;

    // INIMIGO 18
    strcpy(inimigo[18].Nome, "Inimigo 19");
    inimigo[18].Stat[HPMAX] = 0; inimigo[18].Stat[DEFFIS] = 0; inimigo[18].Stat[DEFMAG] = 0;
    inimigo[18].Stat[SPEED] = 0; inimigo[18].Stat[ATQFIS] = 0; inimigo[18].Stat[ATQMAG] = 0;
    inimigo[18].Stat[NIVEL] = 0;
    inimigo[18].HpAtual = 0; inimigo[18].Xp = 0; inimigo[18].Baralho = NULL;

    // INIMIGO 19
    strcpy(inimigo[19].Nome, "Inimigo 20");
    inimigo[19].Stat[HPMAX] = 0; inimigo[19].Stat[DEFFIS] = 0; inimigo[19].Stat[DEFMAG] = 0;
    inimigo[19].Stat[SPEED] = 0; inimigo[19].Stat[ATQFIS] = 0; inimigo[19].Stat[ATQMAG] = 0;
    inimigo[19].Stat[NIVEL] = 0;
    inimigo[19].HpAtual = 0; inimigo[19].Xp = 0; inimigo[19].Baralho = NULL;

    // INIMIGO 20
    strcpy(inimigo[20].Nome, "Inimigo 21");
    inimigo[20].Stat[HPMAX] = 0; inimigo[20].Stat[DEFFIS] = 0; inimigo[20].Stat[DEFMAG] = 0;
    inimigo[20].Stat[SPEED] = 0; inimigo[20].Stat[ATQFIS] = 0; inimigo[20].Stat[ATQMAG] = 0;
    inimigo[20].Stat[NIVEL] = 0;
    inimigo[20].HpAtual = 0; inimigo[20].Xp = 0; inimigo[20].Baralho = NULL;

    // INIMIGO 21
    strcpy(inimigo[21].Nome, "Inimigo 22");
    inimigo[21].Stat[HPMAX] = 0; inimigo[21].Stat[DEFFIS] = 0; inimigo[21].Stat[DEFMAG] = 0;
    inimigo[21].Stat[SPEED] = 0; inimigo[21].Stat[ATQFIS] = 0; inimigo[21].Stat[ATQMAG] = 0;
    inimigo[21].Stat[NIVEL] = 0;
    inimigo[21].HpAtual = 0; inimigo[21].Xp = 0; inimigo[21].Baralho = NULL;
}
