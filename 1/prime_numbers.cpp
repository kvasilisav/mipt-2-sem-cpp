#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, i;
    bool isPrime = true;
    cout << "Enter a number:";
    cin >> n;
    cout << n << endl;
    for (i = 2; i <= (sqrt(abs(n))); i++) {
        if (n % i == 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime)
        cout << "This is a prime number" << endl;
    else
        cout << "This is not a prime number" << endl;
    return 0;
}