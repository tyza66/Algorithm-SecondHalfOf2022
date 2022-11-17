#include<stdio.h>

//n皇后问题中的n，皇后数量 
#define N 4

//情况树节点定义（表示当前下的位置）(要求节省空间，之后找的时候使用回溯方法找回路径)
typedef struct{
	//指向双亲
	int parentI; 	
	int parentJ; 
} Situation; 

//通用棋盘 
int Qmap[N][N]; 

//记录解法数量 
int sum; 

//下标从0开始的验证是否可以放置 
int isCorrect(int i, int j, int (*Q)[N])
{
    int s, t;
    for(s=i,t=0; t<N; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;//判断行
    for(t=j,s=0; s<N; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;//判断列
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;//判断左上方
    for(s=i+1,t=j+1; s<N&&t<N;s++,t++)
        if(Q[s][t]==1)
            return 0;//判断右下方
    for(s=i-1,t=j+1; s>=0&&t<N; s--,t++)
        if(Q[s][t]==1)
            return 0;//判断右上方
    for(s=i+1,t=j-1; s<N&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;//判断左下方
    return 1;//否则返回
}

//棋盘操作：清除/初始化 
void clear(int (*Q)[N]) {
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Q[i][j]=0; 
		}
	} 
}

//棋盘操作：下棋 
void put(int (*Q)[N],int i,int j) {
	Q[i][j]=1;
}

//棋盘操作：退一步
void backup(int (*Q)[N],Situation (*s)[N],int i,int j){
	Q[i][j]=0;
	s[i][j].parentI = -1;
 	s[i][j].parentJ = -1;
} 

//构建情况树 采用深度优先遍历方式进行解树的探索
void Nquene(Situation (*s)[N],int n,int begin,int i,int j){
	if(i>=n||j>=n) return;
	if(begin==i&&isCorrect(i,j,Qmap)==1){
		put(Qmap,i,j);
		s[0][1].parentI = begin;
		s[0][1].parentJ = 0;
		Nquene(s,n,-1,0,1);
		return;
	}
	if(isCorrect(i,j,Qmap)==1){
		put(Qmap,i,j);
		j++;
		//得到了解，用图表示出来 开始回溯找到更多可行的方法 
		if(j==n){
			sum++; 
			printf("解%d:\n",sum);
			int a,b;
			for(a=0;a<n;a++){
				for(b=0;b<n;b++){
					printf("%d ",Qmap[a][b]);
				}
				printf("\n");
			}
			int pi = s[i][j-1].parentI;
			int pj = s[i][j-1].parentJ;
			int temp = pi;
			while(pi!=-1&&pj!=-1){
				//printf("1");
				//printf("%d,%d\n",pi,pj);
				backup(Qmap,s,pi,pj);
				Nquene(s,n,-1,pi+1,pj);
				pi = s[pi][pj].parentI;
				pj = s[temp][pj].parentJ;
				temp = pi;
			}
			return;
		}
		s[0][j].parentI = i;
		s[0][j].parentJ = j-1;
		Nquene(s,n,-1,0,j);	
		return;
	}
	else{
		i++;
		if(i==n) return;
		s[i][j].parentI = s[i-1][j].parentI;
		s[i][j].parentJ = s[i-1][j].parentJ;
		backup(Qmap,s,i-1,j);
		Nquene(s,n,-1,i,j);
		return;
	}
}


 //主函数
 main(){
 	int i,j,k;
 	sum = 0;
 	Situation situation[N][N][N];
 	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				situation[i][j][k].parentI=-1; 
				situation[i][j][k].parentJ=-1; 
			}
		}
	} 
 	for(i=0;i<N;i++){
 		clear(Qmap);
	 	Nquene(situation[i],N,i,i,0);
	 }
/*
 	//查看某一页回溯记录 
 	k=1;
 	printf("\n");
 	for(i=0;i<N;i++){
		for(j=0;j<N;j++){		
			printf("%d%d\t",situation[k][i][j],situation[k][i][j]);
		}
		printf("\n");
	} 
*/
 } 