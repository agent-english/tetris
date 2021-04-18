all:
	g++ main.cpp -lncurses

main:
	g++ field.cpp game.cpp init.cpp shapes.cpp -lncurses
clean:
	rm *.out
