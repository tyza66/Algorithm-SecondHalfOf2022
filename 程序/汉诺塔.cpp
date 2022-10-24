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
	printf("请输入数字n以解决n阶汉诺塔问题：\n");
	scanf("%d", &n);
	//将n个圆盘从A柱借助于B柱移动到C柱上
	hanoi(n,'A', 'B', 'C');
	return 0;
}