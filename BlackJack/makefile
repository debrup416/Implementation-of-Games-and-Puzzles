output: main.o blackjack.o
	g++ main.o blackjack.o -o output

main.o: main.cpp
	g++ -c main.cpp -o main.o

blackjack.o: blackjack.cpp
	g++ -c blackjack.cpp -o blackjack.o

clean:
	-rm -r *.o