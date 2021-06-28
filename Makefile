all:
	g++ ./Source/main.cpp ./Source/field.cpp ./Source/game.cpp ./Source/shapes.cpp ./Source/shapesConstructors.cpp ./Source/shapesPrint.cpp ./Source/shapesRotate.cpp -lncurses

gdb:
	g++ -g ./Source/main.cpp ./Source/field.cpp ./Source/game.cpp ./Source/shapes.cpp ./Source/shapesConstructors.cpp ./Source/shapesPrint.cpp ./Source/shapesRotate.cpp -lncurses -o debug.gdb
main:
	g++ field.cpp game.cpp init.cpp shapes.cpp -lncurses
clean:
	rm *.out
