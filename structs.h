#ifndef STRUCTS_H     // Se STRUCTS_H não está definido
#define STRUCTS_H 

#include "varglobal.h"
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

enum Coordenadas {
    X,
    Y,
};


typedef enum{
    ATAQUEFIS,
    ATAQUEMAG,
    CURA,
    NULO = -1,
}Tipo;

typedef enum {
    NADA,
    BAU,
    ALAVANCA,
    SALA_BOSS,
    ENTRADA,
    OBSTACULO, //Ele nunca entrará numa sala do tipo obstáculo
    SEM_MOB,
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
    DIFICIL,
    MOB_NULO = 4,
}Dificuldade;

typedef enum {
    NORTE,
    LESTE,
    SUL, 
    OESTE,
} DIRECOES;

typedef enum {
    CARREGAR,
    JOGAR,
    DIFICULDADE
}MenuOp;

typedef enum {
    GUERREIRO,
    MAGO,
    SACERDOTE
}MenuClasses;
//-------------------------------------------------------------------------------------------------------------------
//structs:

typedef struct {
    char Nome[50];
    char Descricao[MAX_TAM_DESCRICAO];
    int Stat[7]; //status
    int Custo; //dinheiro
}ITEM;

typedef struct{
    char Nome[50];
    char Descricao[MAX_TAM_DESCRICAO];
    int Tipo,Valor;
}CARTA;

typedef struct NO_BARALHO{ //baralho eh uma lista encadeada
    CARTA Carta;    //carta eh um struct carta
    struct NO_BARALHO *PtrProx;
}NO_BARALHO;


typedef struct{
    int QtdCartaAtual;
    int QtdCartaTotal;
    int QtdCartamaoatual;
}DADOS_BATALHA;

typedef struct {
    char Nome[50];//nome
    int Stat[7];//stats max
    int HpAtual,Xp;//hp atual e xp atual
    int Classe;
}PERSONAGEM;

typedef struct{
    PERSONAGEM DadosPlayer;
    int UltimoSavepoint;
    CARTA Cartas[100];
    int Dificuldade; 
    int Dinheiro;
}SAVE_DADOS;

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
    SKILL_INI Habilidades[MAX_HABILIDADES];
}INIMIGOS;

typedef struct{
    char DescricaoSala[MAX_TAM_DESCRICAO];
    char Direcoes[4][30]; //Norte, Leste, Sul, Oeste
    int Tipo_Especial; //Especial = 0, não é pra voltar nada e outros valores podem ser algo como: 1 = bau, 2 = alavanca...
    int Lugar_Valido; // 0 = Não é possivel Acessar (De forma alguma), 1 = É possivel de ser acessado.
    INIMIGOS inimigos[max_inimigo_sala];//inimigos presentes no quarto
}MODELO_SALA_DUNGEON;

#endif
