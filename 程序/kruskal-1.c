#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef int Vertex;
typedef struct{
	int start;                     //边的起始顶点
	int end;                      //边的终止顶点
	int weight;                    //边的权值
}Edge;

void kruskal(Edge E[],int n,int e)
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n];
	for(i=0;i<=n;i++)        //初始化辅助数组
		vset[i]=i;
	k=1;//表示当前构造最小生成树的第k条边，初值为1
  	j=0;//E中边的下标，初值为1
   while(k<e)//生成的边数小于e时继续循环
   {
        //生成最小生成树
        m1 = E[j+1].start;
        m2 = E[j+1].end;
        sn1 = vset[m1];
        sn2 = vset[m2];
        if(sn1!=sn2){
        	printf("V%d->V%d %d\n",m1,m2,E[j+1].weight);
        	sum+=E[j+1].weight;
        	k++;
        	if(k>=n) break;
        	for(i=1;i<=n;i++){
	        	if(vset[i]==sn2)
	        	 vset[i]=sn1;
	        } 
        }
        j++; 
   }
}

input(Edge E[],int vertex,int edge)
{//初始化图中的每条边 
    int i = 0;
	E[0].start = 0;
	E[0].end = 0;
	E[0].weight = 0;
    printf("输入各边的起始点和终点及权重(%d组)(用空格隔开)：\n",edge);
    for(i=1;i<=edge;i++) {
        scanf("%d %d %d",&E[i].start,&E[i].end,&E[i].weight);
        getchar();
    }
}

quick_sort(Edge E[],int n)
{
//根据边的权重对边进行升序排序 
	int i=0,j=0;
	Edge temp;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			if(E[j].weight<E[i].weight){
				temp = E[i];
				E[i] = E[j];
				E[j] = temp;
			}
		}
	} 
} 
int main()
{
	Edge E[MAXE];
	int vertex,edge;
	int i = 0;
	printf("please intput the vertexs and edges（数量）（空格隔开）:\n");
	scanf("%d %d",&vertex,&edge);
	getchar();
    input(E,vertex,edge);
	quick_sort(E,edge);
	kruskal(E,vertex,edge);
}

