all:
	g++ main.cpp field.cpp game.cpp init.cpp shapes.cpp shapesConstructors.cpp shapesPrint.cpp shapesMove.cpp -lncurses

gdb:
	g++ -g main.cpp field.cpp game.cpp init.cpp shapes.cpp shapesConstructors.cpp shapesPrint.cpp shapesMove.cpp -lncurses -o debug.gdb
main:
	g++ field.cpp game.cpp init.cpp shapes.cpp -lncurses
clean:
	rm *.out
