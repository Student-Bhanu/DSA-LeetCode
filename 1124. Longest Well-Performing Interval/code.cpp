#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int>prefixSum(n, 0);
        unordered_map<int, int>m;
        int currSum = 0;
        int maxLength = 0;
        for(int i = 0; i < n; i++) {
            currSum += (hours[i] > 8 ? 1 : -1);
            if(currSum <= 0) {
                if(m.find(currSum - 1) != m.end()) {
                    int intervalLen = i - m[currSum - 1];
                    maxLength = max(maxLength, intervalLen);
                }

                if(m.find(currSum) == m.end()) {
                    m[currSum] = i;
                }
            } else {
                maxLength = max(maxLength, i + 1);
            }
        }
        

        return maxLength;
    }
};