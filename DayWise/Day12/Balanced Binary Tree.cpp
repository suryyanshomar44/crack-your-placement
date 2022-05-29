//https://leetcode.com/problems/balanced-binary-tree/
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
    bool f = true;
    bool isBalanced(TreeNode* root) {
        
        solve(root);
        return f;
    }
    int solve(TreeNode* root) {
        if(!root)
            return -1;
    
        
        int lh = solve(root->left);
        int rh = solve(root->right);
        if(abs(lh-rh)>1)
            f = false;
        return max(lh,rh)+1;
    }
};
