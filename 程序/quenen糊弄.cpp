#include<stdio.h>

//n�ʺ������е�n���ʺ����� 
#define N 4

//������ڵ㶨�壨��ʾ��ǰ�µ�λ�ã�(Ҫ���ʡ�ռ䣬֮���ҵ�ʱ��ʹ�û��ݷ����һ�·��)
typedef struct{
	//ָ��˫��
	int parentI; 	
	int parentJ; 
} Situation; 

//ͨ������ 
int Qmap[N][N]; 

//��¼�ⷨ���� 
int sum; 

//�±��0��ʼ����֤�Ƿ���Է��� 
int isCorrect(int i, int j, int (*Q)[N])
{
    int s, t;
    for(s=i,t=0; t<N; t++)
        if(Q[s][t]==1 && t!=j)
            return 0;//�ж���
    for(t=j,s=0; s<N; s++)
        if(Q[s][t]==1 && s!=i)
            return 0;//�ж���
    for(s=i-1,t=j-1; s>=0&&t>=0; s--,t--)
        if(Q[s][t]==1)
            return 0;//�ж����Ϸ�
    for(s=i+1,t=j+1; s<N&&t<N;s++,t++)
        if(Q[s][t]==1)
            return 0;//�ж����·�
    for(s=i-1,t=j+1; s>=0&&t<N; s--,t++)
        if(Q[s][t]==1)
            return 0;//�ж����Ϸ�
    for(s=i+1,t=j-1; s<N&&t>=0; s++,t--)
        if(Q[s][t]==1)
            return 0;//�ж����·�
    return 1;//���򷵻�
}

//���̲��������/��ʼ�� 
void clear(int (*Q)[N]) {
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			Q[i][j]=0; 
		}
	} 
}

//���̲��������� 
void put(int (*Q)[N],int i,int j) {
	Q[i][j]=1;
}

//���̲�������һ��
void backup(int (*Q)[N],Situation (*s)[N],int i,int j){
	Q[i][j]=0;
	s[i][j].parentI = -1;
 	s[i][j].parentJ = -1;
} 

//��������� ����������ȱ�����ʽ���н�����̽��
void Nquene(Situation (*s)[N],int n,int begin,int i,int j){
	if(i>=n||j>=n) return;
	if(begin==i&&isCorrect(i,j,Qmap)==1){
		put(Qmap,i,j);
		s[0][1].parentI = begin;
		s[0][1].parentJ = 0;
		Nquene(s,n,-1,0,1);
		return;
	}
	if(isCorrect(i,j,Qmap)==1){
		put(Qmap,i,j);
		j++;
		//�õ��˽⣬��ͼ��ʾ���� ��ʼ�����ҵ�������еķ��� 
		if(j==n){
			sum++; 
			printf("��%d:\n",sum);
			int a,b;
			for(a=0;a<n;a++){
				for(b=0;b<n;b++){
					printf("%d ",Qmap[a][b]);
				}
				printf("\n");
			}
			int pi = s[i][j-1].parentI;
			int pj = s[i][j-1].parentJ;
			int temp = pi;
			while(pi!=-1&&pj!=-1){
				//printf("1");
				//printf("%d,%d\n",pi,pj);
				backup(Qmap,s,pi,pj);
				Nquene(s,n,-1,pi+1,pj);
				pi = s[pi][pj].parentI;
				pj = s[temp][pj].parentJ;
				temp = pi;
			}
			return;
		}
		s[0][j].parentI = i;
		s[0][j].parentJ = j-1;
		Nquene(s,n,-1,0,j);	
		return;
	}
	else{
		i++;
		if(i==n) return;
		s[i][j].parentI = s[i-1][j].parentI;
		s[i][j].parentJ = s[i-1][j].parentJ;
		backup(Qmap,s,i-1,j);
		Nquene(s,n,-1,i,j);
		return;
	}
}


 //������
 main(){
 	int i,j,k;
 	sum = 0;
 	Situation situation[N][N][N];
 	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			for(k=0;k<N;k++){
				situation[i][j][k].parentI=-1; 
				situation[i][j][k].parentJ=-1; 
			}
		}
	} 
 	for(i=0;i<N;i++){
 		clear(Qmap);
	 	Nquene(situation[i],N,i,i,0);
	 }
/*
 	//�鿴ĳһҳ���ݼ�¼ 
 	k=1;
 	printf("\n");
 	for(i=0;i<N;i++){
		for(j=0;j<N;j++){		
			printf("%d%d\t",situation[k][i][j],situation[k][i][j]);
		}
		printf("\n");
	} 
*/
 } 