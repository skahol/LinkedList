#include<iostream>
using namespace std;

// reverse the list
struct Node{
	int data;
	Node* link;
};
struct Node* head;
void insert(int value){
	struct Node* temp = new Node();
	temp->data = value;
	temp->link = head;
	head = temp;
}
struct Node* reverse(){
	Node* current,*prev,*next;		// previous node in reverse manner
	current = head;
	prev = NULL;
	while(current!= NULL){
		// using three pointer variables 
		next = current->link;
		current->link = prev;
		prev = current;		// pointer points to previous
		current = next;		
	}
	head = prev;
	return head;
}
int print(Node* head){
	int count =1;
	struct Node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->link;
		count++;
	}
	printf("\n");
	return count;
}
int main(){
	head =NULL;
	insert(40);
	insert(30);
	insert(20);
	insert(10);
	print(head);
	head = reverse();
	print(head);
	return 0;
}
