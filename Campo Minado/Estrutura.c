//Definindo Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

//Variáveis Globais
#define n_linhas 15
#define n_colunas 15

//Criar Tabuleiro
void tamanho_tabuleiro(int M, int N){ 
n_linhas = M;
n_colunas = N;
}

int campo[n_linhas][n_colunas];
bool z;

typedef struct tabuleiro{
int campo[10][10];
int y;
} t;


//Distribuição das minas no tabuleiro
void gera_minas(int qtd){ 
qtd *= n_colunas;
srand(time(NULL));
int i=1;
for (i = 1; i < qtd; i++){
    int x = rand() % (n_linhas);
    int y = rand() % (n_colunas);
    if(campo[x][y] != 0)
    i--;
    else
    campo[x][y] = 3;
}
}

//Interação do Jogo => atribui caracteres aos valores da matriz campo
void atualiza_jogador(){ 
int i,j = 0;
for(i = 0; i < n_linhas; i++){
    for(j = 0; j < n_colunas; j++){
        if (campo[i][j] == 1)
        printf("|#");
        else if (campo[i][j] == 2)
        printf("|P");
        else if (campo[i][j] == 3)
        printf("|x"); 
        else
        printf("|o");
    }
    printf("|\n");
}
}

//Dica
int minas_proximas(int x, int y){ 
int qtd = 0;
if(x-1 >= 0){
    if(y-1 >= 0 && campo[x-1][y-1] == 3)
    qtd++;
    if(y+1 <= n_colunas-1 && campo[x-1][y+1] == 3)
    qtd++;
    if(campo[x-1][y] == 3)
    qtd++;
}

if(x+1 <= n_linhas-1){
    if(y-1 >= 0 && campo[x+1][y-1] == 3)
    qtd++;
    if(y+1 <= n_colunas-1 && campo[x+1][y+1] == 3)
    qtd++;
    if(campo[x+1][y] == 3)
    qtd++;
}

if(y-1 >= 0 && campo[x][y-1] == 3)
qtd++;
if(y+1 <= n_colunas-1 && campo[x][y+1] == 3)
qtd++;
return qtd;
}

// Verificar se o jogador venceu, perdeu a partida ou finalizou o jogo.
bool verifica_posicao(int x, int y){ 

//Jogador Perdeu
if(campo[x][y] == 3){
    system("color 47");
    system("cls");
    printf("GAME OVER\n A mina explodiu!!!\n\a\a\a");
    z=true;

    //Exibir as minas distribuídas
    int i,j=0;
    for(i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            if(campo[i][j] == 3 && i!=x && j!=y)
            printf("|X");
            else if (i==x && j==y)
            printf("|#");
            else
            printf("| ");
        }
        printf("|\n");
    }
    printf("Pressione ENTER para continuar\n");
    getchar();
    return 0;
}

//Jogador Venceu
else if(campo[x][y] == 1){
    system("color 27");
    system("cls");
    printf("PARABENS!!\n Voce Venceu!!!\n\a\a\a");
    z=false;

    //Exibir as minas distribuídas
    int i,j=0;
    for(i = 0; i < n_linhas; i++){
        for(int j = 0; j < n_colunas; j++){
            if(campo[i][j] == 3 && i!=x && j!=y)
            printf("|X");
            else if (i==x && j==y)
            printf("|#");
            else
            printf("| ");
        }
        printf("|\n");
    }
    printf("Pressione ENTER para continuar\n");
    getchar();
    return 0;
}
else{
    return 1;
}
}

//Esvaziar Campo para Iniciar Jogo
void zera_matriz(){ 
int i,j = 0;
for(i = 0; i< n_linhas; i++){
    for(j = 0; j< n_colunas; j++){
        campo[i][j] = 0;
    }
}
}

//Atribuir Valores ao Campo 
void valor(int x, int y, int val){ 
campo[x][y] = val;
}

//Confirma Posição do Jogador
int *up(int x, int y){
int *pos = (int*)malloc(2* sizeof(int));

if(x>0){
campo[x][y]=0;
x--;
}
if(verifica_posicao(x,y))
campo[x][y]=2;
pos[0]=x;
pos[1]=y;
return pos;
free(pos);
}

//Habilitar Movimentação do Jogador no Tabuleiro
int *down(int x, int y){
    int *pos = (int*)malloc(2* sizeof(int));
    if(x < n_linhas-1){
        campo[x][y]=0;
        x++;
    }
    if(verifica_posicao(x,y))
    campo[x][y]=2;
    pos[0]=x;
    pos[1]=y;
    return pos;
    free(pos);
}


int *left(int x, int y){
    int *pos = (int*)malloc(2* sizeof(int));
    if(y>0){
        campo[x][y]=0;
        y--;
    }
    if(verifica_posicao(x,y))
    campo[x][y]=2;
    pos[0]=x;
    pos[1]=y;
    return pos;
    free(pos);
}


int *right(int x, int y){
    int *pos = (int*)malloc(2* sizeof(int));
    if(y < n_colunas -1){
        campo[x][y]=0;
        y++;
    }
    if(verifica_posicao(x,y))
    campo[x][y]=2;
    pos[0]=x;
    pos[1]=y;
    return pos;
    free(pos);
}

bool zera_pontos(){
    bool y = z;
    return y;
}
