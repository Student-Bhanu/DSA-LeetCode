#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];
        // we only required next row data , so we store it in 1-D array
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                // cost of moving from triangle[i][j] to bottom storing in 1-D array
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};