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
    vector<vector<int>> verticalTraversal(TreeNode* A) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> q;
    q.push({A,{0,0}});
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int x = front.second.first;
        int y = front.second.second;
        
        nodes[x][y].insert(node->val);
        if(node->left){
            q.push({node->left,{x-1, y+1}});
        }
        if(node->right){
            q.push({node->right,{x+1, y+1}});
        }

    }
    vector<vector<int>> res;
    for(auto it: nodes){
        vector<int> temp;
        for(auto x: it.second){
            temp.insert(temp.end(), x.second.begin(), x.second.end());
        }
        res.push_back(temp);
    }
    return res;
    }
};