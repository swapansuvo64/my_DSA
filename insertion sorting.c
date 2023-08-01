#include<stdio.h>
int a[5];
void display()
{
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("\na[%d]=%d",i,a[i]);
	}	
}
void sorting()
{
	int i,j,temp,f;
	for(i=0;i<4;i++)
	{
		temp=a[i+1];
		j=i;
		while(j>=0 && a[j]>temp)
		{
			
				a[j+1]=a[j];
				j--;	
		}
			a[j+1]=temp;		
	}
	
}
void input()
{
	int i;
	for(i=0;i<5;i++)
	{
		printf("\na[%d]=",i);
		scanf("%d",&a[i]);
	}
	
}
void main()
{
	input();
	printf("\nBefore shorting \n");
	display();
	sorting();
	printf("\nafter shorting \n");
	display();	
}