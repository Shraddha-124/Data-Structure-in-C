/*wap to create a linked list*/
#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf

struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*last;


void push()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    pf("Enter the data of the node to be inserted at the beginning:");
    sf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    pf("\n---The element %d has been inserted at beg---",newnode->data);
    /*display*/  
	pf("\nThe linked list you have created is: \n");
    temp=head;
    while(temp!=NULL)
    {

        pf("%d\t",temp->data);
        temp=temp->next;
    }
    

}
void append()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    pf("Enter the data of the node 1:");
    sf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;

    }
    temp->next=newnode;
    pf("\nThe element %d has been inserted at the end:",newnode->data);
	
	/*display*/
    
    pf("The linked list you have created is: \n");
    temp=head;
    while(temp!=NULL)
    {

        pf("%d\t",temp->data);
        temp=temp->next;
    }


}

void insert_pos()
{
	int pos, i=0;
	newnode=(struct node *)malloc(sizeof(struct node));
    pf("Enter the data of the node :");
    sf("%d",&newnode->data);
    pf("\nEnter the pos:");
    sf("%d",&pos);
    temp=last=head;
  
    for(i=0;i<pos;i++)
    {
    	last=temp;
    	temp=temp->next;
    }
   	last->next=newnode;
    newnode->next=temp;
    
        pf("The linked list you have created is: \n");
    temp=head;
    while(temp!=NULL)
    {

        pf("%d\t",temp->data);
        temp=temp->next;
    }
    
    

}
void display()
{
     pf("The linked list you have created is: \n");
    temp=head;
    while(temp!=NULL)
    {

        pf("%d\t",temp->data);
        temp=temp->next;
    }


}
int main()
{
   
   int ch;
   while(1){
      pf("\n\nEnter your choice:\n1.Insert at begining \n2.Insert at End \n3.Insert at a pos \n4.Display: ");
   sf("%d",&ch);
   switch(ch){
   case 1:
            push();
            break;
    case 2: append();
            break;
    case 3:
    		insert_pos();

            break;
    case 4:
            display();
            return 0;
   }
}
   
}