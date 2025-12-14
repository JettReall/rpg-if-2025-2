#if !defined(VARGLOBAL_H)
#define VARGLOBAL_H

#define max_inimigo_Dungeon 4  // Nao contabiliza o boss.
#define max_inimigo_sala 4 // Quantia max de inimigo que pode ter por sala.
#define max_array_inimigo 20
#define MAX_TAM_DESCRICAO 200
#define TEMPLOS 4

#define ITEM_VAZIO {"\0","\0",{0},0}



enum Ativacao{
     NAO_ATIVADO = 0, FECHADO = 0,
     ATIVADO = 1, ABERTO = 1,
};

#endif // VARGLOBAL_H

