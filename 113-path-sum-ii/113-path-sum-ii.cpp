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
    
    void helper(TreeNode* root, int target, vector<vector<int>>& ans, vector<int>& temp){
        if(root==NULL) return;
        target-=root->val;
        temp.push_back(root->val);
        if(target==0 && !root->left && !root->right){
            ans.push_back(temp);
        }
        
        helper(root->left, target, ans, temp);
        helper(root->right, target, ans, temp);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        helper(root, targetSum, ans, temp);
        return ans;
    }
};