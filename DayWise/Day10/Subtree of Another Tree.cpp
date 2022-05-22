//https://leetcode.com/problems/subtree-of-another-tree/

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
    
    bool subtree(TreeNode* root, TreeNode* sroot) {
        if(root==NULL || sroot==NULL){
            return root==NULL && sroot==NULL;
        }
        if(root->val == sroot->val) {
            return subtree(root->left, sroot->left) && subtree(root->right, sroot->right);
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root)
            return false;
        if(root->val == subRoot->val) {
            bool res = subtree(root, subRoot);
            if(res)
                return res;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
            
        
    }
};
