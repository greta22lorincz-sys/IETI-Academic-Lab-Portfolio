/* 
 * Project: Vector Segment Overwrite (IETI Lab 6)
 * File: vector_overwrite.c
 * Aim: This program copies the content of a second vector into a first 
 * vector starting at index k, effectively overwriting existing elements.
 */

#include <stdio.h>
#include <stdlib.h>

void read_vector(int *v, int n) {
    printf("Enter the vector elements: \n");
    for (int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
}

int main() {
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);

    int *a = malloc((n + m) * sizeof(int));
    if (!a) {
        printf("Insufficient memory.\n");
        exit(1);
    }
    int *b = malloc(m * sizeof(int));
    if (!b) {
        printf("Insufficient memory.\n");
        exit(1);
    }

    printf("For vector a: \n");
    read_vector(a, n);
    printf("For vector b: \n");
    read_vector(b, m);

    printf("Insertion position k = ");
    int k;
    scanf("%d", &k);

    int j = 0;
    for (int i = k; i < m + k; i++)
        a[i] = b[j++];

    if (k + m > n) {
        n = k + m;
    }

    printf("The resulting vector is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    free(b);
    return 0;
}