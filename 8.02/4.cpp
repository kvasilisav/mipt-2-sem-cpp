#include <iostream>
int main() {
	using namespace std;
	int n, m1, m2, summin=0, summax=0, sum=0, i=0;
	cin >> n;
	cin >> m1;
	cin >> m2;
	summin = m1 + m2;
	while (i < n-2) {
		i++;
		m1 = m2;
		cin >> m2;
		sum = m1 + m2;
		if (sum < summin) {
			summin = sum;
		}
		else if (sum > summax) {
			summax = sum;
		}
	}
	cout << "sum of max = " << summax<< ", sum of min = " << summin << endl;
}