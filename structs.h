#ifndef structs_H
#define structs_H
//enuns:
typedef enum {
    HPMAX,
    DEFFIS,
    DEFMAG,
    SPEED,
    ATQFIS,
    ATQMAG,
    NIVEL
}Stats;


typedef enum{
    ATAQUEFIS,
    ATAQUEMAG,
    CURA,
}Tipo;

typedef enum {
    DANO,
    STATMOD
}Efeito_Tipos;

typedef enum {
    NADA,
    BAU,
    ALAVANCA,
    SALA_BOSS
}Especiais;

typedef enum {
    INVALIDO,
    VALIDO
}Valido;

typedef enum {
    VENTO = 1,
    BOSQUE,
    AGUA,
    FOGO,
}Dungeon;

typedef enum {
    BOSS,
    FACIL,
    MEDIO,
    DIFICIL
}Dificuldade;


//-------------------------------------------------------------------------------------------------------------------
//structs:

typedef struct {
    char Nome[50];
    char Descricao[200];
    int Stat[7]; //status
    int Custo; //dinheiro
}ITEM;

typedef struct{
    char Nome[50];
    char Descricao[200];
    int Tipo,Valor;
}CARTA;

typedef struct {  //efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
    char Nome[50];
    int Tipo,Valor,Stat,Contador;
}EFEITO;

typedef struct NO_BARALHO{ //baralho eh uma lista encadeada
    CARTA Carta;    //carta eh um struct carta
    struct NO_BARALHO *PtrProx;
}NO_BARALHO;

typedef struct{
    int UltimoSavepoint;
    CARTA Cartas[100];
    int Dificuldade; //Facil = 5, Medio = 10, Dificil = 15;
    int Dinheiro;
}SAVE_DADOS;

typedef struct {
    char Nome[50];//nome
    int Stat[7];//stats max
    int HpAtual,Xp;//hp atual e xp atual
    NO_BARALHO *Baralho; //baralho lista encadeada
    ITEM Equipados[2]; //equipados:: quantidade ainda a decidir
    ITEM Inventario[6];//itens guardados quantidade ainda a decidir
    EFEITO Efeitos[10];//efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
}PERSONAGEM;

typedef struct{
    char Nome[50];
    ITEM Inventario[20];
}NPC;

typedef struct{
    char Nome[30];
    int Tipo, Valor;
}SKILL_INI;

typedef struct{
    char Nome[50];//nome
    int Stat[7];//stats max
    int HpAtual,Xp;//hp atual e xp atual
    ITEM Equipados[2]; //equipados:: quantidade ainda a decidir
    EFEITO Efeitos[10];//efeitos overtime ex: bleed, poison, buff de dano, buff de def etc
    SKILL_INI Habilidades[2];
}INIMIGOS;

typedef struct{
    char Nome[4][30];
    char Direção[4]; //possibilidades de caminhos q o player pode ir, começa de cima, sentido horario.
    Especiais Tipo_Especial; //Especial = 0, não é pra voltar nada e outros valores podem ser algo como: 1 = bau, 2 = alavanca...
    Valido Lugar_Valido; // 0 = Não é possivel Acessar (De forma alguma), 1 = É possivel de ser acessado.
    INIMIGOS inimigos[4];//inimigos presentes no quarto
}MODELO_SALA_DUNGEON;

#endif