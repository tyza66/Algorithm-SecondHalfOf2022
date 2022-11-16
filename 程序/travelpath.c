#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define FINITY 1000
int thingnum; //节点数
int bian;//边个数
int a[MAXSIZE][MAXSIZE];//邻接矩阵
int x[MAXSIZE]={0,1,2,3,4,5};


int cc=0;
int bestc=FINITY;
int bestx[MAXSIZE];
//输出邻接矩阵
void outputjuzhen()
{
    int i,j;
    for(i=1;i<=thingnum;i++)
    {
        for(j=1;j<=thingnum;j++)
        {
            printf("%-5d",a[i][j]);
        }
        printf("\n");
    }
}
//交换
void swap(int t,int i)
{
    int temp;
    temp = x[t];
    x[t] = x[i];
    x[i] = temp;
}

void bactrack(int i)
{
    int j,k;
    if(i==thingnum)
    {
        if(a[x[thingnum-1]][x[thingnum]]!=FINITY && a[x[thingnum]][x[1]]!=FINITY && (cc+a[x[thingnum-1]][x[thingnum]]+a[x[thingnum]][x[1]] <= bestc || bestc ==FINITY))
        {
            for(j=1;j<=thingnum;j++)
            {
                bestx[j] = x[j];
            }
            bestc = cc+a[x[thingnum-1]][x[thingnum]]+a[x[thingnum]][x[1]];
            printf("\nbestx[MAXSIZE]:");
            for(i=1;i<=thingnum;i++)
            {
                printf("%-5d",bestx[i]);
            }
            printf("%-5d",bestx[1]);
            printf("\nbestc:%d",bestc);
        }
    }
    else
    {
        for(j=i;j<=thingnum;j++)
        {
            if(i==1)
            {
                swap(i,j);
                bactrack(i+1);
                swap(i,j);
            }
            else
            {
                if(a[x[i-1]][x[j]]!=FINITY && (cc+a[x[i-1]][x[j]]<bestc || bestc ==FINITY))
                {
                    swap(i,j);
                    cc = cc+a[x[i-1]][x[i]];
                    //printf("\ncc加后=%d",cc);
                    bactrack(i+1);
                    cc-=a[x[i-1]][x[i]];
                    swap(i,j);
                }
            }
        }

    }
}
//a邻接矩阵从i=1 j=1开始算
int main()
{
    int i,j,k;
    int one,two,num;
    printf("请输入结点个数:");
    scanf("%d",&thingnum);
    printf("请输入边数:");
    scanf("%d",&bian);
    //初始化邻接矩阵和x和bestx数组
    for(i=0;i<=thingnum;i++)
    {
        for(j=0;j<=thingnum;j++)
        {
            a[i][j]=FINITY;
        }
        //x[i]=i;bestx[i]=i;
    }
    printf("请输入边信息：\n");
    for(k=0;k<bian;k++)
    {
        scanf(" %d %d %d",&one,&two,&num);
        a[one][two] = num;
        a[two][one] = num;
    }
    printf("矩阵如下：\n");
    outputjuzhen();
    printf("\nx数组是如下：");
    for(i=0;i<=thingnum;i++)
    {
        printf("%-5d",x[i]);
    }

    bactrack(1);
}


