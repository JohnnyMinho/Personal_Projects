#ifdef CHAT_ASSISTOR_FILE_H
#define CHAT_ASSISTOR_FILE_H

struct ChatMessage{
    char Message_Content[256];
    struct ChatUser Sender;
};

struct ChatUser{
    char* NickName;
    int ID;
    int status; //1-> Away; 2-> Online;
};

struct ChatRoomDefs{
    int max_users;
};

#endif 
