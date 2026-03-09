/*** client side program***/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
int main()
{
 char wbuf[128];
 int sockfd;
 struct sockaddr_in srv;
 printf("creating  client socket.....\n");
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 if(sockfd<0)
 {
         perror("socket");
         return 0;
 }
 printf("socket created successfully.....\n");
 srv.sin_family = AF_INET;
 srv.sin_port  =htons(1025);
 srv.sin_addr.s_addr=inet_addr("127.0.0.0");
 printf("client sending reques...\n");
 if(connect(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
   printf("connection established successfully...\n");
 else
         {
         perror("connect");
         return 0;
         }
 printf("enter the message...\n");
 scanf("%s",wbuf);
 write(sockfd,wbuf,strlen(wbuf)+1);
}


