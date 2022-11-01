#define N 6
void findmin(int f[],int w[],int pos)
  {
  	int i,min=1000;
  	for(i=1;i<=N;i++)
  	   if(f[i]!=1&&w[i]!=-1&& min>w[i])
  	       {
			 min=w[i];
  	         pos=i;
	   		}
  }
  
void mintree(int f[],int w[],int b[],int a[][N])
{
  int i,j,v;
  for(i=1;i<N;i++)
     {
     	findmin(f,w,v);
     	f[v]=1;
     	for(j=1;j<=N;j++)
     	    if(a[v][j]!=0 && f[j]!=1 )
			 if(w[j]!=-1 && w[j]>a[v][j])
               {
				w[j]=a[v][j];
				b[j]=v;			  
				} 
             else
			   if(w[j]=-1)
			     {
				   w[j]=a[v][j];
			       b[j]=v;			  
				} 	  	      
	 }
}


int printtree(int f[],int w[],int b[])
   {
   	int i,sum=0;
   	for(i=2;i<=N;i++)
   	   {
		  printf("point %d connects to %d",i,b[i]);
   	      sum=sum+w[i];
   	  }
   	  return sum;
   }
   
int main()
{int f[N+1]={0},w[N+1],b[N+1];
int a[N][N]={{0,0,0,0,0,0,0},
{0,0,6,1,5,0,0},
{0,6,0,5,0,3,0},
{0,1,5,0,5,6,4},
{0,5,0,5,0,0,2},
{0,0,3,6,0,0,6},
{0,0,0,4,2,6,0}};  //构建图的矩阵
int i;

int start=1,tree_weight; 
f[start]=1;   //f数组元素值为1，表示该点已经加入到 V集合中 
//初始化数组w，w数组中的每个元素表示从起始点start到其余各点的距离，如果start到某一点有边，则为改边权重值，否则为负值。
for(i=1;i<=N;i++)
   if(a[start][i]==0)
      {w[i]=-1;
	   b[i]=-1;
	  }
   else
      {w[i]=a[start][i];
       b[i]=start;
	   }
 
mintree(f,w,b,a);
tree_weight=printtree(f,w,b);
printf("The min_tree weight is %d.",tree_weight);
}




