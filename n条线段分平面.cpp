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
	printf("������ֱ������n��");
	scanf("%d",&n); 
	printf("%d��û������ֱ����ƽ�еģ���û������ֱ���ǹ����ֱ�߿��԰�ƽ��ֳ�%d������\n",n,fen(n));
}
