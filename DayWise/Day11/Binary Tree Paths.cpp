//https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        solve(root, "");
        return ans;
    }
    void solve(TreeNode* root, string str) {
        if(!root){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            str += to_string(root->val);
            ans.push_back(str);
            return;
        }
    
        solve(root->left, str+to_string(root->val)+"->");
        solve(root->right, str+to_string(root->val)+"->");
    }
};
