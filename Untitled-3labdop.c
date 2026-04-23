#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    int in_word = 0;
    int count = 0;
    char word[100];    
    int len = 0;

    printf("Enter text (press Ctrl+Z then Enter to finish):\n");
    while ((c = getchar()) != EOF) {
        if (!isalpha(c)) {
            if (in_word) {
                word[len] = '\0';
                char first = tolower(word[0]);
                if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
                    
                    for (int i = 0; i < len; i++) {
                        putchar(toupper(word[i]));
                    }
                    printf("\n");
                    count++;
                }
                in_word = 0;
                len = 0;
            }
            continue;
        }
        if (!in_word) {
            in_word = 1;
        }
        if (len < 99) {
            word[len++] = c;
        }
    }
    if (in_word) {
        word[len] = '\0';
        char first = tolower(word[0]);
        if (first == 'a' || first == 'e' || first == 'i' || first == 'o' || first == 'u') {
            for (int i = 0; i < len; i++) {
                putchar(toupper(word[i]));
            }
            printf("\n");
            count++;
        }
    }
    printf("\nNumber of words starting with a vowel: %d\n", count);
    printf("\nPress Enter to exit...");
    getchar();
    return 0;
}

//если слово удовлетворяет условию, делаем букву заглавной