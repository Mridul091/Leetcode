/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> cnt;
        ListNode*temp = head;
        while(temp!=NULL){
            if(cnt.count(temp))
                return temp;
            else
            {
                cnt[temp] = true;
                temp = temp->next;
            }            
        }
        return NULL;
    }
};