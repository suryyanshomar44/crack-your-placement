//https://leetcode.com/problems/range-sum-of-bst/

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
    void solve(TreeNode* root, int low, int high) {
        if(!root) 
            return;
        else if(root->val>=low && root->val<=high) {
            sum+=root->val;
            solve(root->left, low, high);
            solve(root->right, low, high);
        }
        else if(root->val<low) {
            solve(root->right, low, high);
        }
        else {
            solve(root->left, low, high);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        solve(root, low, high);
        return sum;
        
    }
};
