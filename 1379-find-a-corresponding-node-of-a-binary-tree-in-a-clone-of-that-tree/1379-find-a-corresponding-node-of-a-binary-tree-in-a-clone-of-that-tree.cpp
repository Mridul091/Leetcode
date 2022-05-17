/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //DFS
//     TreeNode* ans;
//     void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target){
//         if(original == NULL) return;
//         if(original==target) ans =cloned;
        
//         dfs(original->left, cloned->left, target);
//         dfs(original->right, cloned->right, target);
//     }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
       // dfs(original, cloned, target);
       //  return ans;
        
        queue<pair<TreeNode*, TreeNode*>>  q;
        q.push({original, cloned});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp.first == target) return temp.second;
            
            if(temp.first->left)
                q.push({temp.first->left, temp.second->left});
            if(temp.first->right)
                q.push({temp.first->right, temp.second->right});  
        }
        return nullptr;
    }
};