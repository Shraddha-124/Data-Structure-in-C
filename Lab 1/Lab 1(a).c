#include<stdio.h>
void swapping(int*x,int*y);
int main()
{
    int x,y;
    printf("Enter two numbers \n");
    scanf("%d%d",&x,&y);
    printf("The value of x and y before swapping is %d and%d\n",x,y);
    swapping(&x,&y);
    return 0;
}
void swapping(int*x,int*y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
    printf("The value of x and y after swapping is %d and %d",*x,*y);
}