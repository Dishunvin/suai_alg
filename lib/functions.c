#include "functions.h"

#include <stdio.h>

double v2_res(double L, double v1,double t){
    return ( L - v1 * t) / t;
}

float sum_res (int N) {
    float sum= 0;
    int k=1;
    int b;

    while (k<= N){
        b=(k%2==1)? 1: -1;
        sum=sum + b * (float) (k+2)/(k*(k+1));

        k++;

    }

    return sum;
}

void input(int *target) {
    printf(">> ");
    while (scanf("%d", target) != 1) { printf("\b"); printf("<<Wrong number, try again\n");
        getchar();
        printf(">> ");}
    printf("\b");
}