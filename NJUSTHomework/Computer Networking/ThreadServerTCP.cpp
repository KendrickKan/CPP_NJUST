// ThreadServerTCP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
// ServerTcp.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <thread>

void func(SOCKET arg, SOCKADDR_IN client_addr, int pos)
{
	char recvBuf[128];
	char sendBuf[128];
	char tempBuf[256];
	int sockConn = arg;
	while (true)
	{
		// 从客户端接收消息
		printf("wait receive client message :\n");
		recv(sockConn, recvBuf, 128, 0);

		// 解析客户端地址信息
		char ipClient[16];
		inet_ntop(AF_INET, &client_addr.sin_addr, ipClient, sizeof(ipClient));
		printf("%s said: %s\n", ipClient, recvBuf);

		// 向客户端发送消息
		gets_s(sendBuf);
		send(sockConn, sendBuf, strlen(sendBuf) + 1, 0);
	}
}



int main()
{

    
	std::cout << "Hello World!\n";

	/**********************************************************************/
/*
WSAStartup必须是应用程序或DLL调用的第一个Windows Sockets函数。
它允许应用程序或DLL指明Windows Sockets API的版本号及获得特定Windows Sockets实现的细节。
应用程序或DLL只能在一次成功的WSAStartup()调用之后才能调用进一步的Windows Sockets API函数。
*/
	WORD wVersionRequested;//记录版本型号的变量
	WSADATA wsaData;//创建结构体变量
	int err;
	wVersionRequested = MAKEWORD(1, 1);//以无符号16位整型数座位版本号，指定高低字节都为1
	err = WSAStartup(wVersionRequested, &wsaData);// 初始化Winsock，加载一个Winsocket库版本
	if (err != 0) { return 0; }//若执行不成功则返回

	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)//进行版本检查
	{
		WSACleanup();//释放资源重置程序
		return 0;
	}
	/***********************************************************************/

	// 申请存储线程的数组
	std::thread threads[10];
	int thread_num = 0;

	/***********************************************************************/
	/*                        socket通讯                                   */
	// 申请套接字
	SOCKET Svr = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN addr;

	// 要绑定的基础信息
	addr.sin_family = AF_INET; // sin_family指代协议族，其值一般是AF_INET表示采用IPv4协议
	addr.sin_port = htons(6002);//将端口号6002赋给sin_port 
	addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);//响应所以地址

	// 进行绑定
	int len = sizeof(sockaddr);
	bind(Svr, (struct sockaddr*) & addr, len);

	// 监听套接字
	int ret = listen(Svr, 10);
	if (ret == SOCKET_ERROR)//监听失败返回提示消息
	{
		printf("侦听失败\n");
		closesocket(Svr);
	}

	// 存储请求连接的套接字信息
	SOCKADDR_IN addrClient;

	while (true)
	{
		// 接受连接，返回一个socket
		SOCKET sockConn = accept(Svr, (struct sockaddr*) & addrClient, &len);
		if (sockConn == INVALID_SOCKET)//检查是否是有效socket
		{
			//printf("无效socket\n");
			continue;
		}

		// 将通讯细节放在线程里处理
		threads[thread_num] = std::thread(func, sockConn, addrClient, thread_num);
		thread_num++;

		if (thread_num == 5)
		{
			printf("线程池达到数量上限");
		}
	}

	// 等待线程结束
	for (int i = 0; i < thread_num; i++)
		threads[i].join();

	// 释放套接字
	closesocket(Svr);
	WSACleanup();
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
