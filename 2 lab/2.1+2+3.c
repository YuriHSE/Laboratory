#include <stdio.h>
#include <math.h>
int function(long double a, long double b){ //function with one complex condition that returns true or false
    return a >= 0 && (b >= 0 && (b < 1 - 2*a || fabs(b - 1 + 2*a) < 0.000001) || (b < 0 && (b > 2*a - 1 || fabs(b - 2*a + 1) < 0.000001))) || (a < 0 && b <= 0 && (pow(a, 2) + pow(b, 2) < 1 || fabs(pow(a, 2) + pow(b, 2) - 1) < 0.000001));
}
int main(){
    long double x, y;
    char a;
    printf("Enter the value x and y: ");
    while (1){ //the cycle will not be interrupted until incorrect data is entered
        while(scanf("%Lf", &x) != 1 || scanf("%Lf", &y) != 1){ //checking the first characters of the input data
            printf("Incorrect value, try again: ");
            while(getchar() != '\n');
        }
        scanf("%c", &a);
        if (a == '\n'){ //lazy input for remainder of last element
            break;
        } else {
            printf("Incorrect value, try again: ");
            while(getchar() != '\n');
            //continue
        }
    }
    printf("Values:\nx = %-10Lf \ny = %-10Lf\n", x, y);
    //nested conditional statements with simple conditions
    printf("Result of the first decision: ");
    if (x>=0){
        if (y>=0){
            if (y < -2*x + 1){
                printf("the point belongs\n");
            } else if (fabs(y + 2*x - 1) < 0.0000001) {
                printf("the point belongs\n");
            } else {
                printf("the point does not belong\n");
            }
        } else if (y > -1 + 2*x){
            printf("the point belongs\n");
        } else if (fabs(y + 1 - 2*x) < 0.0000001){
            printf("the point belongs\n");
        } else{
            printf("the point does not belongs\n");
        }
    } else if (y <= 0){
        if (pow(x, 2) + pow(y, 2) < 1){
            printf("the point belongs\n");
        } else if (fabs(pow(x, 2) + pow(y, 2) - 1) < 0.00000001){
            printf("the point belongs\n");
        } else {
            printf("the point does not belong\n");
        }
    } else{
        printf("the point does not belong\n");
    }


    printf("Result of the second decision: ");
    if (x >= 0 && (y >= 0 && (y < 1 - 2*x || fabs(y - 1 + 2*x) < 0.000001) || (y < 0 && (y > 2*x - 1 || fabs(y - 2*x + 1) < 0.000001))) || (x < 0 && y <= 0 && (pow(x, 2) + pow(y, 2) < 1 || fabs(pow(x, 2) + pow(y, 2) - 1) < 0.000001))){
        printf("the point belongs\n");
    } else {
        printf("the point does not belong\n");
    }


    printf("Result of the third decision: ");
    if (function(x, y)) { //testing a function for true and false
        printf("the point belongs");
    } else {
        printf("the point does not belong");
    }

}
