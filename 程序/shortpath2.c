#include "stdio.h"

typedef struct ArcCell{
    int weight;//保存权值 weight=1说明一开始就输入了这条边，=0说明这两个点之间没有边
    int min_length;//存储最短路径长度
}ArcCell,AdjMaxtrix[100][100];

typedef struct{
    int data;//顶点编号
    int length;//起始顶点到data编号顶点的最短路径
}VerType;

typedef struct{
    VerType vexs[100];//顶点向量
    AdjMaxtrix arcs;
    int dingdian;//顶点数
    int bian;//边的数量
}Graph;

typedef struct{
	int front;
	int rear;
	int data[100];
}Queue;

void init(Queue *q)
  {q->front=q->rear=0;
  }

void push(Queue *q,int d)
   {
      q->data[q->rear]=d;
      q->rear=(q->rear+1)%100;
   }
   
int pop(Queue *q)
  {
  	int f;
	f=q->data[q->front]; 
    q->front=(q->front+1)%100;
    return f; 
  }
    
int empty(Queue *q)
  {
  	if (q->front==q->rear)
  	  return 1;
  	return 0;
  }
  
Graph G;

void CreateGraph()
{
    int m,n,t;
    int i,j;
    
    printf("输入顶点数和边数:");
    scanf("%d%d",&G.dingdian,&G.bian);
    printf("输入顶点编号:");
    for(i=1 ; i<=G.dingdian ; i++)
    {
        scanf("%d",&G.vexs[i].data);
        G.vexs[i].length=10000;
    }

    for(i=1;i<=G.dingdian;i++)
        for(j=1;j<=G.dingdian;j++)
        {
            G.arcs[i][j].weight=0;//先置零 weight=1说明一开始就输入了这条边，=0说明这两个点之间没有边
        }
    printf("输入所有边的起点、终点和边长（用空格隔开）:\n");
    for(i=1;i<=G.bian;i++)
        {
            scanf("%d%d%d",&m,&n,&t);
            G.arcs[m][n].weight=1;//weight=1说明一开始就输入了这条边，=0说明这两个点之间没有边
            G.arcs[m][n].min_length=t;
        }
}

int Nextweight(int v,int w)
{
	int i;
    for(i=w+1;i<=G.dingdian;i++)
        if(G.arcs[v][i].weight)
            return i;//返回已有的边中序号最前的
    return 0;//未找到符合条件结点，就直接返回最初的结点;
}

void ShortestPaths(int v)
{
    int k=0;//从首个节点开始访问，k记录想要访问结点的位置
    int t;
    Queue Q;
    G.vexs[v].length=0;
    push(&Q,G.vexs[v].data);
    while(!empty(&Q))//队列q不为空的时候执行循环
    {
        t=pop(&Q);//t为队列中第一个元素，也就是最先要被弹出的结点，返回值是其编号，第一次执行这一步时是 G.vexs[1].data，初始结点的编号
        k=Nextweight(t,k);//k不断更新为已有的边中序号最前的  
        while(k!=0)
        {
            if(G.vexs[t].length+G.arcs[t][k].min_length<=G.vexs[k].length)//减枝操作
            {
                G.vexs[k].length=G.vexs[t].length+G.arcs[t][k].min_length;

                push(&Q,G.vexs[k].data);
            }
            k=Nextweight(t,k);//k不断更新为已有的边中序号最前的
        }
        pop(&Q);
    }
}

void Print()
{
	int i;
    for(i=2;i<=G.dingdian;i++)
        printf("顶点1到顶点%d的最短路径长是：%d\n",G.vexs[i].data,G.vexs[i].length);
}

int main()
{
    CreateGraph();
    ShortestPaths(1);
    Print();
    return 0;
}

