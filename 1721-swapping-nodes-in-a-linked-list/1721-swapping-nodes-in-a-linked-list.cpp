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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left = head;
        ListNode *right = head;
        ListNode *temp = head;
        
        int cnt = 1;
        while(temp!=NULL){
            if(cnt<k)
                left = left->next;
            else if(cnt>k)
                right = right->next;
            
            temp=temp->next;
            cnt++;
        }
        
        int tmp = left->val;
        left->val = right->val;
        right->val = tmp;
        return head;
    }
};