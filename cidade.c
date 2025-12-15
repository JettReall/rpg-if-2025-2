#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cidade.h"

int Cidade(PERSONAGEM *passagem) {
     InicializarCidade();
      //Ponto de inicio de andar na cidade
     while(Loop) {
          printf("%s\n",LocalAtual->DadosLocal.DescricaoLocal);
          OpcoesDeCadaLocal[LocalAtual->DadosLocal.ID](OpcoesLocal(LocalAtual->DadosLocal.ID),passagem); //Ponteiro de função que acessa função referente ao local, imprime o que tem de lá e escolhe 
          
     }
}

void InicializarCidade() {
     int e = 0;
     int Conexoes[MAXDESTINOS][MAXDESTINOS] = {
          {N_CONECTADO,N_CONECTADO,CONECTADO,CONECTADO},
          {N_CONECTADO,N_CONECTADO,CONECTADO,N_CONECTADO},
          {CONECTADO,CONECTADO,N_CONECTADO,CONECTADO},
          {CONECTADO,N_CONECTADO,CONECTADO,N_CONECTADO},
     }; //Para validar e imprimir as conexões entre mapa
     int LocalInicalizando = 0;

     for (int i = 0; i < MAXDESTINOS;i++) {
          e=0;
          LocalInicalizando = Locais[i].DadosLocal.ID; //Local recebe o ID daquele lugar para comparar com os outros
          for (int k = 0; k < MAXDESTINOS; k++) { //Roda a var Conexoes para ver se é conectado
               if (Conexoes[LocalInicalizando][k] == CONECTADO) { //Se o local está preenchido, salta pro próximo
                    if (Locais[i].ConexaoID[e] != CONEXAO_NULA) {
                         e++;
                    }
                    Locais[i].ConexaoID[e] = k; //Se for conectado, ele salva o k, que, no momento, equivale ao ID do destino conectado
               }   
          }
     }
     LocalAtual = &Locais[CASA];
}


int OpcoesLocal(int Local) {
     int OpcaoEscolhida = 0;
     printf("---\n");

     for (int i = 0; i < OpcoesQtd[Local];i++) {
          if (strcmp(LocalAtual->DadosLocal.Opcoes[i],"\0") != 0) printf("%d. %25s\n",i+1,LocalAtual->DadosLocal.Opcoes[i]);
          //Compara se a string é vazia. Se for, imprime nada, mas se não for, imprime a opção disponivel para o lugar atual
     }
     printf("Qual opção?\n");
     scanf("%d",&OpcaoEscolhida);
     return OpcaoEscolhida; //retorna para o ponteiro de função
}

void OpcoesCasa(int Selecionada,PERSONAGEM *Jgdr) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case SALVAR:
          printf("Encerrando\n");
          exit(0);
          break;
     case MEXER_BARALHO:
          printf("Baralho lacrado\n");
          break;
     }
}
void OpcoesDungeon(int Selecionada,PERSONAGEM *Jgdr) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case ENTRAR_DUNGEON:
          printf("Cada placa aponta para um canto diferente.\n");
          EntrarDungeon(Jgdr);
          break;
     }
}

void EntrarDungeon(PERSONAGEM *Plyr) {
     int CaminhoDungeon = 0;
     int DungeonsAbertas[TEMPLOS] = {ABERTO,FECHADO,FECHADO,FECHADO};

     char NomePlaca[20] = "\0";
     char OutraParteNome[TEMPLOS][10] = {
          "do Vento","do Bosque","da Água","do Fogo",
     };
     for (int i = 0; i < TEMPLOS; i++) {
          strcpy(NomePlaca,"Templo "); //Preenche/reseta a string para impressão
          strcat(NomePlaca,OutraParteNome[i]); //concatena o sufixo
          printf("%d. %20s\n",i+1,NomePlaca); //Imprime o nome completo
     }
          do {
               scanf("%d",&CaminhoDungeon);
               if (!(CaminhoDungeon > 0 && CaminhoDungeon <=TEMPLOS)) printf("Opção inválida\n");

          } while (!(CaminhoDungeon > 0 && CaminhoDungeon <=TEMPLOS)); //Escaneia até liberar um número válido
          printf("Você seguiu o caminho até chegar na entrada da masmorra.\n");
          if (DungeonsAbertas[CaminhoDungeon-1] == ABERTO) { //Checa se o lugar foi liberado
               printf("Cheguei à dungeon\n"); 
               ExplorarDungeon(CaminhoDungeon,Plyr); //Comando para ativar a dungeon
          } else {
               printf("Você caminha e encontra o templo trancado... não há muito o que fazer por agora\n");
               printf("Uma caminhada de volta, criticando o código de quem não pensou um jeito melhor de alertar o jogador, depois; você volta à placa\n");
          }
}

void OpcoesPraca(int Selecionada,PERSONAGEM *Jgdr) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case CONVERSAR:
          printf("Os NPCs corromperam, tentativas de falar com eles podem não ocasionar coisas boas...\n");
          break;
     }
}

void OpcoesTaberna(int Selecionada,PERSONAGEM *Jgdr) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case CONVERSAR:
          printf("Não é um encapuzado, o NPC se fundiu a cortina quando se corrompeu. Não dá para interagir com ele.\n");
          break;
     case LOJISTA:
          printf("O lojista está corrompido... Comprar algo com código duvidoso não parece uma escolha muito sábia.\n");
          break;
     }
}



void TrocarDeLugar(int ID_Atual) {
     int CaminhoEscolhido = CONEXAO_NULA;
     int MaxCaminhos = 0;

     LOCAL *Caminhos[MAXDESTINOS-1] = {NULL};
     for (int i = 0; i < MAXDESTINOS-1; i++) {
          if (LocalAtual->ConexaoID[i] != CONEXAO_NULA) { //Usa do ID previamente copiado para fazer Caminhos apontar para os caminhos válidos e possiveis
               Caminhos[i] = &Locais[LocalAtual->ConexaoID[i]];
          }
     }

     for (int i = 0; i < MAXDESTINOS-1;i++) {
          if (LocalAtual->ConexaoID[i] != CONEXAO_NULA) {
               printf("%d. %30s\n",i+1,Caminhos[i]->DadosLocal.Nome);   //imprime caminhos não nulos
               MaxCaminhos++;
          } 
     }
     printf("Para onde?\n");
     do {
          scanf("%d",&CaminhoEscolhido);
          if (!(CaminhoEscolhido > 0 && CaminhoEscolhido <= MaxCaminhos)) { //faz o jogador apenas escolher um caminho válido
               printf("Opção inválida\n");
          }
          
     } while (!(CaminhoEscolhido > 0 && CaminhoEscolhido <= MaxCaminhos));
     LocalAtual = Caminhos[CaminhoEscolhido-1]; //passa o local escolhido

}

/* OPÇOES INICIAIS
1. Funções de dentro da casa
     -Salvar
     -Mudar baralho
2. Sair da casa
     -Taberna
     -Dungeons
     -Praça
*/

/* SALVAMENTO
//Passa a struct SAVE pra um arquivo, usa o tipo W pra isso
//Pede confirmação
*/

/*CARREGAMENTO
Menu inicial, dá a opção Jogo novo ou Continuar
*/

/*TROCAR BARALHO
Pede pra adicionar ou remover
-Add:
     -Abre as cartas não equipadas
     -Pergunta qual quer adicionar
     -Ela entra no fim do deck
     -Ela sai da lista de não equipadas
     -Pergunta se quer adicionar outra
- Remove:
     -Abre o deck inteiro
     -Pergunta qual remover
     -Carta é desconectada
     -Entra na pilha de cartas desconectadas
     -Pergunta se quer tirar mais

*/

