// Name:33_client.c 
// Author:Rishabh Kumar Singh
// Roll No.:MT2024125
// Date:19 Sep 2024

// 33. Write a program to communicate between two machines using socket.

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
    struct sockaddr_in serv;
    int sd;
    char buf[80];
    sd=socket(AF_UNIX, SOCK_STREAM, 0);

    serv.sin_family=AF_UNIX;
    serv.sin_addr.s_addr=INADDR_ANY;
    serv.sin_port=htons(5055);

    connect(sd,(void *)(& serv),sizeof(serv));
    write(sd,"Hello SERVER\n",14);
    read(sd,buf,sizeof(buf));
    printf("Message from Server:%s\n",buf);
}


// Output:
// Message from Server:ACK from SERVER