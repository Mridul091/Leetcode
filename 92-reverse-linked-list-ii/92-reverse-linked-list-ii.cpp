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
    
    ListNode* reverse(ListNode* head){
        ListNode* prev =NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *temp, *curr = head, *prev = NULL;
        while(left>1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* prev1 = prev, *tail = curr;
        while(right > 0){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            right--;
        }
        
        if(prev1!=NULL) prev1->next = prev;
        else head = prev;
        
        tail->next = curr;
        return head;
    }
};