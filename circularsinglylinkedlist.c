#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node* next;
}node;

node* addToEmpty(node* last,int data)
{
	if(last!=NULL)
	{
		printf("List is not empty!!\n");
		return last;
	}
	else
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->data=data;
		last=temp;
		last->next=last;
	}
	return last;
}

node* addBegin(node* last,int data)
{
	if(last==NULL)
	{
		return addToEmpty(last,data);
	}
	else
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
	}
	return last;
}

node* addend(node* last,int data)
{
	if(last==NULL)
	{
		return addToEmpty(last,data);
	}
	else
	{
		node* temp=(node*)malloc(sizeof(node));
		temp->data=data;
		temp->next=last->next;
		last->next=temp;
		last=temp;
	}
	return last;
}

node* addAfter(node* last,int data, int item)
{
	if(last==NULL)
	{
		return NULL;
	}
	else
	{
		node* temp,*p;
		p=last->next;
		do
		{
			if(p->data==item)
			{
				temp=(node*)malloc(sizeof(node));
				temp->data=data;
				temp->next=p->next;
				p->next=temp;
				if(p==last)
				{
					last=temp;
				}
				return last;
			}
			p=p->next;
		}while(p!=last->next);
		printf("%d not found in the list.\n",item);
	}
	return last;
}

void display(node* last)
{
	if(last==NULL)
	{
		printf("Queue is empty!!\n");
		return;
	}
	else
	{
		node* temp;
		temp=last->next;
		do
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}while(temp!=last->next);
		printf("\n");
	}
}

node* deleteFromend(node* last)
{
	node* temp,*p;
	p=last;
	temp=last->next;
	do
	{
		temp=temp->next;
	}while(temp->next!=last);
	temp->next=last->next;
	last=temp;
	free(p);
	return last;
}

node* deleteFromorigin(node* last)
{
	node* p;
	p=last->next;
	last->next=p->next;
	free(p);
	return last;
}

node* deleterandomly(node* last,int data)
{
	node* p,*temp;
	p=last->next;
	do
	{
		p=p->next;
	}while(p->next->data!=data);
	temp=p->next;
	p->next=temp->next;
	free(temp);
	return last;
}

int main()
{
	int data,choice,item;
	node* last=NULL;
	printf("1.addToEmpty\n2.addEnd\n3.addBegin\n4.addAfter\n5.Deletefromend\n6.Deletefromorigin\n7.Deleterandomly\n8.Display\n9.Exit\n");
	printf("\n=================================================\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nEnter the data you want to enter in queue: ");
				scanf("%d",&data);
				last=addToEmpty(last,data);
				break;
			case 2:
				printf("\nEnter the data you want to enter in queue: ");
                                scanf("%d",&data);
				last=addend(last,data);
				break;
			case 3:
				printf("\nEnter the data you want to enter in list: ");
				scanf("%d",&data);
				last=addBegin(last,data);
				break;
			case 4:
				printf("\nEnter the data you want to enter in list: ");
				scanf("%d",&data);
				printf("\nEnter the data after which you want to enter data: ");
				scanf("%d",&item);
				last=addAfter(last,data,item);
				break;
			case 5:
				last=deleteFromend(last);
				break;
			case 6:
				last=deleteFromorigin(last);
				break;
			case 7:
				printf("Enter the data you want to delete from list: ");
				scanf("%d",&data);
				last=deleterandomly(last,data);
				break;
			case 8:
				printf("Data in linked list are:\n");
				display(last);
				break;
			case 9:
				exit(0);
			default:
				printf("Invalid option. Please try again!!\n");
		}
	}
	return 0;
}

