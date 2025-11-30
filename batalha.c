#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "batalha.h"
#include "structs.h"


//funcoes de efeito overtime
void aplicaEfeito(efeito efeito,personagem *personagem){ //aplica um efeito em algm
    int i=0;
    while(personagem->efeitos[i].contador > 0)i++; //encontra um slot do arrayy de efeitos livre para aplicar
    personagem->efeitos[i]=efeito; //aplica
    if(efeito.tipo==STATMOD){
        personagem->stat[efeito.stat]+=efeito.valor;//caso mude algum stats aplica a mudanca
    }
} 

void causaEfeito(personagem *player){ //causa o efeito de um efeito
    for(int i=0;i<10;i++){  //percorre todos os efeitos do personagem
        switch(player->efeitos[i].tipo){ //decide se eh dano ou stat
              case DANO:
                if(player->efeitos[i].contador>0){ //se for dano e estiver ativo: contador>0 executa o dano
                player->hpatual-=player->efeitos[i].valor; //aplica o dano
                printf("%s %s %d de vida devido ao efeito de %s\n",player->nome,
                player->efeitos[i].valor>0? "perdeu":"ganhou", player->efeitos[i].valor, player->efeitos[i].nome);
                }
                break;
              case STATMOD: //caso for modificacao de status verifica se acabou ou n
                  if(player->efeitos[i].contador==0){ //se acabou ele retira o stat
                      player->stat[player->efeitos[i].stat]-=player->efeitos[i].valor;//retira o stat
                      printf("%s perdeu o efeito de %s\n",player->nome, player->efeitos[i].nome);
                  }
                  break;
                }
                player->efeitos[i].contador--; //atualiza o contador do efeito
        }
}

void funcaoefeito(personagem *player,personagem *inimigo[],int qtdinimigos){ //funcao q sera usada no final do turno
    causaEfeito(player); //casusa no player
    for(int i=0;i<qtdinimigos;i++){ //causa em todos os inimigues
        causaEfeito(inimigo[i]);
    }
}
//funcoes de efeito overtime




//funcoes de calculo de dano
int comboflat(carta carta[3]){ //tabela de bonus de dano em combos
    int tabelaflat[3][3][3]=
    {0};//tem q criar ainda
    return tabelaflat[carta[0].tipo][carta[1].tipo][carta[2].tipo];
}

float comboporcento(carta carta[3]){ //tabela de multiplicador de dano em combos
    float tabelaporcento[3][3][3]=
    {0};//tem q criar ainda
    return tabelaporcento[carta[0].tipo][carta[1].tipo][carta[2].tipo];
}

int decidetipo(carta carta[3]){ //devolve o tipo predominante do combo
    int contagem[3]={0},tipo=0;
    for(int i=0;i<3;i++){
        contagem[carta[i].tipo]++;
    }
    for(int i=1;i<=2;i++){
        if(contagem[i]>contagem[tipo])tipo=i;
    }
    return tipo;
}

void causardano(int danofis,int danomag,int cura,personagem *atacante,personagem *defensor){ //atualiza a vida de quem sofreu o ataque
    defensor->hpatual-=danofis+danomag;
    atacante->hpatual+=cura;
}

void dano(carta carta[3],personagem *atacante,personagem *defensor){ //calcula o dano
    int danofis=0,danomag=0,cura=0,tipo;
    float multfis=1.0,multmag=1.0,multcura=1.0;
    int bonusfis=0,bonusmag=0,bonuscura=0;
    for(int i=0;i<3;i++){ //guarda o valor de todas as cartas
        switch(carta[i].tipo){
            case ATAQUEFIS:
                danofis+=carta[i].valor;
                break;
            case ATAQUEMAG:
                danomag+=carta[i].valor;
                break;
            case CURA:
                cura+=carta[i].valor;
                break;
        }
    }
    tipo=decidetipo(carta); // decide o tipo predominante
    switch(tipo){ //diz o multiplicador e bonus do tipo predominante
        case ATAQUEFIS:
            multfis=comboporcento(carta);
            bonusfis=comboflat(carta);
            break;
        case ATAQUEMAG:
            multmag=comboporcento(carta);
            bonusmag=comboflat(carta);
            break;
        case CURA:
            multcura=comboporcento(carta);
            bonuscura=comboflat(carta);
            break;
    }
    danofis=((danofis+bonusfis+atacante->stat[ATQFIS])*multfis)-defensor->stat[DEFFIS]; //calculo o danofis final
    danomag=((danomag+bonusmag+atacante->stat[ATQMAG])*multmag)-defensor->stat[DEFMAG]; //calculo o danomag final
    cura=(cura+bonuscura)*multcura;//calculo de cura final

    causardano(danofis,danomag,cura,atacante,defensor);//atualiza as vidas dos combatentes
}
//funcoes de calculoo de dano