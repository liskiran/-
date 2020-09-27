#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define NAME_VARIABLE(var_) #var_

using namespace std;
int c = 1;
class Vector {
public:
	Vector() : x(0), y(0), z(0) {}
	Vector(double x_, double y_, double z_)
		  : x(x_), y(y_), z(z_)  {}
	string is_collinear(Vector a) {
		return ((double)(x / a.x) == (double)(y / a.y) == (double)(z / a.z)) ? "is collinear" : "is not collinear";
	}
	double x, y, z;
};
istream& operator>>(istream& stream, Vector& v) {
	stream >> v.x >> v.y >> v.z;
	return stream;
}
ostream& operator<<(ostream& stream, const Vector& v) {
	stream << "Vector " << c++ << ": {" << v.x << ", "  << v.y  << ", " << v.z << "}" << endl;
	return stream;
}

string is_coplanarity(Vector a, Vector b, Vector c) {
	return ((a.x * b.y * c.z) + (b.x * c.y * a.z) + (c.x * a.y * b.z) - (a.x * c.y * b.z) - (b.x * a.y * c.z) - (c.x * b.y * a.z)) == 0 ? "is coplanarity" : "is not coplanarity";
}

int main() {
	Vector v1, v2, v3;
	cin >> v1 >> v2 >> v3;
	cout << v1 << v2 << v3;
	cout << NAME_VARIABLE(v1) << " " << v1.is_collinear(v2) << " " << NAME_VARIABLE(v2) << endl;
	cout << NAME_VARIABLE(v2) << " " << v2.is_collinear(v3) << " " << NAME_VARIABLE(v3) << endl;
	cout << NAME_VARIABLE(v1) << " " << v1.is_collinear(v3) << " " << NAME_VARIABLE(v3) << endl;
	cout << is_coplanarity(v1, v2, v3) << endl;
	return 0;
}