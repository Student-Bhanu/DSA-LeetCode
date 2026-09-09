#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        if(n < 1000) return 0;
        long long ans = 0;
        long long itr = 1000;
        while(itr <= n){
            ans += (n - itr + 1);
            itr *= 1000;
        }
        
        return ans;
    }
};