//ATENÇÃO ESTE CÓDIGO SÓ FUNCIONA COM ARRAYS DE TAMANHO N x N:
#include<stdio.h>
int n;
//Função responsável por limpar a tela:
void clearScreen(int a){
    for (int i = 0; i < a; i++){
        printf("\n");
    }
}
//Função responsável por ler os Arrays:
void readArray(int u[n][n]){
    printf("\nDefine Array:\n");
    for (int i = 0; i < n; i++){
        printf("%iº line:\n", i + 1);
        for (int j = 0; j < n; j++){
            scanf("%i", &u[i][j]);
        }
    }
}
//Função responsável por imprimir os Arrays na tela do utilizador:
void writeArray(int u[n][n]){
    printf("\nArray:\n");
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf(" %i ", u[i][j]);    
        }
        printf("\n");   
    }
}
//Função responsável por multiplicar os Arrays:
void xArray(int u[n][n], int v[n][n]){
    int r[n][n];//O array r é o Array resultante da multiplicação dos dois Arrays introduzidos como argumentos da função
    //Incializa o Array r com todas as suas posições a zero:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            r[i][j] = 0;
        }   
    }
    //Ciclos responsável por fazer a multiplicação dos Arrays:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int l = 0; l < n; l++){
                r[i][j] = r[i][j] + (u[i][l] * v[l][j]);
            }
        }
    }
    //Ciclos responsáveis por imprimir o Array resultante da multiplicação:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf(" %i ", r[i][j]);
        }
        printf("\n");
    }
}

int main(void){
    printf("Please indicate the size of the array: ");
    scanf("%i", &n);
    int u[n][n], v[n][n];
    readArray(u);
    readArray(v);
    clearScreen(150);
    writeArray(u);
    writeArray(v);
    printf("\n");
    xArray(u,v);
    return 0;
}
