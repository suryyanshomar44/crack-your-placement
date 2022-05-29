//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> path;
    bool findPath(TreeNode* root, TreeNode* target) {
        if(!root)
            return false;
        if(root==target) {
            path.push_back(root);
            return true;
        }
        bool lf = findPath(root->left, target);
        if(lf) {
            path.push_back(root);
            return true;
        }
        bool rf = findPath(root->right, target) ;
        if(rf) {
            path.push_back(root);
            return true;
        }
        return false;
    }
    void kleveldown(TreeNode* root, int k, vector<int> &ans, TreeNode* bloacker) {
        if(!root || k<0 || root==bloacker)
            return;
        
        if(k==0 ) {
            ans.push_back(root->val);
        }
        
        kleveldown(root->left, k-1, ans, bloacker);
        kleveldown(root->right, k-1, ans, bloacker);
    }  
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        findPath(root, target);
        for(int i=0; i<path.size(); i++) {
            kleveldown(path[i], k-i, ans, i!=0?path[i-1]:NULL);
        }
        return ans;
        
    }
};
