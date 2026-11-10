#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head_ref,int val){
	struct node *new =(struct node *)malloc(sizeof(struct node));
	new->data=val;
	new->next=NULL;
	if(*head_ref==NULL){
		new->next=*head_ref;
		*head_ref=new;}
	struct node *temp = *head_ref;
	while(temp->next!=NULL){
		temp=temp->next;}
	temp->next=new;
	new->next=NULL;
}




void display(struct node **headR){
	struct node *temp = *headR;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}


struct node *func(struct node *head){
	struct node *odd=head;
	struct node *even=head->next;
	struct node *evenhead=even;

	while(even!=NULL && even->next!=NULL){
		odd->next=even->next;
		odd=odd->next;
		even->next=odd->next;
		even=even->next;
	}
	odd->next=evenhead;
}


void main(){
	int n,d;
	struct node *head = NULL;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	printf("Enter data: ");

	for(int i = 1; i <=n;i++){
		scanf("%d",&d);
		insert(&head,d);
	}
	display(&head);
	func(head);
	printf("\n");
	display(&head);
}
