#include <stdio.h>

int main() {
    char text[1000];
    char result[1000] = {0};  
    int i = 0, j = 0;
    int word_num = 0;

    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);// функция Fgets читает данные из входного потока

    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    i = 0;
    while (text[i] != '\0') {

        while (text[i] == ' ' || text[i] == '\t') {
            i++;
        }
        if (text[i] == '\0') break;

        word_num++;
        int word_start = i;

        while (text[i] != '\0' && text[i] != ' ' && text[i] != '\t') {
            i++;
        }

        if (word_num % 2 == 1) {
            for (int k = word_start; k < i; k++) {
                result[j++] = text[k];
            }
            result[j++] = ' '; 
        }
    }

    if (j > 0 && result[j-1] == ' ') {
        j--;
    }
    result[j] = '\0';

    printf("Result: %s\n", result);

    printf("\nPress Enter to exit...");
   
    return 0;
}

//выбор между чтением из файла и чтением из терминала. Но результат ВСЕГДА записывать в файл.