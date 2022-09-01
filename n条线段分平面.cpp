#include<stdio.h>
int fen(int n){
	if(n==0) return 0;
	int sum = 0;
	if(n==1) 
		sum = 2+fen(n-1);
	else
	{
		sum = n+fen(n-1);
	}
	return sum;
} 
	
main(){
	int n;
	printf("请输入直线数量n：");
	scanf("%d",&n); 
	printf("%d条没有两条直线是平行的，且没有三条直线是共点的直线可以把平面分成%d个区域\n",n,fen(n));
}
