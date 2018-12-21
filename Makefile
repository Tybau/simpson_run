LIBS = -L ./SFML-2.5.1/lib
INCLUDES = -I ./SFML-2.5.1/include

FLAGS = -std=c++11 -Wall
CPP_FLAGS = ${FLAGS} ${INCLUDES}
LD_FLAGS = ${FLAGS} ${LIBS} -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: project

project: main.o game.o position.o tile.o personnage.o wall.o donut.o spicy.o
	g++ -o $@ $^ -g ${LD_FLAGS}

%.o: %.cc
	g++ -c $^ -g ${CPP_FLAGS}

clean:
	rm -f *.o project

re: clean project

.PHONY: all clean re
