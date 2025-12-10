#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cidade.h"

int main() {
     InicializarCidade();
     LocalAtual = &Locais[CASA];
     while(Loop) {
          printf("%s\n",LocalAtual->DadosLocal.DescricaoLocal);
          OpcoesDeCadaLocal[LocalAtual->DadosLocal.ID](OpcoesLocal(LocalAtual->DadosLocal.ID)); //Ponteiro de função que acessa função referente ao local, imprime o que tem de lá e escolhe 
     }
     //Imprime as opções pra ele
     //Escaneia o input
     //Valida a opção
     
}

void InicializarCidade() {
     int e = 0;
     int Conexoes[MAXDESTINOS][MAXDESTINOS] = {
          {N_CONECTADO,N_CONECTADO,CONECTADO,CONECTADO},
          {N_CONECTADO,N_CONECTADO,CONECTADO,N_CONECTADO},
          {CONECTADO,CONECTADO,N_CONECTADO,CONECTADO},
          {CONECTADO,N_CONECTADO,CONECTADO,N_CONECTADO},
     };
     int LocalInicalizando = 0;

     //printf("Aberto inicializador %d\n", Locais[1].DadosLocal.ID);
     for (int i = 0; i < MAXDESTINOS;i++) {
          e=0;
          //printf("%d %d %d|||",Locais[i].ConexaoID[0],Locais[i].ConexaoID[1],Locais[i].ConexaoID[2]);
          //printf("---\n");
          LocalInicalizando = Locais[i].DadosLocal.ID;
         // printf("Local atual: %s\n",Locais[LocalInicalizando].DadosLocal.Nome);
          for (int k = 0; k < MAXDESTINOS; k++) {
               //printf("Checando... %d\n",k);
               if (Conexoes[LocalInicalizando][k] == CONECTADO) {
                    //printf("Há um conectado: ");
                    if (Locais[i].ConexaoID[e] != CONEXAO_NULA) {
                         e++;
                        // printf("Salto em E; ");
                    }
                    Locais[i].ConexaoID[e] = k;
                   // printf("%d\n",Locais[i].ConexaoID[e]);
               }   
          }
               //printf("Fim de cheagem\n");
               //printf("%d %d %d\n",Locais[i].ConexaoID[0],Locais[i].ConexaoID[1],Locais[i].ConexaoID[2]);
     }

}


int OpcoesLocal(int Local) {
     int OpcaoEscolhida = 0;
     printf("---\n");

     for (int i = 0; i < OpcoesQtd[Local];i++) {
          if (strcmp(LocalAtual->DadosLocal.Opcoes[i],"\0") != 0) printf("%d. %25s\n",i+1,LocalAtual->DadosLocal.Opcoes[i]);
     }
     printf("Qual opção?\n");
     scanf("%d",&OpcaoEscolhida);
     return OpcaoEscolhida; //retorna para o ponteiro de função
}

void OpcoesCasa(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case SALVAR:
          printf("Encerrando\n");
          Loop = 0;
          break;
     case MEXER_BARALHO:
          printf("Baralho lacrado\n");
          break;
     }
}
void OpcoesDungeon(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case ENTRAR_DUNGEON:
          printf("Cada placa aponta para um canto diferente.\n");
          EntrarDungeon();
          break;
     }
}

void EntrarDungeon() {
     int CaminhoDungeon = 0;
     int DungeonsAbertas[TEMPLOS] = {ABERTO,FECHADO,FECHADO,FECHADO};

     char NomePlaca[20] = "\0";
     char OutraParteNome[TEMPLOS][10] = {
          "do Vento","do Bosque","da Água","do Fogo",
     };
     for (int i = 0; i < TEMPLOS; i++) {
          strcpy(NomePlaca,"Templo ");
          strcat(NomePlaca,OutraParteNome[i]);
          printf("%d. %20s\n",i+1,NomePlaca);
     }
          do {
               scanf("%d",&CaminhoDungeon);
          } while (!(CaminhoDungeon > 0 && CaminhoDungeon <=TEMPLOS));
          printf("Você seguiu o caminho até chegar na entrada da masmorra.\n");
          if (DungeonsAbertas[CaminhoDungeon-1] == ABERTO) {
               //ExplorarDungeon(CaminhoDungeon);
               printf("Cheguei à dungeon\n");
          } else {
               printf("Você caminha e encontra o templo trancado... não há muito o que fazer por agora\n");
               printf("Uma caminhada de volta, criticando o código de quem não pensou um jeito melhor de alertar o jogador, depois; você volta à placa\n");
          }
}

void OpcoesPraca(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case CONVERSAR:
          printf("Os NPCs corromperam, tentativas de falar com eles podem não ocasionar coisas boas...\n");
          break;
     }
}

void OpcoesTaberna(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          TrocarDeLugar(LocalAtual->DadosLocal.ID);
          break;
     case CONVERSAR:
          printf("Os que não se corromperam são os desmaiados de tanto beber.\n");
          break;
     case LOJISTA:
          printf("O lojista está corrompido... Comprar algo com código duvidoso não parece uma escolha muito sábia.\n");
          break;
     }
}



void TrocarDeLugar(int ID_Atual) {
     int CaminhoEscolhido = CONEXAO_NULA;

     LOCAL *Caminhos[MAXDESTINOS-1] = {NULL};
     for (int i = 0; i < MAXDESTINOS-1; i++) {
          if (LocalAtual->ConexaoID[i] != CONEXAO_NULA) {
               Caminhos[i] = &Locais[LocalAtual->ConexaoID[i]];
          }
     }

     for (int i = 0; i < MAXDESTINOS-1;i++) {
          if (LocalAtual->ConexaoID[i] != CONEXAO_NULA) {
               printf("%d. %30s\n",i+1,Caminhos[i]->DadosLocal.Nome);  
          } 
     }
     printf("Para onde?");
     do {
          scanf("%d",&CaminhoEscolhido);
          if (!(CaminhoEscolhido > 0 && CaminhoEscolhido < MAXDESTINOS)) {
               printf("Opção inválida\n");
          }
          
     } while (!(CaminhoEscolhido > 0 && CaminhoEscolhido < MAXDESTINOS));
     LocalAtual = Caminhos[CaminhoEscolhido-1];

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

