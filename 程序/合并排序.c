#include<stdio.h>
//mergesort
/* 将序列对半拆分直到序列长度为1*/
void Merge(int a[], int left, int m, int right)
{
	int temp[right-left+1];
	int i,j,k;
	i=left;j=m+1;k=0;
	while(i<=m&&j<=right){
		if(a[i]<a[j]) temp[k++]=a[i++];
	 	else temp[k++]=a[j++];
	}
	while(i<=m) temp[k++]=a[i++];
	while(j<=right) temp[k++]=a[j++];
	for(i=left,k=0;i<=right;i++,k++)
		a[i]=temp[k];
} 

void MergeSort(int a[], int left, int right)
{
    int m;
	if (left < right)
    {     
    	m=(left+right)/2;
    	MergeSort(a, left,m);
    	MergeSort(a, m + 1, right);
    	Merge(a, left, m, right);
	}
}

main() 
{
	int n;
	int a[99]; 
	int i; 
	printf("请输入要排序的数字数量：");
	scanf("%d",&n);scanf("");
	printf("请输入数组内容并用空格隔开：");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	} 
	scanf("");
	MergeSort(a,0,n-1);
	printf("排序的结果为：");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	} 
}

