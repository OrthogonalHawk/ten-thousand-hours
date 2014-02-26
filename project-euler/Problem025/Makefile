# Copied from: http://stackoverflow.com/questions/1484817/how-do-i-make-a-simple-makefile-gcc-unix

TARGET  := exercise_solution 
CC      := g++
CFLAGS  := -g -Wall

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))
HEADERS := $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: %(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

clean:
	-rm -f *.o
	-rm -f $(TARGET)
