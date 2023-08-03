#include<stdio.h>
void main()
{
	int a[6],i,j,key,small,f,pos;
	printf("Enter your arrya\n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);	
	}
	printf("After insert: \n");
		for(i=0;i<6;i++)
	{
		printf("a[%d]= %d\n",i,a[i]);	
	}
	for(i=0;i<6;i++)
	{
		key=a[i];
		small=key;
		for(j=i;j<6;j++)
		{
			if(small>a[j])
			{          
				small=a[j];
				pos=j;
			}
		}
		
		a[i]=small;
		a[pos]=key;
	}
	printf("after sorting: \n");
	for(i=0;i<6;i++)
	{
		printf("a[%d]= %d\n",i,a[i]);	
	}
}