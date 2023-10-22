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
        long double slag = (long double)numerator / denominator; 
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
    printf("%.*Lf\n", a, sum);
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
    printf("%.*Lf\n", a, sum);
    return 0;
}
long long int number_sequence(int k){ //calculating denominator and numerator
    long long int t = 1;
    while(k>0){
        t *= k;
        k -= 2;
    }
    return t;
}
long double sum(int n, long double x){ //expression counting
    long double num, det;
    if (n == 0){
        return 1;
    } else {
        num = pow(-1, n) * pow(x, n) * number_sequence(2*n - 1);
        det = number_sequence(2*n);
    }
    return num / det + sum(n-1, x);
}
int main(){ 
    long double x;
    int n, accuracy, p;
    char a;
    printf("Enter the value x, n and accuracy: ");
    while (1){ //the cycle will not be interrupted until incorrect data is entered
        while(scanf("%Lf", &x) != 1 || fabs(x) >= 1 || scanf("%d", &n) != 1 || scanf("%d", &accuracy) != 1){ //checking the first characters of the input data
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
    printf("How to calculate a function: through a cycle \x1B[1;31mWHILE\x1B[0;37m or through a cycle \x1B[1;31mFOR\x1B[0;37m, write the number 1 or 2 accordingly\nEnter the value: ");
    scanf("%d", &p);
    while (p != 1 && p != 2){
        printf("Error\nTry again: ");
        while(getchar() != '\n');
        scanf("%d", &p);
    }
    printf("Result through cycles: ");
    if (p == 1) f_while(x, n, accuracy); //selection operator
    if (p == 2) f_for(x, n, accuracy);
    printf("Result through recursion: %.*Lf", accuracy, sum(n, x));
}
// на 10! и не только при большом количестве знаков х расхождение на 10^-15
// для всех кроме 0,5 расхождение на 10^-15
