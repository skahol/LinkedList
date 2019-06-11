#include<bits/stdc++.h>
using namespace std;
	// insertion at end
struct Node{
	int data;
	struct Node* next;
};
	
struct Node* head;

void insert(int value){
	struct Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->next = head;
	head = temp;	
}

void del(int n){
	struct Node* temp1 = head;
	if(n==1){
		head = temp1->next;
		free(temp1);
		return ;
	}
	for(int i=0;i<n-2;i++){
		temp1 = temp1->next;
	}
	struct Node* temp2 = temp1->next;
	temp1->next = temp2->next;			// establish link from deleting item to next one
	free(temp2);		// deleted item from memory (heap)
}
void print(){
	struct Node* temp = head;
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
int main(){
	head = NULL;
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	print();
	del(1);		// position
	print();
	del(3);
	print();	// 40 30 10 resultant 
	return 0;
}
