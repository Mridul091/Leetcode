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
    
    void helper(ostringstream& out, TreeNode*root){
        
        if(!root) return;
        out << root->val;
        
        
        if(root->left || root->right){
            out << "(";
            helper(out, root->left);
            out << ")";
            
            if(root->right){
                out << "(";
                helper(out, root->right);
                out << ")";
            }
        }
        
    }
    
    string tree2str(TreeNode* root) {
    
      ostringstream out;
    helper(out, root);
        return out.str();

    }
};