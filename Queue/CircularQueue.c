#include<stdio.h>
#include<stdlib.h>

int queue[6];
int size = 6;
int front = 0, rear = 0;

void enqueue()
{
	if((rear+1)%size == front)
	{
		printf("Overflow\n");
	}
	else
	{
		int val;
		printf("Enter the to value to insert\n");
		scanf("%d",&val);
		rear = (rear+1)%size;
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
		front = (front+1)%size;
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
	int i = front+1;
	while(i!=(rear+1)%size)
	{
		printf("%d ",queue[i]);
		i = (i+1)%size;
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
