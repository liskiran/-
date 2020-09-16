#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
double module_value(int a, int b) {
	return sqrt(a * a + b * b);
}

int main() {
	int a, b;
	double M_PI = 3.141592653589;
	cout << "Press Re and Im: ";
	cin >> a >> b;
	int n;
	cout << "Press n value: ";
	cin >> n;
	cout << "Classical complex value: (r)   (a + b * i) = " << a << " + " << b << " * i" << endl;
	cout << "Reversed complex value: (r^-1) (a - b * i) / (a^2 + b^2) = " << a / pow(module_value(a, b), 2)<< " + " << b / pow(module_value(a, b), 2) << " * i" << endl;
	double fi_corner = a > 0 && b > 0 ? acos(a / module_value(a, b)) * 180 / M_PI :
		a > 0 && b < 0 ? -acos(a / module_value(a, b)) * 180 / M_PI :
		a < 0 && b > 0 ? 180 - acos(-a / module_value(a, b)) * 180 / M_PI :
		a < 0 && b < 0 ? -180 + acos(-a / module_value(a, b)) * 180 / M_PI : 0;
	cout << fi_corner << endl;
	cout << "Trigonometry complex value:  r      = r * (cos(fi) + sin(fi) * i) = " << module_value(a, b) << " * (cos(" << fi_corner / 180 << " * pi)"
		<< " + sin(" << fi_corner / 180 << " * pi) * i)" << endl;
	cout << "Trigonometry complex value:  r^(n)  = r^(n) * ((cos(fi * n) + sin(fi * n) * i) = "
		<< pow(module_value(a, b), n) << " * (cos(" << fi_corner * n / 180 << " * pi)"
		<< " + sin(" << fi_corner * n / 180 << " * pi) * i)" << endl;
	cout << "Trigonometry complex value:  r^(-n) = r^(-n) * ((cos(fi * n) + sin(fi * n) * i) = "
		<< pow(module_value(a, b), -n) << " * (cos(" << fi_corner / (-n * 180) << " * pi)"
		<< " + sin(" << fi_corner / (-n * 180) << " * pi) * i)" << endl;
	double value = fi_corner;
	vector<double> corners;
	for (int k = 0; k < n; k++) {
		corners.push_back((fi_corner * n / 180 + 2 * M_PI * k) / n);
	}
	cout << "Corners for an equation with n degree: ";
	for (const auto& c : corners) {
		cout << c << "pi ";
	}
	return 0;
}