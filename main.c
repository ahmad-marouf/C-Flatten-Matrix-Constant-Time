#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *data;
    int q;
} Vector1D;

Vector1D* createVector(int *data, int q) {
    Vector1D* vec = malloc(sizeof(Vector1D));
    vec->data = malloc(q * sizeof(int));
    vec->data = data;
    vec->q = q;
    return vec;
}

Vector1D *flattenMatrix3D(int* mat, int n, int m, int p) {
    int q = n * m * p;
    Vector1D* vec = createVector(mat, q);

    return vec;
}

int main()
{
    int n1 = 2, m1 = 3, p1 = 4;
    int matrix_1[2][3][4] = {
    {{3, 4, 2, 3}, {0, -3, 9, 11}, {23, 12, 23, 2}},
    {{13, 4, 56, 3}, {5, 9, 3, 5}, {3, 1, 4, 9}}};

    Vector1D* vec = flattenMatrix3D((int*)matrix_1, n1, m1, p1);

    /* Printing for Verification */
    printf("3D Indexed Matrix: \t");
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < m1; j++)
            for (int k = 0; k < p1; k++)
                printf("%d ", matrix_1[i][j][k]);
    printf("\n");
    //
    printf("1D Indexed Vector: \t");
    for (int y = 0; y < vec->q; y++)
        printf("%d ", vec->data[y]);
    printf("\n");
    //




    free(vec);
    return 0;
}
