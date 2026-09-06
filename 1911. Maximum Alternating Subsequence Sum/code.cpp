#include <bits/stdc++.h>
using namespace std;

// Memoization
class Solution {
public:
    long long solver(vector<int> &nums, int idx, bool flag, vector<vector<long long>> &dp){
        if(idx == nums.size()) return 0;

        if(dp[idx][flag] != -1) return dp[idx][flag];

        long long skip = solver(nums, idx + 1, flag, dp);

        int val = nums[idx];
        if(!flag){
            val = -val;
        }

        long long take = val + solver(nums, idx + 1, !flag, dp);

        return dp[idx][flag] = max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size() + 1, vector<long long>(2, -1));
        // True -> Even Indices, False -> Odd Indices
        return solver(nums, 0, true, dp);
    }
};

// Tabulation
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2, 0));
        // True -> Even Indices, False -> Odd Indices
        for(int i = 1; i < n + 1; i++){
            dp[i][0] = max(dp[i - 1][1] - nums[i - 1], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + nums[i - 1], dp[i - 1][1]);
        }

        return max(dp[n][0], dp[n][1]);
    }
};