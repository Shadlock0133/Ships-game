sfml_libs = -lsfml-graphics -lsfml-window -lsfml-system
all: main
main: main.o
	g++ -o main main.o $(sfml_libs)
main.o:
	g++ -O3 -c -o main.o main.cpp
clear:
	rm -f *.o main