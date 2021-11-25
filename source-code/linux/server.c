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
 
#define ANY "0.0.0.0"
 #define BUFFER 1024
 #define end 0

void Serving(int PORT);
void Getting_Available_IP(){
	#if __linux__
	FILE * IP_GET;
		printf("\n\t[!] Available IP Address [!] \n ");
		IP_GET=popen("ifconfig |grep 'inet ' | cut -d ' ' -f 10","r");
		char reader[100];
		while(fgets(reader,100,IP_GET)!=NULL){
		printf("\nIP :\t %s",reader);
		}
		printf("\n[+] Client should connect one of this IP [+]\n\n");
		fclose(IP_GET);
	#endif
}
int main(int argc, char*argv[]){
	if (argc ==2){
	int PORT1=atoi(argv[1]);
	Getting_Available_IP();
	Serving(PORT1);
	}
	else if (argc > 2){
	printf("\t\t Me 2 You {Chat App} \n\n\tMade By Eslam Muhammed Elabd\n\t@github.com/Crypt00o\n[*] Usage [*]: \n\t\t ./server <port> \n\t\tport : to listen on ");
	return EXIT_SUCCESS;
	}
else if (argc < 2){
        printf("\t\t Me 2 You {Chat App} \n\n\tMade By Eslam Muhammed Elabd\n\t@github.com/Crypt00o\n[*] Usage [*]: \n\t\t ./server <port> \n\t\tport : to listen on ");
        return EXIT_SUCCESS; 
        }

}

void Serving(int PORT){

//Declaring Variables
	char * readdata=malloc(BUFFER);
	char sendata[BUFFER]; 
	char * recvdata = malloc(BUFFER);
	char * welcome_message=malloc((strlen("[+] welcome to me 2 you chat server [+]")+1));
	welcome_message="[+] welcome to me 2 you chat server [+]";
//Network Part
	
	int client_sock=socket(AF_INET,SOCK_STREAM,0);
	int server_sock=socket(AF_INET,SOCK_STREAM,0);
	
	struct sockaddr_in server_bind;
	server_bind.sin_family=AF_INET;
	server_bind.sin_port=htons(PORT);
	server_bind.sin_addr.s_addr=inet_addr(ANY);

//binding port and Listening on it
	
	bind(server_sock,(struct sockaddr*)&server_bind,sizeof(server_bind));
	listen(server_sock,5);

//Accepting Any Connection
	
	struct sockaddr_in client;
	int sockaddrsize = sizeof(struct sockaddr_in);

	client_sock=accept(server_sock,(struct sockaddr*)&client,(socklen_t*)&sockaddrsize);
	if(client_sock>0){
		printf("\n\n\t[Connected]\n[+] Waiting for Client Message [+]\n\n ");
		
	}
	send(client_sock,welcome_message,strlen(welcome_message),end);
//Sending And Recieving

	while(1){
	recv(client_sock,recvdata,BUFFER,end);
	printf("%s",recvdata);
	printf("\nyour message > : ");
	fgets(readdata,BUFFER,stdin);
	strcpy(sendata,"\nmessage from server: ");
	strcat(sendata,readdata);
	strcat(sendata,"\n");
	send(client_sock,sendata,strlen(sendata),end);
	printf("\n[*] Waiting for Client Message [*]\n\t<-> <-> <-> <-> <-> <->\n\n");
	memset(&sendata,0,sizeof(sendata));
	}

}
