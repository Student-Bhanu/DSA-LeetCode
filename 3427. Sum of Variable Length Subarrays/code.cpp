#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int strt = max(0, i - nums[i]);
            int subArrSum = prefixSum[i + 1] - prefixSum[strt];
            ans += subArrSum;
        }

        return ans;
    }
};