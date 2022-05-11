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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1, s2;
        
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
        s1.push(root);
        while(!s1.empty()){
           vector<int> v;
            while(!s1.empty()){
                TreeNode* temp = s1.top();
                s1.pop();
                v.push_back(temp->val);
                if(temp->left) s2.push(temp->left);
                if(temp->right) s2.push(temp->right);
            }
            if(v.size()>0)
                ans.push_back(v);
            
            vector<int> v1;
            while(!s2.empty()){
                TreeNode* temp = s2.top();
                s2.pop();
                
                v1.push_back(temp->val);
                if(temp->right) s1.push(temp->right);
                if(temp->left) s1.push(temp->left);
            }
            if(v1.size()>0)
                ans.push_back(v1);
        }
        
        return ans;
    }
};