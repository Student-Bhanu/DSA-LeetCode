#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        int leftMax = INT_MIN;
        int rightMin = INT_MAX;
        for(int i = 0; i < n; i++){
            leftMax = max(leftMax, nums[i]);
            
            for(int j = i; j < n; j++){
                rightMin = min(rightMin, nums[j]);
            }
            
            // if we find index that is stable , then we just return it because we have to return smallest index
            if((leftMax - rightMin) <= k){
                return i;
            }
            // restore rightMin value to max integer value
            rightMin = INT_MAX;
        }

        return -1;
    }
};