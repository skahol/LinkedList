#include<stdio.h>
#include<stdlib.h>
/****************Insertion at end***************/
struct Node{
	int data;
	struct Node* link;			// in c++ Node* next pointer to next node
};

struct Node* head;
//struct Node* preptr;			// to create link of previous creates node with current one(previous Node)

void insert(int value, int n){
	/*********create local vaiables to keep orginal values unchanged***************/
	struct Node* temp1 = (Node*) malloc(sizeof(struct Node));		// no objects actually created a pointer of struct Node
	(*temp1).data = value;
	(*temp1).link = NULL;
	int i;
	if(n == 1){
		head = temp1;
		return ;
	}
	struct Node* temp2 = head;
	for(i=0;i<n-2;i++){
		temp2 = temp2->link;			// for eg: n=4 (0-3)elements, temp2 points to 2nd index element now 
	}
	temp1->link = temp2->link;
	temp2->link = temp1;
}
void print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int main(){
	head = NULL;						// point to nothing
	insert(2,1);
	insert(3,2);
	insert(4,1);
	insert(5,2);						// 4 5 2 3 resultant list
	print();
	return 0;
}
