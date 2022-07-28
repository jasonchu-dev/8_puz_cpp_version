CC = g++
CFLAGS = -Wall -g

main: main.cpp Node.cpp UCS.cpp check.cpp
    $(CC) $(CFLAGS) -o a main.cpp Node.cpp UCS.cpp check.cpp