#include <stdio.h>
#include<stdlib.h>
int arr[5],top=-1;
void push()
{
    if(top==4)
    {
        printf("stack overflow");
    }
    else
    {
        printf("Enter a value \n");
        ++top;
        scanf("%d",&arr[top]);
    }
}
void pop()
{
    if(top==-1)
    {
        printf("Stack underflow");
    }
    else
    {
        --top;
    }
}

void display()
{
    int i;
    for(i=0;i<=top;i++)
    {
        printf("%d \n",arr[i]);
    }
}
int main()
{
    int c;
    while(1)
    {
        printf("Enter you option \n");
        printf("1-> PUSH \n");
        printf("2-> POP \n");
        printf("3-> Display \n");
        printf("0-> Exit \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                exit(0);
            default:
                printf("wrong option");
        }
    }

    return 0;
}

