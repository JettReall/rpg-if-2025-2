#include <stdio.h>
#include <stdlib.h>
//#include "criardungeons.h"
#include "jogo.h"
#include "structs.h"
// #include "combate.h"
#include "classes.h"

int Dificuldade_Jogo = FACIL;
int Classe;

void Iniciar()
{
    Menu();
    Comeca_Jogo();
}

void Menu()
{
    int Opcoes = DIFICULDADE;
    while (Opcoes == DIFICULDADE)
    {
        printf("Bem vindo ao mundo de ____\n");
        printf("(0) Carregar Jogo \t(1) Jogar \t(2) Dificuldade \n");
        scanf("%d", &Opcoes);
        switch (Opcoes)
        {
        case CARREGAR:
            TestaSave();
            break;
        case JOGAR:
            EscolheClasse();
            break;
        case DIFICULDADE:
            Dificuldade_Jogo = Escolhedificuldade();
            break;
        default:
            printf("Opcao Invalida. Escolha uma Opcao Valida");
            break;
        }
    }
}
int Escolhedificuldade()
{
    int x = 0;
    while (1)
    {
        printf("\n Qual a dificuldade do jogo? \n (1) Facil \t (2) Medio \t (3) Dificil \n");
        scanf("%d", &x);
        if (x >= FACIL && x <= DIFICIL) return x;
        else printf("Escolha uma Dificuldade Valida.");
    }
}

void TestaSave()
{

}

void EscolheClasse()
{
    int classe = -1;
    char nome[30];
    printf("\n Digite o nome do seu personagem: ");
    scanf("%s", &nome);
    while (classe < GUERREIRO || classe > SACERDOTE)
    {
        printf("\n Escolha uma das 3 Classes: \n (0) Guerreiro \t (1) Mago \t(2) Sacerdote \n");
        scanf("%d", &classe);
        switch (classe)
        {
        case GUERREIRO:
            Cria_Guerreiro(nome);
            break;
        case MAGO:
            Cria_Mago(nome);
            break;
        case SACERDOTE:
            Cria_Sacerdote(nome);
            break;
        default:
            printf("Escolha uma classe valida.\n");
            break;
        }
    }
}
void Comeca_Jogo()
{

}
int main()
{
    Iniciar();
}