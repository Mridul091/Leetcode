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
    ListNode* partition(ListNode* head, int x) {
        ListNode *lessHead = NULL;
        ListNode *lessTail = NULL;
        ListNode *moreHead = NULL;
        ListNode *moreTail = NULL;
        if(head==NULL) return NULL;
        while(head){
            
            if(head->val < x ){
                if(lessHead ==NULL){
                    lessHead = head;
                    lessTail = head;
                }
                else{
                    lessTail->next = head;
                    lessTail = head;
                }
            }
            else{
                if(moreHead==NULL){
                    moreHead= head;
                    moreTail = head;
                }
                else{
                    moreTail->next = head;
                    moreTail = head;
                }
            }
            head = head->next;
        }
        if(moreHead==NULL) return lessHead;
        else if(lessHead == NULL) return moreHead;
        else{
        lessTail->next = moreHead;
        moreTail->next = NULL;
        return lessHead;
        }
    }
};