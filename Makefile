all: project

project: main.o tile.o
	g++ -o $@ $^ -g -std=c++11 -Wall -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cc
	g++ -c $^ -g -std=c++11 -Wall

clean:
	rm -f *.o project

re: clean project

.PHONY: all clean re
