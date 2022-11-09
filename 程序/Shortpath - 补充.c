#include<stdio.h>

#define x 9999
//#define max 9999
#define N 5


void froute(int start, int parent[], int dist[]) {
    int j = 0, k, i,m;
    int path[N + 1];
    for (i = 1; i <= N; i++) 
	{   j=0;
        if (i != start) 
		{
            k = i;
            path[j++] = i;
            while (parent[k] != start) {
                path[j] = parent[k];
                k = parent[k];
                j++;
            }
            path[j]=start;
            
			//逆序_自己写 
            
            
            
            
			for(m=1;m<=j;m++)
			   printf("%d  ",path[m]);  
			printf("\n");   
        }
    }
}

void fpath(int start, int dist[], int parent[], int final[], int a[][N + 1]) {
    int i, j, min, pos;
    dist[start] = x;
    parent[start] = -1;
    final[start] = 1;
    for (i = 1; i <= N; i++) {
        if (i != start) {
            dist[i] = a[start][i];
            if (dist[i] != x)
                parent[i] = start;
            else
                parent[i] = -1;
        }
    }

    for (i = 1; i <= N; i++) {
        
        //生成源点到每一个目的点最短路径 
        
        
        
        
        
        
        
        }
    }
}

int main() {
//    int start;
int i;
    int a[6][6] = {{0, x, x,  x, x, x},
                   {x, 0, 10, x, 30, 100},
                   {x, x, 0, 50, x, x},
                   {x, x, x, 0,  x,  10},
                   {x, x, x, 20, 0,  60},
                   {x, x, x,  x, x,  0}};
    int dist[6], parent[6] = {-1, -1, -1, -1, -1, -1}, final[6] = {0, 0, 0, 0, 0, 0};


    //scanf("%d", &start);
    fpath(1, dist, parent, final, a);
    froute(1,parent,dist);
}
