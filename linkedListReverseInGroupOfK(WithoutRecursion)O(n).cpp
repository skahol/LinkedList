
#include<stdio.h>
#include<stdlib.h>
/* Link list node */
struct node
{
    int data;
    struct node* next;
}*head;
struct node *reverse (struct node *head, int k);
/* Reverses the linked list in groups of size k and returns the
   pointer to the new head node. */
/* UTILITY FUNCTIONS */
/* Function to push a node */
  void insert()
{
    int n,value,i;
    scanf("%d",&n);
    struct node *temp;
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node));
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
printf("\n");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
     /* Created Linked list is 1->2->3->4->5->6->7->8->9 */
     scanf("%d",&t);
     while(t--)
     {
     insert();
     scanf("%d",&k);
     head = reverse(head, k);
     printList(head);
     }
     return(0);
}
struct node *reverse (struct node *head, int k)
{ 
    struct node* current,*next,*prev;
    struct node * temp = head ;       // linking Node between 2 revese groups
    struct node* link = head;
    current = head;
    prev = NULL;
    int count = 0;
    
    while(current->next!=NULL){      // traversing till second-lastNode
        count++;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        if(count == k ){     // for head node
            head = prev;
            temp = current;
        }
        else if(count%k == 0){      // if groups made
            link->next = prev;
            link = temp;        // previous temp
            temp = current;
        }
    }
    // case when k == size of list
    if(count+1 == k){
        head = current;
        current->next = prev;
        link = NULL;
        return head;
    }
    // for last node
    current->next = prev;
    link->next = current;
    temp->next = NULL;
    return head;
}
