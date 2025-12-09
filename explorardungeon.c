
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
          InteragirEmSala();
          //Escolhe direção
          //Entrar em sala
     } while (1);
     
     return 0;
}

void AbrirArquivoDungeon(int Dungeon) {
     char buffer[256];

     InicializarDungeon(Dungeon); //Chama primeiro o incializador para abrir o arquivo correto

     for(int i = 0; i < LINHAS; i++) {
          for(int j = 0; j < COLUNAS; j++) {
               // Pula a linha "Sala x,y"
               if(fgets(buffer, sizeof(buffer), ArqPtr) == NULL) break;
               
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
     for (int i = 0; i < 4; i++) {
          fgets(sala->Direcoes[i],sizeof(sala->Direcoes[i]),arquivo);
          sala->Direcoes[i][strcspn(sala->Direcoes[i], "\n")] = '\0';    
     }

     // Remover espaços extras e quebras de linha
     /*
     for(int i = 0; i < 4; i++) {
          // Remove leading spaces
          char *start = sala->Direcoes[i];
          while (*start == ' ') start++;
          strcpy(sala->Direcoes[i], start);
          
          // Remove trailing spaces and newlines
          int len = strlen(sala->Direcoes[i]);
          while (len > 0 && (sala->Direcoes[i][len-1] == ' ' || sala->Direcoes[i][len-1] == '\n')) {
               sala->Direcoes[i][len-1] = '\0';
               len--;
          }
     */
     
     
     // Linha 3: tipo especial e lugar válido
     fscanf(arquivo, "%d %d", &sala->Tipo_Especial, &sala->Lugar_Valido);
     fgets(buffer, sizeof(buffer), arquivo); // Consome a quebra de linha
}

void InteragirEmSala() {
     SalaAtual = &DungeonAtual[Coordenadas[X]][Coordenadas[Y]]; //Passa as informações da sala que ele entra
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
     for (int i = 0; i < 4; i++) {
          if (strcmp(SalaAtual->Direcoes[i],"\0") != 0) {// Mudar lógica
               printf("%d. %30s\n",i,SalaAtual->Direcoes[i]); // Imprimir acessos
          };
     }
}

