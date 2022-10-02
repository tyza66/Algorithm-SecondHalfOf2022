#define O 1000
#define N 10
#include "stdio.h"

int bj = 0;
int jf = 0;
int BackPath(int a[][N])
{
  int i, j;
  int d[N], p[N];
  for (i = 1; i <N; i++)
  {
    d[i] = O;
    p[i] = -1;
  }
  d[0] = 0;
  p[0] = -1;
  
for (j = 1; j < N; j++)
  {
    for (i = j - 1; i >= 0; i--)
    {
    	bj++;
      if (a[i][j] + d[i] < d[j])
      {
      	jf++;
        d[j] = a[i][j] + d[i];
        p[j] = i;
      }
    }
  }
printf("%d", N - 1);
i = N - 1;
while (p[i] >= 0)
{
printf("<-%d", p[i]);
i = p[i];
}
printf("\n");
return d[N - 1];
}


main()
{
  int i, j, k;
  int weight;
  int arcnum,minshort;
  int a[N][N]={ 
 {O,4,2,3,O,O,O,O,O,O},
 {O,O,O,O,9,8,O,O,O,O},
 {O,O,O,O,6,7,8,O,O,O},
 {O,O,O,O,O,4,7,O,O,O},
 {O,O,O,O,O,O,O,5,6,O},
 {O,O,O,O,O,O,O,8,6,O},
 {O,O,O,O,O,O,O,6,5,O},
 {O,O,O,O,O,O,O,O,O,7},
 {O,O,O,O,O,O,O,O,O,3},
 {O,O,O,O,O,O,O,O,O,O}};

  /*printf("请输入边的个数:");
  scanf_s("%d",&arcnum);
  for (i= 0; i < N; i++)
    for (j = 0; j < N; j++)
      arc[i][j] = O;
  for (k = 0; k < arcnum; k++)
  {
    printf("请输入边的两个顶点和权值:");
    scanf_s("%d,%d,%d", &i, &j, &weight);
    arc[i][j] = weight;
  }*/
  minshort=BackPath(a);
  printf("minshort=%d\n",minshort);
  printf("比较次数=%d\n",bj);
  printf("加法次数=%d\n",jf);
}





