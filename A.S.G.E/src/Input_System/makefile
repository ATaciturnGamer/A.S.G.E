objects = inputSystem.o
objdir = ./obj/

input.o: $(objects)
	ld -r -o $@ $(addprefix $(objdir),$(objects))

inputSystem.o: InputSystem.cpp
	mkdir -p $(objdir)
	g++ -c -o $(objdir)inputSystem.o InputSystem.cpp

clean:
	rm -r -f $(objdir)
	rm -f *.o
