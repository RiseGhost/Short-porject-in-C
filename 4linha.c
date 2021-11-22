//This is a Game: (4 in line)
//Work help:
//https://github.com/LuisLandeiras
//https://github.com/ReynaRodriguess
#include<stdio.h>
#include<stdlib.h>
#define N 8
#define M 8

void clearScreen(int x){
    if (x > 0){
        printf("\n");
        clearScreen(x - 1);
    }
}

void escreve(char v[N][M]){
    for (int i = 0; i < N; i++)
    {
        printf("\033[0;37m"); //Mudar a cor para branco
        printf("%i -> ", i + 1);
        for (int j = 0; j < M; j++)
        {
            printf("\033[0;37m"); //Mudar a cor para branco
            printf("|");
            if (v[i][j] == 'X'){
                printf("\033[1;31m"); //Mudar a cor para vermelho
                printf(" %c ", v[i][j]);
            }
            if (v[i][j] == 'O'){
                printf("\033[0;32m"); //Change color to Green.
                printf(" %c ", v[i][j]);
            }
            if (v[i][j] == ' '){
                printf("\033[0;37m"); //Mudar a cor para branco
                printf(" %i ", j + 1);
            }
        }
        printf("\033[0;37m"); //Mudar a cor para branco
        printf("|");
        printf("\n");
    }   
}

void players(char v[N][M], int play){
    int coluna, aux = 0;
    printf("\033[0;37m"); //Mudar a cor para branco
    if (play % 2 == 0){
        printf("🐶 Jogador 1 selecione a coluna que deseja:\n");
        scanf("%i", &coluna);
        //I -> linhas       J -> colunas
        for (int i = N - 1; i >= 0; i--)
        {
            if (v[i][coluna - 1] == ' ' && aux == 0){
                v[i][coluna - 1] = 'X';
                aux = 20;
            }
        }
    }
    else{
        printf("🐻 Jogador 2 selecione a coluna que deseja:\n");
        scanf("%i", &coluna);
        //I -> linhas       J -> colunas
        for (int i = N - 1; i >= 0; i--)                 
        {
            if (v[i][coluna - 1] == ' ' && aux == 0){
                v[i][coluna - 1] = 'O';
                aux = 20;
            }
        }
    }
}

int condictions(char v[N][M]){
    //condição 1
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++)
        {
            if(v[i][j] == 'X' && v[i][j + 1] == 'X' && v[i][j + 2] == 'X' && v[i][j + 3] == 'X'){
                printf("Jogador 1 ganhou!\n");
                return 1;
            }
            if(v[i][j] == 'O' && v[i][j + 1] == 'O' && v[i][j + 2] == 'O' && v[i][j + 3] == 'O'){
                printf("Jogador 2 ganhou!\n");
                return 1;
            }
        }
    }
    //condição 2
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(v[i][j] == 'X' && v[i +1][j] == 'X' && v[i + 2][j] == 'X' && v[i+3][j] == 'X'){
                printf("Jogador 1 ganhou!\n");
                return 1;
            }
            if(v[i][j] == 'O' && v[i + 1][j] == 'O' && v[i + 2][j] == 'O' && v[i + 3][j] == 'O'){
                printf("Jogador 2 ganhou!\n");
                return 1;
            }
        }
    }
    //condição 3
    for (int i = 0 ; i < N; i++){
        for (int j = 0; j < M; j++){
            if(v[i][j] == 'X' && v[i + 1][j - 1] == 'X' && v[i + 2][j - 2] == 'X' && v[i + 3][j - 3] == 'X'){
                printf("Jogador 1 ganhou!\n");
                return 1;
            }
            if(v[i][j] == 'O' && v[i + 1][j - 1] == 'O' && v[i + 2][j - 2] == 'O' && v[i - 3][j - 3] == 'O'){
                printf("Jogador 2 ganhou!\n");
                return 1;
            }
            if(v[i][j] == 'X' && v[i - 1][j + 1] == 'X' && v[i - 2][j + 2] == 'X' && v[i - 3][j + 3] == 'X'){
                printf("Jogador 1 ganhou!\n");
                return 1;
            }
            if(v[i][j] == 'O' && v[i - 1][j + 1] == 'O' && v[i - 2][j + 2] == 'O' && v[i - 3][j + 3] == 'O'){
                printf("Jogador 2 ganhou!\n");
                return 1;
            }
        }    
    }
    return 0;
}

void menu(char v[N][M],int player){
    int y;
    printf("Choose one of the following options:\n ");
    printf("1-Game 1x1 you trash!\n 2-Instructions for the game\n 3-Configuractions\n 4-Exit\n");
    scanf("%i", &y);
    switch(y){
        case 1:
            for (int i = 0; i < N; i++){
                for (int j = 0; j < M; j++){
                    v[i][j] = ' ';
                }
            }
            do
            {
                clearScreen(100); 
                escreve(v);
                players(v, player);
                escreve(v);
                player++;
            } while (player < 66 && condictions(v) == 0);
            if (player = 66){
                printf("O jogo empatou.\n");
            }
            break;
        case 2:
            printf("Cada jogador deve escolher o seu simbolo e cor antes de iniciar o jogo.\n Para ganhar o jogo o um dos players tem de ter 4 peças seguidas quer seja na vertical, horizontal ou diagonal.\n");break; //escrever as instruçoes
        case 3:
            break;
        case 4:
            system("pause");
            break;
        default:
            printf("Option not available!");
    } 
}

int main(void){
    char v[N][M];
    int player = 2;
    menu(v,player);
    return 0;
}