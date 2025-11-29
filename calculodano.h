#include <stdio.h>
#include <stdlib.h>


typedef enum{
    ATAQUEFIS,
    ATAQUEMAG,
    CURA,
}Tipo;

typedef struct{
    char nome[50];
    char descricao[200];
    int tipo,valor;
}carta;

typedef struct {
    char nome[50];
    int hpatual,hpmax,deffis,defmag,speed,atqfis,atqmag,nivel,xp; //status
    nobaralho *baralho;
    item equipamentos[2]; //equipados
    item inventario[6];
    int coordenada[2];
    int savepoint; //numero do ultimo checkpoint
    buff buffs[10];
}personagem;

int comboflat(carta carta[3]){
    int tabelaflat[3][3][3]=
    {0};//tem q criar ainda
    return tabelaflat[carta[0].tipo][carta[1].tipo][carta[2].tipo];
}

float comboporcento(carta carta[3]){
    float tabelaporcento[3][3][3]=
    {0};//tem q criar ainda
    return tabelaporcento[carta[0].tipo][carta[1].tipo][carta[2].tipo];
}

int decidetipo(carta carta[3]){
    int contagem[3]={0},tipo=0;
    for(int i=0;i<3;i++){
        contagem[carta[i].tipo]++;
    }
    for(int i=1;i<=2;i++){
        if(contagem[i]>contagem[tipo])tipo=i;
    }
    return tipo;
}

void causardano(int danofis,int danomag,int cura,personagem *atacante,personagem *defensor){
    defensor->hpatual-=danofis+danomag;
    atacante->hpatual+=cura;
}

void dano(carta carta[3],personagem *atacante,personagem *defensor){
    int danofis=0,danomag=0,cura=0,tipo;
    float multfis=1.0,multmag=1.0,multcura=1.0;
    int bonusfis=0,bonusmag=0,bonuscura=0;
    for(int i=0;i<3;i++){
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
    tipo=decidetipo(carta);
    switch(tipo){
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
    danofis=((danofis+bonusfis+atacante->atqfis)*multfis)-defensor->deffis;
    danomag=((danomag+bonusmag+atacante->atqmag)*multmag)-defensor->defmag;
    cura=(cura+bonuscura)*multcura;

    causardano(danofis,danomag,cura,atacante,defensor);
    
}