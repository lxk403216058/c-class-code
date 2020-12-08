#include <stdio.h>
/* Windows socket头文件 */
#include <Winsock2.h>
/* 网络API的动态链接库 */
#pragma comment(lib, "ws2_32.lib")

int main()

{
   SOCKET uiFdsocket;
   WSADATA wsaData;
   struct sockaddr_in stServerAddr;
   int iAddrlen = sizeof(sockaddr_in);
   char szbuffer[1024] = "\0";
   if (0 != WSAStartup(MAKEWORD(2,1),&wsaData)) 
   {
   printf("Winsock init faied!\r\n");
   WSACleanup();
   return 0;

   }
   /* 服务器监听的端口和地址 */
   memset(&stServerAddr, 0, sizeof(stServerAddr));
   stServerAddr.sin_family = AF_INET;
   stServerAddr.sin_port = htons(6000); 
   stServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
   printf("Now connecting the server...\r\n");
   uiFdsocket = socket(AF_INET, SOCK_DGRAM, 0);
   while(true)
   {
      printf("please enter\n");
      scanf("%s", szbuffer);
      if(strcmp(szbuffer, "bye") == 0)
      {
         printf("exit\r\n");
         Sleep(100);
         closesocket(uiFdsocket);
         break;
  }
      if(SOCKET_ERROR != sendto(uiFdsocket, szbuffer,sizeof(szbuffer), 0, (struct  sockaddr*)&stServerAddr, iAddrlen))
      {
        Sleep(100);
        if (SOCKET_ERROR != recvfrom(uiFdsocket, szbuffer, sizeof(szbuffer), 0, (struct sockaddr*)&stServerAddr, &iAddrlen))
      {printf("recive from server:%s\r\n", szbuffer);
      }
      }
    }  
   closesocket(uiFdsocket);
   return 0;

}
