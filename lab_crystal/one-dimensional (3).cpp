#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int A[100];
	int number_of_zeroes = 0;
	int a[96];
	int b[96];
	for (int n = 4; n < 100; n++) {
		for (int i = 0; i < n; ++i) {
			if (i % 2 == 1) {
				A[i] = 0;
				number_of_zeroes = number_of_zeroes + 1;
			}
			else {
				A[i] = 1;
			}
		}
		int time = 0;
		while (number_of_zeroes != 0) {
			//сдвиг пустот
			for (int i = 0; i < n; ++i) {
				int variant;
				if (A[i] == 0) {
					if (i == 0 || i == n - 1) {
						A[i] = 1;
						number_of_zeroes = number_of_zeroes - 1;
						continue;
					}
					variant = rand() % 2;
					if (variant == 0) {
						swap(A[i], A[i + 1]);
					}
					else {
						if (variant == 1) {
							swap(A[i], A[i - 1]);
						}
					}
				}
			}
			//проверка на слипание 
			for (int i = 0; i < n; ++i) {
				if (A[i] == 0 && i != 0 && i != n - 1) {
					if (A[i + 1] == 0) {
						A[i] = 1;
						A[i + 1] = 1;
						number_of_zeroes = number_of_zeroes - 2;
					}
				}
				if (A[i] == 0 && i != 0 && i != n - 1) {
					if (A[i - 1] == 0) {
						A[i] = 1;
						A[i - 1] = 1;
						number_of_zeroes = number_of_zeroes - 2;
					}
				}
			}
			time = time + 1;
		}
		a[n - 4] = n;
		b[n - 4] = time;
	}
	for (int k = 0; k < 96; k++) {
		cout << a[k];
		cout << endl;
	}
	cout << endl;
	for (int k = 0; k < 96; k++) {
		cout << b[k];
		cout << endl;
	}

	return 0;
}