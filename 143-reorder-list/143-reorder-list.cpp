/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *findmid(ListNode *head){
        ListNode *slow = head;
        ListNode *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head){
        if(head==NULL || head->next ==NULL )return head;
        
        ListNode *newHead = reverse(head->next);
        ListNode *temp = newHead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = head;
        head->next = NULL;
        
        return  newHead;
    }
    
    void reorderList(ListNode* head) {
        
        if(!head || (!head->next) || (!head->next->next)) return;
         
        ListNode *mid = findmid(head);
        ListNode *head2 = reverse(mid->next);
        mid->next = NULL;
        cout << head2->val << endl;
        ListNode *h = head;
        while(head2){
            ListNode *temp = head2->next;
            head2->next = h->next;
            h->next = head2;
            head2 = temp;
            h = h->next->next;
        }
    }
};