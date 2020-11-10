#Makefile for "imd0030" C++ application
#Created by Silvio Sampaio 08/11/2020


PROG = programa
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = movimentacao.o contacorrente.o agencia.o main.o

all : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp -o $@
agencia.o : agencia.cpp agencia.hpp 
	$(CC) $(CPPFLAGS) -c agencia.cpp -o $@
contacorrente.o : contacorrente.cpp contacorrente.hpp 
	$(CC) $(CPPFLAGS) -c contacorrente.cpp -o $@
movimentacao.o : movimentacao.cpp movimentacao.hpp 
	$(CC) $(CPPFLAGS) -c movimentacao.cpp -o $@
clean:
	rm -f core $(PROG) $(OBJS)
