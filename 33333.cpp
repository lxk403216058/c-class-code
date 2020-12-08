#include <stdio.h>
/* Windows socketͷ�ļ� */
#include <Winsock2.h>
/* ����API�Ķ�̬���ӿ� */
#pragma comment(lib, "ws2_32.lib")
int main()
{
   SOCKET uiFdSocket;
   WSADATA wsaData;
   char szbuffer[1024] = "\0";
   struct sockaddr_in stServerAddr;
   struct sockaddr_in stClientAddr;
   int iAddrlen = sizeof(sockaddr_in);
   /* ����Windows Sockets DLL,�ɹ������ʹ��socketϵ�к��� */
   if (WSAStartup(MAKEWORD(2,1), &wsaData)!=0) 
    {
         printf("Winsock init failed!\r\n");
         WSACleanup();
         return 0;

    }
   memset(&stServerAddr, 0, sizeof(stServerAddr));
   memset(&stClientAddr, 0, sizeof(stClientAddr));
   /* ��������ַ */
   stServerAddr.sin_family = AF_INET;
   /* �����˿� */
   stServerAddr.sin_port = htons(6000); 
   stServerAddr.sin_addr.s_addr = INADDR_ANY;
   /* �������˴���socket, ����ģʽ(UDP)*/
   uiFdSocket = socket(AF_INET, SOCK_DGRAM, 0);
   /* �󶨶˿ں� */
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
