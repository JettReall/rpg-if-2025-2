#include "structs.h"
#include <string.h>

PERSONAGEM Player[1] = {0};
void Cria_Guerreiro(char Nome[30])
{
    strcpy(Player[0].Nome, Nome);
    Player[0].Stat[HPMAX] = 150; Player[0].Stat[DEFFIS] = 10; Player[0].Stat[DEFMAG] = 10;
    Player[0].Stat[SPEED] = 5; Player[0].Stat[ATQFIS] = 10; Player[0].Stat[ATQMAG] = 5; 
    Player[0].HpAtual = 150; Player[0].Classe = GUERREIRO;
}
void Cria_Mago(char Nome[30])
{
    strcpy(Player[0].Nome, Nome);
    Player[0].Stat[HPMAX] = 75; Player[0].Stat[DEFFIS] = 5; Player[0].Stat[DEFMAG] = 10;
    Player[0].Stat[SPEED] = 5; Player[0].Stat[ATQFIS] = 5; Player[0].Stat[ATQMAG] = 15; 
    Player[0].HpAtual = 75; Player[0].Classe = MAGO;
}

void Cria_Sacerdote(char Nome[30])
{
    strcpy(Player[0].Nome, Nome);
    Player[0].Stat[HPMAX] = 100; Player[0].Stat[DEFFIS] = 10; Player[0].Stat[DEFMAG] = 10;
    Player[0].Stat[SPEED] = 0; Player[0].Stat[ATQFIS] = 10; Player[0].Stat[ATQMAG] = 10; 
    Player[0].HpAtual = 100; Player[0].Classe = SACERDOTE;
}