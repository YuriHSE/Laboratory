#include <stdio.h>
#include <stdlib.h>
int** create_matrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Enter the elements of the matrix
    for(int i = 0; i < rows; i++) {
        printf("Enter elements of row %d separated by space: ", i+1);
        for(int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Free the allocated memory
    /*for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);*/
    return matrix;
}
void output_matrix(int** matrix, int rows, int cols){
    // Display the matrix
    printf("\nMatrix:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
double task(int** matrix, int rows, int cols){
    double max1 = matrix[0][0];
    double max2 = matrix[rows - 1][cols - 1];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i < rows - 1 - j && matrix[i][j] > max1) {
                max1 = matrix[i][j];
            } else if (i > rows -  1 - j && matrix[i][j] > max2) {
                max2 = matrix[i][j];
            }
        }
    }
    return (max1 + max2) / 2;
}
int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);
    int** k = create_matrix(rows, cols);
    output_matrix(k, rows, cols);
    /*if (rows == cols) {
        printf("\x1B[1;31mAnswer\x1B[0;37m: %lf", task(k, rows, cols));
    } else {
        printf("A non-square matrix does not have a main and secondary diagonal");
    }*/
    printf("\x1B[1;31mAnswer\x1B[0;37m: %lf", task(k, rows, cols));
    return 0;
}