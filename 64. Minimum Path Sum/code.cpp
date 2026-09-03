#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;

                if (i == 0) {
                    // filling 1st row with only increasing sum of paths
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                }
                else if (j == 0) {
                    // filling 1st column with only increasing sum of paths
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                } else {
                    // choosing minimum of left and upper paths
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};