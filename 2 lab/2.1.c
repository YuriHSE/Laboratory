// first solution, number 28
#include <stdio.h>
#include <math.h>
int main(){
    long double x, y; //defining variables
    printf("Enter the value x and y: ");
    while ( (scanf("%Lf", &x)) != 1 || scanf("%Lf", &y) != 1) { //verification of entered data
        printf("Incorrect entered value, try again: ");
        while (getchar() != '\n');      
    }
    printf("Values:\nx = %-10Lf \ny = %-10Lf\n", x, y); 
    //nested conditional statements with simple conditions
    if (x>=0){
        if (y>=0){
            if (y <= 1 - 2*x){
                printf("The point belongs");
            } else {
                printf("The point does not belong");
            }
        } else if ( y >= -2*x - 1){
            printf("The point belongs");
        } else{
            printf("The point does not belongs");
        }
    } else if (y < 0){
        if (pow(x, 2) + pow(y, 2) <= 1){
            printf("The point belongs");
        }
    } else{
        printf("The point does not belong");
    }
}