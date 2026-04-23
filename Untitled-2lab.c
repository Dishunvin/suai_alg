#include <stdio.h>

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

int main() {
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    float result = sum_res(N);
    printf("Sum=%f\n, result");
   
    return 0;
}

//(data type)
//реализовать функцию расчета задания с циклом while. доп условие - теранарный оператор для смены знака.