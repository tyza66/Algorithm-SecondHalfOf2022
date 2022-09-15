#include<stdio.h>
	int q(int n,int m){
	if(n==1&&m==1){
		return 1;
	} 
	else if(n<m){
		return q(n,n);
	}
	else if(n==m){
		return 1+q(n,n-1);
	}
	else if(n>m&&m>1){
		return q(n,m-1)+q(n-m,m);
	}
} 

main(){
	int m,n;
	scanf("%d",&n);
	printf("%d",q(n,m));
}