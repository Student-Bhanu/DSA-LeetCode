#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        int MOD = 1e9 + 7;
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        vector<int> last(26, 0);
        for(int i = 1; i < n + 1; i++){
            int idx = s[i - 1] - 'a';
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(last[idx]){
                dp[i] = (dp[i] - dp[last[idx] - 1] + MOD) % MOD;
            }
            last[idx] = i;
        }

        return (dp[n] - 1 + MOD) % MOD;
    }
};