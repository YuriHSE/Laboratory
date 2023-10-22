#include <stdio.h>
#include <math.h>
long double f_while(long double x, int n, int a){ //function for WHILE
    long double sum = 1;
    while (n){
        long long int numerator = 1, denominator = 1;
        int k = n; //copy n
        //counting each term
        while (k>0){
            numerator *= 2*k - 1;
            denominator *= 2*k;
            k--;
        }
        long double slag = (double)numerator / denominator; 
        sum += pow(-1, n)*pow(x, n) * slag;
        n--;
    }
    /*if (isnan(sum)){
        printf("The value is NAN");
    } else if (isinf(sum)){
        printf("The value is INF");
    } else {
        printf("Result: %.*Lf", a, sum);
    }*/
    printf("Result: %.*Lf", a, sum);
    return 0;
}
long double f_for(long double x, int n, int a){ //function for FOR 
    long double sum = 1;
    for (int i = 1; i < n+1; ++i){
        long long int slag1 = 1;
        long long int slag2 = 1;
        for (int j = 1; j <= i; ++j){
            slag1 *= 2*j - 1;
            slag2 *= 2*j;
        }
        long double slag = (long double)slag1 / slag2; 
        sum += pow(-1, i)*pow(x, i) * slag;     
    }
    printf("Result: %.*Lf", a, sum);
    return 0;
}
int main(){ 
    int p, a, n; //defining variables
    long double x;
    printf("Enter the x: ");
    scanf("%Lf", &x);
    while (fabs(x) >= 1){ //checking value for a given condition
        printf("Incorrect entered value, try again: ");
        while(getchar() != '\n');
        scanf("%Lf", &x);
    }
    while(getchar() != '\n'); //clearing the buffer from the remainder of the entered line
    printf("Enter the n: ");
    scanf("%d", &n);
    printf("Enter the accuracy: ");
    scanf("%d", &a);
    printf("How to calculate a function: through a cycle \x1B[1;31mWHILE\x1B[0;37m or through a cycle \x1B[1;31mFOR\x1B[0;37m, write the number 1 or 2 accordingly\nEnter the value: ");
    scanf("%d", &p);
    while (p != 1 && p != 2){
        printf("Error\nTry again: ");
        while(getchar() != '\n');
        scanf("%d", &p);
    }
    if (p == 1) f_while(x, n, a);
    if (p == 2) f_for(x, n, a);
}

