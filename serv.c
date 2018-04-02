#include<stdio.h>
#include<string.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
void main()
{
	int ssock,sport,status,sd;
	char rmsg[100];
	//Create a socket
	ssock=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in servaddr, cliaddr;
	printf("Enter server port : ");
	scanf("%d",&sport);
	//initialising shit which dont make no sense to me
	servaddr.sin_family=AF_INET;
	servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	servaddr.sin_port=htons(sport);
	//binding this mudafuka
	sd=bind(ssock,(struct sockaddr*)&servaddr,sizeof(servaddr));
	//checking status of bind
	printf("BInd :%d\n",sd);
	//now listen for how ever long you want
	listen(ssock,5);
	int clilen=sizeof(cliaddr);
	status=accept(ssock,(struct sockaddr*)&cliaddr,&clilen);
	//checking status of accept
	printf("accept :%d\n",status);
	int rec=recv(status,rmsg,100,0);
	//checking status of recv
	printf("rcv :%d\n",rec);
	printf("\nMessage received is :\n");
	printf("%s\n", rmsg);
	const char* data_to_send = "Good job boy";
	send(status, data_to_send, strlen(data_to_send), 0);



}