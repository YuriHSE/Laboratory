// second solution, number 28
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
    //one conditional statement with a complex condition
    if (x >= 0 && (y >= 0 && y <= 1 - 2*x || y < 0 && y >= -2*x - 1) || x < 0 && y < 0 && pow(x, 2) + pow(y, 2) <= 1){
        printf("The point belongs");
    } else {
        printf("The point does not belong");
    }
}