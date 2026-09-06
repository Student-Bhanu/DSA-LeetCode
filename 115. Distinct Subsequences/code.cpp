#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
public:
    int solve(string &s, string &t, int m, int n, vector<vector<int>> &dp){
        if(n == 0) return 1;
        if(m == 0) return 0;

        if(dp[m - 1][n - 1] != -1) return dp[m - 1][n - 1];

        if(s[m - 1] == t[n - 1]){
            dp[m - 1][n - 1] = solve(s, t, m - 1, n, dp) + solve(s, t, m - 1, n - 1, dp);
        }
        else{
            dp[m - 1][n - 1] = solve(s, t, m - 1, n, dp);
        }

        return dp[m - 1][n - 1];
    }
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(s, t, m, n, dp);
    }
};

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        typedef unsigned int ui;
        vector<vector<ui>> dp(m + 1, vector<ui>(n + 1, 0));
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(j == 0){
                    dp[i][j] = 1;
                    continue;
                }

                if(i == 0){
                    continue;
                }

                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};

// Tabulation + Space optimized
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        typedef unsigned int ui;
        vector<ui> dp(n + 1);
        for(int i = 0; i <= m; i++){
            vector<ui> curr(n + 1, 0);
            for(int j = 0; j <= n; j++){
                if(j == 0){
                    curr[j] = 1;
                    continue;
                }

                if(i == 0){
                    continue;
                }

                if(s[i - 1] == t[j - 1]){
                    curr[j] = dp[j - 1] + dp[j];
                }
                else{
                    curr[j] = dp[j];
                }
            }
            dp = curr;
        }

        return dp[n];
    }
};