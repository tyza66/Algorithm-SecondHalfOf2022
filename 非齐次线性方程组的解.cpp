#include<stdio.h>
double x[99];
int CalculationResults(double v[50][50][50],double u[50][50],int k,int s){
	int i,j,a,b,c;
	for(i=0;i<99;i++){
		x[i]=0;
	}
	if(k==1){
		x[0]=u[0][0]/v[0][0][0];
		for(i=2;i<=s;i++){
			double sum = 0;
			for(j=1;j<=i-1;j++){
				sum += v[i-1][i-1][j-1]*x[j-1];
			}
			x[i-1] = (u[i-1][i-1]-sum)/v[i-1][i-1][i-1];
		}
	}
	else{
		for(i=1;i<k;i++){
			u[k-2][i-1] = u[k-1][i-1] * v[k-1][k-1][k-1] - u[k-1][k-1] * v[k-1][i-1][k-1];
			for(j=1;j<k;j++){
				v[k-2][i-1][j-1] = v[k-1][i-1][j-1] * v[k-1][k-1][k-1] - v[k-1][k-1][j-1] * v[k-1][i-1][k-1]; 
			}
		}
		/*
		for(c=0;c<s;c++){
			for(b=0;b<s;b++){
				for(a=0;a<s;a++){
					v[c][b][a] = v[c][b][a]-1;
				}
			}
		}
		for(b=0;b<s;b++){
			for(a=0;a<s;a++){
				u[b][a] = u[b][a]-1;
			}
		}
		*/
		CalculationResults(v,u,k-1,s);
	}
}

main(){
	int a,b,c; 
	int k,s; 
	int i;
	double v[50][50][50];
	double u[50][50];
	printf("请输入矩阵规模k：");
	scanf("%d",&k);
	s = k; scanf("");
	printf("请输入%d个数字作为v用空格隔开（从左至右再换行）:\n",k*k*k);
	for(c=0;c<k;c++){
		for(b=0;b<k;b++){
			for(a=0;a<k;a++){
				scanf("%lf",&v[c][b][a]);
			}
		}
	}
	scanf("");
	printf("请输入%d个数字作为u用空格隔开（从左至右再换行）:\n",k*k);
		for(b=0;b<k;b++){
			for(a=0;a<k;a++){
				scanf("%lf",&u[b][a]);
			}
		}
	CalculationResults(v,u,k,s);
	printf("结果为：\n");
	for(i=0;i<99;i++){
		if(x[i]==0) break;
		printf("%lf\n",x[i]);
	}
}
