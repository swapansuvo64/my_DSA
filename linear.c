#include<stdio.h>
void main()
{
	int a[10],i,n,flage=0,count,f=0;
	printf("Enter the number:  ");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<10;i++)
	{
		if(a[i]==n)
		{
			flage =1;
			count=i;
			f++;
		}
	}
	if(flage=1)
	{
		printf("%d is found and the position is %d and rep is %d",n,count,f);
	}
	else
	{
		printf("value not found");
	}
	
}