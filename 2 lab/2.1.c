// first solution, number 28
#include <stdio.h>
#include <math.h>
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
