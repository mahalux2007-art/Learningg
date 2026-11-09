#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void insert(struct node **head_ref,int val){
	struct node *new =(struct node *)malloc(sizeof(struct node));
	new->data=val;
	new->next=(*head_ref);
	(*head_ref)=new;
}

void display(struct node **head_ref){
	struct node *temp = *head_ref;
	while(temp!=NULL){
		printf("%d -> ",temp->data);
		temp=temp->next;
	}
}
void reverse(struct node **head_ref, int n,struct node **o1){
	struct node *temp = *head_ref;
	for(int i = 1;i<=n;i++){
		insert(&(*o1),temp->data);
		temp=temp->next;
	}
}


void main(){
	int n,d;
	struct node *head = NULL;
	struct node *o = NULL;
	printf("Enter number of nodes :");
	scanf("%d",&n);
	printf("Enter data: ");

	for(int i = 1; i <=n;i++){
		scanf("%d",&d);
		insert(&head,d);
	}
	display(&head);
	(reverse(&head,n,&o));
	printf("\n");
	display(&o);

}
