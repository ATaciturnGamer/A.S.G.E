objects = GameObject.o Sprite2D.o Polygon2D.o
objdir = ./obj/

entity.o: $(objects)
	ld -r -o entity.o $(addprefix $(objdir),$(objects))

GameObject.o:
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ GameObject.cpp

Sprite2D.o:
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ Sprite/Sprite2D.cpp

Polygon2D.o:
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ Shape2D/Polygon2D.cpp

clean:
	rm -r -f $(objdir)
	rm -f *.o
