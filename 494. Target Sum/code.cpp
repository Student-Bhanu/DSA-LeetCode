#include <bits/stdc++.h>
using namespace std;

// Recursion
class Solution {
public:
    int solver(vector<int> &nums, int target, int i, int prevSum, int n){
        if(i == n){
            if(prevSum == target) return 1;
            
            return 0;
        }

        return solver(nums, target, i + 1, prevSum + nums[i], n) +
               solver(nums, target, i + 1, prevSum - nums[i], n);

    }

    

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solver(nums, target, 0, 0, n);
    }
};

// Memoization
class Solution {
public:
    int solver(vector<int> &nums, int target, int i, int prevSum, int n, int maxSum, vector<vector<int>> &dp){
        if(i == n){
            if(prevSum == target) return 1;

            return 0;
        }

        if(dp[i][prevSum + maxSum] != - 1) return dp[i][prevSum + maxSum];

        int minus = solver(nums, target, i + 1, prevSum - nums[i], n, maxSum, dp);
        int plus = solver(nums, target, i + 1, prevSum + nums[i], n, maxSum, dp);

        return dp[i][prevSum + maxSum] = minus + plus;
    }

    

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int maxSum = 0;
        for(int i = 0; i < n; i++){
            maxSum += abs(nums[i]);
        }
        vector<vector<int>> dp(21, vector<int>(2*maxSum + 1, -1));
        return solver(nums, target, 0, 0, n, maxSum, dp);
    }
};