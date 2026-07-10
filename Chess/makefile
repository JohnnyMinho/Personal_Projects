CC=gcc
CFLAGS=-Iinclude -Iinclude/menu -Iinclude/util -Iinclude/gamelogic -IKey-pairs -Wall -Wextra -g
DEPFLAGS=-MMD -MP

# Basic_Chess target
BASIC_SRCS=Basic_chess.c Key-pairs/Chess_Pieces.c include/menu/basicChessMenu.c include/util/basicInputReader.c include/gamelogic/gamelogic.c
BASIC_OBJS=$(BASIC_SRCS:.c=.o)

# ChessGame target
GAME_SRCS=ChessGame.c Key-pairs/Chess_Pieces.c
GAME_OBJS=$(GAME_SRCS:.c=.o)

TARGETS=BasicChess ChessGame

.PHONY: all clean

all: $(TARGETS)

BasicChess: $(BASIC_OBJS)
	$(CC) $(CFLAGS) -o $@ $(BASIC_OBJS) -pthread

ChessGame: $(GAME_OBJS)
	$(CC) $(CFLAGS) -o $@ $(GAME_OBJS) -pthread

# Include generated dependency files (if present)
-include $(BASIC_OBJS:.o=.d) $(GAME_OBJS:.o=.d)


%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(BASIC_OBJS) $(GAME_OBJS) $(TARGETS)
