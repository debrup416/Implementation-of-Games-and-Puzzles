output: main.o sudoku.o
	g++ main.o sudoku.o -o output

main.o: main.cpp
	g++ -c main.cpp -o main.o

sudoku.o: sudoku.cpp
	g++ -c sudoku.cpp -o sudoku.o

clean:
	-rm -r *.o