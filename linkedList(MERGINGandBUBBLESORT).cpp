#include<iostream>
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
Node* sortedMerge(struct Node* a, struct Node* b);
void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}
/* Driver program to test above function*/
int main()
{
    int T,i,n1,n2,l,k;
    cin>>T;
    while(T--)
    {
        struct Node *head1 = NULL,  *tail1 = NULL;
        struct Node *head2 = NULL,  *tail2 = NULL;
        cin>>n1>>n2;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}


Node* sortedMerge(Node* head1,   Node* head2)
{
    // merging
    Node* temp = head1;
    while(temp->next!=NULL)
        temp = temp->next;
        
    temp->next = head2;
    
    //sorting
    Node* prev,*next;
    bool  flag;
    while(1){
        flag = false;
        prev = NULL;
        temp = head1;
        while(temp->next!=NULL){
            if(temp->data > temp->next->data){
                flag = true;
                if(temp == head1){      // for head node
                    head1 = temp->next;
                    next = temp->next->next;
                    head1->next = temp;
                    temp->next = next;
                    prev = head1;       // temp is already on next node
                }
                else{
                    prev->next = temp->next;
                    prev = temp->next;
                    next = temp->next->next;
                    prev->next = temp;
                    temp->next = next;
                }
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        if(flag == false)
            break;
    }
    return head1;
}
