#include <stdio.h>

void print(float matrix[40][40], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("  %f", matrix[i][j]);
        printf("\n");
    }
}

void swap(float matrix[40][40], int row1, int row2, int col) {
    for (int i = 0; i < col; i++) {
        int temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}

int Rank(float matrix[40][40], int rows, int cols) {
    int rank = cols;
    for (int row = 0; row < rank; row++) {
        if (row < cols && row < rows && matrix[row][row] != 0) {
            for (int col = 0; col < rows; col++) {
                if (col != row) {
                    float mult = matrix[col][row] / matrix[row][row];
                    for (int i = 0; i < rank; i++)
                        matrix[col][i] -= mult * matrix[row][i];
                }
            }
        } else {
            bool reduce = true;
            for (int i = row + 1; i < rows; i++){
                if (matrix[i][row] != 0){
                    swap(matrix, row, i, rank);
                    reduce = false;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < rows; i++)
                    matrix[i][row] = matrix[i][rank];
            }
            row--;
        }
    }
    return rank;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k); // Input dimension of the matrix
    float matrix[40][40];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &matrix[j][i]); // Input values of matrix
        }
    }
    printf("Before:\n");
    print(matrix, n, k);
    int rank = Rank(matrix, n, k);
    printf("\nAfter:\n");
    print(matrix, n, k);
    printf("\n");
    printf("Rank matrix: %d", rank);

    return 0;
}
