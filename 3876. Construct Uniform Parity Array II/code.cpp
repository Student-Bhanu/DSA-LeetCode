#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = INT_MAX;
        bool isOddExist = false;
        for(int val : nums1){
            minVal = min(minVal, val);
            if(val & 1) isOddExist = true;
        }

        // if minimum value of nums1 is even and there exist atleast one odd value then we can't create a nums2 array which satisy our condition
        if(isOddExist && !(minVal & 1)) return false;
        return true;
    }
};