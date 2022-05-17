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
    
//     int height(TreeNode* root){
//         if(root==NULL) return 0;
        
//         return 1 + max(height(root->left), height(root->right));
        
//     }
    
//     bool helper(TreeNode* root, int sum, int ind){
//         if(root==NULL) return false;
//         int target = sum-root->val;
//         if(ind==0 && target==0) return true;
        
//        bool left =  helper(root->left, target, ind-1);
//        bool right =  helper(root->right, target, ind-1);
        
//         return left || right;
//     }
    
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(root==NULL) return false;
        targetSum-= root->val;
        if(targetSum==0 && !root->left && !root->right) return true;
        
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};