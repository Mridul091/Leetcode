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
    
    
    TreeNode* helper(vector<int>&preorder, vector<int>& inorder, int inS, int inE, int prS, int prE){
        
        if(inS> inE) return NULL;
        
        int rootData = preorder[prS];
        int rootIndex = -1;
        for(int i =inS;i<=inE;i++){
            if(inorder[i]==rootData){
                rootIndex = i;
                break;
            }
        }
        int line = rootIndex-1;
        int lprs = prS+1;
        int lins = inS;
        int lpre = lprs + line - lins;
    
        int rprs = lpre+1;
        int rpre = prE;
        int rins = rootIndex+1;
        int rine = inE;
        
        TreeNode * root = new TreeNode(rootData);
        root->left = helper(preorder, inorder, lins, line, lprs, lpre);
        root->right = helper(preorder, inorder, rins, rine, rprs, rpre);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        
        return helper(preorder, inorder, 0, size-1, 0, size-1);
    }
};