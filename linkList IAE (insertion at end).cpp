#include<stdio.h>
#include<stdlib.h>
/****************Insertion at end***************/
struct Node{
	int data;
	struct Node* link;			// in c++ Node* next pointer to next node
};

struct Node* head;
struct Node* preptr;			// to create link of previous creates node with current one(previous Node)

void insert1(int value){
	struct Node* t = (Node*) malloc(sizeof(struct Node));
	(*t).data = value;
	(*t).link = preptr;
	head = t;
	preptr = t;
}
void insert(int value){
	/*********create local vaiables to keep orginal values unchanged***************/
	struct Node* temp1 = (Node*) malloc(sizeof(struct Node));		// no objects actually created a pointer of struct Node
	(*temp1).data = value;
	(*temp1).link = NULL;
	
	preptr->link = temp1;			// intially NULL				
	preptr = temp1;		// previous node toset link to current node 
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
	head = NULL;		// point to nothing
	preptr=NULL;
	int number;
	printf("Enter number of elements want to entered in list :");
	scanf("%d",&number);
	if(number==0){
		printf("empty list!");
	}
	else if(number<0){
		printf("only whole numbers");
		return 0;
	}
	int temp=number;
	while(number >0){
		int value;
		printf("Enter the value :");
		scanf("%d",&value);
		if(number == temp){
			insert1(value);
		}
		else
			insert(value);
			
		print();
		number--;
	}
	return 0;
}
