objects = Point2D.o
objdir = ./obj/

math.o: $(objects)
	ld -r -o math.o $(addprefix $(objdir),$(objects))

Point2D.o: Point2D.cpp
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ Point2D.cpp

clean:
	rm -r -f $(objdir)
	rm -f *.o
