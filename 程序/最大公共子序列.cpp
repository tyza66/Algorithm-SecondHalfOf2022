#include <stdio.h>
#define N 10

char A[N] = {'A', 'D', 'B', 'F', 'C', 'D', 'G', 'E', 'H', 'F'};

char B[N] = {'A', 'C', 'B', 'F', 'C', 'D', 'R', 'E', 'H', 'C'};
int c[N][N];
int b[N][N];

int zcgzxl(char X[N], char Y[N]) {
	int i = 0, j = 0;
	int temp1 = 0, temp2 = 0;
	//����һ������Ϊ0ʱ
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (i == 0 || j == 0) {
				c[i][j] = 0;
			}
		}
	}
	//ֱ����ͬ��ʱ��
	for (i = 1; i < N; i++) {
		for (j = 1; j < N; j++) {
			if (X[i] == Y[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
		}
	}
	//����������ͬ��ʱ��
	for (i = 1; i < N; i++) {
		for (j = 1; j < N; j++) {
			if (X[i] != Y[j]) {
				c[i][j] = c[i - 1][j] > c[i][j - 1] ? c[i - 1][j] : c[i][j - 1];
				if (c[i - 1][j] > c[i][j - 1])
					b[i][j] = 2;
				else
					b[i][j] = 3;
			}
		}
	}
	return c[N - 1][N - 1];
}

void out(int i, int j, char X[N]) {
	//printf("%d,%d/", i, j);
	if (i == 0 || j == 0) {
		return;
	}
	if (b[i - 1][j - 1] == 1) {
		out(i - 1, j - 1, X);
		printf("%c,", X[i]);
	} else if (b[i - 1][j - 1] == 2) {
		out(i - 1, j, X);
	} else
		out(i, j - 1, X);
}


main() {
	int l = zcgzxl(A, B);
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", c[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("%d\t", b[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------\n");
	printf("��󹫹��Ӵ�������%d\n", l);
	printf("��Ӵ�����Ϊ��");
	out(N, N, A);
}
