/*
 * Project: Vector Power Series Expression (IETI Lab 6)
 * File: vector_power_expression.c
 * Aim: This program calculates a mathematical expression by summing the results 
 * of raising elements of one vector to the power of elements of another vector.
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int* allocate_vector(int n){
    int *v = malloc(n * sizeof(int)); 
    if(!v){
        printf("Error: Insufficient memory.\n"); 
        exit(1); 
    }
    return v; 
}

void read_vector(int *v, int n){
    printf("Enter the elements of the vector: \n"); 
    for(int i = 0; i < n; i++)
       {
           printf("v[%d]= ", i); 
           scanf("%d", &v[i]); 
       }
}

void calculate_expression(int *a, int *b, int n){
    double result = 0; 
    for(int i = 0; i < n; i++){
        result += pow(a[i], b[i]); 
    }
    printf("The calculated expression result is: %.0f\n", result); 
}

void free_vector(int *v){
    free(v); 
}

int main() {
    printf("Enter the number of elements: "); 
    int n; 
    scanf("%d", &n); 
    
    int *a = allocate_vector(n); 
    int *b = allocate_vector(n); 
    
    printf("First vector: \n"); 
    read_vector(a, n); 
    printf("Second vector: \n"); 
    read_vector(b, n); 
    
    calculate_expression(a, b, n); 
    
    free_vector(a); 
    free_vector(b); 
    
    return 0; 
}