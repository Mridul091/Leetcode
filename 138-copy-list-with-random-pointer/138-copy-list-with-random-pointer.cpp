/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node *temp = head;
        while(temp){
            Node *p = new Node(temp->val);
            p->next = temp->next;
            temp->next = p;
            temp = p->next;
        }
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next;
            else
                temp->next->random = NULL;
            
            temp = temp->next->next;
        }
        Node* final = head->next;
        temp = head->next;
        while(head){ 
            head->next = temp->next;
            head = head->next; 
            if(!head) break; 
            temp->next = head->next; 
            temp = temp->next;
        }
        return final;

        
        
    }
};