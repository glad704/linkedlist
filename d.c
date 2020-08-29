#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
	struct node* prev;
}node;

node* Insertion(node* head);
void display(node* head);
node* Deletionrandomly(node* head);
node* Deletionfromend(node* head);
node* Deletionfromorigin(node* head);

int main(int argv, char* argc)
{
	int choice;
	node* head = NULL;
	printf("1.Insertion.\n");
	printf("2.Deletion from origin.\n");
	printf("3.Deletion from end.\n");
	printf("4.Deletion randomly.\n");
	printf("5.Display.\n");
	printf("6.Exit.\n");
	while(1)
	{
		printf("Enter the choice you want to do with doubly linked list: \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head = Insertion(head);
				break;
			case 2:
				head = Deletionfromorigin(head);
				break;
			case 3:
				head = Deletionfromend(head);
				break;
			case 4:
				head = Deletionrandomly(head);
				break;
			case 5:
				display(head);
				break;
			case 6:
				exit(0);
			default:
				printf("You have entered wrong choice!!Please try once again...... \n");
		}
	}
	return 0;
}

node* Insertion(node* head)
{
	node* temp;
	node* p;
	temp = (node*)malloc(sizeof(node));
	printf("Enter the data you want to enter in doubly linked list: \n");
	scanf("%d",&(temp->data));
	temp->next = NULL;
	temp->prev = NULL;
	if(head==NULL)
	{
		head=p=temp;
	}
	else
	{
		p = head;
		while(p->next!=NULL)
		{
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
		p = p->next;
	}
	return head;
}

void display(node* head)
{
	node* p;
	p = head;
	if(head==NULL)
	{
		printf("Linked list is empty!!\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("->%d",p->data);
			p = p->next;
		}
	}
	printf("\n");
}

node* Deletionrandomly(node* head)
{
	node* temp;
	node* temp1;
	node* temp2;
	int count = 1;
	int pos;
	temp = head;
	if(head==NULL)
	{
		printf("Linked list is empty!!\n");
	}
	else
	{
		printf("Enter the position from where you want to delete the linkedlist: \n");
		scanf("%d",&pos);
		while(pos!=count)
		{
			temp = temp->next;
			count++;
		}
		temp1 = temp->prev;
		temp2 = temp->next;
		temp1->next = temp2;
		temp2->prev = temp1;
		free(temp);
	}
	return head;
}

node* Deletionfromend(node* head)
{
	node* p;
	node* temp;
	p = head;
	if(head==NULL)
	{
		printf("Linked list is empty!!\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			p = p->next;
		}
		temp = p->prev;
		temp->next = NULL;
		free(p);
	}
	return head;
}

node* Deletionfromorigin(node* head)
{
	node* p;
	node* temp;
	p = head;
	temp = head;
	if(head==NULL)
	{
		printf("Linked list is empty!!\n");
	}
	else
	{
		p = p->next;
		p->prev = NULL;
		head = p;
		free(temp);
	}
	return head;
}
