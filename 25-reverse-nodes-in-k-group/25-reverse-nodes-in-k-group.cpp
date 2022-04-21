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
    class Pair{
        public:
            ListNode *head;
            ListNode *tail;
    };
    
    Pair reverse(ListNode *head){
        if(head==NULL || head->next==NULL){
            Pair ans;
            ans.head = head;
            ans.tail = head;
            return ans;
        }
        
        Pair small_ans = reverse(head->next);
        
        small_ans.tail->next = head;
        head->next = NULL;
        Pair ans;
        ans.head = small_ans.head;
        ans.tail = head;
        return ans;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL) return NULL;
        
        ListNode *temp = head;
        int cnt = 1;
        while(cnt<k && temp->next){
            temp = temp->next;
            cnt++;
        }
        
        if(cnt<k) return head;
        
        ListNode *head2 = temp->next;
        temp->next = NULL;
        Pair ans = reverse(head);
        head2 = reverseKGroup(head2, k);
        ans.tail->next = head2;
        return ans.head;
    }
};