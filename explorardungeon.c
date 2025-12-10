
#include <stdio.h>
#include <string.h>
#include "explorardungeon.h"


int main() {
     AbrirArquivoDungeon(VENTO); //USa de um switch para abrir o arquivo correto
    
     do {
          printf("-----------%d,%d-----------\n",Coordenadas[X],Coordenadas[Y]);
          SalaAtual = &DungeonAtual[Coordenadas[X]][Coordenadas[Y]]; //Passa as informações da sala que ele entra
          //Encontro de batalha
          InteragirEmSala(); //Envolve a parte da sala já vazia, escolher uma opção do que fazer na sala
     } while (1);//A condição do While será o Hp do boss, mas como não foi integrado ainda, considerei o 1 para teste
     
     return 0;
}

//---------------------------------------------------------------------------------------------------

void AbrirArquivoDungeon(int Dungeon) {
     char buffer[256];

     InicializarDungeon(Dungeon); //Chama primeiro o incializador para abrir o arquivo correto

     for(int i = 0; i < LINHAS; i++) {
          for(int j = 0; j < COLUNAS; j++) {
               // Pula a linha "Sala x,y"
               if(fgets(buffer, sizeof(buffer), ArqPtr) == NULL) break;//Pega a linha descartável do arquivo
               
               lerSalaDoArquivo(ArqPtr, &DungeonAtual[i][j]);
               //Lê a informação de cada sala, primeiro as colunas, depois as linhas
               
               if(DungeonAtual[i][j].Tipo_Especial == ENTRADA) {
                         Coordenadas[X] = i;
                         Coordenadas[Y] = j;
               } //Pega a coordenada da entrada

               for(int k = 0; k < max_inimigo_Dungeon; k++) {
                    DungeonAtual[i][j].inimigos[k] = InimigoVazio;
                    //copia para os locais de inimigos, uma struct de inimigo vazio
               }
          }  
     }
}
int InicializarDungeon(int DungeonEscolhida) {
     switch (DungeonEscolhida) { //De acordo com o valor dungeon passada pra ele, ele abre o arquivo da dungeon
     case VENTO:
          ArqPtr = fopen("TemploVentoMapa.txt","r");
          AlavancasQtd = ALAVANCAS_VENTO;
          break;
     case BOSQUE:
          ArqPtr = fopen("TemploBosqueMapa.txt","r");
          break;
     case AGUA:
          ArqPtr = fopen("TemploAguaMapa.txt","r");
          break;
     case FOGO:
          ArqPtr = fopen("TemploFogoMapa.txt","r");
          break;
}

     if (ArqPtr == NULL) {
          printf("Erro ao abrir arquivo");
          return 1;
     }
     strcpy(DescDoObstaculo,DescParaObstaculo[DungeonEscolhida-1]); //copia a mensagem de obstáculo da dungeon
     for (int i =0; i < MAX_ALAVANCAS;i++) {
          AlavancasDungeon[i] = Alavancas[DungeonEscolhida-1][i];
     } //preenche as salas de alavanca e aponta para os obstaculos
}


void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala) {
     char buffer[256] = "\0";
     //Ele lÊ sala a sala, uma por uma
     // Linha 1: descrição
     fgets(sala->DescricaoSala, sizeof(sala->DescricaoSala), arquivo);
     sala->DescricaoSala[strcspn(sala->DescricaoSala, "\n")] = '\0';
     //Lê e limpa o buffer do \n no fim
     
     // Linha 2: 4 direções separadas por vírgula
     for (int i = 0; i < DIRECAO; i++) {
          fgets(sala->Direcoes[i],sizeof(sala->Direcoes[i]),arquivo);
          sala->Direcoes[i][strcspn(sala->Direcoes[i], "\n")] = '\0';    
     }
  
     // Linha 3: tipo especial e lugar válido
     fscanf(arquivo, "%d %d", &sala->Tipo_Especial, &sala->Lugar_Valido);
     fgets(buffer, sizeof(buffer), arquivo); // Consome a quebra de linha
}

void InteragirEmSala() {
     int OpcaoSelecionada = 0;
     printf("%s\n",SalaAtual->DescricaoSala); //Imprime a descrição
     printf("O que deseja fazer?\n");
     ImprimirOpcoes();
     scanf("%d",&OpcaoSelecionada);
     ValidarOpcaoSelecionada(&OpcaoSelecionada);
  
}

void ImprimirOpcoes() {
     printf("1. Caminhar pela Dungeon\n");
     if (SalaAtual->Tipo_Especial == BAU || SalaAtual->Tipo_Especial == ALAVANCA) {
          printf("2. Interagir");
          if (SalaAtual->Tipo_Especial == BAU) {
               printf("(Abrir baú)\n");
          } else if (SalaAtual->Tipo_Especial == ALAVANCA) {
               printf("(Puxar alavanca)\n");
          }
     };
}


void ValidarOpcaoSelecionada(int *Selecionada) {
        switch (*Selecionada) {
          case CAMINHAR:
               Andar();
               break;
          case INTERAGIR:
               if ((SalaAtual->Tipo_Especial == BAU || SalaAtual->Tipo_Especial == ALAVANCA)) {
                    EfeitoDeSala(SalaAtual->Tipo_Especial);
               } else {
                    printf("Não há nada para interagir\n");
               }
               
               break; 
          default:
               while (1) { //Só libera após um valor válido ser escrito, até lá, ficará em loop para evitar erros
                    if (!(*Selecionada > 0 && *Selecionada <= MAX_OPCOES_EXPLORAR)) {
                         printf("Inválido. Digite um valor válido\n");
                         scanf("%d",Selecionada);
                    } else {break;};
               }
          }
}

void EfeitoDeSala(int TipoDeSala) {
     if (TipoDeSala == ALAVANCA) {
          printf("Puxando alvanca\n");
         for (int i = 0; i < AlavancasQtd; i++) { //Checa as salas de alavanca, quando acha a sala atual, libera a passagem conectada
               if(AlavancasDungeon[i].Alavanca_X == Coordenadas[X] && AlavancasDungeon[i].Alavanca_Y == Coordenadas[Y]) { //checa as coordenadas e acha as iguais da sala atual
                         printf("Click\n");
                    if (AlavancasDungeon->Ativada==ATIVADO) {
                         printf("Alavanca já puxada\n"); //imprime caso já tenha sido ativada, se o player puxar mais de uma vez
                    } else {
                         AlavancasDungeon->SalaConectada->Tipo_Especial = SEM_MOB; //Muda no mapa DungeonAtual o status da sala para uma sala sem mobs, que é possivel de andar
                         printf("Você escuta um barulho de longe.\n");
                         AlavancasDungeon->Ativada = ATIVADO;
                    }
               }
         } 
     }
}

void Andar() {
     char DirecoesNome[DIRECAO][7] = {"Norte","Leste","Sul","Oeste"};
     int DirecaoEscolhida;
     //Variáveis para cálculos
     const int DirecaoValorCalculo[DIRECAO] = {-COLUNAS,1,COLUNAS,-1};
     const int CalculoCoordX[DIRECAO] = {-1,0,1,0};
     const int CalculoCoordY[DIRECAO] = {0,1,0,-1};
     int Validados[DIRECAO] = {0};
     char VesselParaDescDirecao[40] = "\0";
     MODELO_SALA_DUNGEON *ChecagemDeCaminhada = NULL; //ponteiro para checagem se  direção é válida

     //Checa se o local é válido para ir
     for (int i = 0; i < DIRECAO; i++) {
          ChecagemDeCaminhada = SalaAtual; //Endereça a sala atual
          ChecagemDeCaminhada+=DirecaoValorCalculo[i]; //Usa da aritmetica de ponteiros para dar saltos para ir para um adjacente. Ex.: Pro sul, o ponteiro salta exatamente para o que está abaixo de sala atual (Ptr+QtdColunas)
          if (ChecagemDeCaminhada->Lugar_Valido == 1 && strcmp(SalaAtual->Direcoes[i],"x") != 0) {
               strcpy(VesselParaDescDirecao,SalaAtual->Direcoes[i]);
               if (ChecagemDeCaminhada->Tipo_Especial == OBSTACULO) {
                    strcat(VesselParaDescDirecao,"(Barrado)");//Se o caminho der na sala com obstáculo, concatena esta parte para alertar o jogador. Sai quando ativam a alavanca
                    Validados[i] = OBSTACULO;
               } else {Validados[i] = VALIDO;}
               printf("%d.%8s: %40s\n",i,DirecoesNome[i],VesselParaDescDirecao); // Imprimir acessos para salas válidas
          };
     }

     printf("Para onde ir?\n");
     do {
          scanf("%d",&DirecaoEscolhida);
          if (Validados[DirecaoEscolhida] == VALIDO) {
               Coordenadas[X] += CalculoCoordX[DirecaoEscolhida]; //Passa as coordenadas para ser setado no próximo loop
               Coordenadas[Y] += CalculoCoordY[DirecaoEscolhida];
                    if ((Coordenadas[X] < 0 || Coordenadas[X] > COLUNAS) || (Coordenadas[Y] < 0 || Coordenadas[Y] > LINHAS)) {
                         Coordenadas[X] -= CalculoCoordX[DirecaoEscolhida];
                         printf("Nao pode ir nessa direção.\n");
                    }; //Comando para evitar "Out of Bounds"

          } else if (Validados[DirecaoEscolhida]== OBSTACULO){
               printf("Não dá para passar por aqui\n");
               printf("%s\n",DescDoObstaculo); //Descrição passada no ato de leitura do arquivo

          } else {
               printf("Caminho Inválido. Digite uma opção válida\n");
          }
     } while (Validados[DirecaoEscolhida] != VALIDO);
     
}





