#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool helper(unordered_map<int, vector<int>>& m, vector<bool>& visited,
                int src, vector<bool>& trace, stack<int>& s) {
        visited[src] = true;
        trace[src] = true;

        for (int nbd : m[src]) {
            if (!visited[nbd] && helper(m, visited, nbd, trace, s))
                return true;
            else if (trace[nbd])
                return true;
        }

        s.push(src);
        trace[src] = false;
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N = prerequisites.size();
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < N; i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            m[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> trace(numCourses, false);
        stack<int> s;
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && helper(m, visited, i, trace, s))
                return {};
        }

        vector<int> ans;
        while (!s.empty()) {
            int curr = s.top();
            s.pop();
            ans.push_back(curr);
        }

        return ans;
    }
};