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
class BSTIterator {
private:
        stack<TreeNode *> S;
public:
   
        
    BSTIterator(TreeNode* root) {
        push(root);
    }
    
    int next() {
        TreeNode *temp = S.top();
        S.pop();
        push(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        return !S.empty();
    }
private:
    void push(TreeNode *node){
        for(;node!=NULL; S.push(node),node = node->left );
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */