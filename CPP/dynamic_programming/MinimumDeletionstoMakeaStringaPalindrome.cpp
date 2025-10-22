#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the Longest Palindromic Subsequence
int longestPalindromicSubsequence(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    int n = s.length();
    
    // DP table for LCS(s, reverse(s))
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == rev[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][n];
}

int minDeletionsToPalindrome(string s) {
    int lps = longestPalindromicSubsequence(s);
    return s.length() - lps;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = minDeletionsToPalindrome(s);
    cout << "Minimum deletions to make it palindrome: " << result << endl;

    return 0;
}
