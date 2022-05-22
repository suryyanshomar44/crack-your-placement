//https://leetcode.com/problems/diameter-of-binary-tree/

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
    int dia = 0;
    int diameter(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int lh = diameter(root->left);
        int rh = diameter(root->right);
        int temp = max(lh, rh)+1;
        dia = max(dia, lh+rh);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) 
            return 0;
        diameter(root);
        return dia;
    }
};
