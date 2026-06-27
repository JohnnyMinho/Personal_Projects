CC=gcc
CFLAGS=-Iinclude -Iinclude/menu -Iinclude/util -IKey-pairs -Wall -Wextra -g
DEPFLAGS=-MMD -MP

SRCS=Basic_chess.c Key-pairs/Chess_Pieces.c include/menu/basicChessMenu.c include/util/basicInputReader.c
OBJS=$(SRCS:.c=.o)
TARGET=BasicChess

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Include generated dependency files (if present)
-include $(OBJS:.o=.d)


%.o: %.c
	$(CC) $(CFLAGS) $(DEPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
