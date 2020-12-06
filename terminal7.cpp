#include <stdio.h>

void print(float matrix[40][40], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            printf("  %0.2f", matrix[i][j]);
        printf("\n");
    }
}

void swap(float matrix[40][40], int row1, int row2, int col) {
    for (int i = 0; i < col; i++) {
        float temp = matrix[row1][i];
        matrix[row1][i] = matrix[row2][i];
        matrix[row2][i] = temp;
    }
}
bool is_zero_rows(float matrix[40][40], int rows, int cols) {
    for(int i = 0; i < cols; i++) {
        if(matrix[rows][i] != 0) {
            return false;
        }
    }
    return true;
}

void gauss_method(float matrix[40][40], int rows, int cols) {
    int rank = cols;
    for (int row = 0; row < rank; row++) {
        if(is_zero_rows(matrix, row, cols)) {
            break;
        }
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
        //printf("\n");
       // print(matrix, rows, cols);
        //printf("\n");
    }
}
void find_fundamental_solution(float matrix[40][40], int rows, int cols) {
    int count_params = cols - rows;
    int peremennie = count_params;
    float params[40];
    for(int i = 0; i < 40; i++) {
        params[i] = 0;
    }
    int c = 0;
    float res = 0;
    float value;
    for(int i = 0; i < rows && peremennie != 0; i++) {
        res = 0;
         for(int j = 0; j < cols; j++) {
             if(matrix[i][j] != 0) {
                value = matrix[i][j];
                int count_no_zero = 0;
                j += 1;
                while(j < cols) {
                    if(matrix[i][j] != 0) {
                        res -= matrix[i][j] * 1; 
                        count_no_zero++;
                    }
                    j++;
                }
                params[c] = res / value;
                c += 1;
                peremennie--;
                if(count_no_zero == 1) {
                    params[c - 1] = 0;
                }
                break;
             }
         }
    }
    for(int i = 0; i < cols; i++) {
        printf("%0.2f  ", params[i]);
    }
}
int count_zero_rows(float matrix[40][40], int rows, int cols) {
    int result = rows;
    int c = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(matrix[i][j] != 0) c++;
        }
        if(c == 0) result--;
        c = 0;
    }
    return result;
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, k;
    scanf("%d%d", &n, &k); // Input dimension of the matrix
    float matrix[40][40];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%f", &matrix[i][j]); // Input values of matrix
        }
    }
    printf("Before:\n");
    print(matrix, n, k);
    gauss_method(matrix, n, k);
    printf("\nAfter:\n");
    print(matrix, n, k);
    printf("\n");
    find_fundamental_solution(matrix, count_zero_rows(matrix, n, k), k);
    return 0;
}
