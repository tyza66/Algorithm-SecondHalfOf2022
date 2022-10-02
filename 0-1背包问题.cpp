#include<stdio.h> 
//0-1背包 
//物品数量
#define WPSL 7
//背包容量
 #define BBRL 15
//物品 价值，质量 [V,W] = [0,1]
#define V 0
#define W 1
int things_1[WPSL][2] = {{10,2},{5,3},{15,5},{7,7},{6,1},{18,4},{3,1}};
//用于求解阵列[a,b]
int out[WPSL][BBRL+1]; 
//用于检测是否装入
int out0_1[WPSL];
int max(int x,int y){
	int o = x>y?x:y;
	return o;
}
//求取求解阵列 i：可选物品数量	  j：背包最大容量 
int OutOut(int i,int j,int things[][2]){
	int a,b;
	//背包容量为0时 
	for(a=WPSL-1;a>=0;a--){
		for(b=0;b<=j;b++){
			if(b==0){
				out[a][b] = 0;
			}
		}
	}
	//只有最后一个物体要放的时候 
	for(a=WPSL-1;a>=0;a--){
		for(b=0;b<=j;b++){
			if(a==WPSL-1){
				//printf("a:%d,b:%d\n",a,b);
		 		if(things[a][W]<=b) out[a][b]=things[a][V];
		 		else out[a][b] = 0;
			}
		}
	}
	//都不是的时候 
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
	    if(out[a][b]==out[a+1][b])//没有物品增加 
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
	printf("可以拿的物品最大价值：%d\n",out[0][BBRL]);
	printf("选择的物品："); 
	for(i=0;i<WPSL;i++){
		if(out0_1[i]==1)
			printf("%d ",i+1);
	} 
	printf("\n");
}
