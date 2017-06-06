sfml_libs = -lsfml-graphics -lsfml-window -lsfml-system
build: main
main: main.o
	g++ -o main main.o $(sfml_libs)
main.o: main.cpp
	g++ -O3 -c -o main.o main.cpp
run: build
	./main
clear:
	rm -f *.o main