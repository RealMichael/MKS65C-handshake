#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {
	int des = mkfifo("troy",0644);
	if(des == -1){
	printf("Err");
	}

	int rancid = open("troy",O_RDONLY);
	char first[BUFFER_SIZE];
	read(rancid,first,BUFFER_SIZE);
	printf("Initial: %s\n", first);

	*to_client = open(first,O_WRONLY);
	write(*to_client, "Hello!",10);
	
	char second[BUFFER_SIZE];
	read(rancid,second, BUFFER_SIZE);
	printf("Got: %s\n", second);
	
	return rancid;

}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
	int ran = mkfifo("dom",0644);
	if(ran == -1){
	printf("ERR");
	}

	*to_server = open("troy",O_WRONLY);
	printf("Connected");
	write(*to_server,"Thanks for the greeting",50);
	
	char third[BUFFER_SIZE];
	int beast = open(third,O_RDONLY);
	
	printf("Server- %d \n", beast);
	char four[BUFFER_SIZE];
	read(beast,four,BUFFER_SIZE);
	printf("Message is %s\n",four);
	
	
	return beast;






 // return 0;
}











