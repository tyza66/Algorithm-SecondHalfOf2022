#include<stdio.h>
//���ֲ��ҷǵݹ�
int er_fdg(int a[99],int x,int n){
	int l=0,r=n-1;
	while(l<=r){
		int m = (l+r)/2;
		if(x=a[m]) return m;
		if(x>a[m]) l=m+1;
		else r=m-1;
	} 
	return -1;
} 

int er_dg(int a[99],int x,int l,int r){
	if(l<r){
		int m = (l+r)/2;
		if(x=a[m]) return m;
		if(x>a[m]) return er_dg(a,x,m+1,r);
		else return er_dg(a,x,l,m-1);
	}
	return -1;
} 

main(){
	int n,x; 
	int i;
	int a[99];
	printf("��������:");
	scanf("%d",&n);
	scanf("");
	printf("��������������ݣ��ÿո���:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("");
	printf("����Ҫ�ҵ���:");
	scanf("%d",&x);
	printf("�ǵݹ���Ϊ�±�%d\n",er_fdg(a,x,n));
	printf("�ݹ���Ϊ�±�%d\n",er_dg(a,x,0,n-1));
}
