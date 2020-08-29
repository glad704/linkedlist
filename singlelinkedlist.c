#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}node;

node* createlinkedlist(node* head);
void display(node *head);
node* deleteelement(node *head);
node* deleteendelement(node* head);
node* deleterandomelement(node* head);

int main()
{
	int input;
	node *head = NULL;
	printf("1.Insertion.\n");
	printf("2.Deletion first element.\n");
	printf("3.Deletion end element.\n");
	printf("4.Deletion random element.\n");
	printf("5.Display.\n");
	printf("6.Exit.\n");
	while(1)
	{
		printf("Enter the choice you want to do with linkedlist: \n");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				head = createlinkedlist(head);
				printf("linkedlist after element insertion and head value is %p\n",head);
				break;
			case 2:
				deleteelement(head);
				printf("linkedlist after delete first element and head value is %p\n",head);
				break;
			case 3:
				head = deleteendelement(head);
				printf("linkedlist after end element deletion and its head value is %p\n",head);
				break;
			case 4:
				head = deleterandomelement(head);
				printf("linkedlist after ranadom element deletion and its head value is %p\n",head);
				break;
			case 5:
				display(head);
				printf("\n");
				break;
			case 6:
				exit(0);
			default:
				printf("You hav entered wrong choice!! please choose correct one.......\n");
				break;
		}
	}
	return 0;
}

node *createlinkedlist(node* head)
{
	node *p;
	node *temp;
	if(head==NULL)
	{
		temp = (node*)malloc(sizeof(node));
		printf("Enter the data in element: \n");
		scanf("%d",&(temp->data));
		temp->next = NULL;
		head = temp;
	}
	else
	{
		temp = (node*)malloc(sizeof(node));
		printf("Enter the data in element: \n");
		scanf("%d",&(temp->data));
		temp->next =NULL;
		p = head;
		while(p->next!=NULL)
		{
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}

void display(node* head)
{
	node *temp;
	temp = head;
	if(head==NULL)
	{
		printf("Linkedlist is empty!!\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("->%d",temp->data);
			temp = temp->next;
		}
	}
}

node* deleteelement(node *head)
{
	node *p;
	p = head;
	head = head->next;
	free(p);
	printf("Head value is now %p\n",head);
	return head;
}

node* deleteendelement(node* head)
{
	node* p;
	node* temp;
	p = head;
	while(p->next!=NULL)
	{
		temp = p;
		p = p->next;
	}
	temp->next = NULL;
	free(p);
	return head;
}

node* deleterandomelement(node* head)
{
	node* p;
	node* temp;
	node* temp2;
	int count = 1;
	int choice;
	p = head;
	printf("positional element which you want to delete: \n");
	scanf("%d",&choice);
	while(count!=choice)
	{
		temp = p;
		p = p->next;
		count++;
	}
	temp2 = p;
	p = p->next;
	temp->next = p;
	free(temp2);
	return head;
}
