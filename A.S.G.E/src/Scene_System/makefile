sources = Scene.cpp SceneSystem.cpp
objects = Scene.o SceneSystem.o
objdir = ./obj/

scene.o: $(objects)
	ld -r -o $@ $(addprefix $(objdir),$(objects))

$(objects): %.o: %.cpp
	mkdir -p $(objdir)
	g++ -c -o $(objdir)$@ $<

clean:
	rm -r -f $(objdir)
	rm -f *.o
