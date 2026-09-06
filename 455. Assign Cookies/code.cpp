#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), greater<int>());
        sort(s.begin(), s.end(), greater<int>());
        int ans = 0;
        for(int i = 0, j = 0; i < g.size() && j < s.size();){
            if(s[j] >= g[i]){
                ans++;
                i++, j++;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};