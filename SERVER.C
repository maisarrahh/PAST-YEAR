#include <stdio.h> // standard input and output library

#include <stdlib.h> // this includes functions regarding memory allocation

#include <string.h> // contains string functions

#include <errno.h> //It defines macros for reporting and retrieving error conditions through error codes

#include <time.h> //contains various functions for manipulating date and time

#include <unistd.h> //contains various constants

#include <sys/types.h> //contains a number of basic derived types that should be used whenever appropriate

#include <arpa/inet.h> // defines in_addr structure
#include <sys/socket.h> // for socket creation

#include <netinet/in.h> //contains constants and structures needed for internet domain addresses
 

int main()
{
    
time_t clock;

int epoch_time = 0;
time_t rawtime; 
time_t epoch_time_as_time_t = epoch_time;
struct tm * timeinfo;
char dataSending[1025]; 
int clintListn = 0, clintConnt = 0;
   
struct sockaddr_in ipOfServer;
    
clintListn = socket(AF_INET, SOCK_STREAM, 0); // creating socket
    
memset(&ipOfServer, '0', sizeof(ipOfServer));
    
memset(dataSending, '0', sizeof(dataSending));
    
ipOfServer.sin_family = AF_INET;
    
ipOfServer.sin_addr.s_addr = htonl(INADDR_ANY);
    
ipOfServer.sin_port = htons(7776);         // this is the port number of running server
    
bind(clintListn, (struct sockaddr*)&ipOfServer , sizeof(ipOfServer));
    
listen(clintListn , 20);
 
    
while(1)
   
 {
	        
clock = time(NULL);
  		
time ( &rawtime ); //wew
  		
timeinfo = localtime ( &rawtime ); //wew

        
printf("\n\nWaiting for client connection...\n"); // whenever a request from client came. It will be processed here.
        
clintConnt = accept(clintListn, (struct sockaddr*)NULL, NULL);
 	
	
printf("Connected. Client time : %s" , asctime (timeinfo) ); // whenever a request from client came. It will be processed here.
////////////////////////////////

timeinfo = localtime(&epoch_time_as_time_t);

if(epoch_time >= 0 && epoch_time < 12)
{    

printf("its morning", epoch_time);

snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Morning");

write(clintConnt, dataSending, strlen(dataSending));

}


else if(epoch_time >= 12 && epoch_time < 14)
{    
p
rintf("It's Afternoon :)", epoch_time);

snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Afternoon!");

write(clintConnt, dataSending, strlen(dataSending));

}


else if(epoch_time >= 14 && epoch_time < 19)
{    
printf("It's Evening :)", epoch_time);

snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Evening!");

write(clintConnt, dataSending, strlen(dataSending));

}


else if(epoch_time >= 19 && epoch_time < 24)
{    
printf("It's Night :)", epoch_time);

snprintf(dataSending, sizeof(dataSending), "%.24s\r\n", "Good Night!");

write(clintConnt, dataSending, strlen(dataSending));

}

/////////////////////////////////


       
 
      
  
close(clintConnt);
        
sleep(1);
     
}
 
     
return 0;
}
