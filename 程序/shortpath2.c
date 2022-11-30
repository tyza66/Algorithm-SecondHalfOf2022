#include "stdio.h"

typedef struct ArcCell{
    int weight;//����Ȩֵ weight=1˵��һ��ʼ�������������ߣ�=0˵����������֮��û�б�
    int min_length;//�洢���·������
}ArcCell,AdjMaxtrix[100][100];

typedef struct{
    int data;//������
    int length;//��ʼ���㵽data��Ŷ�������·��
}VerType;

typedef struct{
    VerType vexs[100];//��������
    AdjMaxtrix arcs;
    int dingdian;//������
    int bian;//�ߵ�����
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
    
    printf("���붥�����ͱ���:");
    scanf("%d%d",&G.dingdian,&G.bian);
    printf("���붥����:");
    for(i=1 ; i<=G.dingdian ; i++)
    {
        scanf("%d",&G.vexs[i].data);
        G.vexs[i].length=10000;
    }

    for(i=1;i<=G.dingdian;i++)
        for(j=1;j<=G.dingdian;j++)
        {
            G.arcs[i][j].weight=0;//������ weight=1˵��һ��ʼ�������������ߣ�=0˵����������֮��û�б�
        }
    printf("�������бߵ���㡢�յ�ͱ߳����ÿո������:\n");
    for(i=1;i<=G.bian;i++)
        {
            scanf("%d%d%d",&m,&n,&t);
            G.arcs[m][n].weight=1;//weight=1˵��һ��ʼ�������������ߣ�=0˵����������֮��û�б�
            G.arcs[m][n].min_length=t;
        }
}

int Nextweight(int v,int w)
{
	int i;
    for(i=w+1;i<=G.dingdian;i++)
        if(G.arcs[v][i].weight)
            return i;//�������еı��������ǰ��
    return 0;//δ�ҵ�����������㣬��ֱ�ӷ�������Ľ��;
}

void ShortestPaths(int v)
{
    int k=0;//���׸��ڵ㿪ʼ���ʣ�k��¼��Ҫ���ʽ���λ��
    int t;
    Queue Q;
    G.vexs[v].length=0;
    push(&Q,G.vexs[v].data);
    while(!empty(&Q))//����q��Ϊ�յ�ʱ��ִ��ѭ��
    {
        t=pop(&Q);//tΪ�����е�һ��Ԫ�أ�Ҳ��������Ҫ�������Ľ�㣬����ֵ�����ţ���һ��ִ����һ��ʱ�� G.vexs[1].data����ʼ���ı��
        k=Nextweight(t,k);//k���ϸ���Ϊ���еı��������ǰ��  
        while(k!=0)
        {
            if(G.vexs[t].length+G.arcs[t][k].min_length<=G.vexs[k].length)//��֦����
            {
                G.vexs[k].length=G.vexs[t].length+G.arcs[t][k].min_length;

                push(&Q,G.vexs[k].data);
            }
            k=Nextweight(t,k);//k���ϸ���Ϊ���еı��������ǰ��
        }
        pop(&Q);
    }
}

void Print()
{
	int i;
    for(i=2;i<=G.dingdian;i++)
        printf("����1������%d�����·�����ǣ�%d\n",G.vexs[i].data,G.vexs[i].length);
}

int main()
{
    CreateGraph();
    ShortestPaths(1);
    Print();
    return 0;
}

