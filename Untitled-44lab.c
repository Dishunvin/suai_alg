#include <stdio.h>

int main() {
    char text[1000];          // исходная строка
    char result[1000] = {0};  // строка-результат (обнулена)
    int i, j;                 // индексы для обхода
    int word_num;             // счётчик слов
    int source;               // выбор источника (1 – терминал, 2 – файл)
    FILE *infile, *outfile;   // указатели на файлы
    char filename[100];       // для имени файла

    // ----- 1. Выбор источника ввода -----
    printf("Выберите источник ввода:\n");
    printf("1 – ввод с клавиатуры\n");
    printf("2 – чтение из файла\n");
    printf("Ваш выбор: ");
    scanf("%d", &source);
    getchar();  // убираем символ новой строки после scanf

    if (source == 1) {
        // Ввод с клавиатуры
        printf("Введите строку: ");
        fgets(text, sizeof(text), stdin);
    } 
    else if (source == 2) {
        // Чтение из файла
        printf("Введите имя файла для чтения: ");
        fgets(filename, sizeof(filename), stdin);
        // удаляем символ новой строки из имени файла
        for (i = 0; filename[i] != '\0'; i++) {
            if (filename[i] == '\n') {
                filename[i] = '\0';
                break;
            }
        }
        infile = fopen(filename, "r");
        if (infile == NULL) {
            printf("Ошибка: не удалось открыть файл %s\n", filename);
            return 1;
        }
        // читаем первую строку из файла (максимум 999 символов)
        if (fgets(text, sizeof(text), infile) == NULL) {
            printf("Ошибка: файл пуст или не удалось прочитать строку\n");
            fclose(infile);
            return 1;
        }
        fclose(infile);
    } 
    else {
        printf("Неверный выбор. Завершение программы.\n");
        return 1;
    }

    // ----- 2. Удаление символа перевода строки (если есть) -----
    for (i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
    }

    // ----- 3. Обработка строки: удаление слов с чётным номером -----
    i = 0;
    j = 0;
    word_num = 0;

    while (text[i] != '\0') {
        // пропускаем пробелы и табуляции
        while (text[i] == ' ' || text[i] == '\t') {
            i++;
        }
        if (text[i] == '\0') break;  // достигнут конец строки

        word_num++;                  // нашли новое слово
        int word_start = i;          // запоминаем начало

        // ищем конец слова (пробел, табуляция или конец строки)
        while (text[i] != '\0' && text[i] != ' ' && text[i] != '\t') {
            i++;
        }

        // если слово нечётное – копируем в результат
        if (word_num % 2 == 1) {
            for (int k = word_start; k < i; k++) {
                result[j++] = text[k];
            }
            result[j++] = ' ';  // добавляем пробел после слова
        }
    }

    // убираем последний лишний пробел, если он есть
    if (j > 0 && result[j-1] == ' ') {
        j--;
    }
    result[j] = '\0';   // завершаем строку-результат

    // ----- 4. Запись результата в файл (всегда) -----
    outfile = fopen("result.txt", "w");
    if (outfile == NULL) {
        printf("Ошибка: не удалось создать файл result.txt\n");
        return 1;
    }
    fprintf(outfile, "%s\n", result);
    fclose(outfile);

    // ----- 5. Сообщение пользователю -----
    printf("Результат записан в файл result.txt\n");
    printf("Содержимое результата: %s\n", result);
    printf("\nНажмите Enter для выхода...");
    getchar();

    return 0;
}
