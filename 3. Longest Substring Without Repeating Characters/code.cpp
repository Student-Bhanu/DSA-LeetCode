#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        unordered_map<char, int> alpha;
        int ans = INT_MIN;
        int prevItr = 0;
        for (int i = 0; i < n; i++) {
            if (alpha.find(s[i]) != alpha.end() && alpha[s[i]] + 1 >= prevItr) {
                prevItr = alpha[s[i]] + 1;
            }
            int length = i - prevItr + 1;
            ans = max(ans, length);
            alpha[s[i]] = i;
        }

        return ans;
    }
};