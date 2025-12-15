// varglobal.c
#include <stdlib.h>
#include "varglobal.h"
#include "structs.h"
// --- Variáveis Globais de Combate e Baralho (Dados Baralho) ---

// Definição da variável de controle do baralho/mão
// Nota: Os valores de inicialização (TAM_BARALHO_INICIAL, etc.) vêm de varglobal.h



// --- Variáveis Globais da Dungeon (Exploração) ---

// Dungeon atual (matriz de salas)
MODELO_SALA_DUNGEON DungeonAtual[LINHAS][COLUNAS] = {0};

// Ponteiro para a sala atual onde o jogador está
MODELO_SALA_DUNGEON *SalaAtual = NULL;

// Ponteiro para a sala do Boss (usado em criardungeons.c)
MODELO_SALA_DUNGEON *SalaBoss = NULL; // Definição de 'SalaBoss'

// Flag de saída da Dungeon (resetada no início de ExplorarDungeon)
int FlagSaida = NAO_ATIVADO; // Definição de 'FlagSaida'

// Coordenadas [X, Y] do jogador na Dungeon (resetadas no início de ExplorarDungeon)
int Coordenadas[2] = {0, 0}; // Definição de 'Coordenadas'


// --- Variáveis Globais de Jogo/Save ---



