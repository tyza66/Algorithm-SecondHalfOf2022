#include<stdio.h>
void move(int n,char A,char C)
{
	printf("disk %d from %c to %c \n",n,A,C);
}
void hanoi(int n,char A,char B,char C)
{
	if(n==1)
	printf("disk %d from %c to %c \n",n,A,C);
	else{
		hanoi(n-1,A,C,B);
		move(n,A,C);
		hanoi(n-1,B,A,C);
	}
} 
int main()
{
	int n = 0;
	printf("����������n�Խ��n�׺�ŵ�����⣺\n");
	scanf("%d", &n);
	//��n��Բ�̴�A��������B���ƶ���C����
	hanoi(n,'A', 'B', 'C');
	return 0;
}