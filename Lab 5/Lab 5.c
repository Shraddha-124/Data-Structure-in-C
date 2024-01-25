#include<stdio.h>
#include<stdlib.h>
#define pf printf
#define sf scanf

struct node{
    int data;
    struct node *next;
};
struct node *head,*newnode,*temp,*temp1;


void create()
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

void delete_at_beg(){
    temp=head;
    if(head==NULL){
        pf("\nThe linked list is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        pf("\nThe only node is deleted, the list is now empty")  ;
    }
    else{
         head=temp->next;
        free(temp);
    }
}
void delete_at_end()
{
        if(head==NULL)
    {
        pf("\nThe linked list is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        pf("\nThe only node is deleted, the list is now empty")  ;
    }
    else
        {
            temp=head;
        while(temp->next!=NULL)
        {
                    temp1=temp;
                    temp=temp->next;

        }
        temp1->next=NULL;
        free(temp);
}
}

void delete_atpos()
{
    temp=head;
    int pos,i;


    if(head==NULL){
        pf("\nThe linked list is empty");
    }
    else if(head->next==NULL)
    {
        head=NULL;
        pf("\nThe only node is deleted, the list is now empty");
    }
    else{
        pf("\nEnter the position of element to be deleted:");
        sf("%d",&pos);

    for(i=1;i<pos;i++)
    {
        temp1=temp;
        temp=temp->next;
        if(temp==NULL){
            pf("\nThere are less than %d elements in the list",pos);
            return 0;
            }
    }
    temp1->next=temp->next;
    free(temp);
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
    while(1)
    {
         pf("\n----Menu----\n 1.Create\n2.Delete_at_beg\n3.delete at end\n4.Delete at pos\n5.Display: ");
        sf("%d",&ch);
    switch(ch)
    {

    case 1:create();
            break;
    case 2:delete_at_beg();
            break;
    case 3:delete_at_end();
            break;
    case 4:delete_atpos();
            break;
    case 5: display();
           return 0;
        }

    }

}
