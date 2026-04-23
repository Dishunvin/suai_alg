#include <stdio.h>

double v2_res(double L, double v1,double t){
    


return ( L - v1 * t) / t;

}

int main() {
    double L, v1, t, v2;

    // Data input
    printf("Enter the distance between points A and B (L, km): ");
    scanf("%lf", &L);
    
    printf("Enter the speed of the first pedestrian (v1, km/h): ");
    scanf("%lf", &v1);
    
    printf("Enter the meeting time (t, hours): ");
    scanf("%lf", &t);

    // Clear input buffer
    while (getchar() != '\n');

    // Linear algorithm: calculate the speed of the second pedestrian
    // Distance covered by the first: v1 * t
    // Distance covered by the second: L - v1 * t
    // Speed of the second: (L - v1 * t) / t
    v2 = (L - v1 * t) / t;
    
    // Output result
    printf("The speed of the second pedestrian is: %.2f km/h\n", v2);
    
    // Pause before exit
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}