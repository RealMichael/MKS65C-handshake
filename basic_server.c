#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

	char se[BUFFER_SIZE];
		
	while(read(from_client,se,BUFFER_SIZE)){
	
	write(to_client,se,BUFFER_SIZE);
	
	}
return 0;

}
