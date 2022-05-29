//https://leetcode.com/problems/recover-binary-search-tree/

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
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;
public:
    void swap(TreeNode* &first, TreeNode* &second) {
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    } 
    void solve(TreeNode* root) {
        if(!root)
            return;
        
        solve(root->left);
        if(prev!=NULL && (root->val<prev->val)) {
            if(first == NULL) {
                first = prev;
                middle = root;
            }
            else {
                last = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        middle = first = last = prev = NULL;
        solve(root);
        if(first && last) swap(first, last);
        else swap(first, middle);
    }
};
