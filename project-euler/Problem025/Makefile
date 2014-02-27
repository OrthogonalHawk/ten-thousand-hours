
TARGET      := solution 
TEST_TARGET := test
GTEST_MAIN  := -lgtest
 
CC      := g++
CFLAGS  := -c -Wall -g
LDFLAGS := -lgtest -lpthread

.PHONY: all solution tests

all: solution test

COMMON_SOURCES := LargeNumber.cpp
TARGET_SOURCES := Problem025.cpp
TEST_SOURCES   := LargeNumberTest.cpp

COMMON_OBJECTS := $(COMMON_SOURCES:.cpp=.o)
TARGET_OBJECTS := $(TARGET_SOURCES:.cpp=.o)
TEST_OBJECTS   := $(TEST_SOURCES:.cpp=.o)

HEADERS := $(wildcard *.h)

$(TARGET): $(COMMON_OBJECTS) $(TARGET_OBJECTS)
	$(CC) -o $@ $(COMMON_OBJECTS) $(TARGET_OBJECTS)

$(TEST_TARGET): $(COMMON_OBJECTS) $(TEST_OBJECTS)
	$(CC) -o $@ $(COMMON_OBJECTS) $(TEST_OBJECTS) $(LDFLAGS) 

.cpp.o: $(HEADERS)
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET) $(TEST_TARGET) 

