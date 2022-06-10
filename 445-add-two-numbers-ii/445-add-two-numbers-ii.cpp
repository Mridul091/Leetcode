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
    ListNode* reverse( ListNode* head){
         ListNode* prev = NULL;
         ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr=nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        first = reverse(first);
        second = reverse(second);
        
        ListNode *dummy = new ListNode(0);
        ListNode* temp = dummy;
        int carry = 0;
        while(first!=NULL || second!=NULL || carry){
            int sum = 0;
            if(first!=NULL){
                sum += first->val;
                first = first->next;
            }
            if(second!=NULL){
                sum += second->val;
                second = second->next;
            }
            sum+=carry;
            carry = sum/10;
            ListNode *node = new ListNode(sum%10);
            temp->next = node;
            temp = node;
        }
        dummy = dummy->next;
        dummy = reverse(dummy);
        return dummy;
    }
};