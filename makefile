LINK_TARGET = test.out

all: $(LINK_TARGET)

test.out:	DynamicWaterTest_main.cpp tests/Dynamic_Water/Water2D.cpp A.S.G.E/asge.a
	g++ -o $@ $^ -std=c++11 -lncurses

A.S.G.E/asge.a:
	make -C A.S.G.E

clean:
	rm -f ./test.out
	make clean -C A.S.G.E

run:
	./test.out
