#include<stdio.h>
void main()
{
	int a[5],i,mid,n,up,low,temp,f=0;
	printf("Enter the number:  ");
	scanf("%d",&n);
	for(i=0;i<5;i++)
	{
		printf("a[%d]= ",i);
		scanf("%d",&a[i]);	
	}
	
		low=0;
		up=5;
		mid=(low+up)/2;
		for(i=0;mid>=0 && mid<=5;i++)
		{	
			
				mid=(low+up)/2;
			
				if(a[mid]==n)
				{
					printf("value found");
					f=1;
					break;
				}
				else if(n>a[mid])
				{
					low=mid;
				}
				else if(n<a[mid])
				{
					up=mid;
				}
		}
			
	if(f==0){
		printf("Value doesn't exist");
	}
	
	
}