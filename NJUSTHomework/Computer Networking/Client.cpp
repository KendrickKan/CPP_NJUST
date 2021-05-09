#include <stdio.h>
#include <winsock.h>

// Function prototype
void StreamClient(char *szServer, short nPort);

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
	// Check for the host and port arguments
	//
	if (argc != 3)//检测端口与主机参数 
	{
		fprintf(stderr,"\nSyntax: client ServerName PortNumber\n");
		return 0;
	}

	nPort = atoi(argv[2]);


	//
	// Initialize WinSock and check the version
	//
	nRet = WSAStartup(wVersionRequested, &wsaData);//初始化Winsock，加载一个Winsocket库版本
	if (wsaData.wVersion != wVersionRequested)//进行版本检查，版本不相同则告知版本有错 
	{	
		fprintf(stderr,"\n Wrong version\n");
		return 0;
	}


	//
	// Go do the stuff a stream client does
	//
	StreamClient(argv[1], nPort);
	
	//
	// Release WinSock
	//
	WSACleanup();//重置，为应用程序 重新分配的资源 
}

////////////////////////////////////////////////////////////

void StreamClient(char *szServer, short nPort)
{
	printf("\nStream Client connecting to server: %s on port: %d",
				szServer, nPort);

	//
	// Find the server
	//
    LPHOSTENT lpHostEntry;//创建对象IpHostEntry 

	lpHostEntry = gethostbyname(szServer);//获取server 
    if (lpHostEntry == NULL)//没获取到server则输出相应的错误类型 
    {
        PRINTERROR("gethostbyname()");
        return;
    }

	//
	// Create a TCP/IP stream socket
	//
	SOCKET	theSocket;

	theSocket = socket(AF_INET,				// Address family，表示IPV4 
					   SOCK_STREAM,			// Socket type，，表示采用TCP  
					   IPPROTO_TCP);		// Protocol，指定TCP 
	if (theSocket == INVALID_SOCKET)//如果是无效的socket则告知错误 
	{
		PRINTERROR("socket()");
		return;
	}

	//
	// Fill in the address structure
	//
	SOCKADDR_IN saServer;//定义存放本地地址信息的结构体变量

	saServer.sin_family = AF_INET;//sin_family指代协议族，其值一般是AF_INET表示采用IPv4协议
	saServer.sin_addr = *((LPIN_ADDR)*lpHostEntry->h_addr_list);//响应IpHostEntry的地址 
										// ^ Server's address
	saServer.sin_port = htons(nPort);	// Port number from command line，将端口号赋给sin_port 

	//
	// connect to the server
	//
	int nRet;
//将sockSrv连接到端口（nport）
	nRet = connect(theSocket,				// Socket
				   (LPSOCKADDR)&saServer,	// Server address
				   sizeof(struct sockaddr));// Length of server address structure
	if (nRet == SOCKET_ERROR)//提示错误类型 
	{
		PRINTERROR("socket()");
		closesocket(theSocket);
		return;
	}

	//
	// Send data to the server
	//
	char szBuf[256];

	strcpy(szBuf, "From the Client");//复制消息进入buf 
	nRet = send(theSocket,				// Connected socket，向服务器发送数据 
				szBuf,					// Data buffer
				strlen(szBuf),			// Length of data
				0);						// Flags
	if (nRet == SOCKET_ERROR)//提示发送错误类型 
	{
		PRINTERROR("send()");
		closesocket(theSocket);
		return;
	}

	//
	// Wait for a reply
	//
	nRet = recv(theSocket,				// Connected socket，从服务器接收数据 
				szBuf,					// Receive buffer
				sizeof(szBuf),			// Size of receive buffer
				0);						// Flags
	if (nRet == SOCKET_ERROR)//提示接收错误类型 
	{
		PRINTERROR("recv()");
		closesocket(theSocket);
		return;
	}

	//
	// Display the received data
	//
	printf("\nData received: %s", szBuf);//输出从服务器接收到缓冲区里的数据 


	closesocket(theSocket);//结束套接口 
	return;
}

