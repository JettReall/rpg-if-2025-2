#if !defined(VARGLOBAL_H)
#define VARGLOBAL_H

#define max_inimigo_Dungeon 4  // Nao contabiliza o boss.
#define max_inimigo_sala 4 // Quantia max de inimigo que pode ter por sala.
#define TOTAL_INIMIGOS 20
#define DIFICULDADES 3
#define CHANCE_TOTAL_SPAWN 20
#define MAX_TAM_DESCRICAO 200
#define TEMPLOS 4
#define modificador 5
#define MAX_HABILIDADES 2
#define LINHAS 6
#define COLUNAS 6
#define TOTAL_SALAS (LINHAS * COLUNAS)
#define COMPRA_POR_TURNO 2
#define TAMANHO_DECK 12
#define ALERTA_FIM_DE_PILHA 3
#define MAX_CLASSES 3
#define MAX_STATS 7
#define MAX_TIPO_CARTA 3
#define CARTAS_CADA_CAT 2

#define ITEM_VAZIO {"\0","\0",{0},0}



enum Ativacao{
     NAO_ATIVADO = 0, FECHADO = 0,
     ATIVADO = 1, ABERTO = 1,
};

#endif // VARGLOBAL_H

