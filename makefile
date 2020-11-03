CC=g++
STD=c++11
CFLAGS=-Wall -Wextra -std=$(STD)

TARGET_NAME=./tp3
BUILD_PATH=./build
SOURCE_PATH=./src
LIB_PATH=./include
OUTPUT_PATH=./output

SOURCE_EXT := cpp
SOURCES := $(shell find $(SOURCE_PATH) -path '*.$(SOURCE_EXT)')
OBJECTS := $(patsubst $(SOURCE_PATH)/%,$(BUILD_PATH)/%,$(SOURCES:.$(SOURCE_EXT)=.o))

all: $(TARGET_NAME)

$(BUILD_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(LIB_PATH)/%.hpp
	mkdir -p $(BUILD_PATH)
	$(CC) -c $(CFLAGS) -o $@ $<

$(TARGET_NAME): $(OBJECTS) ./main.cpp
	$(CC) $(CFLAGS) -o $(TARGET_NAME) ./main.cpp $(OBJECTS)

clean:
	rm -rf $(BUILD_PATH)/*
	rm $(TARGET_NAME)

run:
	$(TARGET_NAME) ./input/in01.txt

mem:
	valgrind --leak-check=full --show-leak-kinds=all $(TARGET_NAME) ./input.txt > ./output/mem.log