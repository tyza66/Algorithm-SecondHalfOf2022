#define N 3
#include "stdio.h"
int c1=50,c2=50;
int w[N]={10,40,40};
int  r=0;//剩余装载箱重量
int cw=0; //当前载重量
int bestx[N],bestw=0; //bestx[]当前最优解 ，当前最优载重量
int x[N]={0};
void backtrack (int k)
   {  int i=0;
      if (k > N)  // 到达叶结点
      {
   //更新最优解
    if(cw>bestw){
     for(i=0;i<N;i++)
     bestx[i]=x[i];
     bestw=cw;
    } 
   return;
   }
      r -= w[k];  
      if (cw + w[k] <= c1) {// 搜索左子树
          x[k]=1;
          cw+=w[k];
          backtrack(k+1);
          x[k]=0;
          cw-=w[k];   
   }
      if (cw + r > bestw)  {
       //搜索右子树
    x[k]=0;
     backtrack(k+1);
     }
      r += w[k];
   }

main()
{
int i;
for(i=0;i<N;i++)
   r=r+w[i];
backtrack(0);
for(i=0;i<N;i++)
   printf("%d ",bestx[i]);
}
 