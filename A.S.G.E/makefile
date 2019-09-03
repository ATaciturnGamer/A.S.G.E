sources = Scene.cpp SceneSystem.cpp
srcdir = ./src/
objects = 	Ascii_Render_System/render.o \
			Core/core.o\
			Input_System/input.o\
			Scene_System/scene.o\
			Window_System/window.o\
			gameLoop.o\
			Timer.o
objdir = ./obj/

asge.a: $(objdir)asge.o
	ar -rv $@ $<

$(addprefix $(objdir),asge.o): $(addprefix $(srcdir), $(objects))
	mkdir -p $(objdir)
	ld -r  -o $@ $^

$(addprefix $(srcdir),Ascii_Render_System/render.o):
	make -C $(srcdir)Ascii_Render_System/


$(addprefix $(srcdir),Core/core.o):
	make -C $(srcdir)Core/

$(addprefix $(srcdir),Input_System/input.o):
	make -C $(srcdir)Input_System/

$(addprefix $(srcdir),Scene_System/scene.o):
	make -C $(srcdir)Scene_System/

$(addprefix $(srcdir),Window_System/window.o):
	make -C $(srcdir)Window_System/

$(addprefix $(srcdir),gameLoop.o): $(addprefix $(srcdir),GameLoop.cpp)
	g++ -c -o $(srcdir)gameLoop.o $< -std=c++11

$(addprefix $(srcdir),Timer.o): $(addprefix $(srcdir),Timer.cpp)
	g++ -c -o $(srcdir)Timer.o $< -std=c++11

clean:
	rm asge.a
	rm -r -f $(objdir)
	rm -f $(srcdir)*.o
	make clean -C $(srcdir)Ascii_Render_System/
	make clean -C $(srcdir)Core/
	make clean -C $(srcdir)Input_System/
	make clean -C $(srcdir)Scene_System/
	make clean -C $(srcdir)Window_System/
