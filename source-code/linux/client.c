/*\ ____________________________
 * | [+]  Chat APP Client  [+]  | 
 * |	  ---------------	|
 * |  This Program Made	By	|
 * |	Eslam Muhammed Elabd	|
 * |____________________________|
 \*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <errno.h>

 #define BUFFER 1024
 #define end 0
void Connecting(int PORT,char * IP);
int main(int argc , char * argv[]){
if (argc ==3){
	int PORT1=atoi(argv[2]);
	Connecting(PORT1,argv[1]);
	}
	else if (argc > 3){
	printf("\t\t Me 2 You {Chat App} \n\n\tMade By Eslam Muhammed Elabd\n\t@github.com/Crypt00o\n[*] Usage [*]: \n\t\t ./client <ip> <port>\n\t\tip : to connect on \n\t\tport : to listen on ");
	return EXIT_SUCCESS;
	}
else if (argc < 3){
        printf("\t\t Me 2 You {Chat App} \n\n\tMade By Eslam Muhammed Elabd\n\t@github.com/Crypt00o\n[*] Usage [*]: \n\t\t ./client <ip> <port>\n\t\tip: to connect on \n\t\tport : to connect to ");
        return EXIT_SUCCESS; 
        }
return EXIT_SUCCESS;
}
struct sockaddr_in server;
void Connecting(int PORT,char* IP){
//Declaring Variables
	/*error variable*/ errno=0;
	static int connect_times=1;
	char * readdata=malloc(BUFFER);
	char sendata[BUFFER]; 
	char * recvdata=malloc(BUFFER);
//Declaring Network Part
	int client_sock=socket(AF_INET,SOCK_STREAM,end);
	struct sockaddr_in * ptrserver=&server;
	ptrserver->sin_family=AF_INET;
	ptrserver->sin_port=htons(PORT);
	ptrserver->sin_addr.s_addr=inet_addr(IP);
	if(connect(client_sock,(struct sockaddr*)ptrserver,sizeof(*ptrserver))){
		printf("\n\n\n\t\t[!] Server is Down Try Again Letter [!]\n\n");
                perror("Error Chat App ");
                exit(EXIT_FAILURE);
	}
	printf("\n\n\t[Connected]\n\n");
	recv(client_sock,recvdata,BUFFER,end);
	printf("%s\n",recvdata);
	while(1){
	printf("\nyour message > : ");
	fgets(readdata,BUFFER,stdin);
	strcpy(sendata,"\nmessage from client: ");
	strcat(sendata,readdata);
	strcat(sendata,"\n");
	send(client_sock,sendata,strlen(sendata),end);
	printf("\n[*] Waiting for Server Message [*]\n\t<-> <-> <-> <-> <-> <->\n\n");
	recv(client_sock,recvdata,BUFFER,end);
	printf("%s",recvdata);
	memset(&sendata,0,sizeof(sendata));
	//Connection refused errno = 111 
	if (errno==111){
		printf("\n\n\n\t\t[!] Server is Down Try Again Letter [!]\n\n");
		perror("Error Chat App ");
		exit(EXIT_FAILURE);
		break;
			}
	}
}

