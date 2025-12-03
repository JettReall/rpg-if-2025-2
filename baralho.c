#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <time.h>

void AdicionaCarta(CARTA n,NO_BARALHO **head){
    NO_BARALHO *novo=malloc(sizeof(NO_BARALHO));
    novo->Carta=n;
    novo->PtrProx=*head;
    *head=novo;
}

void RetiraCarta(int carta,NO_BARALHO **head,int *qtd){
    NO_BARALHO *atual = *head;
    NO_BARALHO *anterior = NULL;
    if (carta == 1) {
        *head = atual->PtrProx;
        free(atual);
        return;
    }
    for (int i = 1; i < carta && atual != NULL; i++) {
        anterior = atual;
        atual = atual->PtrProx;
    }
    anterior->PtrProx = atual->PtrProx;
    free(atual);
    *qtd=*qtd-1;
}

CARTA *listtoarray(NO_BARALHO *baralho, int *qtd){
    *qtd = 0;
    NO_BARALHO *p = baralho;
    while (p != NULL) {
        (*qtd)++;
        p = p->PtrProx;
    }

    CARTA *baralhoarr = malloc(sizeof(CARTA) * (*qtd));
    p = baralho;
    for (int i = 0; i < *qtd; i++) {
        baralhoarr[i] = p->Carta;
        p = p->PtrProx;
    }

    return baralhoarr;
}

void Embaralhar(NO_BARALHO **baralho){
    int qtd;
    CARTA *baralhoarr = listtoarray(*baralho, &qtd);
    for (int i = qtd - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        CARTA temp = baralhoarr[i];
        baralhoarr[i] = baralhoarr[j];
        baralhoarr[j] = temp;
    }
    NO_BARALHO *p = *baralho;
    for (int i = 0; i < qtd; i++) {
        p->Carta = baralhoarr[i];
        p = p->PtrProx;
    }

    free(baralhoarr);
}

void CriaBaralho(CARTA *array,NO_BARALHO **baralho,int qtd){
    for(int i=0;i<qtd;i++){
        AdicionaCarta(array[i],baralho);
    }
}

void PrintBaralho(NO_BARALHO *b){
    while(b != NULL){
        printf("%s %d\n", b->Carta.Nome, b->Carta.Valor);
        b = b->PtrProx;
    }
}

CARTA PuxarCarta(NO_BARALHO **baralho,int *qtd){
    CARTA carta=(*baralho)->Carta;
    RetiraCarta(1,baralho,qtd);
    return carta;
}

void RecarregaBaralho(NO_BARALHO **baralho,CARTA *array,int *qtdatual,int qtdtotal){
    for(int i=0;i<*qtdatual;i++){
        RetiraCarta(1,baralho,1);
    }
    CriaBaralho(array,baralho,qtdtotal);
    *qtdatual=qtdtotal;
    Embaralhar(baralho);
}