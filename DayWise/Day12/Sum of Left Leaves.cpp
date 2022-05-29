//https://leetcode.com/problems/sum-of-left-leaves/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, false);
        return sum;
    }
    void solve(TreeNode* root, bool f) {
        if(!root)
            return;
        if((root->left==NULL && root->right==NULL) && f)
            sum+= root->val;
        solve(root->left, true);
        solve(root->right, false);
    }
};
