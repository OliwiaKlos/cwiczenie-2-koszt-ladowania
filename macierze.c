#include <stdio.h>

#define MAX 20

int main(void)
{
    const int rowsA = 2, colsA = 3;
    const int rowsB = 2, colsB = 3;
    int i = 0, j = 0;
    double A[MAX][MAX] = {
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0}
    };
    double B[MAX][MAX] = {
        {7.0, 8.0, 9.0},
        {10.0, 11.0, 12.0}
    };
    double C[MAX][MAX];

    if (rowsA < 1 || rowsA > MAX || colsA < 1 || colsA > MAX ||
        rowsB < 1 || rowsB > MAX || colsB < 1 || colsB > MAX)
    {
        printf("Nieprawidlowe wymiary macierzy.\n");
        return 1;
    }

    if (rowsA != rowsB || colsA != colsB)
    {
        printf("Nie mozna dodac macierzy o roznych wymiarach.\n");
        return 1;
    }

    printf("Macierz A:\n");
    for (i = 0; i < rowsA; ++i)
    {
        for (j = 0; j < colsA; ++j)
        {
            printf("%8.2f", A[i][j]);
        }
        printf("\n");
    }

    printf("\nMacierz B:\n");
    for (i = 0; i < rowsB; ++i)
    {
        for (j = 0; j < colsB; ++j)
        {
            printf("%8.2f", B[i][j]);
        }
        printf("\n");
    }

    printf("\nSuma macierzy A i B:\n");
    for (i = 0; i < rowsA; ++i)
    {
        for (j = 0; j < colsA; ++j)
        {
            C[i][j] = A[i][j] + B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }

    printf("\nRoznica macierzy A i B:\n");
    for (i = 0; i < rowsA; ++i)
    {
        for (j = 0; j < colsA; ++j)
        {
            C[i][j] = A[i][j] - B[i][j];
            printf("%8.2f", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
