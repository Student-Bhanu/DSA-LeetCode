#include <bits/stdc++.h>
using namespace std;

// Brute Force
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && boxes[j] == '1')
                    ans[i] += abs(i - j);
            }
        }

        return ans;
    }
};

// Optimal
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        // count of 1's in left and right side of i'th index
        int countL = 0, countR = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                continue;
            }

            // prefix
            int prev = boxes[i - 1] - '0';
            prefix[i] += prefix[i - 1] + countL + prev;
            countL += prev;


            // suffix
            int next = boxes[n - i] - '0';
            suffix[n - i - 1] += suffix[n - i] + countR + next;
            countR += next;
        }
        
        for(int i = 0; i < n; i++){
            prefix[i] += suffix[i];
        }

    return prefix;
        
    }
};