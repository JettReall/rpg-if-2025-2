#include "structs.h"
#include <string.h>

INIMIGOS inimigo[5] = {0};
void criar_ini_vento()
{
    // Inimigo 0
    strcpy(inimigo[0].Nome, "Inimigo 1");
    inimigo[0].Stat[HPMAX] = 0; inimigo[0].Stat[DEFFIS] = 0; inimigo[0].Stat[DEFMAG] = 0;
    inimigo[0].Stat[SPEED] = 0; inimigo[0].Stat[ATQFIS] = 0; inimigo[0].Stat[ATQMAG] = 0;
    inimigo[0].Stat[NIVEL] = 0; inimigo[0].Dungeon = 0; inimigo[0].Dificuldade = 0;
    inimigo[0].HpAtual = 0; inimigo[0].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[1].Nome, "Inimigo 2");
    inimigo[1].Stat[HPMAX] = 0; inimigo[1].Stat[DEFFIS] = 0; inimigo[1].Stat[DEFMAG] = 0;
    inimigo[1].Stat[SPEED] = 0; inimigo[1].Stat[ATQFIS] = 0; inimigo[1].Stat[ATQMAG] = 0;
    inimigo[1].Stat[NIVEL] = 0; inimigo[1].Dungeon = 0; inimigo[1].Dificuldade = 0;
    inimigo[1].HpAtual = 0; inimigo[1].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[2].Nome, "Inimigo 3");
    inimigo[2].Stat[HPMAX] = 0; inimigo[2].Stat[DEFFIS] = 0; inimigo[2].Stat[DEFMAG] = 0;
    inimigo[2].Stat[SPEED] = 0; inimigo[2].Stat[ATQFIS] = 0; inimigo[2].Stat[ATQMAG] = 0;
    inimigo[2].Stat[NIVEL] = 0; inimigo[2].Dungeon = 0; inimigo[2].Dificuldade = 0;
    inimigo[2].HpAtual = 0; inimigo[2].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[3].Nome, "Inimigo 4");
    inimigo[3].Stat[HPMAX] = 0; inimigo[3].Stat[DEFFIS] = 0; inimigo[3].Stat[DEFMAG] = 0;
    inimigo[3].Stat[SPEED] = 0; inimigo[3].Stat[ATQFIS] = 0; inimigo[3].Stat[ATQMAG] = 0;
    inimigo[3].Stat[NIVEL] = 0; inimigo[3].Dungeon = 0; inimigo[3].Dificuldade = 0;
    inimigo[3].HpAtual = 0; inimigo[3].Xp = 0;

    // Boss
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0; inimigo[4].Dungeon = 0; inimigo[4].Dificuldade = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0;
}
void criar_ini_bosque()
{
    // Inimigo 0
    strcpy(inimigo[0].Nome, "Inimigo 1");
    inimigo[0].Stat[HPMAX] = 0; inimigo[0].Stat[DEFFIS] = 0; inimigo[0].Stat[DEFMAG] = 0;
    inimigo[0].Stat[SPEED] = 0; inimigo[0].Stat[ATQFIS] = 0; inimigo[0].Stat[ATQMAG] = 0;
    inimigo[0].Stat[NIVEL] = 0; inimigo[0].Dungeon = 0; inimigo[0].Dificuldade = 0;
    inimigo[0].HpAtual = 0; inimigo[0].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[1].Nome, "Inimigo 2");
    inimigo[1].Stat[HPMAX] = 0; inimigo[1].Stat[DEFFIS] = 0; inimigo[1].Stat[DEFMAG] = 0;
    inimigo[1].Stat[SPEED] = 0; inimigo[1].Stat[ATQFIS] = 0; inimigo[1].Stat[ATQMAG] = 0;
    inimigo[1].Stat[NIVEL] = 0; inimigo[1].Dungeon = 0; inimigo[1].Dificuldade = 0;
    inimigo[1].HpAtual = 0; inimigo[1].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[2].Nome, "Inimigo 3");
    inimigo[2].Stat[HPMAX] = 0; inimigo[2].Stat[DEFFIS] = 0; inimigo[2].Stat[DEFMAG] = 0;
    inimigo[2].Stat[SPEED] = 0; inimigo[2].Stat[ATQFIS] = 0; inimigo[2].Stat[ATQMAG] = 0;
    inimigo[2].Stat[NIVEL] = 0; inimigo[2].Dungeon = 0; inimigo[2].Dificuldade = 0;
    inimigo[2].HpAtual = 0; inimigo[2].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[3].Nome, "Inimigo 4");
    inimigo[3].Stat[HPMAX] = 0; inimigo[3].Stat[DEFFIS] = 0; inimigo[3].Stat[DEFMAG] = 0;
    inimigo[3].Stat[SPEED] = 0; inimigo[3].Stat[ATQFIS] = 0; inimigo[3].Stat[ATQMAG] = 0;
    inimigo[3].Stat[NIVEL] = 0; inimigo[3].Dungeon = 0; inimigo[3].Dificuldade = 0;
    inimigo[3].HpAtual = 0; inimigo[3].Xp = 0;

    // Boss
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0; inimigo[4].Dungeon = 0; inimigo[4].Dificuldade = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0;
}
void criar_ini_agua()
{
    // Inimigo 0
    strcpy(inimigo[0].Nome, "Inimigo 1");
    inimigo[0].Stat[HPMAX] = 0; inimigo[0].Stat[DEFFIS] = 0; inimigo[0].Stat[DEFMAG] = 0;
    inimigo[0].Stat[SPEED] = 0; inimigo[0].Stat[ATQFIS] = 0; inimigo[0].Stat[ATQMAG] = 0;
    inimigo[0].Stat[NIVEL] = 0; inimigo[0].Dungeon = 0; inimigo[0].Dificuldade = 0;
    inimigo[0].HpAtual = 0; inimigo[0].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[1].Nome, "Inimigo 2");
    inimigo[1].Stat[HPMAX] = 0; inimigo[1].Stat[DEFFIS] = 0; inimigo[1].Stat[DEFMAG] = 0;
    inimigo[1].Stat[SPEED] = 0; inimigo[1].Stat[ATQFIS] = 0; inimigo[1].Stat[ATQMAG] = 0;
    inimigo[1].Stat[NIVEL] = 0; inimigo[1].Dungeon = 0; inimigo[1].Dificuldade = 0;
    inimigo[1].HpAtual = 0; inimigo[1].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[2].Nome, "Inimigo 3");
    inimigo[2].Stat[HPMAX] = 0; inimigo[2].Stat[DEFFIS] = 0; inimigo[2].Stat[DEFMAG] = 0;
    inimigo[2].Stat[SPEED] = 0; inimigo[2].Stat[ATQFIS] = 0; inimigo[2].Stat[ATQMAG] = 0;
    inimigo[2].Stat[NIVEL] = 0; inimigo[2].Dungeon = 0; inimigo[2].Dificuldade = 0;
    inimigo[2].HpAtual = 0; inimigo[2].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[3].Nome, "Inimigo 4");
    inimigo[3].Stat[HPMAX] = 0; inimigo[3].Stat[DEFFIS] = 0; inimigo[3].Stat[DEFMAG] = 0;
    inimigo[3].Stat[SPEED] = 0; inimigo[3].Stat[ATQFIS] = 0; inimigo[3].Stat[ATQMAG] = 0;
    inimigo[3].Stat[NIVEL] = 0; inimigo[3].Dungeon = 0; inimigo[3].Dificuldade = 0;
    inimigo[3].HpAtual = 0; inimigo[3].Xp = 0;

    // Boss
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0; inimigo[4].Dungeon = 0; inimigo[4].Dificuldade = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0;
}
void criar_ini_fogo()
{
    // Inimigo 0
    strcpy(inimigo[0].Nome, "Inimigo 1");
    inimigo[0].Stat[HPMAX] = 0; inimigo[0].Stat[DEFFIS] = 0; inimigo[0].Stat[DEFMAG] = 0;
    inimigo[0].Stat[SPEED] = 0; inimigo[0].Stat[ATQFIS] = 0; inimigo[0].Stat[ATQMAG] = 0;
    inimigo[0].Stat[NIVEL] = 0; inimigo[0].Dungeon = 0; inimigo[0].Dificuldade = 0;
    inimigo[0].HpAtual = 0; inimigo[0].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[1].Nome, "Inimigo 2");
    inimigo[1].Stat[HPMAX] = 0; inimigo[1].Stat[DEFFIS] = 0; inimigo[1].Stat[DEFMAG] = 0;
    inimigo[1].Stat[SPEED] = 0; inimigo[1].Stat[ATQFIS] = 0; inimigo[1].Stat[ATQMAG] = 0;
    inimigo[1].Stat[NIVEL] = 0; inimigo[1].Dungeon = 0; inimigo[1].Dificuldade = 0;
    inimigo[1].HpAtual = 0; inimigo[1].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[2].Nome, "Inimigo 3");
    inimigo[2].Stat[HPMAX] = 0; inimigo[2].Stat[DEFFIS] = 0; inimigo[2].Stat[DEFMAG] = 0;
    inimigo[2].Stat[SPEED] = 0; inimigo[2].Stat[ATQFIS] = 0; inimigo[2].Stat[ATQMAG] = 0;
    inimigo[2].Stat[NIVEL] = 0; inimigo[2].Dungeon = 0; inimigo[2].Dificuldade = 0;
    inimigo[2].HpAtual = 0; inimigo[2].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[3].Nome, "Inimigo 4");
    inimigo[3].Stat[HPMAX] = 0; inimigo[3].Stat[DEFFIS] = 0; inimigo[3].Stat[DEFMAG] = 0;
    inimigo[3].Stat[SPEED] = 0; inimigo[3].Stat[ATQFIS] = 0; inimigo[3].Stat[ATQMAG] = 0;
    inimigo[3].Stat[NIVEL] = 0; inimigo[3].Dungeon = 0; inimigo[3].Dificuldade = 0;
    inimigo[3].HpAtual = 0; inimigo[3].Xp = 0;

    // Boss
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0; inimigo[4].Dungeon = 0; inimigo[4].Dificuldade = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0;
}
void criar_ini_final()
{
    // Boss
    strcpy(inimigo[4].Nome, "Inimigo 5");
    inimigo[4].Stat[HPMAX] = 0; inimigo[4].Stat[DEFFIS] = 0; inimigo[4].Stat[DEFMAG] = 0;
    inimigo[4].Stat[SPEED] = 0; inimigo[4].Stat[ATQFIS] = 0; inimigo[4].Stat[ATQMAG] = 0;
    inimigo[4].Stat[NIVEL] = 0; inimigo[4].Dungeon = 0; inimigo[4].Dificuldade = 0;
    inimigo[4].HpAtual = 0; inimigo[4].Xp = 0;
}