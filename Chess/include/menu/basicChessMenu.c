#include <stdio.h>
#include <stdlib.h>
#include "basicInputReader.h"


//Aux functins

void clear_console(){
    #ifdef _WIN32
        clrscr();
    #else
        system("clear");
    #endif
}

int validate_user_input(char input){
    int asciiValue = (int)input;
    if(asciiValue >= 49 && asciiValue <= 52){
        return 1;
    }
    return 0;
}

//We load the menu and return the user input. If there is none we exit
char loadmenu(){
    char *user_input = malloc(sizeof(char) * 2);
    while(1){
        clear_console();
        printf("CHESS - S&M\n");
        printf("1. Start New Game\n");
        printf("2. Load Game\n"); //We can store it as an .txt with information
        printf("3. Test Game\n"); //Prints out all the components for the game.
        printf("4. Exit\n");
        quickReadInputStdin(1, user_input);
        printf("You selected: %c\n", user_input[0]);
        int user_choice = validate_user_input(user_input[0]);
        if(user_choice == 1){
            return user_input[0];
        }else{
            printf("Invalid input, please try again!\n");
            quickReadInputStdin(1, user_input); //We wait for the user to aknowledge the error and then we clear the console and re-render the menu
        }
    }
    printf("There was no user input, goodbye!\n");
    return '4';
}

