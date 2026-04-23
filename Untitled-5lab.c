
#include <stdio.h>
#define N 10

int lab_5()
{
    int arr[N];
    float result[N];     
    int max;
    int i;
    
    printf("Enter %d integers:\n", N);// % - спецификатор формата, функция вывода приглашения ввести N(10) целых чисел. %d изменяетсся на значение N, \n - перевод строки
    for (i = 0; i < N; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]); //&- в данном случае оператор взятия адреса
        result[i] = arr[i]; 
    }
    
    max = arr[0];// присваивание переменной max значения первого элемента массива для начала поиска максимума
    for (i = 1; i < N; i++) {
        if (arr[i] > max) { // if- условный оператор
            max = arr[i]; // обновление максимума
        }
    }
    
    printf("\nMaximum element = %d\n", max);
    
    if (max == 0) { //проверка, если максимальный элемент равен нулю
        printf("Error: Maximum element is zero! Cannot divide.\n");
        return 1;
    }
    
    for (i = 0; i < N; i++) { // цикл для обработки элементов массива
        if (arr[i] < 0) {
            result[i] = (float)arr[i] / max; // float - приведение массива к этому типу
        }
    }
    
    printf("\nResult array (negative elements divided by %d):\n", max);
    for (i = 0; i < N; i++) {
        printf("arr[%d] = %.2f\n", i, result[i]);
    }
    
    return 0;
}
