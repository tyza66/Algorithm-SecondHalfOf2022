#include<stdio.h> 
//0-1���� 
//��Ʒ����
#define WPSL 7
//��������
 #define BBRL 15
//��Ʒ ��ֵ������ [V,W] = [0,1]
#define V 0
#define W 1
int things_1[WPSL][2] = {{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
//�����������[a,b]
int out[WPSL][BBRL+1]; 
//���ڼ���Ƿ�װ��
int out0_1[WPSL];
int max(int x,int y){
	int o = x>y?x:y;
	return o;
}
//��ȡ������� i����ѡ��Ʒ����	  j������������� 
int OutOut(int i,int j,int things[][2]){
	int a,b;
	//��������Ϊ0ʱ 
	for(a=WPSL-1;a>=0;a--){
		for(b=0;b<=j;b++){
			if(b==0){
				out[a][b] = 0;
			}
		}
	}
	//ֻ�����һ������Ҫ�ŵ�ʱ�� 
	for(a=WPSL-1;a>=0;a--){
		for(b=0;b<=j;b++){
			if(a==WPSL-1){
				//printf("a:%d,b:%d\n",a,b);
		 		if(things[a][W]<=b) out[a][b]=things[a][V];
		 		else out[a][b] = 0;
			}
		}
	}
	//�����ǵ�ʱ�� 
	for(a=WPSL-2;a>=0;a--){
		for(b=1;b<=j;b++){
			if(things[a][W]>b)
				out[a][b] = out[a+1][b];
			else
				out[a][b]=max(out[a+1][b],out[a+1][b-things[a][W]]+things[a][V]);
		}
	}
}
int OutOut0_1(int i,int j,int things[][2]){
	int a,b=j;
	for(a=0;a<i-1;a++){
	    if(out[a][b]==out[a+1][b])//û����Ʒ���� 
	        out0_1[a]=0;
	    else{
	        out0_1[a]=1;
	    	b=b-things[a][W];
		}
	}
	if (out[a][b]>0)
	   	out0_1[i]=1;
	else               
	   	out0_1[i]=0;
}
main(){
	int i,j;
	for(i=0;i<WPSL;i++){
		out0_1[i] = 0;
	} 
	OutOut(WPSL,BBRL,things_1);
	OutOut0_1(WPSL,BBRL,things_1);
	/*for(i=0;i<WPSL;i++){
		for(j=0;j<=BBRL;j++){
			printf("%d\t",out[i][j]);
		}
		printf("\n");
	}*/
	printf("�����õ���Ʒ����ֵ��%d\n",out[0][BBRL]);
	printf("ѡ�����Ʒ��"); 
	for(i=0;i<WPSL;i++){
		if(out0_1[i]==1)
			printf("%d ",i+1);
	} 
	printf("\n");
}
