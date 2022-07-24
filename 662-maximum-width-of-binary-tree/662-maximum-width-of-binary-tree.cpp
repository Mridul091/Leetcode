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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            int size = q.size();
            int start = q.front().second;
            int end = q.back().second;
            ans = max(ans, end-start+1);
            for(int i =0;i<size;i++){
                auto node = q.front();
                int idx = node.second-start;
                q.pop();
                if(node.first->left){
                    q.push({node.first->left, (long long)2*idx+1});
                }
                if(node.first->right){
                    q.push({node.first->right, (long long)2*idx+2});
                }
            }
        }
        return ans;
    }
};