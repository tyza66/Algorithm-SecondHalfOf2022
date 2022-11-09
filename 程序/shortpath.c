#include <stdio.h>
#define x 9999
#define N 5

void froute(int start, int parent[], int dist[])
{
    int j = 0, k, i, m;
    int path[N];
    for (i = 1; i < N; i++)
    {
        printf("0->%d:",i);
        j = 0;
        k = parent[i];
		while(k != -1){
			path[j++] = k;
			k = parent[k];
		} 
		printf("0");
		for(--j; j >= 0; j--){
			if(path[j] != 0)
				printf("->%d",path[j]);
		}
		printf("->%d",i);
		printf("	%d",dist[i]);
		printf("\n");
    }
}

void fpath(int start, int dist[], int parent[], int final[], int a[][N])
{
    int i, j, min, pos;
    dist[start] = 0;
    parent[start] = -1;
    final[start] = 1;
    for (i = 1; i < N; i++)
    {
        if (i != start)
        {
            dist[i] = a[start][i];
            if (dist[i] != x)
                parent[i] = start;
            else
                parent[i] = -1;
        }
    }	
    //����Դ�㵽ÿһ��Ŀ�ĵ����·�� 
    for (i = 0; i < N; i++)
    {
		//�ҵ�δ��ǽڵ��о�����̵���̵Ľڵ� 
		min = x; 
	 	for (j = 0; j < N; j++){
	 		if(final[j] == 0 && dist[j]<min){
		 		min = dist[j];
		 		pos = j;
		 	}
	 	}
	 	final[pos] = 1;
	 	//���ҵ���δ��ǽڵ�����������ܵ���Ľڵ㲢������ܵ��ĵط���ԭ����¼�Ķ̵Ļ��͸������·��
		 for (j = 1; j < N; j++){
		 	if (a[pos][j] != x && a[pos][j] + dist[pos] < dist[j]){
				dist[j] = a[pos][j] + dist[pos];
				parent[j] = pos;
	 		}
		 }
    }
}

int main()
{
    int i;
	//�ҵ��Ǵ�0��ʼ�� �����޸������ 
    int a[5][5] = {{0, 10, x, 30, 100},
                   {x, 0,  50, x, x},
                   {x, x,  0,  x, 10},
                   {x, x,  20, 0, 60},
                   {x, x,  x,  x, 0}};
	//���ڱ��ԭ�㵽�������㵱ǰ���·�� 
    int dist[5] = {0,x,x,x,x}; 
    //���ڱ�����·������һ��� 
	int parent[5] = {-1, -1, -1, -1, -1};
	//���ڼ�¼���㱻���ʱ�� 
	int final[5] = {1, 0, 0, 0, 0};
    fpath(0, dist, parent, final, a);
    printf("�������ڵ�����·��:");
    for (i = 0; i < N; i++){
		 printf("%d ",dist[i]);	
	}
	printf("\n");
	printf("��ϸ��Ϣ:");
	printf("\n");
    froute(0,parent,dist);
}
