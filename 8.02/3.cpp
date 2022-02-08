#include <iostream>
int main() {
	using namespace std;
	int h1=0, h2, n = 0, i = 0;
	cin >> h2;
	do {
		i++;
		h1 = h2;
		cin >> h2;
		if (h2 > h1) {
			n++;
		}
	} while (h2 != 0);
	cout << n << endl;
	return 0;
}

