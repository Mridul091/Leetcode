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


    // 0 -> wanted camera from parent
    // 1 -> provides camera
    // 2 -> ok
class Solution {
public:
    int nocam = 0;
    int dfs(TreeNode *root){
        if(root==NULL) return 2;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        
        if(left==0 || right ==0 ){
            nocam++;
            return 1;
        }
        else if(left == 1 || right == 1) return 2;
        else return 0;
        
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0) nocam++;
        return nocam;
    }
};