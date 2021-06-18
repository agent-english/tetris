all:
	g++ ./Source/main.cpp ./Source/field.cpp ./Source/game.cpp ./Source/init.cpp ./Source/shapes.cpp ./Source/shapesConstructors.cpp ./Source/shapesPrint.cpp ./Source/shapesRotate.cpp -lncurses

gdb:
	g++ -g main.cpp field.cpp game.cpp init.cpp shapes.cpp shapesConstructors.cpp shapesPrint.cpp shapesMove.cpp -lncurses -o debug.gdb
main:
	g++ field.cpp game.cpp init.cpp shapes.cpp -lncurses
clean:
	rm *.out
