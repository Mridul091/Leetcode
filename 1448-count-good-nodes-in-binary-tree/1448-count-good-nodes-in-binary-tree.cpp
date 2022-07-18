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
    int count = 0;
    void helper(TreeNode* root, int maxi){
        
        if(root==NULL ) return;
        
        if(maxi <= root->val){
            maxi = root->val;
            count++;
        }
        
        helper(root->left, maxi);
        helper(root->right, maxi);
    }
    
    int goodNodes(TreeNode* root) {
         helper(root, root->val);
        return count;
    }
};