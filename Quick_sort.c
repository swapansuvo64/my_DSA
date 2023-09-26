#include<stdio.h>
void swap(int *a,int *b)
{
	int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];//int pivot = arr[low]; 
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);//swap(&arr[low], &arr[i]);
//    	for (int k = 0; k < 5; k++) {
//       		 printf("a[%d]=%d \n",k, arr[k]);
////    	}
////int partition(int arr[], int low, int high) {
//    int pivot = arr[low]; // Pivot is taken from the lower bound
//    int i = low;
//    for (int j = low + 1; j <= high; j++) {
//        if (arr[j] <= pivot) {
//            i++;
//            swap(&arr[i], &arr[j]);
//        }
//    }
//    swap(&arr[low], &arr[i]);
//    return i;
//}
    return (i + 1);
}
void quickSort(int a[],int lb,int ub)
{
	int i;
	if(lb<ub)
	{
		int pi = partition(a,lb,ub);
//		for (int i = 0; i < 5; i++) {
//       		 printf("a[%d]=%d \n",i, a[i]);
//    	}
		quickSort(a,lb,pi-1);
//		for (int i = 0; i < 5; i++) {
//       		 printf("a[%d]=%d \n",i, a[i]);
//   		 }
		quickSort(a,pi+1,ub);	
//		 for (int i = 0; i < 5; i++) {
//        	printf("a[%d]=%d \n",i, a[i]);
//  	  }
	}
}
void main()
{
	int arr[100];
	 for (int i = 0;i<5; i++)
	{
        scanf("%d",&arr[i]);
    }

    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }

    quickSort(arr, 0, 4);

    printf("\nSorted array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
}
