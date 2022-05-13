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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return{};
        queue<TreeNode*> pending;
        
        pending.push(root);
        pending.push(NULL);
        vector<vector<int>> ans;
        vector<int> temp;
        while(!pending.empty()){
            
            TreeNode* front = pending.front();
            pending.pop();
            if(front==NULL){
                if(!pending.empty()) pending.push(NULL);
                ans.push_back(temp);
                temp.clear();
            }
            
            else{
                temp.push_back(front->val);
                if(front->left)
                    pending.push(front->left);
                if(front->right)
                    pending.push(front->right);
            }
            
        }
        return ans;
    }
};