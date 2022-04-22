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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *evenHead=NULL;
        ListNode *oddHead=NULL;
        
        ListNode *evenTail=NULL;
        ListNode *oddTail=NULL;
        ListNode *temp = head;
        int count =0;
        while(temp){
            if(count%2==0){
                if(evenHead==NULL){
                    evenHead = temp;
                    evenTail = temp;
                }
                else{
                    evenTail->next = temp;
                    evenTail = temp;
                }
            }
            else{
                if(oddHead==NULL){
                    oddHead = temp;
                    oddTail = temp;
                }
                else{
                    oddTail->next = temp;
                    oddTail =temp;
                }
            }
        temp=temp->next;
        count++;
        }
        
        if(oddHead ==NULL) return evenHead;
        else if(evenHead == NULL) return oddHead;
      
        evenTail->next = oddHead;
        oddTail->next = NULL;
        
        return evenHead;
        
    }
};