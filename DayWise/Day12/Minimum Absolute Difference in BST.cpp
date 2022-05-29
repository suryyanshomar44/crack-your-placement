//https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    int ans = INT_MAX;
    int prev = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        solve(root);
        return ans;
    }
    void solve(TreeNode* root) {
       if(!root)
           return;
        solve(root->left);
        if(prev!=INT_MAX)
        ans = min(ans, abs(root->val-prev));
        prev = root->val;
        solve(root->right);
        
    
    }
};
