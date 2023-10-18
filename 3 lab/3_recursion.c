// first solution, number 28
#include <stdio.h>
#include <math.h>
int p1(int k){
    int t = 1;
    while(k>0){
        t *= k;
        k -= 2;
    }
    return t;
}
float sum(int n, float x){
    float num, det;
    if (n == 0){
        return 1;
    } else {
        num = pow(-1, n) * pow(x, n) * p1(2*n - 1);
        det = p1(2*n);
    }
    return num / det + sum(n-1, x);
}
int main(){
    float x;
    int n, accuracy;
    char a;
    printf("Enter the value x, n and accuracy: ");
    while (1){ //the cycle will not be interrupted until incorrect data is entered
        while(scanf("%f", &x) != 1 || scanf("%d", &n) != 1 || scanf("%d", &accuracy) != 1){ //checking the first characters of the input data
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
    printf("Values:\nx = %f \nn = %d\naccuracy = %d\n", x, n, accuracy);
    printf("%.*f", accuracy, sum(n, x));
}