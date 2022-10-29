#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5

typedef struct huffNode {
	int weight[2 * N];
	int lchild[2 * N], rchild[2 * N], parent[2 * N];
} HuffTree;


void select(HuffTree *t, int n, int *s1, int *s2) {
	int min1, min2, i;
	*s1 = *s2 = 0;

	min1 = 1000;
	min2 = 1000;

	for (i = 1; i < n; i++)
		if ((*t).parent[i] == 0) {
			//找到权重最小的两个值
			if ((*t).weight[i] < min1) {
				min2 = min1;
				*s2 = *s1;
				min1 = (*t).weight[i];
				*s1 = i;
			} else if ( ((*t).weight[i] >=  min1)  &&  ((*t).weight[i]  < min2)  ) {
				min2 = (*t).weight[i];
				*s2 =  i;
			}
		}
}


void huffmanCode(HuffTree *t, int n) {
	int i, s1, s2;
	for (i = n + 1; i <= 2 * n - 1; i++) {
		select(t, i, &s1, &s2);
		//5个元素 赋值
		(*t).parent[s1] =  i;
		(*t).parent[s2] = i;
		(*t).lchild[i]  = s1;
		(*t).rchild[i]  = s2;
		(*t).weight[i]  = (*t).weight[s1] + (*t).weight[s2];
	}
}

void huffmanbit(HuffTree *t, int i, char *code) {
	int j, k, c, f;
	char temp;
	for (c = i, f = (*t).parent[c]; (*t).parent[c] != 0; c = (*t).parent[c], f = (*t).parent[c], j++)
		if ((*t).lchild[f] == c)
			code[j] = '0';
		else if ((*t).rchild[f] == c)
			code[j] = '1';
	code[j] = '\0';
	j--;
	for (k = 0; k < j; k++, j--) {
		temp = code[k];
		code[k] = code[j];
		code[j] = temp;
	}
}

int main() {
	int i;
	char *code;
	HuffTree tree;
	tree.weight[1] = 1;
	tree.weight[2] = 2;
	tree.weight[3] = 4;
	tree.weight[4] = 5;
	tree.weight[5] = 6;
	for (i = 1; i <= 2 * N - 1; i++) {
		tree.parent[i] = 0;
		tree.lchild[i] = 0;
		tree.rchild[i] = 0;
	}
	huffmanCode(&tree, N);
	/*for (i = 1; i <= N; i++) {
		code = (char *)malloc(20 * sizeof(char));
		//huffmanbit(&tree, i, code);
		//puts(code);
	}*/
	for (i = 0; i < 2 * N; i++) {
		if (i == 0)
			printf("     \t");
		else
			printf("%d\t", i);
	}
	printf("\n");
	for (i = 0; i < 2 * N; i++) {
		if (i == 0)
			printf("parent\t");
		else
			printf("%d\t", tree.parent[i]);
	}
	printf("\n");
	for (i = 0; i < 2 * N; i++) {
		if (i == 0)
			printf("lchild\t");
		else
			printf("%d\t", tree.lchild[i]);
	}
	printf("\n");
	for (i = 0; i < 2 * N; i++) {
		if (i == 0)
			printf("rchild\t");
		else
			printf("%d\t", tree.rchild[i]);
	}
	printf("\n");
	for (i = 0; i < 2 * N; i++) {
		if (i == 0)
			printf("weight\t");
		else
			printf("%d\t", tree.weight[i]);
	}
	printf("\n");
}


