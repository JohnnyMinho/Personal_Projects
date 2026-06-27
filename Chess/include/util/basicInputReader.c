#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t size_read(char* readBuffer);

//This function uses fgets and just quickly trims the newline character since the size we will always return is small
void quickReadInputStdin(size_t maxSizeForReturn, char* originalBuffer) {
    char readingBuffer[257];
    readingBuffer[256] = '\0';
    while(fgets(readingBuffer, 256, stdin) != NULL) {
        size_t bufferSize = size_read(readingBuffer);
        memmove(originalBuffer, readingBuffer, maxSizeForReturn);
        if(maxSizeForReturn < (bufferSize-1) ){
            originalBuffer[maxSizeForReturn] = '\0';
        }else if(maxSizeForReturn > 256){
            originalBuffer[256] = '\0';
        }
        //We know that the last character is a newline so the actual size we want is bufferSize - 1;
        break;
    }
}

size_t size_read(char* readBuffer){
    size_t size = 0;
    while(readBuffer[size] != '\0'){
        size++;
    }
    return size;
}