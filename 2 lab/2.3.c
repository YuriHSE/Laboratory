//third dolution, number 28
#include <stdio.h>
#include <math.h>
int function(long double a, long double b){ //function with one complex condition that returns true or false
    return a >= 0 && (b >= 0 && b <= 1 - 2*a || b < 0 && b >= -2*a - 1) || a < 0 && b < 0 && pow(a, 2) + pow(b, 2) <= 1;
}
int main(){
    long double x, y; //defining variables
    printf("Enter the value x and y: ");
    while ( (scanf("%Lf", &x)) != 1 || scanf("%Lf", &y) != 1) { //verification of entered data
        printf("Incorrect entered value, try again: ");
        while (getchar() != '\n');      
    }
    printf("Values:\nx = %-10Lf \ny = %-10Lf\n", x, y);
    if (function(x, y)) { //testing a function for true and false
        printf("The point belongs");
    } else {
        printf("The point does not belong");
    }
}