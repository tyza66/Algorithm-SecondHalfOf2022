#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define FINITY 1000
int thingnum; //�ڵ���
int bian;//�߸���
int a[MAXSIZE][MAXSIZE];//�ڽӾ���
int x[MAXSIZE]={0,1,2,3,4,5};


int cc=0;
int bestc=FINITY;
int bestx[MAXSIZE];
//����ڽӾ���
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
//����
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
                    //printf("\ncc�Ӻ�=%d",cc);
                    bactrack(i+1);
                    cc-=a[x[i-1]][x[i]];
                    swap(i,j);
                }
            }
        }

    }
}
//a�ڽӾ����i=1 j=1��ʼ��
int main()
{
    int i,j,k;
    int one,two,num;
    printf("�����������:");
    scanf("%d",&thingnum);
    printf("���������:");
    scanf("%d",&bian);
    //��ʼ���ڽӾ����x��bestx����
    for(i=0;i<=thingnum;i++)
    {
        for(j=0;j<=thingnum;j++)
        {
            a[i][j]=FINITY;
        }
        //x[i]=i;bestx[i]=i;
    }
    printf("���������Ϣ��\n");
    for(k=0;k<bian;k++)
    {
        scanf(" %d %d %d",&one,&two,&num);
        a[one][two] = num;
        a[two][one] = num;
    }
    printf("�������£�\n");
    outputjuzhen();
    printf("\nx���������£�");
    for(i=0;i<=thingnum;i++)
    {
        printf("%-5d",x[i]);
    }

    bactrack(1);
}


