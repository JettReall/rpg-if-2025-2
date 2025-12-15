#include <stdio.h>
#include <stdlib.h>
//#include "criardungeons.h"
#include "jogo.h"
#include "structs.h"
#include "classes.h"
#include "cartas.h"


int Dificuldade_Jogo = FACIL;
int Classe;

SAVE_DADOS SaveSlot;
PERSONAGEM Jogador;
DADOS_BATALHA dadosbaralho={
    .QtdCartaTotal = TAMANHO_DECK,
    .QtdCartaAtual = TAMANHO_DECK,
    .QtdCartamaoatual = 0,
    };

void Iniciar()
{
    Menu();
    //
    printf("%s\n%d\n%d\n",Jogador.Nome,Jogador.Classe,Jogador.HpAtual);
    for (int i = 0; i < TAMANHO_DECK; i++) {
        printf("%s\n",SaveSlot.Cartas[i].Nome);
    }
    //
}

void Menu() {
    int Opcoes = DIFICULDADE;
    while (Opcoes == DIFICULDADE) {
        printf("A camminhada do Herói\n");
        printf("(0) Carregar Jogo \t(1) Jogar \t(2) Dificuldade \n");
        scanf("%d", &Opcoes);
        switch (Opcoes)
        {
        case CARREGAR:
            TestaSave();
            break;
        case JOGAR:
            EscolheClasse();
            Historia_Comeco_Jogo();
            break;
        case DIFICULDADE:
            SaveSlot.Dificuldade = Escolhedificuldade();
            break;
        default:
            printf("Opcao Invalida. Escolha uma Opcao Valida");
            break;
        }
    }
}

int Escolhedificuldade() {
    int x = 0;
    while (1) {
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
    scanf("%s", &Jogador.Nome);
    while (classe < GUERREIRO || classe > SACERDOTE)
    {
        printf("\n Escolha uma das 3 Classes: \n (0) Guerreiro \t (1) Mago \t(2) Sacerdote \n");
        scanf("%d", &classe);
        switch (classe) {
        case GUERREIRO:
        case MAGO:
        case SACERDOTE:
            PreencherPadrao(&classe);
            break;
        default:
            printf("Escolha uma classe valida.\n");
            break;
        }
    }
}
void PreencherPadrao(int *ClsEscolhida) {
    CARTA *DeckInicial[TAMANHO_DECK] = {
       &CatalogoCartas[0][0][0],&CatalogoCartas[0][0][1],
       &CatalogoCartas[0][0][0],&CatalogoCartas[0][0][1],
       &CatalogoCartas[0][1][0],&CatalogoCartas[0][1][1],
       &CatalogoCartas[0][2][0],&CatalogoCartas[0][2][1],
    };
    

    for (int i = 0; i < MAX_STATS; i++) {
        Jogador.Stat[i] = DadosClasses[*ClsEscolhida].Stat[i];
    }
    Jogador.HpAtual = DadosClasses[*ClsEscolhida].HpAtual;
    Jogador.Classe = DadosClasses[*ClsEscolhida].Classe;
    for (int i = 0; i < dadosbaralho.QtdCartaTotal;i++) {
        SaveSlot.Cartas[i] = *DeckInicial[i];
    }
}

void AperteBotaoParaPular() {
    int Pular;
    printf("Aperte qualquer número do teclado\n");
    scanf("%d",&Pular);
}

void Historia_Comeco_Jogo()
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

    //Cidade();

    return 0;
}