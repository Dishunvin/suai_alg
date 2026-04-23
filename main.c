#include <stdio.h>
#include <stdlib.h>

#include "lib/labs.h"
#include "lib/functions.h"


int main () {
    system("cls");
    while (true) {
        printf("SUAI Algorithms -- labs\n");
        printf("1. lab1\n");
        printf("2. lab1-dop\n");
        printf("3. lab2\n");
        printf("4. lab2-dop\n");
        printf("5. lab3\n");
        printf("6. lab3-dop\n");
        printf("7. lab4\n");
        printf("8. lab5\n");
        printf("-1 to exit\n");

        int labToRun;
        input(&labToRun);

        switch (labToRun) {
            case -1:
                printf("Exiting program...\n");
                return 0;
            case 1:
                printf("Starting lab 1...\n");
                printf("\nLab ended with exit code %d", lab_1()); getchar(); getchar();
                break;
            case 2:
                printf("Starting lab 1-dop...\n");
                printf("\nLab ended with exit code %d", lab_1d()); getchar(); getchar();
                break;
            case 3:
                printf("Starting lab 2...\n");
                printf("\nLab ended with exit code %d", lab_2()); getchar(); getchar();
                break;
            case 4:
                printf("Starting lab 2-dop...\n");
                printf("\nLab ended with exit code %d", lab_2d()); getchar(); getchar();
                break;
            case 5:
                printf("Starting lab 3...\n");
                printf("\nLab ended with exit code %d", lab_3()); getchar(); getchar();
                break;
            case 6:
                printf("Starting lab 3-dop...\n");
                printf("\nLab ended with exit code %d", lab_3d()); getchar(); getchar();
                break;
            case 7:
                printf("Starting lab 4...\n");
                printf("\nLab ended with exit code %d", lab_4()); getchar(); getchar();
                break;
            case 8:
                printf("Starting lab 5...\n");
                printf("\nLab ended with exit code %d", lab_5()); getchar(); getchar();
                break;
            default:
                printf("There's no such lab!\n");
                getchar(); getchar();
                break;
        }
        system("cls");
    }
}