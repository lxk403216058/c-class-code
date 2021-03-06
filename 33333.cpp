#include <stdio.h>
/* Windows socket头文件 */
#include <Winsock2.h>
/* 网络API的动态链接库 */
#pragma comment(lib, "ws2_32.lib")
int main()
{
   SOCKET uiFdSocket;
   WSADATA wsaData;
   char szbuffer[1024] = "\0";
   struct sockaddr_in stServerAddr;
   struct sockaddr_in stClientAddr;
   int iAddrlen = sizeof(sockaddr_in);
   /* 调用Windows Sockets DLL,成功后才能使用socket系列函数 */
   if (WSAStartup(MAKEWORD(2,1), &wsaData)!=0) 
    {
         printf("Winsock init failed!\r\n");
         WSACleanup();
         return 0;

    }
   memset(&stServerAddr, 0, sizeof(stServerAddr));
   memset(&stClientAddr, 0, sizeof(stClientAddr));
   /* 服务器地址 */
   stServerAddr.sin_family = AF_INET;
   /* 监听端口 */
   stServerAddr.sin_port = htons(6000); 
   stServerAddr.sin_addr.s_addr = INADDR_ANY;
   /* 服务器端创建socket, 报文模式(UDP)*/
   uiFdSocket = socket(AF_INET, SOCK_DGRAM, 0);
   /* 绑定端口号 */
   bind(uiFdSocket, (struct sockaddr*)&stServerAddr, sizeof(sockaddr_in));
   while(1)
   {
    printf("waiting...\r\n");
    if (SOCKET_ERROR != recvfrom(uiFdSocket,szbuffer,sizeof(szbuffer),0,(struct  sockaddr*)&stClientAddr, &iAddrlen))
    {
     printf("recive from %s--%s\n", inet_ntoa(stClientAddr.sin_addr), 	szbuffer);
     sendto(uiFdSocket, szbuffer, sizeof(szbuffer), 0, (struct sockaddr*)&stClientAddr, 	iAddrlen);
   }
   }
   closesocket(uiFdSocket);
}
