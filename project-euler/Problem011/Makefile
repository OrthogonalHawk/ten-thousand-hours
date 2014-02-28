
TARGET      := solution 
 
CC      := g++
CFLAGS  := -c -Wall -g

.PHONY: all solution

all: solution

COMMON_SOURCES := 
TARGET_SOURCES := Problem011.cpp
TEST_SOURCES   := 

COMMON_OBJECTS := $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS := $(TARGET_SOURCES:.cpp=.o)
TEST_OBJECTS   := $(TEST_SOURCES:.cpp=.o)

HEADERS := $(wildcard *.h)

$(TARGET): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	$(CC) -o $@ $(COMMON_OBJECTS) $(TARGET_OBJECTS)

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)

