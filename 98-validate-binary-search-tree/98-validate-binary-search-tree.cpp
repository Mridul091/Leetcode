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
    
    bool helper(TreeNode * root, int* min, int* max){
        if(root==NULL) return true;
        if(( min && root->val <= *min) ||( max && root->val >= *max))
            return false;
        
        bool isLeftOk = helper(root->left, min, &(root->val));
        bool isRightOk = helper(root->right, &(root->val), max);
        
        return isLeftOk && isRightOk;
    }
    
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};