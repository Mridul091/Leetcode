// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

Node *merge(Node *head1, Node *head2){
    Node *fhead;
    Node *ftail;
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    // if(head1 == NULL && head2 ==NULL) return NULL;
    if(head1->data < head2->data){
        fhead = head1;
        ftail = head1;
        head1 = head1->next;
    }
    else{
        fhead = head2;
        ftail=  head2;
        head2 = head2 ->next;
    }
    
    
    while(head1!=NULL && head2!=NULL){
    if(head1->data < head2->data){
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
Node *mid_ele(Node* head){
    if(head ==NULL) return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)
            return head;
        Node* mid = mid_ele(head);
        Node* head1 = head;
        Node* head2 = mid->next;
        mid->next = NULL;
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        Node* fhead = merge(head1, head2);
        return fhead;
    }
};


// { Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends