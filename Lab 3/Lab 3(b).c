#include<stdio.h>
#define pf printf
#define sf scanf
#define MAX 100
int cq[MAX];
int front=-1,rear=-1;

void enqueue(){
	int data;
	pf("\nEnter the element:");
	sf("%d",&data);
	
	if(front==-1 && rear==-1){
		front=rear=0;
		cq[rear]=data;
	}
	else if((rear+1)%MAX==front)
		pf("\nQueue Overflow");
	else{
		rear=(rear+1)%MAX;
		cq[rear]=data;
	}
}
void dequeue()
{
	if(front==-1 && rear==-1){
		pf("\nQueue is empty");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		front=(front+1)%MAX;
	}
}

void display()
{
	int i=front;
	pf("\nThe circular queue is :\n");
	while(i!=rear){
		pf("\t%d",cq[i]);
		i=(i+1)%MAX;
	}
	pf("\t%d",cq[i]);
}
int main()
{
	int ch;
	while(1){
		pf("\n----Enter----\n1.Insertion\n2.Deletion\n3.Display\t");
		sf("%d",&ch);
		switch(ch){
			case 1: enqueue();
					display();
					break;
			case 2: dequeue();
					display();
					break;
			case 3: display();
					return 0;
					
		}
	}
		
}