objects = ascRen.o
objdir = ./obj/

render.o: $(objects)
	ld -r -o $@ $(addprefix $(objdir),$(objects))

ascRen.o: AsciiRenderer.cpp
	mkdir -p $(objdir)
	g++ -c -o $(objdir)ascRen.o AsciiRenderer.cpp

clean:
	rm -r -f $(objdir)
	rm -f *.o
