#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longestCommonSubsequence(const string& s1, const string& s2, string& lcs) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return dp[m][n];
}

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string lcs;
    int length = longestCommonSubsequence(s1, s2, lcs);

    cout << length << endl;

    cout << lcs << endl;

    return 0;
}


