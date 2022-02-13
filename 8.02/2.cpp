#include <iostream>
int main() {
	using namespace std;
	int n, m, i = 0, min = 0, k = 1;
	cin >> n;
	cin >> m;
	min = m;
	while (i < n-1) {
		i++;
		cin >> m;
		if (m < min) {
			min = m;
			k = 1;
		}
		else if (m == min) {
			k++;
		}
	}
	cout << "min = " << min << ", number of repetitions = " << k << endl;
	return 0;
}
