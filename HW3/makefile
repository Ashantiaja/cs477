# Makefile : CS477 : HW3
# @Ash Cudiamat

CC = g++
FLAGS = -std=c++11

SRCS = modifiedBubbleSort.cpp modifiedMergeSort.cpp #$(wildcard *.cpp)
#OBJS = $( patsubst %.cpp, %.o, $(SRCS) )

# Compile each algorithm separately
all:
	$(CC) -c $(SRCS) $(FLAGS)
	$(CC) -o bubble modifiedBubbleSort.o $(FLAGS)
	$(CC) -o merge modifiedMergeSort.o $(FLAGS)

clean:
	-rm -f *~
	-rm -f *.o
	-rm bubble merge
