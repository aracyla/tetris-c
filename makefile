COMPILER = gcc
FLAGS = -Wall -lpthread

SOURCES=$(wildcard *.c) 
HEADERS=$(wildcard *.h)

all: tetris
   
tetris: $(SOURCES:.c=.o)
	$(COMPILER) -o $@ $^ $(FLAGS)

%.o: %.c $(HEADERS)
	$(COMPILER) -c $< -o $@ $(FLAGS)

clean:
	rm -f *.o tetris 
