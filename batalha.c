#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "batalha.h"
#include "structs.h"


//funcoes de efeito overtime
void aplicaEfeito(EFEITO Efeito,PERSONAGEM *Personagem){ //aplica um efeito em algm
    int i=0;
    while(Personagem->Efeitos[i].Contador > 0)i++; //encontra um slot do arrayy de efeitos livre para aplicar
    Personagem->Efeitos[i]=Efeito; //aplica
    if(Efeito.Tipo==STATMOD){
        Personagem->Stat[Efeito.Stat]+=Efeito.Valor;//caso mude algum stats aplica a mudanca
    }
} 

void CausaEfeito(PERSONAGEM *Player){ //causa o efeito de um efeito
    for(int i=0;i<10;i++){  //percorre todos os efeitos do personagem
        switch(Player->Efeitos[i].Tipo){ //decide se eh dano ou stat
              case DANO:
                if(Player->Efeitos[i].Contador>0){ //se for dano e estiver ativo: contador>0 executa o dano
                Player->HpAtual-=Player->Efeitos[i].Valor; //aplica o dano
                printf("%s %s %d de vida devido ao efeito de %s\n",Player->Nome,
                Player->Efeitos[i].Valor>0? "perdeu":"ganhou", Player->Efeitos[i].Valor, Player->Efeitos[i].Nome);
                }
                break;
              case STATMOD: //caso for modificacao de status verifica se acabou ou n
                  if(Player->Efeitos[i].Contador==0){ //se acabou ele retira o stat
                      Player->Stat[Player->Efeitos[i].Stat]-=Player->Efeitos[i].Valor;//retira o stat
                      printf("%s perdeu o efeito de %s\n",Player->Nome, Player->Efeitos[i].Nome);
                  }
                  break;
                }
                Player->Efeitos[i].Contador--; //atualiza o contador do efeito
        }
}

void FuncaoEfeito(PERSONAGEM *Player,PERSONAGEM *Inimigo[],int QtdInimigos){ //funcao q sera usada no final do turno
    CausaEfeito(Player); //casusa no player
    for(int i=0;i<QtdInimigos;i++){ //causa em todos os inimigues
        CausaEfeito(Inimigo[i]);
    }
}
//funcoes de efeito overtime




//funcoes de calculo de dano
int ComboFlat(CARTA Carta[3]){ //tabela de bonus de dano em combos
    int TabelaFlat[3][3][3]=
    {0};//tem q criar ainda
    return TabelaFlat[Carta[0].Tipo][Carta[1].Tipo][Carta[2].Tipo];
}

float comboporcento(CARTA Carta[3]){ //tabela de multiplicador de dano em combos
    float tabelaporcento[3][3][3]=
    {0};//tem q criar ainda
    return tabelaporcento[Carta[0].Tipo][Carta[1].Tipo][Carta[2].Tipo];
}

int decidetipo(CARTA carta[3]){ //devolve o tipo predominante do combo
    int Contagem[3]={0},tipo=0;
    for(int i=0;i<3;i++){
        Contagem[carta[i].Tipo]++;
    }
    for(int i=1;i<=2;i++){
        if(Contagem[i]>Contagem[tipo])tipo=i;
    }
    return tipo;
}

void CausarDano(int DanoFis,int DanoMag,int Cura,PERSONAGEM *Atacante,PERSONAGEM *Defensor){ //atualiza a vida de quem sofreu o ataque
    Defensor->HpAtual-=DanoFis+DanoMag;
    Atacante->HpAtual+=Cura;
}

void Dano(CARTA Carta[3],PERSONAGEM *Atacante,PERSONAGEM *Defensor){ //calcula o dano
    int danofis=0,danomag=0,cura=0,tipo;
    float multfis=1.0,multmag=1.0,multcura=1.0;
    int bonusfis=0,bonusmag=0,bonuscura=0;
    for(int i=0;i<3;i++){ //guarda o valor de todas as cartas
        switch(Carta[i].Tipo){
            case ATAQUEFIS:
                danofis+=Carta[i].Valor;
                break;
            case ATAQUEMAG:
                danomag+=Carta[i].Valor;
                break;
            case CURA:
                cura+=Carta[i].Valor;
                break;
        }
    }
    tipo=decidetipo(Carta); // decide o tipo predominante
    switch(tipo){ //diz o multiplicador e bonus do tipo predominante
        case ATAQUEFIS:
            multfis=ComboPorcento(Carta);
            bonusfis=ComboFlat(Carta);
            break;
        case ATAQUEMAG:
            multmag=ComboPorcento(Carta);
            bonusmag=ComboFlat(Carta);
            break;
        case CURA:
            multcura=ComboPorcento(Carta);
            bonuscura=ComboFlat(Carta);
            break;
    }
    danofis=((danofis+bonusfis+Atacante->Stat[ATQFIS])*multfis)-Defensor->Stat[DEFFIS]; //calculo o danofis final
    danomag=((danomag+bonusmag+Atacante->Stat[ATQMAG])*multmag)-Defensor->Stat[DEFMAG]; //calculo o danomag final
    cura=(cura+bonuscura)*multcura;//calculo de cura final

    causardano(danofis,danomag,cura,Atacante,Defensor);//atualiza as vidas dos combatentes
}
//funcoes de calculoo de dano