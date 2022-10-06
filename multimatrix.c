#include "stdio.h" 
int s[6][6]={0};
void matrixChain(int  *p, int (*m)[6], int (*s)[6]){
	int n=6,i=0,j=0,k=0,r=0,t=0;
 	for(i=1;i<=n;i++) m[i-1][i-1] = 0;      
 	for(r=2;r<=n;r++){
 		for(i=1;i<=n-r+1;i++){
		 	j=i+r-1;
		 	//printf("{%d,%d}`",i,j); 
		 	m[i-1][j-1]=m[i-1][i-1]+m[i+1-1][j-1]+ p[i-1]*p[i]*p[j];
		 	s[i-1][j-1] = i;
		 	for (k = i+1; k < j; k++) {
               t = m[i-1][k-1] + m[k+1-1][j-1] + p[i-1]*p[k]*p[j];
               if(t < m[i-1][j-1]) {
                 m[i-1][j-1] = t;
                 s[i-1][j-1] = k;}
               }
		 }
 	}
 }
void traceBack(int i,int j){ 
	if(i==j)
		printf("A%d",i);
	else if(i+1==j)
		printf("(A%dA%d)",i,j);
	else{
		printf("(");
		traceBack(i,s[i][j]-1);
		traceBack(s[i][j],j);
		printf(")");
	}
}
	   
main(){
	int i,j;
	int p[7]={30,35,15,5,10,20,25};
 	int m[6][6]={0};
 	matrixChain(p,m,s);
 	
 	for(i=0;i<6;i++){
	 	for(j=0;j<6;j++){
	 		printf("%d\t",m[i][j]);
	 	}
	 	printf("\n");
	 }
	 printf("\n");
	 for(i=0;i<6;i++){
	 	for(j=0;j<6;j++){
	 		printf("%d\t",s[i][j]);
	 	}
	 	printf("\n");
	 }
	 printf("½á¹ûÊÇ£º");
	 traceBack(0,5);
	 printf("\n"); 
 }

