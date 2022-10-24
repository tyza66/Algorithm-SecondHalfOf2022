#include "stdio.h"








//int r[6][6]={0};
void matrixChain(float *p, float *q, int n, float (*e)[8], float (*w)[8], int (*root)[8]) {
	int i = 0, j = 0, l = 0, r = 0;
	for (i = 1; i <= n ; i++) {
		e[i][i - 1] = q[i - 1];
		w[i][i - 1] = q[i - 1];
	}
	for (l = 1; l <= n; l++) {
		for (i = 1; i <= n ; i++) {
			j = i + l - 1;
			e[i][j] = 100;
			w[i][j] = w[i][j - 1] + q[j] + p[j];
			for (r = i; r <= j; r++) {
				float t = e[i][r - 1] + e[r + 1][j] + w[i][j];
				if (t < e[i][j]) {
					e[i][j] = t;
					root[i][j] = r;
				}
			}
		}
	}
}

void traceBack(int i, int j, int (*r)[8]) {
	if (i <= j) {
		printf("%d ", r[i][j]);
		if (i != j) {
			printf("%d左", r[i][j]);
			traceBack(i, r[i][j] - 1, r);
			printf("%d右", r[i][j]);
			traceBack(r[i][j] + 1, j, r);
		}
	}
}

int main() {
	float p[8] = {0, 0.04, 0.06, 0.08, 0.02, 0.1, 0.12, 0.14};
	float q[8] = {0.06, 0.06, 0.06, 0.06, 0.05, 0.05, 0.05, 0.05};
	float e[8][8] = {0}, w[8][8] = {0};
	int r[8][8] = {0};
	int i = 0, j = 0;
	matrixChain(p, q, 7, e, w, r);
	//输出e表
	printf("------e:\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%f\t", e[i][j]);
		}
		printf("\n");
	}
	//输出w表
	printf("------w:\n");
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			printf("%f\t", w[i][j]);
		}
		printf("\n");
	}
	//输出r表
	printf("------r:\n");
	for (i = 1; i < 8; i++) {
		for (j = 1; j < 8; j++) {
			printf("%d\t", r[i][j]);
		}
		printf("\n");
	}
	//输出结果
	printf("------最终求得的结果:\n");
	traceBack(1, 6, r);
}
