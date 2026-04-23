#include <stdio.h>
#include "lib/functions.h"


int lab_2d() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    float result = sum_res(N);
    printf("Sum=%f\n", result);
   
    return 0;
}

//(data type)
//реализовать функцию расчета задания с циклом while. доп условие - теранарный оператор для смены знака.