#define chessBoardxSize 8
#define chessBoardySize 8
#define BlackChessNumber 16
#define WhiteChessNumber 16

struct chess_piece{ 
    char[4] Type; // P -> Pawn, B -> Bishop, H -> Horse, R -> Rook, Q -> Queen, K -> King, first numbers are whites, 2nd group is blacks
    int y_pos; //0-7
    int x_pos; //a-g is 0-7
};

struct board_pos{
    char[4] current_piece;
    int y_pos;
    int x_pos;
}

//Initial board is drawn with the entire pieces on the correct pos
char Draw_Initial_Board(){
    
}


//When a piece is moved the entire board isn't re-rendered, only the pos is redone
char re_render_pos_board_pos(){
    
}

void move_piece(){
    
}

void main(int argc, char* argv[]){

    printf("♞");
    return 0;
}