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

void AperteBotaoParaPular() {
    int Pular;
    printf("Aperte qualquer número do teclado\n");
    scanf("%d",&Pular);
}

void Comeca_Jogo()
{
    printf("É mais um dia normal no campus, o sol está se pondo e pediram para você desmntar um computador do LAZIC\n");
    printf("Você está no corredor do bloco 3, se dirigindo ao laboratório.\n");
    AperteBotaoParaPular();
    printf("Você entra no laboratório, e encontra o computador para desconectar. Porém, deixaram-no ligado.\nHá algo confuso na tela, você não sabe ao certo o que é. Melhor fechar o arquivo\n");
    AperteBotaoParaPular();
    printf("Quando você ia fechar o arquivo, apareceu uma mensagem de erro para resolver:\n 'Erro encontrado, reinicie o programa antes' é o que diz, e só há uma opção: Recarregar.\n");
    AperteBotaoParaPular();
    printf("Quando você clica em recarregar, algo estranho aparece na tela;\nSubitamente você sente um turbilhão ao seu redor e uma luz brilha muito forte. \nQuando você recobra sua consciência, você está deitado no que parece ser o chão.\n");
    AperteBotaoParaPular();
    printf("Você se levanta, não sabe ao certo onde está, mas parece ser dentro do computador. \nPor sorte, conseguiste trazer um aparato com você, seu Flipper (que por algum motivo você anda com um). \nIsso te permite ver o código do que você está, se isto for, de fato, um computador.\n");
    AperteBotaoParaPular();
    printf("Após dar uma vasculhada, você descobre que está dentro de um código de um RPG genérico rodada em uma Engine duvidosa, baixada em um local mais duvidoso ainda.\n");
    printf("Pelo Flipper, você aproveitou de um erro no código, fazendo que a função main termine em 'return Player', então isso deve te ejetar para fora... Em teoria.\n");
    printf("A função main só acaba quando o jogador finaliza o jogo, que, para isso, precisa passar por 4 dungeons, coletar 4 artefatos elementais e derrotar o chefe final... Morrer nesse jogo não causa que eu seja apagado\n");
    printf("então zerar o jogo é o jeito mais plausível de sair vivo daqui... então melhor começar a aventura\n");
    AperteBotaoParaPular();
    printf("Você vê o mapa carregar na sua frente. Parece ser uma cabana.\n");

}


int main()
{
    Iniciar();
}