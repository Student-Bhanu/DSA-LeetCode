#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void subSetSumFunc(vector<int>& nums, int i, int j,
                       unordered_map<int, vector<int>>& subSetSum) {
        int sizeOfSubSet = j - i;
        int totalSubSet = 1 << sizeOfSubSet;
        for (int mask = 0; mask < totalSubSet; mask++) {
            int sum = 0, count = 0;
            for (int k = 0; k < sizeOfSubSet; k++) {
                if (mask & (1 << k)) {
                    count++;
                    sum += nums[k + i];
                }
            }
            subSetSum[count].push_back(sum);
        }
    }

    int minimumDifference(vector<int>& nums) {
        int m = nums.size();
        int n = m / 2;
        unordered_map<int, vector<int>> subSetSum1;
        unordered_map<int, vector<int>> subSetSum2;

        // making subset sum <size of subset, sum of subset>
        subSetSumFunc(nums, 0, n, subSetSum1);
        subSetSumFunc(nums, n, m, subSetSum2);

        // we have to mininmize the factor abs(2 * s1 - S) , s1 = sum of one
        // half subset
        int ans = INT_MAX;
        int S = 0; // total sum of nums array
        for (int i = 0; i < m; i++) {
            S += nums[i];
        }

        for (int i = 0; i <= n; i++) {
            vector<int> leftSubSetSum = subSetSum1[i];
            vector<int> rightSubSetSum = subSetSum2[n - i];
            if (!rightSubSetSum.empty()) {
                sort(rightSubSetSum.begin(), rightSubSetSum.end());

                // find rightSubSetSum closest to (S - 2 * leftSubSetSum) / 2

                for (int j = 0; j < leftSubSetSum.size(); j++) {
                    int factor = (S - 2 * leftSubSetSum[j]) / 2;
                    auto closestFactor = lower_bound(
                        rightSubSetSum.begin(), rightSubSetSum.end(), factor);
                    int rightElementFactor;
                    if (closestFactor == rightSubSetSum.begin()) {
                        rightElementFactor = *closestFactor;
                    } else if (closestFactor == rightSubSetSum.end()) {
                        rightElementFactor = *prev(closestFactor);
                    } else {
                        int before = *prev(closestFactor);
                        int after = *(closestFactor);
                        rightElementFactor =
                            (after - factor < factor - before) ? after : before;
                    }

                    ans = min(
                        ans,
                        abs(2 * (leftSubSetSum[j] + rightElementFactor) - S));
                }
            }
        }

        return ans;
    }
};