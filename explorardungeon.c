
#include <stdio.h>
#include <string.h>
#include <direct.h>
#include "explorardungeon.h"

int main() {
     int Dungeon;
     scanf("%d",&Dungeon);
     InicializarDungeon(Dungeon);
     return 0;
}

int InicializarDungeon(int DungeonEscolhida) {
     FILE *ArqPtr = NULL;
     char buffer[256];

     switch (DungeonEscolhida) {
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
     for(int i = 0; i < LINHAS; i++) {
          for(int j = 0; j < COLUNAS; j++) {
               // Pula a linha "Sala x,y"
               if(fgets(buffer, sizeof(buffer), ArqPtr) == NULL) break;
               
               lerSalaDoArquivo(ArqPtr, &DungeonAtual[i][j]);
          }
     }
     return 0;
}


void lerSalaDoArquivo(FILE *arquivo, MODELO_SALA_DUNGEON *sala) {
     char buffer[256];
     
     // Linha 1: descrição
     fgets(sala->DescricaoSala, sizeof(sala->DescricaoSala), arquivo);
     sala->DescricaoSala[strcspn(sala->DescricaoSala, "\n")] = '\0';
     
     // Linha 2: 4 direções separadas por vírgula
     fgets(buffer, sizeof(buffer), arquivo);
     sscanf(buffer, "%[^,], %[^,], %[^,], %s", 
          sala->Direcoes[NORTE], 
          sala->Direcoes[LESTE], 
          sala->Direcoes[SUL], 
          sala->Direcoes[OESTE]);
     
     // Remover espaços extras
     for(int i = 0; i < 4; i++) {
          if(sala->Direcoes[i][0] == ' ') 
               strcpy(sala->Direcoes[i], sala->Direcoes[i] + 1);
          sala->Direcoes[i][strcspn(sala->Direcoes[i], "\n")] = '\0';
     }
     
     // Linha 3: tipo especial e lugar válido
     fscanf(arquivo, "%d %d", &sala->Tipo_Especial, &sala->Lugar_Valido);
     fgets(buffer, sizeof(buffer), arquivo); // Consome a quebra de linha
}