#include <stdio.h>
int partition(int arr[],int p,int r)
{
	int i = p+1, j = r,k;
 	int x = arr[p];
 	int temp;
 	int find = i;
 	while(i<j) {
 		while (arr[j]>x && i<j) j--;
		while (arr[i]<x && i<j) i++;
		if(i>=j) break;
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
 		j--; i++;          
	}
	while(find<r&&arr[find]<=x) find++;
	printf("%d\n",find);
	if(find==r&&x<arr[r]){
		//É¶Ò²²»¸É 
	}
	else if(find!=r){
		arr[p]=arr[find-1];
		arr[find-1]=x;
	}else{
		arr[p]=arr[r];
		arr[r]=x;
	}
	for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
      return j-1;
}
  
void quickSort(int arr[], int low, int high)
{
    int first = low;
    int last  = high;
    if(low >= high)
        return;
    else
    {
    	printf("%d,%d,%d\n",arr,first,last);
    	first=partition(arr,first,last);
    	quickSort(arr, low, first-1);
    	quickSort(arr, first+1, high);
	}
}

int main()
{
    int i;
    int a[11] = {3, 1, 11, 5, 8, 2, 0, 9, 13,81,44};

    for(i = 0; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");

    quickSort(a, 0, 10);

    for(i = 0; i < 11; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
