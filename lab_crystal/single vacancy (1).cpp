#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	int A[100][100];
	int a[96];
	int b[96];
	for (int n = 4; n < 100; n++) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == j && i == n / 2) {
					A[i][j] = 0;
				}
				else {
					A[i][j] = 1;
				}
			}
		}
		int number_of_zeroes = 1;
		int time = 0;
		while (number_of_zeroes != 0) {
			//проверка нулей на краю
			for (int i = 0; i < n; ++i) {
				if (A[i][n - 1] == 0) {
					A[i][n - 1] = 1;
					number_of_zeroes = number_of_zeroes - 1;
				}
				if (A[i][0] == 0) {
					A[i][0] = 1;
					number_of_zeroes = number_of_zeroes - 1;
				}		
			}
			for (int j = 0; j < n; ++j) {
				if (A[0][j] == 0) {
					A[0][j] = 1;
					number_of_zeroes = number_of_zeroes - 1;
				}
				else {
					if (A[n - 1][j] == 0) {
						A[n - 1][j] = 1;
						number_of_zeroes = number_of_zeroes - 1;
					}
				}
			}
			if (number_of_zeroes == 0) {
				break;
			}
			//сдвиг пустот
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					int variant;
					if (A[i][j] == 0) {
						if (i == 0 || j == 0 || i == n - 1 || j == n - 1) {
							A[i][j] = 1;
							number_of_zeroes = number_of_zeroes - 1;
							continue;
						}
						variant = rand() % 4;
						if (variant == 0) {
							A[i][j] = 1;
							A[i + 1][j] = 0;
						}
						else {
							if (variant == 1) {
								A[i][j] = 1;
								A[i][j + 1] = 0;
							}
							else {
								if (variant == 2) {
									A[i][j] = 1;
									A[i - 1][j] = 0;
								}
								else {
									A[i][j] = 1;
									A[i][j - 1] = 0;
								}
							}
						}
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
