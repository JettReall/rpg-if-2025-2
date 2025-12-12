#include "structs.h"
#include <string.h>

INIMIGOS inimigo[4] = {0};
INIMIGOS Inimigo_Nulo[1] = {0};

void criar_ini_vento()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Harpia");
    inimigo[BOSS].Stat[HPMAX] = 50; inimigo[BOSS].Stat[DEFFIS] = 15; inimigo[BOSS].Stat[DEFMAG] = 15;
    inimigo[BOSS].Stat[SPEED] = 10; inimigo[BOSS].Stat[ATQFIS] = 25; inimigo[BOSS].Stat[ATQMAG] = 25;
    inimigo[BOSS].HpAtual = 50; inimigo[BOSS].Xp = 1500;
    strcpy(inimigo[BOSS].Habilidades[0].Nome, "Dilacerar");
    inimigo[BOSS].Habilidades[0].Tipo = ATAQUEFIS; inimigo[BOSS].Habilidades[0].Valor = 20;
    strcpy(inimigo[BOSS].Habilidades[1].Nome, "Hipoxia");
    inimigo[BOSS].Habilidades[1].Tipo = ATAQUEMAG; inimigo[BOSS].Habilidades[0].Valor = 30;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Falcao");
    inimigo[FACIL].Stat[HPMAX] = 5; inimigo[FACIL].Stat[DEFFIS] = 5; inimigo[FACIL].Stat[DEFMAG] = 5;
    inimigo[FACIL].Stat[SPEED] = 5; inimigo[FACIL].Stat[ATQFIS] = 10; inimigo[FACIL].Stat[ATQMAG] = 0; 
    inimigo[FACIL].HpAtual = 10; inimigo[FACIL].Xp = 100;
    strcpy(inimigo[FACIL].Habilidades[0].Nome, "Bicar");
    inimigo[FACIL].Habilidades[0].Tipo = ATAQUEFIS; inimigo[FACIL].Habilidades[0].Valor = 5;
    strcpy(inimigo[FACIL].Habilidades[1].Nome, "Rasgar");
    inimigo[FACIL].Habilidades[1].Tipo = ATAQUEFIS; inimigo[FACIL].Habilidades[0].Valor = 10;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Elemental de Vento");
    inimigo[MEDIO].Stat[HPMAX] = 20; inimigo[MEDIO].Stat[DEFFIS] = 10; inimigo[MEDIO].Stat[DEFMAG] = 10;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 5; inimigo[MEDIO].Stat[ATQMAG] = 20;
    inimigo[MEDIO].HpAtual = 20; inimigo[MEDIO].Xp = 250;
    strcpy(inimigo[MEDIO].Habilidades[0].Nome, "Gume de Vento");
    inimigo[MEDIO].Habilidades[0].Tipo = ATAQUEMAG; inimigo[MEDIO].Habilidades[0].Valor = 10;
    strcpy(inimigo[MEDIO].Habilidades[1].Nome, "Asfixiar");
    inimigo[MEDIO].Habilidades[1].Tipo = ATAQUEFIS; inimigo[MEDIO].Habilidades[0].Valor = 10;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "HipoGrifo");
    inimigo[DIFICIL].Stat[HPMAX] = 20; inimigo[DIFICIL].Stat[DEFFIS] = 10; inimigo[DIFICIL].Stat[DEFMAG] = 15;
    inimigo[DIFICIL].Stat[SPEED] = 10; inimigo[DIFICIL].Stat[ATQFIS] = 10; inimigo[DIFICIL].Stat[ATQMAG] = 10;
    inimigo[DIFICIL].HpAtual = 20; inimigo[DIFICIL].Xp = 500;
    strcpy(inimigo[MEDIO].Habilidades[0].Nome, "Bicar");
    inimigo[MEDIO].Habilidades[0].Tipo = ATAQUEFIS; inimigo[MEDIO].Habilidades[0].Valor = 10;
    strcpy(inimigo[MEDIO].Habilidades[1].Nome, "Coice");
    inimigo[MEDIO].Habilidades[1].Tipo = ATAQUEFIS; inimigo[MEDIO].Habilidades[0].Valor = 15;

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
    inimigo[FACIL].Habilidades[0].Tipo = ATAQUEFIS; inimigo[FACIL].Habilidades[0].Valor = 5;
    strcpy(inimigo[FACIL].Habilidades[1].Nome, "Pocao de Cura");
    inimigo[FACIL].Habilidades[1].Tipo = CURA; inimigo[FACIL].Habilidades[0].Valor = 5;

    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Elemental de Planta");
    inimigo[MEDIO].Stat[HPMAX] = 20; inimigo[MEDIO].Stat[DEFFIS] = 10; inimigo[MEDIO].Stat[DEFMAG] = 10;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 5; inimigo[MEDIO].Stat[ATQMAG] = 20;
    inimigo[MEDIO].HpAtual = 20; inimigo[MEDIO].Xp = 500;
    strcpy(inimigo[MEDIO].Habilidades[0].Nome, "Lamina de Folha");
    inimigo[MEDIO].Habilidades[0].Tipo = ATAQUEMAG; inimigo[MEDIO].Habilidades[0].Valor = 10;
    strcpy(inimigo[MEDIO].Habilidades[1].Nome, "Fotossintese");
    inimigo[MEDIO].Habilidades[1].Tipo = CURA; inimigo[MEDIO].Habilidades[0].Valor = 10;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Toco assombrado");
    inimigo[DIFICIL].Stat[HPMAX] = 30; inimigo[DIFICIL].Stat[DEFFIS] = 10; inimigo[DIFICIL].Stat[DEFMAG] = 15;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 10; inimigo[DIFICIL].Stat[ATQMAG] = 15;
    inimigo[DIFICIL].HpAtual = 30; inimigo[DIFICIL].Xp = 750;
    strcpy(inimigo[DIFICIL].Habilidades[0].Nome, "Definhar");
    inimigo[DIFICIL].Habilidades[0].Tipo = ATAQUEMAG; inimigo[DIFICIL].Habilidades[0].Valor = 15;
    strcpy(inimigo[DIFICIL].Habilidades[1].Nome, "Dilacerar");
    inimigo[DIFICIL].Habilidades[1].Tipo = ATAQUEFIS; inimigo[DIFICIL].Habilidades[0].Valor = 15;
}
void criar_ini_agua()
{
    // Boss
    strcpy(inimigo[BOSS].Nome, "Boss da agua");
    inimigo[BOSS].Stat[HPMAX] = 0; inimigo[BOSS].Stat[DEFFIS] = 0; inimigo[BOSS].Stat[DEFMAG] = 0;
    inimigo[BOSS].Stat[SPEED] = 0; inimigo[BOSS].Stat[ATQFIS] = 0; inimigo[BOSS].Stat[ATQMAG] = 0;
    inimigo[BOSS].Stat[NIVEL] = 0; inimigo[BOSS].HpAtual = 0; inimigo[BOSS].Xp = 0;

    // INIMIGO 1
    strcpy(inimigo[FACIL].Nome, "Peixe-gato");
    inimigo[FACIL].Stat[HPMAX] = 20; inimigo[FACIL].Stat[DEFFIS] = 10; inimigo[FACIL].Stat[DEFMAG] = 10;
    inimigo[FACIL].Stat[SPEED] = 10; inimigo[FACIL].Stat[ATQFIS] = 20; inimigo[FACIL].Stat[ATQMAG] = 15; 
    inimigo[FACIL].HpAtual = 0; inimigo[FACIL].Xp = 400;
    strcpy(inimigo[FACIL].Habilidades[0].Nome, "Morder");
    inimigo[FACIL].Habilidades[0].Tipo = ATAQUEFIS; inimigo[FACIL].Habilidades[0].Valor = 10;
    strcpy(inimigo[FACIL].Habilidades[1].Nome, "Recuperar-se");
    inimigo[FACIL].Habilidades[1].Tipo = CURA; inimigo[FACIL].Habilidades[0].Valor = 10;


    // INIMIGO 2
    strcpy(inimigo[MEDIO].Nome, "Elemental de Agua");
    inimigo[MEDIO].Stat[HPMAX] = 35; inimigo[MEDIO].Stat[DEFFIS] = 15; inimigo[MEDIO].Stat[DEFMAG] = 30;
    inimigo[MEDIO].Stat[SPEED] = 0; inimigo[MEDIO].Stat[ATQFIS] = 10; inimigo[MEDIO].Stat[ATQMAG] = 30;
    inimigo[MEDIO].HpAtual = 35; inimigo[MEDIO].Xp = 800;
    strcpy(inimigo[MEDIO].Habilidades[0].Nome, "Jato de Agua");
    inimigo[MEDIO].Habilidades[0].Tipo = ATAQUEMAG; inimigo[MEDIO].Habilidades[0].Valor = 20;
    strcpy(inimigo[MEDIO].Habilidades[1].Nome, "Sugar Agua");
    inimigo[MEDIO].Habilidades[1].Tipo = CURA; inimigo[MEDIO].Habilidades[0].Valor = 15;

    // INIMIGO 3
    strcpy(inimigo[DIFICIL].Nome, "Tritao");
    inimigo[DIFICIL].Stat[HPMAX] = 50; inimigo[DIFICIL].Stat[DEFFIS] = 30; inimigo[DIFICIL].Stat[DEFMAG] = 30;
    inimigo[DIFICIL].Stat[SPEED] = 0; inimigo[DIFICIL].Stat[ATQFIS] = 25; inimigo[DIFICIL].Stat[ATQMAG] = 20;
    inimigo[DIFICIL].HpAtual = 0; inimigo[DIFICIL].Xp = 1250;
    strcpy(inimigo[DIFICIL].Habilidades[0].Nome, "Lamina de Agua");
    inimigo[DIFICIL].Habilidades[0].Tipo = ATAQUEMAG; inimigo[DIFICIL].Habilidades[0].Valor = 30;
    strcpy(inimigo[DIFICIL].Habilidades[1].Nome, "Dilacerar");
    inimigo[DIFICIL].Habilidades[1].Tipo = ATAQUEFIS; inimigo[DIFICIL].Habilidades[0].Valor = 30;

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
    strcpy(inimigo[0].Habilidades[0].Nome, "Nula");
    inimigo[0].Habilidades[0].Tipo = ATAQUEFIS; inimigo[0].Habilidades[0].Valor = 0;
    strcpy(inimigo[0].Habilidades[1].Nome, "Nula");
    inimigo[0].Habilidades[1].Tipo = CURA; inimigo[0].Habilidades[0].Valor = 0;
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
    strcpy(inimigo[0].Habilidades[0].Nome, "Nula");
    inimigo[0].Habilidades[0].Tipo = ATAQUEFIS; inimigo[0].Habilidades[0].Valor = 0;
    strcpy(inimigo[0].Habilidades[1].Nome, "Nula");
    inimigo[0].Habilidades[1].Tipo = CURA; inimigo[0].Habilidades[0].Valor = 0;
}