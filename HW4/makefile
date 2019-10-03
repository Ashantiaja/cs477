# makefile
# cs477 : hw4
# @Ash Y Cudiamat

CC = g++
FLAGS = -std=c++11
TARGET = test

SRCS = $(wildcard *.cpp)
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

.PHONY: all clean

all: $(TARGET)

%.o: %.cpp
	$(CC) $(FLAGS) -c  $< -o $@

$(TARGET): $(OBJS)
	@echo "Sources: " $(SRCS)
	@echo "Objects: " $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)
	@echo "End result: " $(TARGET)

clean:
	-rm *~
	-rm $(TARGET)
	-rm *.o
