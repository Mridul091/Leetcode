// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    
    // Node* reverse(Node* head){
    //     Node* curr = head;
    //     Node* prev = NULL;
    //     while(curr!=NULL){
    //         Node* next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }
    //     return prev;
    // }
    // Node* findmid(Node*head){
    //     Node* fast = head;
    //     Node* slow = head;
    //     while(fast!=NULL && fast->next!=NULL){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow;
    // }
    //Function to check whether the list is palindrome.
    // int length(Node *head){
    // int len = 1;
    // while(head->next ){
    //     head = head->next;
    //     len++;
    // }


    bool isPalindrome(Node *head)
    {
        //Your code here
         if(!head || !head->next) return true;
        Node* pre = NULL;
        Node* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp=temp->next;
        }
        Node* middle = head;
        int mid= (len-1)/2;
        bool isPalindrome= true; 
        
        for(int i = 0;i<mid;i++) {
        middle= middle->next;
        }
        Node* curr = middle->next;
        Node* next = curr->next;
        while(curr){
            curr->next = pre;
            pre = curr;
            curr = next;
            if(next)
                next = next->next;
        }
        middle ->next = pre;
        temp = head;
        while(pre){
            if(temp->data!=pre->data)return false;
            temp=temp->next;
            pre = pre->next;
        }
        
   return true;
    }
};



// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends