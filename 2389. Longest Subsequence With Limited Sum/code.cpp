#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<int>prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixSum[i] += (prefixSum[i - 1] + nums[i]);
        }

        vector<int> ans(m, 0);
        for (int i = 0; i < m; i++) {
            int target = queries[i];
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = low + (high - low) / 2;
                if(prefixSum[mid] <= target) {
                    ans[i] = mid + 1;
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return ans;
    }
};