CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=gnu99 -O2
LDFLAGS = -lm

SRC_DIR = src_c
OBJ_DIR = obj

# List of source files
SRCS = $(SRC_DIR)/core/main.c \
       $(SRC_DIR)/io/graph.c \
       $(SRC_DIR)/utils/math_utils.c \
       $(SRC_DIR)/algorithms/fr.c \
       $(SRC_DIR)/algorithms/tutte.c

# List of object files (mirroring the source structure in the obj directory)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Binary name
TARGET = graphviz

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
