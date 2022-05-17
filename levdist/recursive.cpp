#include<iostream>
#include<string>

using namespace std;

int min(int a, int b, int c) {
    if (a > b) {
        if (b > c) {
            return c;
        }
        return b;
    }
    else {
        if (a > c) {
            return c;
        }
        return a;
    }
}

int levdist(string s1, string s2, int i, int j) {
    if (i == 0) {
        return j;
    }
    else {
        if (j == 0) {
            return i;
        }
        else {
            if (s1[i] == s2[j]) {
                return levdist(s1, s2, i - 1, j - 1);
            }
            else {
                return 1 + min(levdist(s1, s2, i - 1, j - 1), levdist(s1, s2, i - 1, j), levdist(s1, s2, i, j - 1));
            }

        }

    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1, l2;
    l1 = s1.length();
    l2 = s2.length();
    cout << levdist(s1, s2, l1, l2);
    return 0;
}