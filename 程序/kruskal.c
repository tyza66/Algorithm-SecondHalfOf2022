#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef struct{
	int start;                     //�ߵ���ʼ����
	int end;                      //�ߵ���ֹ����
	int weight;                    //�ߵ�Ȩֵ
}Edge;

void kruskal(Edge E[],int n,int e)
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	
	int vset[n+1];
	for(i=1;i<=n;i++)        //��ʼ����������
		vset[i]=i;
	k=1;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ1
  	j=0;//E�бߵ��±꣬��ֵΪ0
   while(k<e)//���ɵı���С��eʱ����ѭ��
   {
        //������С������ 
       
       
       
       
}
input(Edge E[],int vertex,int edge)
{//��ʼ��ͼ�е�ÿ���� 

}

quick_sort(Edge E[],int n)
{
//���ݱߵ�Ȩ�ضԱ߽����������� 

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

