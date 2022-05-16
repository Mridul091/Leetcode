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
    void helper(TreeNode* root, vector<int>& nums){
        if(!root) return;
        
        helper(root->left, nums);
        nums.push_back(root->val);
        helper(root->right, nums);
    }
    
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        
        helper(root, nums);
        
        int i= 0;
        int j = nums.size()-1;
        bool flag = false;
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum==k){
                flag = true;
                break;
            }
            else if(sum>k) j--;
            else i++;
        }
        return flag;
    }
};