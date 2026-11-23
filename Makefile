SRC = $(shell find . -not -path './$(BUILD_DIR)/*' -name "*.cpp")
BUILD_DIR = build
OBJS = $(patsubst ./%.cpp,$(BUILD_DIR)/%.o,$(SRC))
OBJ_NAME = $(BUILD_DIR)/main

CC = g++
COMPILER_FLAGS = -w -g -O0
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: $(OBJ_NAME)

$(OBJ_NAME): $(OBJS)
	mkdir -p $(dir $@)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@

$(BUILD_DIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(COMPILER_FLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)