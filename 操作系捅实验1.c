#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int semaphore;
/*�����ź�������ֵ*/
semaphore S1 = 0; //��ʾ�Ƿ�����˾���������������ֵΪ0��
semaphore S2 = 0; //��ʾ�Ƿ�������ƱԱ�����ţ����ֵΪ0��

struct v {
	int i;
};

_Noreturn driver() {  /*˾������*/
	while (1) {
		WaitForSingleObject(S1, INFINITE); //wait(S1);
		Sleep(rand() % 101 * 10);
		printf("˾����������\n");//��������;
		Sleep(rand() % 101 * 10);
		printf("˾�������г�\n");//�����г�;
		Sleep(rand() % 101 * 10);
		printf("˾����վͣ��\n");//��վͣ��;
		ReleaseSemaphore(S2, 1, NULL); //signal(S2);
	}
}

_Noreturn Seller() {   /*��ƱԱ����*/
	while (1) {
		Sleep(rand() % 101 * 10);
		printf("��ƱԱ�س���\n");//�س���;
		ReleaseSemaphore(S1, 1, NULL); //signal(S1);
		Sleep(rand() % 101 * 10);
		printf("��ƱԱ��Ʊ\n");//��Ʊ��
		WaitForSingleObject(S2, INFINITE); //wait(S2);
		Sleep(rand() % 101 * 10);
		printf("��ƱԱ������\n");//������;
	}
}

main() {
	DWORD ThreadP, ThreadC;
	struct v a, b;
	S1 = CreateSemaphore(NULL, 0, 1, NULL);
	S2 = CreateSemaphore(NULL, 0, 1, NULL);
	a.i = 1;
	b.i = 2;
	CreateThread(NULL, 0, driver, &a, 0, &ThreadP);
	CreateThread(NULL, 0, Seller, &b, 0, &ThreadC);
	Sleep(20000);
}
