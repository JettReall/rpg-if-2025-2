#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "structs.h"
#include "baralho.h"
#include "tabela.h"
#include "inimigos.h"

CARTA fis1={"fisico1 teste","",ATAQUEFIS,5};
CARTA mag1={"magico1 teste","",ATAQUEMAG,5};
CARTA cura1={"cura1 teste","",CURA,5};


//FUNCOES DE EFEITO
void AplicaEfeitoEmInimigos(EFEITO Efeito,INIMIGOS *Personagem){ //aplica um efeito em algum inimigo
    int i=0;
    while(Personagem->Efeitos[i].Contador > 0)i++; //encontra um slot do arrayy de efeitos livre para aplicar
    Personagem->Efeitos[i]=Efeito;
    printf("\n%s recebeu o efeito %s por %d turnos/\n",Personagem->Nome,Efeito.Nome,Efeito.Contador); //aplica
    if(Efeito.Tipo==STATMOD){
        Personagem->Stat[Efeito.Stat]+=Efeito.Valor;//caso mude algum stats aplica a mudanca
    }
} 

void CausaEfeitoPlayer(PERSONAGEM *Player){ //causa o efeito de um efeito no player
    for(int i=0;i<10;i++){  //percorre todos os efeitos do personagem
        switch(Player->Efeitos[i].Tipo){ //decide se eh dano ou stat
              case DANOC:
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

void CausaEfeitoInimigo(INIMIGOS *Player){ //causa o efeito de um efeito em um inimigue
    for(int i=0;i<10;i++){  //percorre todos os efeitos do personagem
        switch(Player->Efeitos[i].Tipo){ //decide se eh dano ou stat
              case DANOC:
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

void FuncaoEfeito(PERSONAGEM *Player,INIMIGOS *Inimigo[4],int qtdvivo){ //funcao q sera usada no final do turno
    CausaEfeitoPlayer(Player); //casusa no player
    for(int i=0;i<qtdvivo;i++){ //causa em todos os inimigues
        if(Inimigo[i]!=NULL)CausaEfeitoInimigo(Inimigo[i]);
    }
}
//FUNCOES DE EFEITO

DADOS_BATALHA dadosbaralho={8,8,0};

typedef struct dano{
    int danofis;
    int danomag;
    int cura;
    float multiplier;
}DANO;

void AcumulaDano(DANO *dano,CARTA *cartas[3]){
    int i=0;;
    while(cartas[i]!=NULL){
        switch(cartas[i]->Tipo){
            case ATAQUEFIS:
                dano->danofis+=cartas[i]->Valor;
                break;
            case ATAQUEMAG:
                dano->danomag+=cartas[i]->Valor;
                break;
            case CURA:
                dano->cura+=cartas[i]->Valor;
                break;
        }
    }
}

int DecideTipo(CARTA carta[3]){ //devolve o tipo predominante do combo
    int Contagem[3]={0},tipo=0;
    for(int i=0;i<3;i++){
        Contagem[carta[i].Tipo]++;
    }
    for(int i=1;i<=2;i++){
        if(Contagem[i]>Contagem[tipo])tipo=i;
    }
    return tipo;
}

ELEMENTO_TABELA PegaTabela(CARTA *cartas){
    return TABELA[cartas[0].Tipo][cartas[1].Tipo][cartas[2].Tipo];
}

void CalculaCombo(int tipo,ELEMENTO_TABELA tabela,DANO *dano){
    switch(tipo){
        case ATAQUEFIS:
            dano->danofis+=tabela.Bonus;
            break;
        case ATAQUEMAG:
            dano->danomag+=tabela.Bonus;
            break;
        case CURA:
            dano->cura+=tabela.Bonus;
            break;
    }
    dano->multiplier=tabela.Multiplier;
}

EFEITO *EfeitoCombo(ELEMENTO_TABELA tabela,int *aoe){
    switch(tabela.Efeito->Tipo){
        case 0: case 2:
            return tabela.Efeito;
        case 3:
            *aoe=1;
            return NULL;
    }   
    return NULL; 
}

void CausaDanoPlayer(PERSONAGEM *player,INIMIGOS *inimigos[4],DANO dano,int aoe,int escolha,EFEITO *efeito){
    int vez=0;
    int danorecebido;
    do{
        if(inimigos[escolha]->HpAtual>0){

            danorecebido=((dano.danofis+player->Stat[ATQFIS]-inimigos[escolha]->Stat[DEFFIS])+
            (dano.danomag+player->Stat[ATQMAG]-inimigos[escolha]->Stat[DEFMAG]))*dano.multiplier;

            inimigos[escolha]->HpAtual-=danorecebido;
            printf("%s recebeu %d de dano ",inimigos[escolha]->Nome,danorecebido);

            if(inimigos[escolha]->HpAtual<=0)printf("e morreu");
            printf("\n");
        }
        escolha++;
        if(escolha>3){
            escolha=0;
        }
        vez++;
    }while(aoe&&vez<=3);
    if(efeito!=NULL){
        AplicaEfeitoEmInimigos(*efeito,inimigos[escolha]);
    }
}

void CuraPlayer(DANO dano,PERSONAGEM *player){
    player->HpAtual+=dano.cura;
    if(player->HpAtual>player->Stat[HPMAX]){
        player->HpAtual=player->Stat[HPMAX];
    }
    printf("\n%s curou %d de hp e agora esta com %d\n",player->Nome,dano.cura,player->HpAtual);
}

void DanoPlayer(CARTA *cartas,PERSONAGEM *player,INIMIGOS *inimigos[4],int inimigoescolha){
    int tipo,AOE=0;
    EFEITO *efeito;
    DANO dano={0,0,0,1};
    ELEMENTO_TABELA tabela;
    tipo=DecideTipo(cartas);
    tabela=PegaTabela(cartas);
    AcumulaDano(&dano,&cartas);
    CalculaCombo(tipo,tabela,&dano);
    efeito=EfeitoCombo(tabela,&AOE);
    CuraPlayer(dano,player);
    CausaDanoPlayer(player,inimigos,dano,AOE,inimigoescolha,efeito);
}

void Turno1(NO_BARALHO **head,CARTA *mao[6]){
    CARTA carta;
    printf("funcao turno 1\n");
    for(int i=0;i<4;i++){
        printf("loop de puxar carta\n");
        carta=PuxarCarta(head,&dadosbaralho.QtdCartaAtual);
        printf("saiu da funcao puxar carta\n");
        mao[i]=&carta;
        printf("Puxou uma carta\n");
        printf("%s\n",mao[i]->Nome);
        dadosbaralho.QtdCartamaoatual++;
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

void InterfacePlayer(PERSONAGEM *player,CARTA *mao[6],int turno,CARTA cartasjogadas[3],int acao){
    int cartanum=1;
    printf("\nVai printar a interface\n");
    printf("Turno: %d\nTurno de %s\nHP:%d/%d\n",turno,player->Nome,player->HpAtual,player->Stat[HPMAX]);
    printf("Mao do jogador:\n");
    for(int i=0;i<6;i++){
        printf("loop pra printar as cartas do player\n");
        if(mao[i]!=NULL){
            printf("carta atual eh nao nula\n");
        printf("(%d)%s(%s, %d)\n",cartanum,mao[i]->Nome,TipoAtq(mao[i]->Tipo),mao[i]->Valor);
        cartanum++;
        }else{
            cartanum--;
        }
    }
    if(acao==0)printf("(0) Recarregar baralho\n");
    printf("(10)acabar turno\n");
    printf("\n cartas jogadas:\n");
    for(int i=0;i<acao+1;i++){
        printf("%s(%s, %d)\n",cartasjogadas[i].Nome,TipoAtq(cartasjogadas[i].Tipo),cartasjogadas[i].Valor);
    }
}

CARTA *PlayerAcao(CARTA *mao[6],NO_BARALHO **baralho,CARTA *baralhoarr,PERSONAGEM *player,int turno){
    static CARTA cartasjogadas[3];
    int i=0;
    int decisao;
    printf("funcao player acaoa");
    for(int acao=0;acao<3;acao++){
        printf("entrou no loop de acao do player");
        InterfacePlayer(player,mao,turno,cartasjogadas,acao);
        scanf("%d",&decisao);
        printf("leu a decisao\n");
        if(decisao==0){
            if(acao==0){
                RecarregaBaralho(baralho,baralhoarr,&dadosbaralho.QtdCartaAtual,dadosbaralho.QtdCartaTotal);
                printf("Baralho recarregado\n");
                return NULL;
            }else{
                printf("Não pode recarregar após ter jogado uma carta\n");
            }
        }
        if(decisao>0&&decisao<dadosbaralho.QtdCartamaoatual+1){
            printf("entro na parte de jogar a carta\n");
            cartasjogadas[i]=*mao[decisao-1];
            printf("guardou valor da carta jogada e excluiu ela da mao\n");
            i++;
            mao[decisao]=NULL;
            dadosbaralho.QtdCartamaoatual--;
        }else{
            printf("\nentre um valor válido\n");
            acao--;
        }
        if(decisao==10){
            break;
        }
    }
    return cartasjogadas;
}

int DecideAlvo(INIMIGOS *inimigos[4]){
    int decisao;
    int sla=0;
    printf("\nQuem você deseja atacar?::\n");
    for(int i=0;i<4;i++){
        if(inimigos[i]!=NULL){
            printf("(%d)%s\n",sla,inimigos[i]->Nome);
        }
    }
    scanf("%d",&decisao);
    return decisao;
}

void TurnoPlayer(NO_BARALHO **baralho,PERSONAGEM *player,INIMIGOS *inimigos[4],CARTA *mao[6],int *turno,
                CARTA *baralhoarr){

    printf("entro no turno do pleier\n");
    int inimigoatingido;
    CARTA *array=malloc(sizeof(CARTA)*3);
    printf("criou a mao\n");
    //int decisao;
    if(*turno==0){
        printf("turno 0\n");
        Turno1(baralho,mao);
    }
    printf("inicio turno\n");
    array=PlayerAcao(mao,baralho,baralhoarr,player,*turno);
    if(array!=NULL){
        inimigoatingido=DecideAlvo(inimigos);
        DanoPlayer(array,player,inimigos,inimigoatingido);
    }
}

int ContaInimigues(INIMIGOS inimigos[4]){
    int temp=0;
    for(int i=0;i<4;i++){
        if(inimigos[i].HpAtual>0)temp++;
    }
    return temp;
}

void DanoInimigue(PERSONAGEM *player,INIMIGOS *inimigo,int dano,int tipo){
    int danototal,dodge;
    dodge=rand()%101;
    if(dodge<player->Stat[SPEED]){
    switch(tipo){
        case ATAQUEFIS:
            danototal=(dano+inimigo->Stat[ATQFIS]-player->Stat[DEFFIS]);
            player->HpAtual-=danototal;
            printf("%s tomou %d de dano, de %s\n",player->Nome,danototal,inimigo->Nome);
            break;
        case ATAQUEMAG:
            danototal=(dano+inimigo->Stat[ATQMAG]-player->Stat[DEFMAG]);
            player->HpAtual-=danototal;
            printf("%s tomou %d de dano, de %s\n",player->Nome,danototal,inimigo->Nome);
            break;
        case CURA:
            inimigo->HpAtual+=dano;
            printf("%s curou %d de vida\n",inimigo->Nome,dano);
    }
    }
}

void AtaqueInimigo(PERSONAGEM *player,INIMIGOS *inimigos[4],int *escolhas,int qtdatq){
    int dano,atqescolhido,tipo;
    for(int i=0;i<qtdatq;i++){
        dano=0;
        atqescolhido=rand()%2;
        dano=inimigos[escolhas[i]]->Habilidades[atqescolhido].Valor;
        tipo=inimigos[escolhas[i]]->Habilidades[atqescolhido].Tipo;
        DanoInimigue(player,inimigos[escolhas[i]],dano,tipo);
    }
}


void TurnoInimigo(PERSONAGEM *player,INIMIGOS *inimigos[4]){
    srand(time(NULL));
    int qtdvivo,qtdatq;
    int *iniescolhidos;
    qtdvivo=ContaInimigues(*inimigos);
    qtdatq=rand()%qtdvivo+1;
    iniescolhidos=malloc(sizeof(int)*qtdatq);
    for(int i=0;i<qtdatq;i++){
        iniescolhidos[i]=rand()%qtdvivo+1;
    }
    AtaqueInimigo(player,inimigos,iniescolhidos,qtdatq);
}

int Batalha(NO_BARALHO **baralho,PERSONAGEM player,INIMIGOS *inimigos[4],CARTA *baralhoarr){
    printf("entro en batalia\n");
    int finalizado=0,turno=0;
    DANO cura;
    cura.cura=(player.Stat[HPMAX]*0.15);
    CARTA *mao[6]={NULL};
    //CARTA cartasjogadas[3];
    printf("Declarou as carta\n");
    while(!finalizado){
        printf("entro no loop de batalia\n");
        TurnoPlayer(baralho,&player,inimigos,mao,&turno,baralhoarr);
        TurnoInimigo(&player,inimigos);
        FuncaoEfeito(&player,inimigos,ContaInimigues(*inimigos));
        if(!ContaInimigues(*inimigos)){
            finalizado=1;
        }else{
            turno++;
        }
    }
    CuraPlayer(cura,&player);
    return player.HpAtual;
}

int main(){
    printf("Entrou no main\n");
    DADOS_BATALHA dadosbaralho={8,8,0};
    PERSONAGEM player = {
    "personagem demo",       // Nome
    {50,5,5,10,10,10,1},     // Stat[7]
    50,                      // HpAtual
    0,                       // Xp
    { {0}, {0} },            // Equipados[2]
    { {0} },                 // Inventario[6]  (isso inicializa todos com zero)
    { {0} }                  // Efeitos[10]
    };
    printf("declarou personagem\n");
    printf("algo\n");
    criar_ini_bosque();
    INIMIGOS *inimigosc[4]={&inimigo[0],&inimigo[1],&inimigo[2],&inimigo[3]};
    printf("declarou inimigos\n");
    NO_BARALHO *baralho=NULL;
    printf("criou a head\n");
    CARTA baralhoarr[8]={fis1,fis1,fis1,mag1,mag1,mag1,cura1,cura1};
    printf("declarou o arr baralho\n");
    CriaBaralho(baralhoarr,&baralho,dadosbaralho.QtdCartaTotal);
    PrintBaralho(baralho);
    printf("Criou baralho\n");
    player.HpAtual=Batalha(&baralho,player,inimigosc,baralhoarr);
}