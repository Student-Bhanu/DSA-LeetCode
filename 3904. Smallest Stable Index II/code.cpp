#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstStableIndex(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> m(n);
        int leftMax = INT_MIN;
        int rightMin = INT_MAX;

        // storing every index's right minimun value
        for (int i = n - 1; i >= 0; i--)
        {
            rightMin = min(rightMin, nums[i]);
            m[i] = rightMin;
        }

        for (int i = 0; i < n; i++)
        {
            leftMax = max(leftMax, nums[i]);

            // if we found index which is stable return it, because we have to return minimum index
            if (leftMax - m[i] <= k)
                return i;
        }

        return -1;
    }
};