/*
 * Project: Numeric String Extractor (IETI Lab 6)
 * File: numeric_extractor.c
 * Aim: This program reads input character by character and extracts 
 * consecutive digit sequences, converting them into integer values.
 */
#include <stdio.h>

int main(void) {
    int c;
    int num = 0;
    int in_number = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
            in_number = 1;
        } else {
            if (in_number) {
                printf("%d ", num);
                num = 0;
                in_number = 0;
            }
        }
    }
    if (in_number)
        printf("%d", num);

    return 0;
}