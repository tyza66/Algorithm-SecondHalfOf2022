#define N 10
#include "stdio.h"

typedef struct {
	int No;
	int start;
	int end;
	int select;  //0 »ò 1
} TIME;

void bubble(TIME a[], int n) {
	int i = 0, j = 0;
	TIME temp = {0, 0, 0, 0};
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (a[i].end > a[j].end) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void arrange(TIME *t, int n) {
	int i = 0, j = 0;
	t[0].select = 1;
	while (i < n) {
		for (j = i + 1; j < n; j++)
			if (t[i].end <= t[j].start) {
				t[j].select = 1;
				i = j;
				break;
			}
		i++;
	}
}

main() {
	TIME t[N] = {{.No = 1, .start = 5, .end = 9, .select = 0}, {2, 0, 6, 0}, {3, 3, 5, 0}, {4, 5, 7, 0}, {5, 3, 8, 0}, {6, 1, 4, 0}, {7, 8, 11, 0}, {8, 6, 10, 0}, {9, 8, 12, 0}, {10, 12, 14, 0}};;
	int i;
	bubble(t, N);
	arrange(t, N);
	for (i = 0; i < N; i++)
		if (t[i].select != 0)
			printf("%d ", t[i].No);
}


