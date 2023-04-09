comp=g++
flags= -Wall -Werror -Wextra
folder= /mnt/c/Users/yakupchik/CLionProjects/Programming_Labs_02semestr/lab02/

all: main

main: main.cpp kramer memory matrix gauss operations
	$(comp) $(flags) $(folder)main.cpp $(folder)kramer.out $(folder)gauss.out $(folder)matrix.out $(folder)operations.out -o $(folder)output

memory: memory.cpp
	$(comp) -c $(folder)memory.cpp -o $(folder)memory.out

kramer: kramer.cpp
	$(comp) -c $(folder)kramer.cpp  -o $(folder)kramer.out

matrix: matrix.cpp
	$(comp) -c $(folder)matrix.cpp -o $(folder)matrix.out

gauss: gauss.cpp
	$(comp) -c $(folder)gauss.cpp -o $(folder)gauss.out

operations: operations.cpp
	$(comp) -c $(folder)operations.cpp -o $(folder)operations.out

clean:
	rm -rf $(folder)*.out

rebuild: clean