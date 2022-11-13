class Solution {
public:
    

    
    ListNode* reverseList(ListNode* head) {
//         if(head==NULL) return head;
        
//         if(head->next==NULL)
//             return head;
        
//         ListNode* newHead = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;
//         return newHead;
        
        ListNode* prev = NULL;
        while(head!=NULL){
            ListNode* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }
    
};