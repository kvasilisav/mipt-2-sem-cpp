#include <iostream>
int main() {
	using namespace std;
	int r1, r2, a, b, r;

	cout << "Enter first number: ";
	cin >> a; 

	cout << "Enter second number: ";
	cin >> b;

	r1 = a; 
	r2 = b;

	while (r2 > 0) {
		r = r1 % r2; 
		r1 = r2; 
		r2 = r;
	}

	cout << "GCD(" << a << "," << b << ") = " << r1 << endl;

}

