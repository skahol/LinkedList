#include<bits/stdc++.h>
using namespace std;

struct Node
{
int data;
Node* next;
};

Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
Node *compute(Node *head);
int main()
{
    int T;
	cin>>T;
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=newNode(data);
			else
			{
				temp->next = newNode(data);
				temp=temp->next;
			}
		}
        Node *result = compute(head);
        print(result);
        cout<<endl;
    }
}

Node *compute(Node *head)
{
   bool flag ;
   
   while(1){
     Node* curr,*next;
     flag =false;
     curr = head;
    // for single node list condition
        if(curr->next == NULL)
            return head;

    next = curr->next;
   // for head node
   while(curr->data < next->data){
       head = next;
       curr = head;
       if(next->next == NULL)       // if not NULL then move to next node
       
        break;
       next = next->next;
   }
   Node* prev = curr;
   while(next->next!=NULL){
       curr = next;
       next = next->next;
       if(curr->data < next->data){
           flag = true;
           free(curr);
           prev->next = next;       // set previous link to next ,not current link.
       }
       else{
           prev = curr;
       }
   }
    if(flag ==false)
        break;
   }
   return head;
}
