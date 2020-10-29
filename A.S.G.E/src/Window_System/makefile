sources = AscWindow.cpp WindowSystem.cpp
objects = AscWindow.o WindowSystem.o
objdir = ./obj/

window.o: $(objects)
	ld -r -o $@ $(addprefix $(objdir),$(objects))

$(objects): %.o: %.cpp
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ $<

clean:
	rm -r -f $(objdir)
	rm -f *.o
