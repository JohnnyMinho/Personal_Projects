#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

void* Request_Handler_Thread(){

}

void*


//Since this is only going to be local we will use the localhost ip range 127.0.0.1 - 127.255.255.255
//This part of the code will be responsible for maintaning the chatrooms and their creation
//The server will be running on the 127.0.0.1

int main(int argc, char* argv[]){

    int ChatMasterSocket;
    struct sockaddr_in ChatMasterAddr, ClientAddr;
    char RequestBuffer[257];
    RequestBuffer[256] = '\0';
    socklen_t ChatMasterAddr_Size = sizeof(ChatMasterAddr);

    ChatMasterSocket = socket(AF_INET,SOCK_DGRAM, 0);

    if(ChatMasterSocket == 0){
        perror("Couldn't create the ChatMasterSocket");
        exit(0);
    }

    ChatMasterAddr.sin_addr.s_addr = "127.0.0.1";
    ChatMasterAddr.sin_family = AF_INET;
    ChatMasterAddr.sin_port = htons(8080);

    if(bind(ChatMasterSocket, (struct socketaddr *) &ChatMasterAddr, ChatMasterAddr_Size)){
        perror("Couldn't bind the socket to it's default parameters");
        exit(0);
    }
    
    while(1){
        int NumBytes_Received = recvfrom(ChatMasterSocket,)
    }
}