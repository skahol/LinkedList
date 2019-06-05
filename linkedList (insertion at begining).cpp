#include<stdio.h>
#include<stdlib.h>
/**********position at begining*******************/
/***requires only head's position to access linked list***/
struct Node{
	int data;
	struct Node* link;			// in c++ Node* next pointer to next node
};

//struct Node* head;

Node* insert(Node* head1, int value){
	/*********create local vaiables to keep orginal values unchanged***************************/
	struct Node* temp1 = (Node*) malloc(sizeof(struct Node));		// no objects actually creating pointers of struct Node
	(*temp1).data = value;
	(*temp1).link = head1;		// head is pointing to previous created node
	head1 = temp1;		// here head is pointing to different location so need to return head to original head 
	return head1;
}
void print(Node * head){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int main(){
	
	struct Node* head = NULL;		// point to nothing
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
	while(number--){
		int value;
		printf("Enter the value :");
		scanf("%d",&value);
		head = insert(head, value);
	//	print(head);
	}
	print(head);
	return 0;
}
