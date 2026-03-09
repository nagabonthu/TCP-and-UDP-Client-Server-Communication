/*** Server side program***/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<strings.h>
int main()
{
  char rbuf[128];
 int sockfd,newfd;
 struct sockaddr_in srv,cln;
 printf("creatin  server socket.....\n");
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 if(sockfd<0)
 {
         perror("socket");
         return 0;
 }
 printf("socket created successfully.....\n");
 srv.sin_family = AF_INET;
 srv.sin_port  =htons(1025);
 srv.sin_addr.s_addr=inet_addr("0.0.0.0");
 printf("binding address....\n");
 if(bind(sockfd,(struct sockaddr*)&srv,sizeof(srv))==0)
   printf("bind success...\n");
 else
         {
         perror("bind");
         return 0;
         }
 if(listen(sockfd,1)==0)
 printf("server listening....\n");
 else
 {
         perror("listen");
         return 0;
}
         int len=sizeof(cln);
 newfd=accept(sockfd,(struct sockaddr*)&cln,&len);
                 if(newfd<0)
                 {
                 perror("accept");
                 return 0;
                 }
            printf("new connnection accepted....\n");


                 bzero(rbuf,128);
                 read(newfd,rbuf,128);
                 printf("received message:%s\n",rbuf);

}

