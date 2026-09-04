#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
public:
    int m, n;
    using V = vector<int>;
    using VB = vector<V>;
    using VBB = vector<VB>;
    VBB dp = VBB(71, VB(71, V(71, -1)));
    int solver(vector<vector<int>> &grid, int row, int col1, int col2){
        if(row >= m) {
            return 0;
        }

        if(dp[row][col1][col2] != -1) return dp[row][col1][col2];

        int curr = grid[row][col1];
        if(col1 != col2){ // if both are not at the same cell
            curr += grid[row][col2];
        }
        int ans = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                int newRow = row + 1;
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;

                if(newCol1 >= 0 && newCol1 < n && newCol2 >= 0 && newCol2 < n) {
                    ans = max(ans, solver(grid, newRow, newCol1, newCol2));
                }
            }
        }

        return dp[row][col1][col2] = curr + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        return solver(grid, 0, 0, n - 1);
    }
};

// Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        using V = vector<int>;
        using VB = vector<V>;
        using VVB = vector<VB>;
        VVB dp = VVB(71, VB(71, V(71)));
        dp[0][0][n - 1] = grid[0][0];
        // if both the robots are not starting from same point that is if there is more than 1 column
        if(n != 1){
            dp[0][0][n - 1] += grid[0][n - 1];
        }

        for(int row = 1; row < m; row++){
            for(int col1 = 0; col1 <= min(row, n - 1); col1++){
                for(int col2 = max(n - row - 1, 0); col2 < n; col2++){
                    int prevMax = 0;
                    for(int i = max(col1 - 1, 0); i <= min(col1 + 1, n - 1); i++){
                        for(int j = max(col2 - 1, 0); j <= min(col2 + 1, n - 1); j++){
                            prevMax = max(prevMax, dp[row - 1][i][j]);
                        }
                    }

                    dp[row][col1][col2] = grid[row][col1] + prevMax;
                    if(col1 != col2){
                        dp[row][col1][col2] += grid[row][col2];
                    }
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, dp[m - 1][i][j]);
            }
        }
        return ans;
    }
};

// Optimized + Tabulation
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prevState(n + 1, vector<int>(n + 1));
        prevState[0][n - 1] = grid[0][0];
        // if both the robots are not starting from same point that is if there is more than 1 column
        if(n != 1){
            prevState[0][n - 1] += grid[0][n - 1];
        }

        for(int row = 1; row < m; row++){
            vector<vector<int>> currState(n, vector<int>(n));
            for(int col1 = 0; col1 <= min(row, n - 1); col1++){
                for(int col2 = max(n - row - 1, 0); col2 < n; col2++){
                    int prevMax = 0;
                    for(int i = max(col1 - 1, 0); i <= min(col1 + 1, n - 1); i++){
                        for(int j = max(col2 - 1, 0); j <= min(col2 + 1, n - 1); j++){
                            prevMax = max(prevMax, prevState[i][j]);
                        }
                    }

                    currState[col1][col2] = grid[row][col1] + prevMax;
                    if(col1 != col2){
                        currState[col1][col2] += grid[row][col2];
                    }
                }
            }
            // we just only have to store previous state
            prevState = currState;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans = max(ans, prevState[i][j]);
            }
        }
        return ans;
    }
};