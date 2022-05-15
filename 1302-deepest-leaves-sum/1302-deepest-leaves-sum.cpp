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
    
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    int helper(TreeNode* root,int ind, int h){
        if(root==NULL) return 0;
        if(root && ind==h){
            return root->val;
        } 
        
        return helper(root->left, ind+1, h) + helper(root->right,ind+1, h);
            
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        return helper(root, 1,h);
    }
};