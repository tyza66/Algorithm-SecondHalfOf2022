#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef int semaphore;
/*定义信号量及初值*/
semaphore S1 = 0; //表示是否允许司机启动车辆，其初值为0；
semaphore S2 = 0; //表示是否允许售票员开车门，其初值为0。

struct v {
	int i;
};

_Noreturn driver() {  /*司机描述*/
	while (1) {
		WaitForSingleObject(S1, INFINITE); //wait(S1);
		Sleep(rand() % 101 * 10);
		printf("司机启动车辆\n");//启动车辆;
		Sleep(rand() % 101 * 10);
		printf("司机正常行车\n");//正常行车;
		Sleep(rand() % 101 * 10);
		printf("司机到站停车\n");//到站停车;
		ReleaseSemaphore(S2, 1, NULL); //signal(S2);
	}
}

_Noreturn Seller() {   /*售票员描述*/
	while (1) {
		Sleep(rand() % 101 * 10);
		printf("售票员关车门\n");//关车门;
		ReleaseSemaphore(S1, 1, NULL); //signal(S1);
		Sleep(rand() % 101 * 10);
		printf("售票员售票\n");//售票；
		WaitForSingleObject(S2, INFINITE); //wait(S2);
		Sleep(rand() % 101 * 10);
		printf("售票员开车门\n");//开车门;
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
