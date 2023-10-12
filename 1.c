// number 28
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/*int f8(long long x) {
    int sign;
    if (x<0){
        x = -x;
        sign = -1;
    } else{
        sign = 1;
    }
    long long int size8 = log(x)/log(8) + 1, count1 = 0;
    long long int octal[size8];
        
    while (x>0){
        octal[count1] = x % 8;
        x /= 8;
        count1++;
    }
    octal[size8 - 1] *= sign;
    for (int i = size8 - 1; i>-1; --i) {
        printf("%lld", octal[i]);
    }
    return 0;
}
int f16(long long y){
    long long int size16 = log(y)/log(16) + 1;
    long long int hex[size16], count2 = 0;
    while (y>0){
        hex[count2] = y % 16;
        y /= 16;
        count2++;
    }
    for (int j = size16 - 1; j>-1; --j) {
        if (hex[j] > 9){
            char c = (char)(65 + hex[j] - 10);
            printf("%c", c);
        } else {
            printf("%lld", hex[j]);
        }
    }
    return 0;
}*/
int main(){
    long long int x, y; //defining variables
    long double z, a, b;
    printf("Enter the value x: ");
    while ( (scanf("%lld", &x)) != 1 ) { //verification of entered data
        printf("Incorrect entered value, try again: ");
        while (getchar() != '\n');       
    }
    while (getchar() != '\n'); //clearing the buffer from the remainder of the entered line
    printf("Enter the value y: ");
    while ( (scanf("%lld", &y)) != 1 ) {
        printf("Incorrect entered value, try again: ");
        while (getchar() != '\n');
    }
    while (getchar() != '\n');
    printf("Enter the value z: ");
    while ( (scanf("%Lf", &z)) != 1 ) {
        printf("Incorrect entered value, try again: ");
        while (getchar() != '\n');      
    }
    while (getchar() != '\n');


    printf("Values:\nx = %-10lld \ny = %-10lld \nz = %-10.5LE \nResults:\n", x, y, z); //output of entered data, field width 10 left


    if (cos(2*pow(x, 3) - 7) >=0 && cos(2*pow(x, 3) - 7) != pow(3.4, 2)){ //denominator check
        a = pow(llabs(y-2*x), (float)(1/3)) / (sqrt(cos(2*pow(x, 3) - 7)) - 3.4); //calculation of the function a
        printf("a = %.4Lf \n", a); //function value output a
    } else {
        printf("Incorrect entered value for a, try again \n");
    }
    b = atan((2*x) / (fabsl(3*z - 1) + 4)); //calculation of the function b
    printf("b = %.4Lf\n", b); //function value output b
    if (x < 0){ //output in octal number system, taking into account sign
        x = -x;
        printf("x in octal number system: -%llo\n", x);
    } else {
        printf("x in octal number system: %llo\n", x);
    }
    if (y<0){ //output in hexadecimal number system, taking into account sign
        y = -y;
        printf("y in hexacademical number system: -%llx", y);
    } else {
        printf("y in hexacademical number system: %llx", y);
    }
}
