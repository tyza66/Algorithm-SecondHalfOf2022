#include <stdio.h>
#define MAXE 100
#define MAXV 100

typedef int Vertex;
typedef struct{
	int start;                     //�ߵ���ʼ����
	int end;                      //�ߵ���ֹ����
	int weight;                    //�ߵ�Ȩֵ
}Edge;

void kruskal(Edge E[],int n,int e)
{ 
	int i,j,m1,m2,sn1,sn2,k,sum=0;
	int vset[n];
	for(i=0;i<=n;i++)        //��ʼ����������
		vset[i]=i;
	k=1;//��ʾ��ǰ������С�������ĵ�k���ߣ���ֵΪ1
  	j=0;//E�бߵ��±꣬��ֵΪ1
   while(k<e)//���ɵı���С��eʱ����ѭ��
   {
        //������С������
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
{//��ʼ��ͼ�е�ÿ���� 
    int i = 0;
	E[0].start = 0;
	E[0].end = 0;
	E[0].weight = 0;
    printf("������ߵ���ʼ����յ㼰Ȩ��(%d��)(�ÿո����)��\n",edge);
    for(i=1;i<=edge;i++) {
        scanf("%d %d %d",&E[i].start,&E[i].end,&E[i].weight);
        getchar();
    }
}

quick_sort(Edge E[],int n)
{
//���ݱߵ�Ȩ�ضԱ߽����������� 
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
	printf("please intput the vertexs and edges�����������ո������:\n");
	scanf("%d %d",&vertex,&edge);
	getchar();
    input(E,vertex,edge);
	quick_sort(E,edge);
	kruskal(E,vertex,edge);
}

