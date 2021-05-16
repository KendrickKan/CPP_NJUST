// ThreadClientTCP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
//客户端
// ClientTcp.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <thread>

void new_client(int pos)
{
	WORD wVersionRequested;//记录版本型号的变量
	WSADATA wsaData;//创建结构体变量
	int err;
	wVersionRequested = MAKEWORD(1, 1);//以无符号16位整型数座位版本号，指定高低字节都为1
	err = WSAStartup(wVersionRequested, &wsaData); // 初始化Winsock，加载一个Winsocket库版本
	if (err != 0) { return; }//若执行不成功则返回

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)//进行版本检查
	{
		WSACleanup();//释放资源重置程序
		return;
	}

	SOCKET Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//创建新的套接口对象，使用IPV4与TCP
	SOCKADDR_IN Server;//义存放本地地址信息的结构体变量

	// 要连接的基础信息
	Server.sin_family = AF_INET;  //sin_family指代协议族，其值一般是AF_INET表示采用IPv4协议
	Server.sin_port = htons(6002);//将端口号6002赋给sin_port 
	inet_pton(AF_INET, "127.0.0.1", &Server.sin_addr); //点分十进制地址转换成网络字节序

	// 向服务端发起连接
	int ret = connect(Client, (struct sockaddr*) & Server, sizeof(Server));

	if (ret == SOCKET_ERROR)//提示错误类型
	{
		printf("连接失败\n");
		closesocket(Client);//关闭改错误的套接口
		WSACleanup();//重置
		return;
	}

	char recvBuf[128];
	char sendBuf[128];

	while (true)//资源成功配置
	{
		printf("please input message:\n");//用户可输入数据
		gets_s(sendBuf);
		sprintf_s(sendBuf, "%s_%d", sendBuf, pos);//发送数据给服务器
		send(Client, sendBuf, strlen(sendBuf) + 1, 0);//发送数据给服务器
		/*
		recv(Client, recvBuf, 128, 0);
		char ipServer[16];
		inet_ntop(AF_INET, &Server.sin_addr, ipServer, sizeof(ipServer));
		printf("%s said: %s\n", ipServer, recvBuf);
		*/
		
	}

	closesocket(Client);//关闭客户端套接口
	WSACleanup();//重置
}


int main()
{
    std::cout << "Hello World!\n";
	std::thread threads[10];
	int client_num = 1;
	for (int i = 0; i < client_num; i++)
		threads[i] = std::thread(new_client, i);

	for (int i = 0; i < client_num; i++)
		threads[i].join();

	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
