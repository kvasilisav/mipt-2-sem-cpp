#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*int levdist(string s1, string s2, int n, int m) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }

        }
    }
    return dp[n][m];
}*/

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int l1, l2;
    l1 = s1.length();
    l2 = s2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    for (int i = 0; i <= l1; ++i)
    {
        for (int j = 0; j <= l2; ++j)
        {
            if (i == 0) {
                dp[i][j] = j;
            }
            else if (j == 0) {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }

        }
    }
    cout << dp[l1][l2] << endl;
    for (int i = 0; i < l1; i++) {
        for (int j = 0; j < l2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}