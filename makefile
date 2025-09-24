CC=gcc
CFLAGS=-Wall -Iinclude -O2
SRC_DIR=src
BUILD_DIR=build
TARGETS=$(BUILD_DIR)/tictactoe
SRCS=main.c $(SRC_DIR)/game.c $(SRC_DIR)/ui.c
OBJS=$(BUILD_DIR)/main.o $(BUILD_DIR)/game.o $(BUILD_DIR)/ui.o

all:$(TARGETS)
	@echo "all done"

$(TARGETS):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.o:$(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o:%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)/*
	rm -f *.o

.PHONY:clean all