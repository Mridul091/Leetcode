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
    
    TreeNode* helper(vector<int>& postorder, vector<int>& inorder, int poS, int poE, int inS, int inE ){
    if(inS>inE) return NULL;
    int rootData = postorder[poE];
    int rootIndex = -1;
    for(int i=inS;i<=inE;i++){
        if(inorder[i]==rootData){
            rootIndex = i;
			break;
        }
    }
    int linS = inS;
    int linE = rootIndex-1;
    int lpoS = poS;
    int lpoE = lpoS + linE-linS;
;
    int rinS = rootIndex+1;
    int rinE = inE;
    int rpoS = lpoE+1;
    int rpoE = poE-1;
    
    TreeNode *root = new TreeNode(rootData);
    root->left = helper(postorder, inorder, lpoS,lpoE,linS, linE);
    root->right = helper(postorder, inorder, rpoS, rpoE, rinS, rinE);
    return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = inorder.size();
        return helper(postorder, inorder, 0, size-1, 0, size-1);
    }
};