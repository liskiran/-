#include <iostream>

using namespace std;

void matr_i_j(int mas[50][50], int p[50][50], int i_, int j_, int m) {
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
int determinant(int mas[50][50], int m) {
    int i, j = 0, d = 0, n = m - 1;
    int p[50][50];
    if (m == 1) {
        return mas[0][0];
    }
    if (m == 2) {
        return mas[0][0] * mas[1][1] - mas[1][0] * mas[0][1];
    }
    if (m > 2) {
        for (i = 0; i < m; i++) {
            matr_i_j(mas, p, i, 0, m);
            if(i % 2 == 0) d += mas[i][0] * determinant(p, n);
            else d -= mas[i][0] * determinant(p, n);
        }
    }
    return(d);
}
int main() {
	int n;
	cout << "Press n: ";
	cin >> n;
	int matrix[50][50];
	cout << "Press elements of matrix(n * n): " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	int result = determinant(matrix, n);
	cout << "Result: det = "<< result;
	return 0;
}