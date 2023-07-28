#include <stdio.h>
#include<stdlib.h>
int a[6],f=-1,r=-1;
void insert()
{
	if((r==5 && f==0) || (r==f-1))
	{
		printf("overflow");
	}
	else
	{
  	printf("Enter a value \n");
  		if(r==-1)
  		{
  			++f;
  			++r;
	  	}
		else if(r==5)
		{
			r=0;
		}
		else
		{
	  		++r;
		}
		
    	scanf("%d",&a[r]);
	}
		
}
void delet()
{
 if(f==r)
    {
        printf("underflow");
    }
    else if(r>f)
    {
        ++f;
    } 
    else if(f==5)
    {
    	f=0;
	}
	else if(f>r)
	{
		++f;
	}
}
/*void re-enter()
{
	int i=f;
	for(i=0;i<f;i++)
	{
		scanf("%d",&a[i]);
	}
}*/
void display()
{
    if(r>f)
    {
    	int i;
    	for(i=f;i<=r;i++)
    	{
        	printf(" The elements are a[%d] = %d \n",i,a[i]);
   		}
   	}
    else if(f>r)
    {
    	int i;
    	for(i=f;i<=5;i++)
   		{
        	printf(" The elements are a[%d] = %d \n",i,a[i]);
   		}
   		for(i=0;i<=r;i++)
   		{
        	printf(" The elements are a[%d] = %d \n",i,a[i]);
   		}
   		
	}
}
void main()
{
	int c;
	while(1)
	{
        printf("\nEnter you option \n");
        printf("1-> insert \n");
        printf("2-> delete \n");
        printf("3-> Display \n");
        printf("0-> Exit \n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                insert();
                break;
            case 2:
                delet();
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
}