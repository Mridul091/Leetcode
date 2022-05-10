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
    
    pair<int, bool> helper(TreeNode* root){
        if(root==NULL){
            pair<int, bool> p;
            p.first = 0;
            p.second = true;
            return p;
        }
        
        pair<int, bool> lans = helper(root->left);
        pair<int, bool> rans = helper(root->right);
        
        int lh = lans.first;
        int rh = rans.first;
        
        bool lbool = lans.second;
        bool rbool = rans.second;
        
        int height = 1+ max(lh,rh);
        
        bool ans;
        
        if(lbool && rbool){
            if(abs(lh-rh)<=1) ans = true;
            else ans =  false;
        }
        else{
            ans = false;
        }
        
        pair<int, bool> p;
        p.first = height;
        p.second = ans;
        
        return p;
    }
    
    bool isBalanced(TreeNode* root) {
        pair<int, bool> ans = helper(root);
        return ans.second;
    }
};