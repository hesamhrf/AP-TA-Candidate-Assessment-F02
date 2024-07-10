CC = g++
FLAGS = -std=c++11
COMPILE_FLAGS = $(FLAGS) -c 

all:main

main:main.o
	$(CC) main.o  Node.o Program.o  Input.o  Operand.o Operator.o Tree.o Exception.o   $(FLAGS) -o main

main.o:main.cpp Program.o define.hpp
	$(CC) $(COMPILE_FLAGS)  main.cpp

Program.o:Program.cpp Input.o Tree.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Program.cpp 

Input.o:Input.cpp  Tree.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Input.cpp

Tree.o:Tree.cpp Node.o Operand.o Operator.o Exception.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Tree.cpp

Node.o:Node.cpp Exception.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Node.cpp

Operand.o:Operand.cpp Node.o Exception.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Operand.cpp

Operator.o:Operator.cpp Node.o Exception.o define.hpp
	$(CC) $(COMPILE_FLAGS)  Operator.cpp

Exception.o:Exception.cpp define.hpp
	$(CC) $(COMPILE_FLAGS)  Exception.cpp

clean:
	rm *.o main