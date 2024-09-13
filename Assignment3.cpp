#include <iostream>
using namespace std;
#define MAXSIZE 10
int cQueue[MAXSIZE], front = -1, rear = -1;


void enQueue(int);
void deQueue();
void display();



void enQueue(int value)
{
	if ((front == 0 && rear == MAXSIZE - 1) || (front == rear + 1))
		cout << "\nCircular Queue is Full\n";
	else
	{
		if (rear == MAXSIZE - 1 && front != 0)
			rear = -1;
		cQueue[++rear] = value;
		cout << "\nInsertion Success\n";
		if (front == -1)
			front = 0;
	}
}
void deQueue()
{
	if (front == -1 && rear == -1)
	{
		cout << "\nCircular Queue is Empty\n";
	}
	else
	{
		cout << "\nDeleted element :" << cQueue[front++];
		if (front == MAXSIZE)
			front = 0;
		if (front - 1 == rear)
			front = rear = -1;
	}
}
void display()
{
	if (front == -1)
		cout << "\nCircular Queue is Empty!!!\n";
	else
	{
		int i = front;
		cout << "\nCircular Queue Elements are : \n";
		if (front <= rear)
		{
			while (i <= rear)
				cout << cQueue[i++]<<"\t";
		}
		else
		{
			while (i <= MAXSIZE - 1)
				cout << cQueue[i++]<<"\t";
			i = 0;
			while (i <= rear)
				cout << cQueue[i++]<<"\t";
		}
	}
}

int main()
{
	int ch, val,i=0;
	

	while (1)
	{
		
		cout << "\n\n1. Insert\n2. Delete\n3. Display\n4. Exit\n";
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			
				cout<<"\nEnter the value to be insert:  ";
				cin >> val;
				enQueue(val);
				i+=1;
				
			    break;
		case 2:
			deQueue();
			break;
		case 3:
			display();
			break;
		case 4:
			cout<<"Exitting";
		default:
			cout << "\nPlease select the correct choice!!!\n";
		}
	}
}
