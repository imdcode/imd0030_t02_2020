#Makefile for "imd0030" C++ application
#Created by Silvio Sampaio 08/11/2020

BIN = ./bin
SRC = ./src
INC = ./include

PROG = $(BIN)/programa
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = $(BIN)/movimentacao.o $(BIN)/conta.o $(BIN)/contacorrente.o $(BIN)/contapoupanca.o $(BIN)/agencia.o $(BIN)/main.o

all : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

$(BIN)/main.o : $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@
$(BIN)/agencia.o : $(SRC)/agencia.cpp $(INC)/agencia.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/agencia.cpp -o $@
$(BIN)/conta.o : $(SRC)/conta.cpp $(INC)/conta.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/conta.cpp -o $@
$(BIN)/contacorrente.o : $(SRC)/contacorrente.cpp $(INC)/contacorrente.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/contacorrente.cpp -o $@
$(BIN)/contapoupanca.o : $(SRC)/contapoupanca.cpp $(INC)/contapoupanca.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/contapoupanca.cpp -o $@
$(BIN)/movimentacao.o : $(SRC)/movimentacao.cpp $(INC)/movimentacao.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/movimentacao.cpp -o $@
clean:
	rm -f core $(PROG) $(OBJS)
