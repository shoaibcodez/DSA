#include<stdio.h>
#include<stdlib.h>

int queue[5];
int size = 5;
int front = -1, rear = -1;

void enqueue()
{
	if(rear==size-1)
	{
		printf("Overflow\n");
	}
	else
	{
		int val;
		printf("Enter the to value to insert\n");
		scanf("%d",&val);
		rear++;
		queue[rear] = val;
	}
}

void dequeue()
{
	if(front==rear)
	{
		printf("Underflow\n");
	}
	else
	{
		front++;
		printf("deleted value:- %d\n",queue[front]);
	}
}

void display()
{
	if(front==rear)
	{
		printf("Queue is empty\n");
		return;
	}
	printf("The Queue Elements are :-\n");
	int i;
	for(i=front+1;i<=rear;i++)
	{
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main()
{
	int ch;

	while(1)
	{
		printf("Enter your choice\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				enqueue();
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
}
