#include <stdio.h>
#include <stdlib.h>

int main() {
    double l, v1, t, v2;

    // Input data
    printf("Enter the distance between points A and B (l, km): ");
    scanf("%lf", &l);

    printf("Enter the speed of the first pedestrian (v1, km/h): ");
    scanf("%lf", &v1);

    printf("Enter the time until meeting (t, hours): ");
    scanf("%lf", &t);

    // Clear input buffer
    while (getchar() != '\n');

    // Check for valid input
    if (l <= 0 || v1 <= 0 || t <= 0) {
        printf("Error: All values must be positive.\n");
        return 1;
    }

    if (v1 * t > l) {
        printf("Error: The first pedestrian would reach point B before the meeting time.\n");
        return 1;
    }

    if (v1 * t == l) {
        printf("The second pedestrian is standing still (0 km/h).\n");
        return 0;
    }

    // Calculate the speed of the second pedestrian
    v2 = (l - v1 * t) / t;

    // Output result
    printf("The speed of the second pedestrian is: %.2f km/h.\n", v2);

    // Pause before exit
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
