objects = Entity/entity.o Math/math.o

core.o: $(objects)
	ld -r -o core.o $^

Entity/entity.o:
	make -C Entity/

Math/math.o:
	make -C Math/

clean:
	make clean -C Entity/
	make clean -C Math/
	rm -f *.o
