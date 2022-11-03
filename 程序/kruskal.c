#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef struct{
	int start;                     //边的起始顶点
	int end;                      //边的终止顶点
	int weight;                    //边的权值
}Edge;

void kruskal(Edge E[],int n,int e)
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	
	int vset[n+1];
	for(i=1;i<=n;i++)        //初始化辅助数组
		vset[i]=i;
	k=1;//表示当前构造最小生成树的第k条边，初值为1
  	j=0;//E中边的下标，初值为0
   while(k<e)//生成的边数小于e时继续循环
   {
        //生成最小生成树 
       
       
       
       
}
input(Edge E[],int vertex,int edge)
{//初始化图中的每条边 

}

quick_sort(Edge E[],int n)
{
//根据边的权重对边进行升序排序 

} 
int main()
{
	Edge E[MAXE];
	int vertex,edge;
    
	printf("please intput the vertexs and edges:\n");
	scanf("%d%d",&vertex,&edge);
    input(E,vertex,edge);
	quick_sort(E,edge);
	kruskal(E,vertex,edge);
}

