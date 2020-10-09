#include <iostream>
#include <vector>
using namespace std;

struct Point{
	int x, y;
	Point(int xpos=0, int ypos=0) : x(xpos), y(ypos) {}
	friend ostream& operator<<(ostream&, Point&);
	friend istream& operator>>(istream&, Point&);
	bool operator>(Point &p) {
		if (x < p.x && y < p.y)
			return true;
	}
	Point& operator=(Point & p) {
		this->x = p.x;
		this->y = p.y;
		return *this;
	}
};
ostream& operator<<(ostream& os, Point& p) {
	os << p.x << " " << p.y;
	return os;
}
istream& operator>>(istream& is, Point& p) {
	is >> p.x >> p.y;
	return is;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N; cin >> N;
	vector<Point> v(N);
	for (int i = 0; i < N; i++) {
		Point p; cin >> p;
		v[i] = p;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (v[i].x  > v[j].x) {
				Point tmp = v[i]; 
				v[i] = v[j];
				v[j] = tmp;
			}
			else if (v[i].x == v[j].x) {
				if (v[i].y > v[j].y ) {
					Point tmp2 = v[i];
					v[i] = v[j];
					v[j] = tmp2;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << v[i] <<'\n';
	}
}