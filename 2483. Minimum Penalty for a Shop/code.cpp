#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> penalty(n + 1, 0);
        int countPreN = 0;
        int countPostY = 0;
        for(int i = 1; i < n + 1; i++){
            // No of N till ith index
            if(customers[i - 1] == 'N'){
                countPreN++;
            }
            // No of Y after ith index
            if(customers[n - i] == 'Y'){
                countPostY++;
            }
            penalty[i] += countPreN;
            penalty[n - i] += countPostY;
        }
        int ans = -1;
        int currVal = INT_MAX;
        for(int i = 0; i < n + 1; i++){
            if(penalty[i] < currVal){
                ans = i;
                currVal = penalty[i];
            }
        }
        
        return ans;
    }
};