#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long firstSqrLen = rec1[2] - rec1[0];
        long long firstSqrHt = rec1[3] - rec1[1];
        long long secSqrLen = rec2[2] - rec2[0];
        long long secSqrHt = rec2[3] - rec2[1];

        long long combinedLen = max(abs(rec2[2] - rec1[0]), abs(rec1[2] - rec2[0]));
        long long combinedHt = max(abs(rec2[3] - rec1[1]), abs(rec1[3] - rec2[1]));

        cout << firstSqrLen << " " << firstSqrHt << endl;
        cout << secSqrLen << " " << secSqrHt << endl;
        cout << combinedLen << " " << combinedHt << endl;

        if(combinedLen >= firstSqrLen + secSqrLen || combinedHt >= firstSqrHt + secSqrHt) return false;

        return true;
    }
};