NAME		:= editor

SRC_DIR		:= source/editor
OBJ_DIR		:= obj/editor
BUILD_DIR	:= build

SRC		:= $(wildcard $(SRC_DIR)/*.c)
OBJ		:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

EXEC_SRC	:= source/main.c source/dlfcn.c
EXEC_OBJ	:= $(EXEC_SRC:source/%.c=obj/%.o)

CC		:= gcc
CFLAG		:= -ggdb -Wall -Wextra
LFLAG		:= -lraylib -lopengl32 -lgdi32 -lwinmm -lpthread

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | build_dir
	$(CC) $(CFLAG) -fPIC -c $< -o $@

obj/%.o: source/%.c | build_dir
	$(CC) $(CFLAG) -c $< -o $@

all: exec lib

exec: $(EXEC_OBJ)
	$(CC) $(EXEC_OBJ) -o $(BUILD_DIR)/$(NAME)

lib: build_dir $(OBJ)
	$(CC) -fPIC -shared $(OBJ) $(LFLAG) -o $(BUILD_DIR)/lib$(NAME).so

build_dir:
	mkdir -p $(BUILD_DIR)
	mkdir -p obj
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) obj $(BUILD_DIR)

.PHONY: all exec lib clean build_dir
