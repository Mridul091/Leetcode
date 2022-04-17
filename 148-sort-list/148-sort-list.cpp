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
    ListNode *findMid(ListNode *head){
        if(head==NULL) return head;
        ListNode *slow= head;
        ListNode *fast=head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        return slow;
    }
ListNode *merge(ListNode *head1, ListNode *head2){
        
        ListNode *fhead, *ftail;
        
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        
        if(head1->val < head2->val){
            fhead = head1;
            ftail = head1;
            head1 = head1->next;
        }
    
        else{
            fhead = head2;
            ftail = head2;
            head2 = head2 ->next;
        }
    
    while(head1!=NULL && head2!=NULL){
        if(head1->val < head2->val){
            ftail->next = head1;
            ftail = head1;
            head1 = head1->next;
        }
        else{
            ftail->next = head2;
            ftail = head2;
            head2 = head2->next;
    	    }
     }
    
        if(head1 == NULL)
            ftail->next = head2;
        else if(head2 == NULL)
            ftail->next = head1;
    
        return fhead;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode *mid = findMid(head);
        ListNode *head1 = head;
        ListNode *head2 = mid->next;
        mid->next = NULL;
        head1 = sortList(head1);
        head2 = sortList(head2);
        ListNode *finalHead = merge(head1, head2);
        return finalHead;
    }
};