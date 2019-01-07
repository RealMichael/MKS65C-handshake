#include "pipe_networking.h"


int main() {

	int to_server;
	int from_server;

	char send[BUFFER_SIZE];
	char get[BUFFER_SIZE];
	


	from_server = client_handshake( &to_server );
	
	while (1){
		printf("TYPE A MESSAGE!");	
		fgets(send,BUFFER_SIZE,stdin);
		write(to_server,send,256);
		printf("wrote: %s\n",send);

		read(from_server,get,256);
		printf("got: %s\n",get);
	}

	return 0;
}
