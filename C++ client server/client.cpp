//*********************************************************************************************************
//This is the client code for the chat program
//
//*********************************************************************************************************

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

using namespace std;

int port = 4040;
int main(int argc, char *argv[])
{
    int sock, n;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    char buffer[256];
    if (argc < 2) {
       cout << "Error, you are missing address" << endl;
       exit(0);
    }
   
   for(int i = 0; i < 3; i++)
  {
    sock = socket(AF_INET, SOCK_STREAM, 0);		//create socket
    if (sock < 0) 
        cout << "ERROR opening socket" << endl;

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        cout << "Could not find host" << endl;
        exit(0);
      }
   // bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr,server->h_length);
    serverAddr.sin_port = htons(port);
 
    if (connect(sock,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0) 
        cout << "Connection failed" << endl;
    
    printf("Please enter your password: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);			//recieves message from user
    n = write(sock,buffer,strlen(buffer));	//writes to server socket
    if (n < 0) 
         cout << "Write failed" << endl;

    bzero(buffer,256);				//fills buffer with zeros to be filled with new message
    n = read(sock,buffer,255);
    if (n < 0) 
         cout << "Read failed" << endl;
    cout << buffer;
  
    close(sock);
  }
    return 0;
}
