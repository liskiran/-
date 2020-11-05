#include <iostream>

using namespace std;

void matr_i_j(double mas[50][50], double p[50][50], int i_, int j_, int m) {
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
double determinant(double mas[50][50], int m) {
    int i, j = 0, d = 0, n = m - 1;
    double p[50][50];
    if (m == 1) {
        return mas[0][0];
    }
    if (m == 2) {
        return mas[0][0] * mas[1][1] - mas[1][0] * mas[0][1];
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
    int n;
    cout << "Press n: ";
    cin >> n;
    double matrix[50][50];
    cout << "Press elements of matrix(n * n): " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    double b[50] = { 0 };
    cout << "Press elements of matrix_b(n): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    double reverse_matrix[50][50];
    double extra_matrix[50][50];
    double res[50];
    // AX = b => X = A^-1 * b
    double det_matrix = determinant(matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matr_i_j(matrix, extra_matrix, j, i, n);
            if ((i + j) % 2 == 0) reverse_matrix[i][j] = determinant(extra_matrix, n - 1) / det_matrix;
            else reverse_matrix[i][j] = -determinant(extra_matrix, n - 1) / det_matrix;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reverse_matrix[i][j] << " ";
        }
        cout << endl;
    }
    double c;
    for (int i = 0; i < n; i++) {
        c = 0;
        for (int j = 0; j < n; j++) {
            c += reverse_matrix[i][j] * b[j];
        }
        res[i] = c;
        cout << endl;
    }
    cout << "X equal: " << endl;
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
    return 0;
}