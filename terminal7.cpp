#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<math.h>
void gauss_method(double a[40][40], int m, int n) {
	int flag = 0;
	double x = 0, r = 0;
	//перестановка строк чтобы на главной диагонали нулей не было
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			if ((a[j][i] != 0.0) && (j != i)) {
				for (int m = 0; m < n; m++) {
					// меняем строки
					r = a[j][m];
					a[j][m] = a[i][m];
					a[i][m] = r;
				}
				break;
			}
			if ((a[j][i] != 0.0) && (j == i)) break;
		}
	}
	//приводим к ступенчатому виду
	int m1;
	if (m > n)
		m1 = n;
	else
		m1 = m;
	// гаусс вниз и вверх для прямоугольных и квадратных матриц
	for (int i = 0; i < m1; i++) {
		if (a[i][i] != 0.0) {
			for (int j = i + 1; j < m1; j++) {
				x = a[j][i] / a[i][i];
				for (int l = 0; l < n; l++) {
					a[j][l] = a[j][l] - x * a[i][l];
				}
			}
		}
	}
	for (int i = m1 - 1; i > 0; i--) {
		if (a[i][i] != 0.0) {
			for (int j = i - 1; j >= 0; j--) {
				x = a[j][i] / a[i][i];
				for (int l = 0; l < n; l++) {
					a[j][l] = a[j][l] - x * a[i][l];
				}
			}
		}
	}

	int kol = 0;
	// строки равные нулю отправляем вниз матрицы
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0.0) {
				kol += 1;
			}
		}
		// если строка равна нулевая перемещаем вниз
		if (kol == 0) {
			for (int h = i; h < m - 1; h++) {
				for (int l = 0; l < n; l++) {
					a[h][l] = a[h + 1][l];
					a[h + 1][l] = 0;
				}
			}
		}
		kol = 0;
	}
}
void find_fundamental_solution(double a[40][40], int n, int m) {
	gauss_method(a, m, n);
	int b[40] = { 0 };
	double ix[40] = { 0 };
	int niz = 0;
	int kol = 0;
	//ищем нижнюю ненулевую строку
	for (int i = m - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0.0) {
				niz = i;
				break;
			}
		}
		if (niz != 0) break;
	}
	//printf("%d\n",niz);
	int sum = 0;
	//ищем зависимые переменные
	for (int i = niz; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] != 0.0) {
				b[j] += 1;
				sum += 1;
				break;
			}
		}
	}
	int in = 1;
	printf("Fundamental system of solution\n\n");
	// если сумма равно n, то тогда нулевой столбец единственное решение
	if (sum == n) {
		printf("1) ");
		for (int i = 0; i < n; i++) {
			printf("%f ", 0);
		}
		return;
	}
	int t = n;
	if (abs(n - m) > 1) t = n - 1;
	for (int i = 0; i < t; i++) {
		if (b[i] == 0) {
			ix[i] = 1;
			for (int j = niz; j >= 0; j--) {
				for (int l = 0; l < n; l++) {
					if (a[j][l] != 0.0) {
						// тут находим базисный корень 
						for (int h = l + 1; h < n; h++) {
							ix[l] += ix[h] * a[j][h] * (-1);
						}
						ix[l] = ix[l] / a[j][l];
						break;
					}
				}
			}
			printf("%d) ", in);
			in += 1;
			for (int m = 0; m < n; m++) {
				printf("%lf ", ix[m]);
			}
			for (int q = 0; q < n; q++) ix[q] = 0;
			printf("\n");
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m); //  Введите размерность матрицы
	double a[40][40];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%lf", &a[i][j]); // Введите значения матрицы
		}
	}
	find_fundamental_solution(a, m, n);

	return 0;
}
