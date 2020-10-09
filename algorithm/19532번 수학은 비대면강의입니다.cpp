#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int x = (b*f - c * e) / (b*d - e * a);
	int y = (d*c - a * f) / (d*b - a * e);
	cout << x << " " << y << '\n';
}