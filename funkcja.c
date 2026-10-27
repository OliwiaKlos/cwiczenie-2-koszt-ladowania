#include <stdio.h>

#define MAX 20

void wypisz(double M[][MAX], int w, int k){
    int i, j;

    for(i = 0; i < w; i++){
        for(j = 0; j < k; j++){
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
}

int wymiary_poprawne(int w, int k){
    if(w<=20 || k<=20){
        return 0;
    }
    else{
        printf("zle wymiary\n");
        return 1;
    }
}

int zgodne_do_sumy(int wA, int kA, int wB, int kB){
    if(wA!=wB || kA != kB){
        printf("nie da sie dodac macierzy o roznych wymiarach\n");
        return 1;
    }
    else{
        return 0;
    }
}

int zgodne_do_mozenia(int wA, int kB){
    if(wA!=kB){
        printf("nie da sie pomnozyc takich macierzy\n");
        return 1;
    }
    else{
        return 0;
    }
}

int dodaj(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k){
    int i, j;
    for(i = 0; i < w; i++){
        for(j = 0; j < k; j++){
            C[i][j]=A[i][j]+B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }
}

int odejmij(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k){
    int i, j;
    for(i = 0; i < w; i++){
        for(j = 0; j < k; j++){
            C[i][j]=A[i][j]-B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB){
    int i, j, n;
    double suma;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            suma = 0.0;
            for (n = 0; n < kA; n++) {
                suma = suma + A[i][n] * B[n][j];
            }
            C[i][j] = suma;
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }
}


int main(void){
    double A[MAX][MAX] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    double B[MAX][MAX] = {
        {10,11,12},
        {13,14,15},
        {16,17,18}
    };
    double C[MAX][MAX];
    int wA = 3;
    int kA = 2;
    int wB = 2;
    int kB = 3;

    wypisz(A, wA, kA);
    wypisz(B, wB, kB);

    int wymiar_a = wymiary_poprawne(wA, kA);
    int wymiar_b = wymiary_poprawne(wB, kB);

    int zgodne_suma = zgodne_do_sumy(wA, kA, wB, kB);
    int zgodne_mozenie = zgodne_do_mozenia(wA, kB);

    if(wymiar_a!=0 || wymiar_b!=0 || zgodne_suma!=0){
        printf("blad!!!!\n");
    }
    else{
        dodaj(A, B, C, wA, kA);
        odejmij(A, B, C, wB, kB);
    }

    if(wymiar_a!=0 || wymiar_b!=0 || zgodne_mozenie!=0){
        printf("blad!!!!\n");
    }
    else{
        pomnoz(A, B, C, wA, kA, kB);
        pomnoz(B, A, C, wB, kB, kA);
    }
    return 0;
}
