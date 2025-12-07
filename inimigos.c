#include "structs.h"
#include <string.h>

INIMIGOS inimigo[4] = {0};
INIMIGOS Inimigo_Nulo[1] = {0};

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
    strcpy(inimigo[BOSS].Nome, "Boss do Bosque");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Goblin");
    inimigo[FACIL].Stat[HPMAX] = 10; inimigo[FACIL].Stat[DEFFIS] = 5; inimigo[FACIL].Stat[DEFMAG] = 5;
    inimigo[FACIL].Stat[SPEED] = 5; inimigo[FACIL].Stat[ATQFIS] = 10; inimigo[FACIL].Stat[ATQMAG] = 5; 
    inimigo[FACIL].HpAtual = 10; inimigo[FACIL].Xp = 200;
    strcpy(inimigo[FACIL].Habilidades[0].Nome, "Esfaquear");
    inimigo[FACIL].Habilidades[0].Tipo = 0; inimigo[FACIL].Habilidades[0].Valor = 5;
    strcpy(inimigo[FACIL].Habilidades[1].Nome, "Poção de Cura");
    inimigo[FACIL].Habilidades[1].Tipo = 2; inimigo[FACIL].Habilidades[0].Valor = 5;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Elemental de Planta");
    inimigo[MEDIO].Stat[HPMAX] = 20; inimigo[MEDIO].Stat[DEFFIS] = 10; inimigo[MEDIO].Stat[DEFMAG] = 10;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 5; inimigo[MEDIO].Stat[ATQMAG] = 20;
    inimigo[MEDIO].HpAtual = 20; inimigo[MEDIO].Xp = 500;
    strcpy(inimigo[MEDIO].Habilidades[0].Nome, "Lamina de Folha");
    inimigo[MEDIO].Habilidades[0].Tipo = 1; inimigo[MEDIO].Habilidades[0].Valor = 10;
    strcpy(inimigo[MEDIO].Habilidades[1].Nome, "Fotossíntese");
    inimigo[MEDIO].Habilidades[1].Tipo = 2; inimigo[MEDIO].Habilidades[0].Valor = 10;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Toco assombrado");
    inimigo[DIFICIL].Stat[HPMAX] = 30; inimigo[DIFICIL].Stat[DEFFIS] = 10; inimigo[DIFICIL].Stat[DEFMAG] = 15;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 10; inimigo[DIFICIL].Stat[ATQMAG] = 15;
    inimigo[DIFICIL].HpAtual = 30; inimigo[DIFICIL].Xp = 750;
    strcpy(inimigo[DIFICIL].Habilidades[0].Nome, "Definhar");
    inimigo[DIFICIL].Habilidades[0].Tipo = 1; inimigo[DIFICIL].Habilidades[0].Valor = 15;
    strcpy(inimigo[DIFICIL].Habilidades[1].Nome, "Dilacerar");
    inimigo[DIFICIL].Habilidades[1].Tipo = 0; inimigo[DIFICIL].Habilidades[0].Valor = 15;
}
void criar_ini_agua()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Inimigo 1");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Peixe-gato");
    inimigo[FACIL].Stat[HPMAX] = 20; inimigo[FACIL].Stat[DEFFIS] = 10; inimigo[FACIL].Stat[DEFMAG] = 10;
    inimigo[FACIL].Stat[SPEED] = 10; inimigo[FACIL].Stat[ATQFIS] = 20; inimigo[FACIL].Stat[ATQMAG] = 15; 
    inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 400;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Elemental de Água");
    inimigo[MEDIO].Stat[HPMAX] = 35; inimigo[MEDIO].Stat[DEFFIS] = 15; inimigo[MEDIO].Stat[DEFMAG] = 30;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 10; inimigo[MEDIO].Stat[ATQMAG] = 30;
    inimigo[MEDIO].HpAtual = 35; inimigo[MEDIO].Xp = 800;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Tritão");
    inimigo[DIFICIL].Stat[HPMAX] = 50; inimigo[DIFICIL].Stat[DEFFIS] = 30; inimigo[DIFICIL].Stat[DEFMAG] = 30;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 25; inimigo[DIFICIL].Stat[ATQMAG] = 20;
    inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 1250;

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
void criar_ini_nulo()
{
    strcpy(Inimigo_Nulo[0].Nome, "Dummy");
    Inimigo_Nulo[0].Stat[HPMAX] = -1;
}