SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = play
INCLUDE_PATHS = -I include -I header
LIBRARY_PATHS = -L lib
COMPILER_FLAGS = -std=c++17 -Wall -O0 -g
LINKER_FLAGS = -lsdl2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all:
		$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)