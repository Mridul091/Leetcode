/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        
        queue<Node*>pendingNode;
        
        pendingNode.push(root);
        pendingNode.push(NULL);
        
        while(!pendingNode.empty()){
            
            Node* front = pendingNode.front();
            pendingNode.pop();
            
            if(front==NULL){
                if(!pendingNode.empty()) pendingNode.push(NULL);
            }
            else{
            front->next = pendingNode.front(); 
                if(front->left)
                    pendingNode.push(front->left);
                if(front->right)
                    pendingNode.push(front->right);
            }
        }
        return root;
    }
};