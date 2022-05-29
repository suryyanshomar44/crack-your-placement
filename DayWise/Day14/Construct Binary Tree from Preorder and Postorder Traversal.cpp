//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        TreeNode* ans = solve(preorder, 0, n-1, postorder, 0, n-1);
        return ans; 
    }
    TreeNode* solve(vector<int>& preorder, int psi, int pei, vector<int>& postorder, int posi, int poei) {
        if(psi>pei)
            return NULL;
            
        TreeNode* root = new TreeNode(preorder[psi]);
        if(psi==pei)
            return root;
        int idx = posi;
        while(postorder[idx] != preorder[psi+1]) idx++;
        int tnel = idx-posi+1;
        root->left = solve(preorder, psi+1, psi+tnel, postorder, posi, idx);
        root->right = solve(preorder, psi+tnel+1, pei, postorder, idx+1, poei-1);
        return root;
        
    }
};
