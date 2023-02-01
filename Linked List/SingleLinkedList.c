#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void insert_Last();
void Delete();
void display();
void Exit();

struct node{
	int data;
	struct node* next;
};
struct node* first = NULL;

void create()
{
	int val;
	printf("Enter the value of first node\n");
	scanf("%d",&val);

	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	first = newNode;
}

void insert()
{
	int val, ind;
	printf("Enter the value to insert\n");
	scanf("%d",&val);
	printf("Enter the index where you want to insert\n");
	scanf("%d",&ind);
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	if(ind==1)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		int i;
		struct node* p;
		p = first;
		for(i=1;i<ind-1;i++)
		{
			p = p->next;
		}
		newNode->next = p->next;
		p->next = newNode;
	}
}
void insert_Last()
{
	int val, i;
	printf("Enter the value to insert\n");
	scanf("%d",&val);
	struct node* p;
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = val;
	newNode->next = NULL;
	p = first;
	while(p->next!=NULL)
	{
		p = p->next;
	}
	p->next = newNode;
}
void Delete()
{
	int ind;
	printf("Enter the index of the node to delete\n");
	scanf("%d",&ind);

	struct node*p = first;
	if(ind==1)
	{
		first = first->next;
		free(p);
	}
	else
	{
		int i;
		struct node*q = NULL;
		for(i=1;i<ind;i++)
		{
			q =p;
			p = p->next;
		}
		q->next = p->next;
		free(p);
	}
}

void display()
{
	struct node* p = first;
	printf("The List Elements are:-\n");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int ch;

	while(1)
	{
		printf("Enter your choice:-\n1.Create\n2.Insert\n3.Insert At End\n4.Delete\n5.Display\n6.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				create();
				break;
			case 2:
				insert();
				break;
			case 3:
				insert_Last();
				break;
			case 4:
				Delete();
				break;
			case 5:
				display();
				break;
			case 6:
				return 0;
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
}
