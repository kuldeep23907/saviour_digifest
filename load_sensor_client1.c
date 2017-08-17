#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#define echomax 255

void  onlyerror( char *msg )
{
printf("%s",msg);
}
void main(int argc , char *argv[])
{
int sock;
struct sockaddr_in serveraddr;
struct sockaddr_in clientaddr;

unsigned short serverport;
unsigned short clientport;
unsigned int recievesize;
 
char *serverip;
char *clientip;

char *stringecho;
int stringecholen;
int recievestringlen;
char bufferecho[echomax + 1];



serverip=argv[1];
//printf("entr the message");
//scanf("%s",stringecho);
stringecho=argv[2];

stringecholen=strlen(stringecho) ;
serverport=5509;

sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

if(bind(sock,(struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0)
onlyerror("bindfails");
memset(&serveraddr ,0 ,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr(serverip);
serveraddr.sin_port=htons(serverport);

connect(sock,(struct sockaddr *)&serveraddr,sizeof(serveraddr));

send(sock,stringecho,stringecholen,0);

recievesize=sizeof(clientaddr);
recievestringlen=recv(sock,bufferecho,echomax,0);

 bufferecho[recievestringlen]='\0';
 printf(" %s\n",bufferecho);
 close(sock);
exit(1);
}










