#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "baralho.h"
#include "inimigos.h"

CARTA fis1={"fisico1 teste","",ATAQUEFIS,8};
CARTA mag1={"magico1 teste","",ATAQUEMAG,8};
CARTA cura1={"cura1 teste","",CURA,5};
CARTA cartanula={"Nulo","Nulo",-1,0};
DADOS_BATALHA dadosbaralho={8,8,0};

typedef struct{
    int danofis;
    int danomag;
    int cura;
}DANO;

void CompactaMao(CARTA mao[6]) {
    CARTA temp[6];
    int idx = 0;

    // Copia cartas válidas para temp
    for(int i = 0; i < 6; i++){
        if(mao[i].Tipo != -1){   // carta válida
            temp[idx++] = mao[i];
        }
    }

    // Preenche o resto com cartanula
    while(idx < 6){
        temp[idx++] = cartanula;
    }

    // Copia de volta para mao
    for(int i = 0; i < 6; i++){
        mao[i] = temp[i];
    }
}

void limpaMao(CARTA mao[6]){
    for(int i=0;i<6;i++){
        mao[i] = cartanula;
    }
}

void printmao(CARTA mao[6]){
    printf("\n");
    for(int i=0;i<6;i++){
        if(mao[i].Tipo!=-1){
            printf("%s\n",mao[i].Nome);
        }
    }
    printf("\n");
}

void AcumulaDano(DANO *dano,CARTA *cartas,int qtd){
    for(int i=0;i<qtd;i++){
        switch(cartas[i].Tipo){
            case ATAQUEFIS:
                dano->danofis+=cartas[i].Valor;
                break;
            case ATAQUEMAG:
                dano->danomag+=cartas[i].Valor;
                break;
            case CURA:
                dano->cura+=cartas[i].Valor;
                break;
        }
    }
    printf("M%d F%d C%d\n\n",dano->danomag,dano->danofis,dano->cura);
}

void PuxarCartasPlayer(NO_BARALHO **baralho, CARTA mao[6], int turno){
    int qtd = (turno == 0 ? 4 : 1);
    int compradas = 0;

//    printf("\nPuxar cartas\n");

    while(compradas < qtd){
        int achou = 0;

        // procura primeiro slot livre
        for(int i = 0; i < 6; i++){
            if(mao[i].Valor == 0){   // slot vazio
                mao[i] = PuxarCarta(baralho, &dadosbaralho.QtdCartaAtual);
                printf("Puxou: (%d) %s\n", i, mao[i].Nome);

                dadosbaralho.QtdCartamaoatual++;
                compradas++;
                achou = 1;
                break;
            }
        }

        if(!achou){  
            // mao cheia → para
            printf("Mao cheia! Nao eh possivel puxar mais cartas.\n");
            break;
        }
    }
}


char *TipoAtq(int tipo){
    switch(tipo){
        case ATAQUEFIS:
            return "FISICO";
        case ATAQUEMAG:
            return "MAGICO";
        case CURA:
            return "CURA";
    }
    return NULL;
}

void InterfacePlayer(PERSONAGEM player,CARTA mao[6],int turno){
    int contador=0;
    printf("Turno %d\n\nTurno de %s:\n %d/%d HP\n\n",turno,player.Nome,player.HpAtual,player.Stat[HPMAX]);
    for(int i=0;i<6;i++){
        if(mao[i].Valor>0){
            printf("(%d)%s(%s, %d)\n",contador+1,mao[i].Nome,TipoAtq(mao[i].Tipo),mao[i].Valor);
            contador++;
        }
    }
    printf("\nQuantas Cartas deseja jogar(MAX 3)?Ou (10) para recarregar o baralho\n");
}

void EscolheAlvo(INIMIGOS inimigos[4],int *alvo){
    int contador=0;
    for(int i=0;i<4;i++){
        contador++;
        if(inimigos[i].HpAtual>0){
            printf("(%d)%s\n",contador,inimigos[i].Nome);
        }else{
            contador--;
        }
    }
    scanf("%d",alvo);
    *alvo=*alvo+(4-contador);
}

void CausaDanoPlayer(PERSONAGEM *player,INIMIGOS inimigos[4],DANO dano,int alvo){
    alvo-=1;
    if(dano.danofis>0)dano.danofis=(dano.danofis+player->Stat[ATQFIS]-inimigos[alvo].Stat[DEFFIS]);
    if(dano.danomag>0)dano.danomag=(dano.danomag+player->Stat[ATQMAG]-inimigos[alvo].Stat[DEFFIS]);
    int dodge=rand()%101;
    if(dodge>=inimigos[alvo].Stat[SPEED]){
        inimigos[alvo].HpAtual-=dano.danofis+dano.danomag;
        printf("%s recebeu %d de dano\n",inimigos[alvo].Nome,dano.danofis+dano.danomag);
        if((alvo-1)!=-1&&inimigos[alvo-1].HpAtual>0){
            inimigos[alvo-1].HpAtual-=(dano.danofis+dano.danomag)/2;
        printf("%s recebeu %d de dano\n",inimigos[alvo-1].Nome,(dano.danofis+dano.danomag)/2);
        }
        if((alvo+1)!=4&&inimigos[alvo+1].HpAtual>0){
            inimigos[alvo+1].HpAtual-=(dano.danofis+dano.danomag)/2;
        printf("%s recebeu %d de dano\n",inimigos[alvo+1].Nome,(dano.danofis+dano.danomag)/2);
        }
    }
}

void CuraPlayer(PERSONAGEM *player,DANO dano){
    player->HpAtual+=dano.cura;
    if(player->HpAtual>player->Stat[HPMAX]){
        player->HpAtual = player->Stat[HPMAX];
    }
    printf("%s curou %d de HP, agora esta com %d/%d\n\n\n",player->Nome,dano.cura,player->HpAtual,player->Stat[HPMAX]);
}

void RetiraCartasDaMao(CARTA mao[6], int *decisao, int qtd) {
    for(int i = 0; i < qtd; i++){
        int idx = decisao[i] - 1;
        mao[idx] = cartanula;
    }
}

void PlayerAtaque(PERSONAGEM *player,CARTA mao[6],INIMIGOS inimigos[4],NO_BARALHO **baralho,CARTA *baralhoarr){
    int qtdprajogar;
    int *decisao;
    int valido=0;
    int alvo;
    CARTA *cartasjogadas;
    DANO dano={0,0,0};
    while(!valido){
        scanf("%d",&qtdprajogar);
        if(qtdprajogar>0&&qtdprajogar<=3||qtdprajogar==10){
            decisao=malloc(sizeof(int)*qtdprajogar);
            cartasjogadas=malloc(sizeof(CARTA)*qtdprajogar);
            valido=1;
        }else{
            printf("Digite um valor valido");
        }
    }
    if(qtdprajogar!=10){   
        printf("Digite o numero () das cartas que gostaria de jogar separando por enter:\n");
        for(int i=0;i<qtdprajogar;i++){
        scanf("%d",&decisao[i]);
            if(i>0){
                for(int j=i-1;j>=0;j--){
                    if(decisao[j]==decisao[i]){
                        printf("Nao repita cartas\n");
                        i--;
                    }
                }
            }
        }
        for(int i=0;i<qtdprajogar;i++){
            cartasjogadas[i]=mao[decisao[i]-1];
        }
        RetiraCartasDaMao(mao,decisao,qtdprajogar);
        CompactaMao(mao);
        AcumulaDano(&dano,cartasjogadas,qtdprajogar);
        EscolheAlvo(inimigos,&alvo);
        CausaDanoPlayer(player,inimigos,dano,alvo);
        CuraPlayer(player,dano);
    }else{
        RecarregaBaralho(baralho,baralhoarr,&dadosbaralho.QtdCartaAtual,dadosbaralho.QtdCartaTotal);
        Embaralhar(baralho);
        printf("baralho recarregado\n");
    }
}

void TurnoPlayer(NO_BARALHO **baralho,CARTA *baralhoarr,PERSONAGEM *player,INIMIGOS inimigos[4],CARTA mao[6],int turno){
    PuxarCartasPlayer(baralho,mao,turno);
//    printf("puxou as cartas\n");
    InterfacePlayer(*player,mao,turno);
    PlayerAtaque(player,mao,inimigos,baralho,baralhoarr);
}

void DanoInimigue(DANO dano,INIMIGOS *inimigo,PERSONAGEM *player){
    int dodge=rand()%101;
    if(dano.danofis>0)dano.danofis=dano.danofis+inimigo->Stat[ATQFIS]-player->Stat[DEFFIS];
    if(dano.danomag>0)dano.danomag=dano.danomag+inimigo->Stat[ATQMAG]-player->Stat[DEFMAG];
    if(dodge>=player->Stat[SPEED]){
        player->HpAtual-=(dano.danofis+dano.danomag);
        printf("%s causou %d de dano em %s\n",inimigo->Nome,(dano.danofis+dano.danomag),player->Nome);
    }else{
        printf("%s Desviou\n",player->Nome);
    }
}

void InimigueAtaque(INIMIGOS *inimigo,PERSONAGEM *player){
    int atq=rand()%2;
    DANO dano={0};
    switch(inimigo->Habilidades[atq].Tipo){
        case ATAQUEFIS:
            dano.danofis=inimigo->Habilidades[atq].Valor;
            break;
        case ATAQUEMAG:
            dano.danomag=inimigo->Habilidades[atq].Valor;
            break;
        case CURA:
            dano.cura=inimigo->Habilidades[atq].Valor;
            break;
    }
    printf("%s usou %s\n",inimigo->Nome,inimigo->Habilidades[atq]);
    DanoInimigue(dano,inimigo,player);
}

void TurnoInimigos(PERSONAGEM *player,INIMIGOS inimigos[4]){
    int i=0;
    while(i<4){
        if(inimigos[i].HpAtual>0){
            InimigueAtaque(&inimigos[i],player);
        }
        i++;
    }
}

int FimDeTurno(PERSONAGEM player,INIMIGOS inimigos[4]){
    int flag=0;
    int inimortos=0;
    if(player.HpAtual<=0){
        flag=1;
        printf("\n\n%s morreu\n",player.Nome);
        return flag;
    }
    for(int i=0;i<4;i++){
        if(inimigos[i].HpAtual<=0){
            inimortos++;
            printf("\n%s esta morto\n\n",inimigos[i].Nome);
        }
    }
    if(inimortos==4)flag=1;
    return flag;
}

void HealthPack(PERSONAGEM *player, DANO health){
    player->HpAtual+=(player->Stat[HPMAX]*(health.cura/100));
    if(player->HpAtual>player->Stat[HPMAX])player->HpAtual=player->Stat[HPMAX];
}

int batalha(NO_BARALHO **baralho,CARTA *baralhoarr,PERSONAGEM player,INIMIGOS inimigos[4]){
    int turno=0,finalizado=0;
    CARTA mao[6];
    limpaMao(mao);
    printmao(mao);
    while(!finalizado){
    TurnoPlayer(baralho,baralhoarr,&player,inimigos,mao,turno);
    TurnoInimigos(&player,inimigos);
    finalizado=FimDeTurno(player,inimigos);
    turno++;
    }
    if(player.HpAtual<=0){
        printf("%s nao pode mais lutar e a luta foi encerrada\n",player.Nome);
    }else{
        printf("%s ganhou a luta\n",player.Nome);
        DANO healthpack={0,0,125};
        HealthPack(&player,healthpack);
    }
    
    return player.HpAtual;
}

int main(){
    srand(time(NULL));
//    printf("Entrou no main\n");
    DADOS_BATALHA dadosbaralho={8,8,0};
    PERSONAGEM player = {
    "personagem demo",        // Nome
    {200, 5, 5, 10, 10, 10, 1}, // Stat[7]
    200,                      // HpAtual
    0                         // Xp
    };

//    printf("declarou personagem\n");
    inimigo[1] = CatalogoVento[3];
    //INIMIGOS *inimigosc[4]={&inimigo[0],&inimigo[1],&inimigo[2],&inimigo[3]};
//    printf("declarou inimigos\n");
    NO_BARALHO *baralho=NULL;
//    printf("criou a head\n");
    CARTA baralhoarr[8]={fis1,fis1,fis1,mag1,mag1,mag1,cura1,cura1};
    printf("\n");//PRINTF LENDARIO
    CriaBaralho(baralhoarr,&baralho, dadosbaralho.QtdCartaTotal,&dadosbaralho.QtdCartaAtual);
    Embaralhar(&baralho);
//    PrintBaralho(baralho);
//    printf("Criou baralho\n");
    player.HpAtual=batalha(&baralho,baralhoarr,player,inimigo);
    printf("A batalha acabou e %s esta com %d/%d de vida",player.Nome,player.HpAtual,player.Stat[HPMAX]);
}
