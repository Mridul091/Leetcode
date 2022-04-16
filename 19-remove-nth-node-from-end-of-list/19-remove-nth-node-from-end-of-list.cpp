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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head==NULL)
        return head;
    ListNode *temp = head;
        int cnt=0;
        while(temp){
            temp = temp->next;
            cnt++;
        }
        if(cnt==1) return NULL;
        if(cnt==n) return head->next;
        int cnt1 = cnt-n-1;
        cout << cnt << " ";
        cout << cnt1 << " ";
        ListNode *temp1  = head;
        while(cnt1){
            temp1 = temp1->next;
            cnt1--;
        }
        cout << cnt1 << " ";
        cout << temp1-> val;
        temp1->next = temp1->next->next;
        return head;
    }
};