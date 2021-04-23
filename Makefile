all: build

build: 
	g++ -o game *.cpp -I. -g -lm -lncurses

clean: 
	rm -f *.out game