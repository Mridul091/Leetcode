// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    
    
    public:
    
    Node* rev(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr!=NULL){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp; 
        }
        return prev;
    }
    
    Node* reverseBetween(Node* head, int m, int n)
    {
        //code here
    
        Node* h1 = head;
        Node* t1 = head;
        int cnt = 0;
        while((cnt+1)!=m){
            t1 = h1;
            h1 = h1->next;
            cnt++;
        }
        Node* h2 = h1;
        cnt = 0;
        while(cnt!=abs(n-m)){
            h2 = h2->next;
            cnt++;
        }
        
        Node* temp1 = h2->next;
        h2->next = NULL;
        Node *revhead = rev(h1);
        if(m==1) head = revhead;
        else t1->next = revhead;
        
        Node* temp2 = revhead;
        while(temp2->next){
            temp2 = temp2->next;
        }
        temp2->next = temp1;
        
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends