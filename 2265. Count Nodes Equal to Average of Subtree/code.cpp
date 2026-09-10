#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = right = NULL;
    }

    TreeNode(int x)
    {
        int val = x;
        left = right = NULL;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        int val = x;
        this->left = left;
        this->right = right;
    }
};

class Solution
{
public:
    int ans = 0;
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        auto descLeft = solve(root->left);
        auto descRight = solve(root->right);
        int Nodes = 1 + descLeft.second + descRight.second;
        int currSum = (root->val + descLeft.first + descRight.first);
        if (currSum / Nodes == root->val)
        {
            ans++;
        }

        return {currSum, Nodes};
    }
    int averageOfSubtree(TreeNode *root)
    {
        solve(root);
        return ans;
    }
};