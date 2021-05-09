#include <stdio.h>
#include <winsock.h>

// Function prototype
void StreamServer(short nPort);

// Helper macro for displaying errors
#define PRINTERROR(s)	\
		fprintf(stderr,"\n%: %d\n", s, WSAGetLastError())

////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	WORD wVersionRequested = MAKEWORD(1,1);//创建无符号16位整型作为版本号，指定新变量的高低字节都为1 
	WSADATA wsaData;//定义结构体变量wsaData
	int nRet;
	short nPort;

	//
	// Check for port argument
	//
	if (argc != 2)//检查端口参数 
	{
		fprintf(stderr,"\nSyntax: server PortNumber\n");
		return 0;
	}

	nPort = atoi(argv[1]);

	//
	// Initialize WinSock and check version
	//
	nRet = WSAStartup(wVersionRequested, &wsaData);//初始化Winsock，加载一个Winsocket库版本
	if (wsaData.wVersion != wVersionRequested)//进行版本检查，版本不相同则告知版本有错 
	{	
		fprintf(stderr,"\n Wrong version\n");//输出版本错误 
		return 0;
	}
	// Do the stuff a stream server does
	StreamServer(nPort);// 
	// Release WinSock
	//
	WSACleanup();//重置，为应用程序 重新分配的资源 
}


void StreamServer(short nPort)
{
	//
	// Create a TCP/IP stream socket to "listen" with
	//
	SOCKET	listenSocket;//创建SOCKET对象listenSocket 

	listenSocket = socket(AF_INET,			// Address family，表示IPV4 
						  SOCK_STREAM,		// Socket type，表示采用TCP 
						  IPPROTO_TCP);		// Protocol，指定TCP 
	if (listenSocket == INVALID_SOCKET)//如果是无效的socket则告知错误 
	{
		PRINTERROR("socket()");
		return;
	}

	//
	// Fill in the address structure
	//
	SOCKADDR_IN saServer;	//定义存放本地地址信息的结构体变量saServer	

	saServer.sin_family = AF_INET;//sin_family指代协议族，其值一般是AF_INET表示采用IPv4协议
	saServer.sin_addr.s_addr = INADDR_ANY;	// Let WinSock supply address，响应所有地址 
	saServer.sin_port = htons(nPort);// Use port from command line，将端口号赋给sin_port 

	//
	// bind the name to the socket
	//
	int nRet;
//将sockSrv绑定到端口（nport） 
	nRet = bind(listenSocket,				// Socket 
				(LPSOCKADDR)&saServer,		// Our address
				sizeof(struct sockaddr));	// Size of address structure
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("bind()");
		closesocket(listenSocket);
		return;
	}

	//
	// This isn't normally done or required, but in this 
	// example we're printing out where the server is waiting
	// so that you can connect the example client.
	//
	int nLen;
	nLen = sizeof(SOCKADDR);
	char szBuf[256];

	nRet = gethostname(szBuf, sizeof(szBuf));//获取主机名 
	if (nRet == SOCKET_ERROR)//主机名不匹配 
	{
		PRINTERROR("gethostname()");
		closesocket(listenSocket);
		return;
	}

	//
	// Show the server name and port number
	//
	printf("\nServer named %s waiting on port %d\n",
			szBuf, nPort);//在屏幕上输出主机名与端口号 

	//
	// Set the socket to listen
	//

	printf("\nlisten()");
	nRet = listen(listenSocket,					// Bound socket
		  SOMAXCONN);					// Number of connection request queue
	if (nRet == SOCKET_ERROR)
	{
		PRINTERROR("listen()");
		closesocket(listenSocket);
		return;
	}

	//
	// Wait for an incoming request
	//
	SOCKET	remoteSocket;

	printf("\nBlocking at accept()");
	remoteSocket = accept(listenSocket,			// Listening socket
						  NULL,					// Optional client address，建立一个新的套接字用于通信 
						  NULL);
	if (remoteSocket == INVALID_SOCKET)
	{
		PRINTERROR("accept()");
		closesocket(listenSocket);
		return;
	}

	//
	// We're connected to a client
	// New socket descriptor returned already
	// has clients address

	//
	// Receive data from the client
	//
	memset(szBuf, 0, sizeof(szBuf));//szBuf清0 
	nRet = recv(remoteSocket,					// Connected client，从客户端接受数据 
				szBuf,							// Receive buffer
				sizeof(szBuf),					// Lenght of buffer
				0);								// Flags
	if (nRet == INVALID_SOCKET)//提示接收错误类型 
	{
		PRINTERROR("recv()");
		closesocket(listenSocket);//关闭侦听 
		closesocket(remoteSocket);//关闭接收 
		return;
	}

	//
	// Display received data
	//
	printf("\nData received: %s", szBuf);//输出szBuf内容 
    //提供服务
	//
	// Send data back to the client
	//
	strcpy(szBuf, "From the Server");//复制消息进入buf 
	nRet = send(remoteSocket,				// Connected socket，向客户端发送数据 
				szBuf,						// Data buffer
				strlen(szBuf),				// Lenght of data
				0);							// Flags

	//
	// Close BOTH sockets before exiting
	//
	closesocket(remoteSocket);//关闭侦听 
	closesocket(listenSocket);//关闭接收 
	return;
}



