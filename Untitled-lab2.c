#include <stdio.h>

int lab_2() {
    int N;
    float sum = 0;

    printf("Enter N: ");
    scanf("%d", &N);

    for(int k = 1; k <= N; k++) {
        if(k % 2 == 1)
            sum = sum + (float)(k + 2) / (k * (k + 1));
        else
            sum = sum - (float)(k + 2) / (k * (k + 1));
    }

    printf("Sum = %f\n", sum);
    return 0;
}