//*************************************************************************************************
//server program for chat
//
//*************************************************************************************************

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

int port = 4040;
int main(int argc, char *argv[])
{
     int serverSock, clientSock;		//sockets to read and write to client/server
     socklen_t size;
     char buffer[256];				//buffer holds message from client
     char hostname[255];
     struct sockaddr_in serverAddr, clientAddr;
     int n;
     cout << "Use following hostname to connect to this server: " << endl; 
     gethostname(hostname, 255); 		//prints out host name of the server
     printf(hostname);
     cout << endl;
 
     serverSock = socket(AF_INET, SOCK_STREAM, 0);
     if (serverSock < 0) 
        cout << "Socket creation failed" << endl;
     cout << "Socket created" << endl;

     serverAddr.sin_family = AF_INET;
     serverAddr.sin_addr.s_addr = INADDR_ANY;
     serverAddr.sin_port = htons(port);
     if (bind(serverSock, (struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0)   //binds to socket 
        cout << "Binding failed" << endl;
     cout << "Binding successful" << endl;

     listen(serverSock,5);			//listens for client, at most 5 connections
     size = sizeof(clientAddr);
   while (1 == 1)				//infinite loop
   {
     clientSock = accept(serverSock,(struct sockaddr *) &clientAddr,&size);	//accepts connection from client
     if (clientSock < 0) 
          cout << "Connection failed" << endl;
     cout << "Connection successful" << endl;
     
     bzero(buffer,256);			
     n = read(clientSock,buffer,255);		//reads message from client and stores in buffer
     cout << "This is message: ";
     printf(buffer);
     cout << endl;
     if (n < 0)
       cout << "Read failed" << endl;
     cout << "Read succesfful" << endl;
     
     n = write(clientSock,"I got your message",18);
     if (n < 0) 
       cout << "Write failed" << endl;

    
     close(clientSock);				//closes client connection after message is sent back
   }
     close(serverSock);
     return 0; 
}
