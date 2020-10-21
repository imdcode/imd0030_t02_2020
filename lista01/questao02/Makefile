#Makefile for "imd0030" C++ application
#Created by Silvio Sampaio 10/08/2016


PROG = programa
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = dado.o jogador.o jogo.o main.o

all : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp -o $@
jogo.o : jogo.cpp jogo.hpp 
	$(CC) $(CPPFLAGS) -c jogo.cpp -o $@
jogador.o : jogador.cpp jogador.hpp 
	$(CC) $(CPPFLAGS) -c jogador.cpp -o $@
dado.o : dado.cpp dado.hpp 
	$(CC) $(CPPFLAGS) -c dado.cpp -o $@
clean:
	rm -f core $(PROG) $(OBJS)
