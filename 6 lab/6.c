#include <stdio.h>
#include <stdlib.h>

void delete_element(int* arr, int* n, int index) {
    if (index < 0 || index >= *n) {
        printf("Index out of range\n");
        return;
    }
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
}

void print_array(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int last_max(int* arr, int n){
    int max = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] >= arr[max]) max = i;
    }
    return max;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    if (n <= 0) return 0;

    int* arr = (int*) malloc(n * sizeof(int));
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Original array: \n");
    print_array(arr, n);

    int k = last_max(arr, n);   
    for (int i = 0; i < k; i++){
        if (arr[i] < 0 && arr[i] % 3 != 0) {
            delete_element(arr, &n, i);
            i--;
            k--;
        }
    }

    printf("Array after deletion: \n");
    print_array(arr, n);

    free(arr);

    return 0;
}
