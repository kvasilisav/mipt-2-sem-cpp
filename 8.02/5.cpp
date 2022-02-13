#include <iostream>
int main() {
	using namespace std;
	int a1, b1, c1, a2, b2, c2, x = 0, y = 0;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
	if (b1 == 0 || a1 * b2 == a2 * b1) {
		cout << "No";
	}
	else {
		int DivXY = a1 * b2 - a2 * b1;
		int DivX = b1 * c2 - b2 * c1;
		int DivY = c1 * a2 - c2 * a1;
		x = DivX / DivXY;
		y = DivY / DivXY;
		cout << x << "," << y << endl;
	}
	return 0;
}