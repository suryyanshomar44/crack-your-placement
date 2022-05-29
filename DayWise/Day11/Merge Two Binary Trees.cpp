//https://leetcode.com/problems/merge-two-binary-trees/

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL)
            return NULL;
        
        int val = (root1==NULL?0:root1->val) + (root2==NULL?0:root2->val);
        TreeNode* newNode = new TreeNode(val);
        newNode->left = mergeTrees(root1==NULL?NULL:root1->left, root2==NULL?NULL:root2->left);
        newNode->right = mergeTrees(root1==NULL?NULL:root1->right, root2==NULL?NULL:root2->right);
        return newNode;
    }
};
