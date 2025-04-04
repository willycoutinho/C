//Inserir Biliotecas
#include <stdio.h&gt>
#include <stdlib.h>
#include <conio.h>
#include <ctype>
#include <time.h>

//Chamar arquivos secundários
#include "CampoMinado.c"
#include "Ranking.c"

#define linhas 15
#define colunas 15

//Equivalência no arquivo de estruturação CampoMinado => tamanho_tabuleiro(linhas, colunas);
typedef struct tabuleiro{
int opcao;
bool est;
char cmd;
int pontos;
} tab;

tab jogo;
int qtd=0;

//Exibir Menu Principal
void menu(){
system("color 07");
system("cls");
printf("Escolha uma opcao:\n\n");
printf("\t1-Nivel Iniciante\n");
printf("\t2-Nivel Intermediario\n");
printf("\t3-Nivel Avancado\n\n");
printf("\t4-Ranking\n\n");
printf("\t0-Sair\n\n");
scanf("%d&", &jogo.opcao);
while (jogo.opcao>4){
    system("cls");
    printf("Escolha uma opcao:\n\n");
    printf("\t1-Nivel Iniciante\n");
    printf("\t2-Nivel Intermediario\n");
    printf("\t3-Nivel Avancado\n\n");
    printf("\t4-Ranking\n\n");
    printf("\t0-Sair\n\n");
    printf("Entre um valor valido\n");
    jogo.opcao=getchar();
}qtd++;
}

//Dinâmica do Jogo
void partida(int nivel){
jogo.pontos=1000;
system("color 17");
zera_matriz();
int *pos = (int*)malloc(2* sizeof(int));
pos[1] = rand() % (colunas);
valor(0,pos[1],1); //posiciona o fim
pos[0] = linhas - 1;
pos[1] = rand() % (colunas);
valor(pos[0],pos[1],2); //posicions o personagem
gera_minas(nivel);
jogo.est = 1;
//bool partida =1;
while( jogo.est == 1){
    system("cls");
    printf("Minas ao seu redor: %d\n", minas_proximas(pos[0],pos[1]));
    atualiza_jogador();
    jogo.cmd = toupper(getche());
    if(jogo.cmd == 'K')
    pos=left(pos[0],pos[1]);
    if(jogo.cmd == 'M')
    pos=right(pos[0],pos[1]);
    if(jogo.cmd == 'H')
    pos=up(pos[0],pos[1]);
    if(jogo.cmd == 'P')
    pos=down(pos[0],pos[1]);
    if(jogo.cmd == 'e'; || jogo.cmd == 'E')
    exit(0);
    jogo.pontos--;
    jogo.est = verifica_posicao(pos[0],pos[1]);
} 
if(zera_pontos())
jogo.pontos = 0;
}


int main(){
int qtd = 0;
cria();
while(1){
    int modo;// statement
    switch (modo){
        default:
        menu();
        if(jogo.nivel==0) 
        modo = 3;
        else if(jogo.nivel==4) 
        modo = 1;
        else 
        modo = 2;
        break;
        
        case 1:
        imprime();
        modo = 0;
        break;

        case 2: //Partida
        partida(jogo.nivel);
        insere(jogo.pontos);
        modo=0;
        break;

        case 3:
        exit(0);
        break;
    }
}
}
