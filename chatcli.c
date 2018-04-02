#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
	int sd,cport;
	char rmsg[100];
	printf("Enter port no : ");
	scanf("%d",&cport);
	sd=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr,cliaddr;
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(cport);
	int cd=connect(sd,(struct sockaddr*)&servaddr,sizeof(servaddr));
	for(;;)
	{
		char sms[100];
		printf("Client : ");
		fgets(sms,100,stdin);
		send(sd, sms, 100, 0);
		int rec=recv(sd,rmsg,100,0);
		printf("\nServer : ");
		printf("%s\n", rmsg);
	}
}