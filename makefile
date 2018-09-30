VPATH = A.S.G.E/
LINK_TARGET = test.out

all: $(LINK_TARGET)

test.out:	asciiShipsTest_main.cpp Ship.cpp asge.a
	g++ -o $@ $^ -std=c++11 -lncurses

run:
	./test.out
