#include <stdio.h>
#include <string.h>
#include "cidade.h"

int main() {
     int LocalAtual = 0;
     for (int i = 0; i < 3; i++) {
          OpcoesDeCadaLocal[LocalAtual](OpcoesLocal(LocalAtual)); //Ponteiro de função que acessa função referente ao local, imprime o que tem de lá e escolhe 
     }
     LocalAtual++;
     OpcoesDeCadaLocal[LocalAtual](OpcoesLocal(LocalAtual));
     //Imprime as opções pra ele
     //Escaneia o input
     //Valida a opção
}

int OpcoesLocal(int Local) {
     int OpcaoEscolhida = 0;
     printf("---\n");
     char Opcoes[MAXDESTINOS][MAXOPCOES_MAIOR][25] = {{"Sair para a cidade","Salvar","Mudar baralho"},{"Voltar para a cidade","Entrar em uma dungeon","\0"},{"\0"},{"\0"}}; //Salva toda as opçoes disponiveis por lugar

     for (int i = 0; i < OpcoesQtd[Local];i++) {
          if (strcmp(Opcoes[Local][i],"\0") != 0) printf("%d. %25s\n",i+1,Opcoes[Local][i]);
     }
     printf("Qual opção?\n");
     scanf("%d",&OpcaoEscolhida);
     return OpcaoEscolhida; //retorna para o ponteiro de função
}

void OpcoesCasa(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          printf("A porta tá fechada\n");
          break;
     case SALVAR:
          printf("Save não implementado\n");
          break;
     case MEXER_BARALHO:
          printf("Baralho lacrado\n");
          break;
     }
}
void OpcoesDungeon(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          printf("Voltaste");
          break;
     case ENTRAR_DUNGEON:
          printf("Qual dungeon?\n");
          break;
     }
}

void OpcoesPraca(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          printf("Voltaste");
          break;
     case ENTRAR_DUNGEON:
          printf("Qual dungeon?\n");
          break;
     }
}

void OpcoesTaberna(int Selecionada) {
     switch (Selecionada) {
     case SAIR_LOCAL:
          printf("Voltaste");
          break;
     case ENTRAR_DUNGEON:
          printf("Qual dungeon?\n");
          break;
     }
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