#include <bits/stdc++.h>
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
};
using namespace std;
void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}
Node* flatten (Node* root);
int main(void) {
	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			temp = (struct Node*)malloc(sizeof(struct Node));
			scanf("%d",&temp->data);
			temp->next=NULL;
			temp->bottom=NULL;
			if(flag){
				head=temp;
				pre=temp;
				flag=0;
				flag1=1;
			}
			else{
				pre->next=temp;
				pre=temp;
				flag1=1;
			}
			for(int j=0;j<m;j++){
				tempB = (struct Node*)malloc(sizeof(struct Node));
				scanf("%d",&tempB->data);
				tempB->next=tempB->bottom=NULL;
				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;
		   /*
		while(fun!=NULL)
            {
                cout<<fun->data<<" ";
                fun2 = fun->bottom;
                fun=fun->next;
                while(fun2){
                cout<<fun2->data<<" ";
                fun2=fun2->bottom;
                }
                cout<<endl;
            }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
	}
	return 0;
}


Node *flatten(Node *root)
{
   Node* curr = root;
   Node* dummy = root;
   Node* next = root;
   // flattening list
   while(dummy != NULL){
       while(curr->bottom!=NULL){
            dummy->bottom = curr->bottom;
            dummy = dummy->bottom;
            curr = curr->bottom;
       }
       next = next->next;
       dummy->bottom = next;
       dummy = dummy->bottom;
       curr = next;
   }
   // sorting
   Node* prev,*temp;
    bool  flag;
    while(1){
        flag = false;
        prev = NULL;
        temp = root;
        while(temp->bottom!=NULL){
            if(temp->data > temp->bottom->data){
                flag = true;
                if(temp == root){      // for head node
                    root = temp->bottom;
                    next = temp->bottom->bottom;
                    root->bottom = temp;
                    temp->bottom = next;
                    prev = root;       // temp is already on next node
                }
                else{
                    prev->bottom = temp->bottom;
                    prev = temp->bottom;
                    next = temp->bottom->bottom;
                    prev->bottom = temp;
                    temp->bottom = next;
                }
            }
            else{
                prev = temp;
                temp = temp->bottom;
            }
        }
        if(flag == false)
            break;
    }
   return root;
}
