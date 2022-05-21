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
    
    void parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentTrack, int target){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            
            if(front->left){
                parentTrack[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parentTrack[front->right] = front;
                q.push(front->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parentTrack;
        parent(root, parentTrack, k);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> marked;
        marked[target] = true;
        int curr_level= 0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front->left && !marked[front->left]){
                    q.push(front->left);
                    marked[front->left] = true;
                }
                if(front->right && !marked[front->right]){
                    q.push(front->right);
                    marked[front->right] = true;
                }
                if(parentTrack[front] && !marked[parentTrack[front]]){
                    q.push(parentTrack[front]);
                    marked[parentTrack[front]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};