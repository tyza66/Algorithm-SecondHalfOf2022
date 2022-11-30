#include "stdio.h"

#include "stdlib.h"

#define Maxsize 20
#define N 7  //行数 
#define M 8   //列数

int grid[N+2][M+2];

typedef struct 
{int x;
int y;
 }Position;
 
struct Queue
 {Position pos[Maxsize];
  int front;
  int rear;
 };
 
 void init(struct Queue *Q)
   {(*Q).front=(*Q).rear=0;
   }
   
 int isEmpty(struct Queue Q)
 {return Q.front==Q.rear;
 }
 
 void EnQ(struct Queue *Q,Position x)
   {if((*Q).front!=((*Q).rear+1)%Maxsize)
     {(*Q).pos[(*Q).rear]=x;
     (*Q).rear=((*Q).rear+1)%Maxsize;
	 }
   }
   
void DeQ(struct Queue *Q,Position *x)
   {if((*Q).front!=(*Q).rear)
      {(*Q).front=((*Q).front+1)%Maxsize;
      *x=(*Q).pos[(*Q).front];
	  }
   }
   
int FindPath(Position start,Position finish,Position Path[], int *Pathlen)
      {struct Queue Q;
       int i,j;
	   Position here,nbr,offset[4];
       init(&Q);
       if(start.x==finish.x && start.y==finish.y)
           return 1;
       for( i=0;i<M+2;i++)
          grid[0][i]=grid[N+1][i]=1;
	   for( i=0;i<N+2;i++)
          grid[i][0]=grid[i][M+1]=1;
       
	   for(i=0;i<N+2;i++)
         {
		 for(j=0;j<M+2;j++)
            printf("%d ",grid[i][j]);
         printf("\n");
         }
         
         
       here.x=start.x;
       here.y=start.y;
       offset[0].x=0;
       offset[0].y=1;
       offset[1].x=1;
       offset[1].y=0;
	   offset[2].x=0;
	   offset[2].y=-1;
	   offset[3].x=-1;
	   offset[3].y=0;
	   grid[start.x][start.y]=2;
	  
	  do
	  {
	  for( i=0;i<4;i++)
	    {nbr.x=here.x+offset[i].x;
	     nbr.y=here.y+offset[i].y;
	    if(grid[nbr.x][nbr.y]==0)
	        {grid[nbr.x][nbr.y]=grid[here.x][here.y]+1;
	         if(nbr.x==finish.x && nbr.y==finish.y)
	           break;
	         EnQ(&Q,nbr);
	         
			}
		}
		if(nbr.x==finish.x && nbr.y==finish.y)
		     break;
		if(isEmpty(Q))
		  return 0;
		DeQ(&Q,&here);
	  }while(1);
	 
	  *Pathlen=grid[finish.x][finish.y]-2;
	  //Path=(Position *)malloc(sizeof(*Pathlen));
	  //printf("%x  ",Path);
	  here=finish;
      //输出布线点位 
      
      j=*Pathlen;
      while(here.x!=start.x && here.y!=start.y)
         {
         	for(i=0;i<4;i++)
         	    nbr.x=here.x+offset[0].row;
         	    nbr.y=here.y+offset[0].col;
         	  if(grid[here.x][here.y]==grid[nbr.x][nbr.y]+1)
         	      path[j]=nbr;
         	      
				  here=nbr;
         	     
		 }







		return 1;
	  }
	  
   void main()
    {   int i,j;
		Position path[20];
		Position start,finish;
		int Pathlen=0;
    	int ret;
	
		grid[5][1]=grid[6][1]=grid[7][1]=grid[6][2]=grid[7][2]=grid[1][3]=grid[2][3]=grid[6][3]=grid[7][3]=grid[2][4]=grid[4][4]=grid[3][5]=grid[4][5]=grid[5][5]=1;
	
		start.x=3;
		start.y=2;
		finish.x=4;
		finish.y=6;
	    
		ret=FindPath(start,finish,path,&Pathlen);
		//printf("%x  ",Path);
		if(!ret)
		   printf("无解");
		else
		  {for( i=0;i<N+1;i++)
		     {
			 for(j=0;j<M+1;j++)
			   if(grid[i][j]>=2)
			      printf("%d  ",grid[i][j]-2);
			    else
			       printf("%d  ",grid[i][j]);
			    //if(j==M+1)
			  printf("\n");
		     }
		   printf("(%d,%d)\n",start.x,start.y);
		   for(i=0;i<Pathlen;i++)
			  printf("(%d,%d)\n",path[i].x,path[i].y);
				   }	
}
