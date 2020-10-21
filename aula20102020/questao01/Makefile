#Makefile for "imd0030" C++ application
#Created by Silvio Sampaio 10/08/2016

BIN = ./bin
SRC = ./src
INC = ./include

PROG = $(BIN)/programa
CC = g++
CPPFLAGS = -Wall -std=c++11 -I./include

OBJS = $(BIN)/date.o $(BIN)/funcionario.o $(BIN)/empresa.o $(BIN)/questao01.o $(BIN)/main.o

all : $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

debug: CPPFLAGS += -DDEBUG -g -O0
debug: clean all

$(BIN)/main.o : $(SRC)/main.cpp
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@
$(BIN)/questao01.o :  $(SRC)/questao01.cpp $(INC)/questao01.hpp
	$(CC) $(CPPFLAGS) -c $(SRC)/questao01.cpp -o $@
$(BIN)/empresa.o : $(SRC)/empresa.cpp $(INC)/empresa.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/empresa.cpp -o $@
$(BIN)/funcionario.o : $(SRC)/funcionario.cpp $(INC)/funcionario.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/funcionario.cpp -o $@
$(BIN)/date.o : $(SRC)/date.cpp $(INC)/date.hpp 
	$(CC) $(CPPFLAGS) -c $(SRC)/date.cpp -o $@
clean:
	rm -f core $(PROG) $(OBJS)
