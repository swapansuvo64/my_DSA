#include<stdio.h>
void swap(int *a,int *b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[],int lb,int ub)
{
	int pivot=a[lb];
	int start=lb;
	int end=ub;
	while(start<end)
	{
		while(a[start]<=pivot)
		{
			start++;
		}
		while(a[end]>pivot)
		{
			end--;
		}
		if(start<end)
		{
			swap(&a[start],&a[end]);
		}
	swap(&a[lb],&a[end]);	
	}
	return end;	
}
void quickSort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int pi = partition(a,lb,ub);
		quickSort(a,lb,pi-1);
		quickSort(a,pi+1,ub);	
	}
}
void main()
{
	int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}