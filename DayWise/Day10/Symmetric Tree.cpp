//https://leetcode.com/problems/symmetric-tree/

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
    
    bool solve(TreeNode* lr, TreeNode* rr) {
        if(lr==NULL || rr==NULL){
            return lr==NULL && rr==NULL;
        }
        else if(lr->val != rr->val) {
            return false;
        }
        return solve(lr->left, rr->right) && solve(lr->right, rr->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        bool ans = solve(root->left, root->right);
        return ans;
    }
};
