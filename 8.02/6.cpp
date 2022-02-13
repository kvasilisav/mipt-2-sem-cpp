#include <iostream>
int main() {
	using namespace std;
	int x, y, a, b, r, x1, y1;
	cin >> x >> y >> a >> b >> r;
	x1 = x - a;
	y1 = y - b;
	if ((x1 * x1 + y1 * y1) <= r * r) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}
