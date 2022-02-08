#include <iostream>
int main() {
	using namespace std;
	int n, i = 0, max = 0;
	do {
		i++;
		cin >> n;
		if (n > max && n % 2 == 0) {
			max = n;
		}
	} while (n != 0);
	cout << "The largest even number is " << max << endl;
	return 0;
}