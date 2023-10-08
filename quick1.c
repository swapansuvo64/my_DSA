#include<stdio.h>
void main()
{

	void merge(int a[],int si,int ei,int mid)
	{	
	int len = (ei-si+1);
	int x[len];
	int l=sizeof(x)/sizeof(x[0]);	
		
		int ia=si;
		int ib=mid+1;
		int j=0;
		while(ia<=mid && ib<=ei)
		{
			if(a[ia]<=a[ib])
			{
				x[j]=a[ia];
				j++;
				ia++;	
			}
			else if(a[ia]>=a[ib]){
				x[j]=a[ib];
				ib++;
				j++;
			}
		}
			while(ia<=mid)
			{
				x[j]=a[ia++];
				j++;
			}
			while(ib<=ei)
			{
				x[j]=a[ib++];
				j++;
			}	
			
	 for (j = 0; j < len; j++) {
        a[si + j] = x[j];
    }
//			while(j<len)
//			{
//				x[i++]=m[j++]
//			}
	}
	void div(int a[],int si, int ei)
	{
		if(si!=ei)
		{
			int mid=(si+ei)/2;
			div(a,si,mid);
			div(a,mid+1,ei);
			merge(a,si,ei,mid);
		}			
	}
	int a[6],i,j;
	int si=0,ei=5;
	printf("Enter the arrya: \n");
	for(i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("Unsorted element is:\t");
	for(i=0;i<6;i++)
	{
		printf("%d, ",a[i]);
	}
	printf("\n");
	div(a,si,ei);
	printf("\nSorted element\n");
	for(i=0;i<6;i++)
	{
		printf("%d, ",a[i]);
	}
}