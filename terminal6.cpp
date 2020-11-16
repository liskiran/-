#include <iostream>

using namespace std;

void matr_i_j(double mas[10][10], double p[10][10], int i_, int j_, int m) {
    int i, j, di = 0, dj;
    for (i = 0; i < m - 1; i++) {
        if (i == i_) di = 1;
        dj = 0;
        for (j = 0; j < m - 1; j++) {
            if (j == j_) dj = 1;
            p[i][j] = mas[i + di][j + dj];
        }
    }
}
double determinant(double mas[10][10], int m) {
    int i, j = 0, d = 0, n = m - 1;
    double p[10][10];
    if (m == 1) {
        return (double)mas[0][0];
    }
    if (m == 2) {
        return (double)mas[0][0] * mas[1][1] - mas[1][0] * mas[0][1];
    }
    if (m > 2) {
        for (i = 0; i < m; i++) {
            matr_i_j(mas, p, i, 0, m);
            if (i % 2 == 0) d += mas[i][0] * determinant(p, n);
            else d -= mas[i][0] * determinant(p, n);
        }
    }
    return(d);
}
int main() {
    setlocale(LC_ALL, "rus");
    int n;
    cout << "Press n: ";
    cin >> n;
    double matrix[10][10];
    cout << "Press elements of matrix(n * n): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    double reverse_matrix[10][10];
    double extra_matrix[10][10];
    double det_matrix = determinant(matrix, n);
    if (det_matrix != 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matr_i_j(matrix, extra_matrix, j, i, n);
                if ((i + j) % 2 == 0) reverse_matrix[i][j] = determinant(extra_matrix, n - 1) / det_matrix;
                else reverse_matrix[i][j] = -determinant(extra_matrix, n - 1) / det_matrix;
            }
        }
        cout << "Reversed matrix: " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << reverse_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "Обратной матрицы не существует.";
    }
    return 0;
}