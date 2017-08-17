#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void onlyerror(char *t)
{
printf("%s",&t);
}
#define echomax 255
int num=0;
int main(int argc,char *argv[])
{ 

int sock,clisock;
struct sockaddr_in serveraddr;
struct sockaddr_in clientaddr;
unsigned int incsize;
unsigned int recievedmsg;
char bufferecho[256];
char *reverse;
unsigned int serverport;
unsigned int clientport;

serverport=atoi(argv[1]);

sock=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

memset(&serveraddr ,0,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(serverport);
serveraddr.sin_addr.s_addr=htonl(INADDR_ANY);

if(bind (sock ,(struct sockaddr*) &serveraddr,sizeof(serveraddr)) < 0)
onlyerror("bind faileds");

listen(sock,200);

int i=0,j=1;
while(i<=2)
{
i++;
incsize = sizeof(clientaddr);

clisock=accept(sock,(struct sockaddr*) &clientaddr,&incsize);
recievedmsg = recv(clisock,bufferecho,echomax, 0);
if(i==1)
{
printf("\nHandling client %s\n", inet_ntoa(clientaddr.sin_addr)) ;
 bufferecho[recievedmsg]='\0';

printf("weight in kg ==%s\n",bufferecho);
func(bufferecho);

}
else if(i==2)
{
char tr[100]="someone-is-attempting-suicide";
char tr1[100]="nothing-is-happening";
if(num>50)
{


printf("Handling client %s\n", inet_ntoa(clientaddr.sin_addr)) ;
printf("time is : %s",system("/home/harshit/Desktop/scr123" ));
send(clisock,tr , 100, 0);
system("/home/harshit/Desktop/src11" );
printf("-----------------------------------------------------------------------------");



}
i=0;
/*else 
{
send(clisock,tr1 , 28, 0);
i=0;
}*/
}




close(clisock);

}
}

void func(char *p)
{
num=0;
for(int i=0;p[i]!=NULL;i++)
{
int y=(int)p[i]-48;
//printf("%d",y);
num=num*10+y;
}
if(num>50)
printf("weight exceed");
}


