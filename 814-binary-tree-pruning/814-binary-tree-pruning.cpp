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
    TreeNode* postOrderTraversal(TreeNode* root)
    {
        if(root==NULL)
            return root;
        root->left=postOrderTraversal(root->left);
        root->right=postOrderTraversal(root->right);
        if(root->val==0)
        {
            if(root->left==NULL&&root->right==NULL)
            {
                delete root;
                return NULL;
            }
            return root;
        }
        return root;    
    }
    TreeNode* pruneTree(TreeNode* root) {
        root=postOrderTraversal(root);
        return root;
    }
};