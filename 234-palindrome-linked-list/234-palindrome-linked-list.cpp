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
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        while(curr!=NULL){
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
//     ListNode *reverseLinkedListRec(ListNode *head)
// {
//     //Write your code here
 
//   	if(head==NULL || head->next==NULL) return head;
//     ListNode *newHead = reverseLinkedListRec(head->next);
    
//     ListNode *temp = newHead;
//     while(temp->next){
//         temp= temp->next;
//     }
    
//     temp->next= head;
//     head->next = NULL;
//     return newHead;
// }
    ListNode *mid_ele(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head->next;
    
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    bool isPalindrome(ListNode* head) {
    if(head==NULL) return true;
    ListNode *mid = mid_ele(head);
    ListNode *last = reverseList(mid->next);
    ListNode *curr = head;
    while(last!=NULL){
        if(last->val!=curr->val)
            return false;
        last = last->next;
        curr = curr->next;
    }
    return true;
    }
};