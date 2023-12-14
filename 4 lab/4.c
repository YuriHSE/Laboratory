#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double task1(double *arr, double y, int count) {
    double max = -1;
    for (int i = 0; i < count; i++) {
        if (fabs(arr[i]) < y && fabs(arr[i]) > max) max = fabs(arr[i]);
    }
    return max;
}
double task2(double *arr, int count) {
    int min = 0;
    for (int i = 1; i < count; i++){
        if (arr[i] < arr[min]) min = i;
    }

    double sum = 0;
    for (int i = min + 1; i < count; i++){
        sum += arr[i];
    }
    return sum / (count - min - 1);
}
int main() {
    int size = 1;
    char a;
    double *arr = (double *)malloc(size * sizeof(double));
    if(arr == NULL) {
        printf("Error! Memory not allocated.");
        exit(0);
    }

    int count = 0;
    double num;
    printf("Enter array: ");
    while(1) {
        scanf("%lf", &num);

        if(count == size) {
            size += 1;
            arr = (double *)realloc(arr, size * sizeof(double));
            if(arr == NULL) {
                printf("Error! Memory not allocated.");
                exit(0);
            }
        }

        arr[count] = num;
        count++;

        scanf("%c", &a);
        if (a == '\n') {
            break;
        }

    }

    printf("\nArray of Numbers:\n");
    for(int i = 0; i < count; i++) {
        printf("%lf ", arr[i]);
    }

    // Free the memory
    free(arr);


    double y;
    printf("\nEnter y: ");
    scanf("%lf", &y);

    if (task1(arr, y, count) != -1) {
        printf("Answer to \x1B[1;31m1 task\x1B[0;37m: %lf\n", task1(arr, y, count));
    } else {
        printf("There are no numbers in the array modulo greater than y\n");
    }
    printf("Answer to \x1B[1;31m2 task\x1B[0;37m: %lf", task2(arr, count));
    return 0;
}