#include<stdio.h>
int weight(int arr[50],int l,int r)
{
	int sum = 0;
	int i = 0;
	for(i=l;i<=r;i++)
	{
		sum += arr[i];
	}
	return sum;
}

int find(int arr[50],int l,int r)
{
	if(r-l==1)
	{
		if(arr[l]>=arr[r])
			//arr[r]Ϊ�ٱ� 
			return r+1;
		else
			//arr[l]Ϊ�ٱ�
			return l+1;
	}
	else
	{
		if(weight(arr,l,(l+r)/2)>weight(arr,(l+r)/2+1,r))
		{
			l=(l+r)/2+1;
		}
		else
		{
			r=(l+r)/2;
		}
		return find(arr,l,r);
	} 
} 

main(){
	int n,i;
	int yb[50]; 
	printf("������Ӳ������");
	scanf("%d",&n);
	scanf("");
	printf("������Ӳ���������鲢�ÿո������");
	for(i=0;i<n;i++)
		scanf("%d",&yb[i]);
	scanf("");
	printf("��%d��Ӳ���Ǽٱ�\n",find(yb,0,n-1));
	//�����n������2��n���� 
} 
