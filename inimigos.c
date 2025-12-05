#include "structs.h"
#include <string.h>

INIMIGOS inimigo[4] = {0};
void criar_ini_vento()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Inimigo 2");
    inimigo[FACIL].Stat[HPMAX] = 0; inimigo[FACIL].Stat[DEFFIS] = 0; inimigo[FACIL].Stat[DEFMAG] = 0;
    inimigo[FACIL].Stat[SPEED] = 0; inimigo[FACIL].Stat[ATQFIS] = 0; inimigo[FACIL].Stat[ATQMAG] = 0; 
    inimigo[FACIL].Stat[NIVEL] = 0; inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Inimigo 3");
    inimigo[MEDIO].Stat[HPMAX] = 0; inimigo[MEDIO].Stat[DEFFIS] = 0; inimigo[MEDIO].Stat[DEFMAG] = 0;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 0; inimigo[MEDIO].Stat[ATQMAG] = 0;
    inimigo[MEDIO].Stat[NIVEL] = 0; inimigo[MEDIO].HpAtual = 0; inimigo[MEDIO].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Inimigo 4");
    inimigo[DIFICIL].Stat[HPMAX] = 0; inimigo[DIFICIL].Stat[DEFFIS] = 0; inimigo[DIFICIL].Stat[DEFMAG] = 0;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 0; inimigo[DIFICIL].Stat[ATQMAG] = 0;
    inimigo[DIFICIL].Stat[NIVEL] = 0; inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 0;

}
void criar_ini_bosque()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Inimigo 2");
    inimigo[FACIL].Stat[HPMAX] = 0; inimigo[FACIL].Stat[DEFFIS] = 0; inimigo[FACIL].Stat[DEFMAG] = 0;
    inimigo[FACIL].Stat[SPEED] = 0; inimigo[FACIL].Stat[ATQFIS] = 0; inimigo[FACIL].Stat[ATQMAG] = 0; 
    inimigo[FACIL].Stat[NIVEL] = 0; inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Inimigo 3");
    inimigo[MEDIO].Stat[HPMAX] = 0; inimigo[MEDIO].Stat[DEFFIS] = 0; inimigo[MEDIO].Stat[DEFMAG] = 0;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 0; inimigo[MEDIO].Stat[ATQMAG] = 0;
    inimigo[MEDIO].Stat[NIVEL] = 0; inimigo[MEDIO].HpAtual = 0; inimigo[MEDIO].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Inimigo 4");
    inimigo[DIFICIL].Stat[HPMAX] = 0; inimigo[DIFICIL].Stat[DEFFIS] = 0; inimigo[DIFICIL].Stat[DEFMAG] = 0;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 0; inimigo[DIFICIL].Stat[ATQMAG] = 0;
    inimigo[DIFICIL].Stat[NIVEL] = 0; inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 0;
}
void criar_ini_agua()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Inimigo 2");
    inimigo[FACIL].Stat[HPMAX] = 0; inimigo[FACIL].Stat[DEFFIS] = 0; inimigo[FACIL].Stat[DEFMAG] = 0;
    inimigo[FACIL].Stat[SPEED] = 0; inimigo[FACIL].Stat[ATQFIS] = 0; inimigo[FACIL].Stat[ATQMAG] = 0; 
    inimigo[FACIL].Stat[NIVEL] = 0; inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Inimigo 3");
    inimigo[MEDIO].Stat[HPMAX] = 0; inimigo[MEDIO].Stat[DEFFIS] = 0; inimigo[MEDIO].Stat[DEFMAG] = 0;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 0; inimigo[MEDIO].Stat[ATQMAG] = 0;
    inimigo[MEDIO].Stat[NIVEL] = 0; inimigo[MEDIO].HpAtual = 0; inimigo[MEDIO].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Inimigo 4");
    inimigo[DIFICIL].Stat[HPMAX] = 0; inimigo[DIFICIL].Stat[DEFFIS] = 0; inimigo[DIFICIL].Stat[DEFMAG] = 0;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 0; inimigo[DIFICIL].Stat[ATQMAG] = 0;
    inimigo[DIFICIL].Stat[NIVEL] = 0; inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 0;

}
void criar_ini_fogo()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Inimigo 2");
    inimigo[FACIL].Stat[HPMAX] = 0; inimigo[FACIL].Stat[DEFFIS] = 0; inimigo[FACIL].Stat[DEFMAG] = 0;
    inimigo[FACIL].Stat[SPEED] = 0; inimigo[FACIL].Stat[ATQFIS] = 0; inimigo[FACIL].Stat[ATQMAG] = 0; 
    inimigo[FACIL].Stat[NIVEL] = 0; inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 0;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Inimigo 3");
    inimigo[MEDIO].Stat[HPMAX] = 0; inimigo[MEDIO].Stat[DEFFIS] = 0; inimigo[MEDIO].Stat[DEFMAG] = 0;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 0; inimigo[MEDIO].Stat[ATQMAG] = 0;
    inimigo[MEDIO].Stat[NIVEL] = 0; inimigo[MEDIO].HpAtual = 0; inimigo[MEDIO].Xp = 0;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Inimigo 4");
    inimigo[DIFICIL].Stat[HPMAX] = 0; inimigo[DIFICIL].Stat[DEFFIS] = 0; inimigo[DIFICIL].Stat[DEFMAG] = 0;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 0; inimigo[DIFICIL].Stat[ATQMAG] = 0;
    inimigo[DIFICIL].Stat[NIVEL] = 0; inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 0;
}
void criar_ini_final()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;
}