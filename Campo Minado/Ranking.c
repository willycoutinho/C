//Inserir Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define capacidade 10

struct celula{
    int score;
    struct celula *prox;
};


struct celula *topo;
struct celula *fundo;

void cria(){
    struct celula *aux;
    aux = (struct celula*) malloc(sizeof(struct celula));
    topo = aux;
    fundo = topo;
}

void insere(int x){
    struct celula *aux;
    aux = (struct celula*) malloc(sizeof(struct celula));
    aux->score = x;
    fundo->prox = aux;
    fundo = fundo->prox;
    aux->prox = topo;
}

void imprime(){
struct celula *aux;
if(topo == topo->prox){
    printf("\n\t\tAinda nao existe pontuacao\n");
    getche();
    return;
}
aux = topo->prox;
system("cls");
printf("\n\t\t\tRANKING\n\n");
int i=1;
while(aux != topo){
    printf("\t\t %d Pontos no jogo %d\n", aux->score, i);
    aux = aux->prox;
    i++;
}
printf("Pressione ENTER para voltar ao menu!");
getch();
}