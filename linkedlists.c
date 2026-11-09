#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void push(struct node **head_ref,int new_data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node==NULL)
		printf("Data allocation failed");
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}

void insert(struct node **head_ref,int new_data,int pos){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node==NULL)
		printf("Data allocation failed");
	new_node->data=new_data;
	struct node *temp = *head_ref;
	if(pos==1){
		new_node->next=(*head_ref);
		*head_ref=new_node;}
	for(int i = 1;i<pos-1 && temp!=NULL;i++){
		temp=temp->next;
	}
	new_node->next=temp->next;
	temp->next=new_node;
}

void append(struct node **head_ref,int new_data){
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	if(new_node==NULL)
		printf("Data allocation failed");
	new_node->data=new_data;
	struct node *temp = *head_ref;
	while(temp->next!=NULL)
		temp=temp->next;
	new_node->next=NULL;
	temp->next=new_node;
}

void printlist(struct node **head_ref){
	struct node *temp = *head_ref;
	while(temp!=NULL){
		printf("%d ->",temp->data);
		temp=temp->next;
	}
}

void delbeg(struct node **head_ref){
	struct node *temp = *head_ref;
	*head_ref=(*head_ref)->next;

}

void delpos(struct node **head_ref,int pos){
	struct node *ptr1, *ptr2;
	ptr1=(*head_ref);

	for(int i = 1; i < pos -1 && ptr1!=NULL;i++)
		ptr1=ptr1->next;
	ptr2=ptr1->next;
	ptr1->next=ptr2->next;
}

void dellast(struct node **head_ref){
	struct node *ptr1, *ptr2;
	ptr1=*head_ref;
	while(ptr1->next!=NULL){
		ptr2=ptr1;
		ptr1=ptr1->next;
	}
	ptr2->next=NULL;
}


void main(){
	struct node *head = NULL;
	push(&head,10);
        push(&head,20);
        push(&head,40);
	insert(&head,30,2);
	append(&head,0);
	delbeg(&head);
	delpos(&head,3);
	dellast(&head);
	printlist(&head);

}



