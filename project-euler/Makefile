
TARGET  := project_euler 
 
CC      := g++
CFLAGS  := -c -Wall -std=c++11

INCLUDE_DIR := include/

OBJ_DIR := obj/
SRC_DIR := src/

.PHONY: all solution

all: $(TARGET) 

TARGET_SOURCES := $(SRC_DIR)ProjectEulerMain.cpp \
                  $(SRC_DIR)CommonUtilities.cpp \
                  $(SRC_DIR)Problem001.cpp \
                  $(SRC_DIR)Problem002.cpp \
                  $(SRC_DIR)Problem004.cpp \
                  $(SRC_DIR)Problem009.cpp \
                  $(SRC_DIR)Problem011.cpp \
                  $(SRC_DIR)Problem012.cpp \
                  $(SRC_DIR)Problem014.cpp \

TARGET_OBJECTS := $(addprefix $(OBJ_DIR),$(notdir $(TARGET_SOURCES:.cpp=.o)))

HEADERS := $(wildcard *.h)

$(TARGET): $(TARGET_OBJECTS)
	$(CC) -o $@ $(TARGET_OBJECTS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CC) -I $(INCLUDE_DIR) $(CFLAGS) $< -o $@

test:
	echo $(TARGET_OBJECTS)

clean:
	-rm -f $(OBJ_DIR)*.o
	-rm -f $(TARGET)

