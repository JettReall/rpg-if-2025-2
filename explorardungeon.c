
#include <stdio.h>
#include <string.h>
#include <direct.h>
#include "explorardungeon.h"


int main() {
     AbrirArquivoDungeon(VENTO); //USa de um switch para abrir o arquivo correto
     /*
     
     printf("----------------------Resultado final:-----------------------\n");
     for(int i = 0; i < LINHAS; i++) {
          for(int j = 0; j < COLUNAS; j++) {
               
                    printf("%s\n%s\n%s\n%s\n---\n",
                    DungeonAtual[i][j].Direcoes[NORTE], 
                    DungeonAtual[i][j].Direcoes[LESTE], 
                    DungeonAtual[i][j].Direcoes[SUL], 
                    DungeonAtual[i][j].Direcoes[OESTE]);
                    
          }
     }
     
     */
     do {
          SalaAtual = &DungeonAtual[Coordenadas[X]][Coordenadas[Y]]; //Passa as informações da sala que ele entra
          //Encontro de batalha
          InteragirEmSala(); //Envolve a parte da sala já vazia, escolher uma opção do que fazer na sala
     } while (1);//A condição do While será o Hp do boss, mas como não foi integrado ainda, considerei o 1 para teste
     
     return 0;
}

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
               }
                    //Pega a coordenada da entrada
               for(int k = 0; k < max_inimigo_Dungeon; k++) {
                    DungeonAtual[i][j].inimigos[k] = InimigoVazio;
                    //copia para os locais de inimigos, uma struct de inimigo vazio
               }
          }  
     }
}
int InicializarDungeon(int DungeonEscolhida) {
     switch (DungeonEscolhida) { //De acordo com o valor dungeon passada pra ele, ele abre o arquivo da dungeon
     case BOSQUE:
     ArqPtr = fopen("TemploBosqueMapa.txt","r");
     break;
     case VENTO:
     ArqPtr = fopen("TemploVentoMapa.txt","r");
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
     printf("%s\n",SalaAtual->DescricaoSala);
     printf("O que deseja fazer?\n");
     //ImprimirOpcoes();
     scanf("%d",&OpcaoSelecionada);
     ValidarOpcaoSelecionada(&OpcaoSelecionada);
  
}


void ValidarOpcaoSelecionada(int *Selecionada) {
     printf("Validando\n");
        switch (*Selecionada) {
          case CAMINHAR:
               Andar();
               break;
          case INTERAGIR:
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

void Andar() {
     char DirecoesNome[DIRECAO][7] = {"Norte","Leste","Sul","Oeste"};
     int DirecaoValorCalculo[DIRECAO] = {-COLUNAS,1,COLUNAS,-1};
     int CalculoCoordX[DIRECAO] = {-1,0,1,0};
     int CalculoCoordY[DIRECAO] = {0,1,0,-1};
     int Validados[DIRECAO] = {0};
     int DirecaoEscolhida;

     MODELO_SALA_DUNGEON *ChecagemDeCaminhada = NULL; //ponteiro para checagem se  direção é válida
     for (int i = 0; i < DIRECAO; i++) {
          ChecagemDeCaminhada = SalaAtual; //Endereça a sala atual
          ChecagemDeCaminhada+=DirecaoValorCalculo[i]; //Usa da aritmetica de ponteiros para dar saltos para ir para um adjacente. Ex.: Pro sul, o ponteiro salta exatamente para o que está abaixo de sala atual (Ptr+QtdColunas)
          if (ChecagemDeCaminhada->Lugar_Valido == 1 && strcmp(SalaAtual->Direcoes[i],"x") != 0) {
               printf("%d.%8s: %30s\n",i,DirecoesNome[i],SalaAtual->Direcoes[i]); // Imprimir acessos para salas válidas
               Validados[i] = 1;
          };
     }
     printf("Para onde ir?\n");
     do {
          scanf("%d",&DirecaoEscolhida);
          if (Validados[DirecaoEscolhida] == 1) {
               Coordenadas[X] += CalculoCoordX[DirecaoEscolhida]; //Passa as coordenadas para ser setado no próximo loop
               Coordenadas[Y] += CalculoCoordY[DirecaoEscolhida];
          } else {
               printf("Caminho Inválido. Digite uma opção válida\n");
          }
     } while (Validados[DirecaoEscolhida] != 1);
     
}





