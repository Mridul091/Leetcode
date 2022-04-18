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
    int val;
    int ans;
    void helper(TreeNode *root){
        if(root==NULL) return;
        helper(root->left);
        val--;
        if(val==0)
            ans = root->val;
        helper(root->right);
    }
    
  
    int kthSmallest(TreeNode* root, int k) {
        val = k;
        helper(root);
        return ans;
    }
};