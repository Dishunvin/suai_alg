#include <stdio.h>
#include <ctype.h>

int main() {
    int c;
    int in_word = 0;
    int count = 0;

    printf("Enter text (press Ctrl+Z then Enter to finish):\n");

    while ((c = getchar()) != EOF) {
        char lower = tolower(c);

        if (c == ' ' || c == '.' || c == ',' || c == '!' || 
            c == '?' || c == ';' || c == ':' || c == '\n' || c == '\t') {
            in_word = 0;  
        }
        else {
            if (in_word == 0) {  
                if (lower == 'a' || lower == 'e' || lower == 'i' || 
                    lower == 'o' || lower == 'u') {
                    count++;
                    c=toupper(c);
                    }
                in_word = 1;
             
               printf("\nChar: %c\n", c);
            }
            
        }

        
    }

    printf("\nNumber of words starting with a vowel: %d\n", count);

    printf("\nPress Enter to exit...");
    

    return 0;
}
//если слово удовлетворяет условию, делаем букву заглавной