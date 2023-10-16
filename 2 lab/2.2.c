// second solution, number 28
#include <stdio.h>
#include <math.h>
int main(){
    long double x, y; //defining variables
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
    //one conditional statement with a complex condition
    if (x >= 0 && (y >= 0 && (y < 1 - 2*x || fabs(y - 1 + 2*x) < 0.000001) || (y < 0 && (y > 2*x - 1 || fabs(y - 2*x + 1) < 0.000001))) || (x < 0 && y <= 0 && (pow(x, 2) + pow(y, 2) < 1 || fabs(pow(x, 2) + pow(y, 2) - 1) < 0.000001))){
        printf("The point belongs");
    } else {
        printf("The point does not belong");
    }
}
