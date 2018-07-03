VPATH = A.S.G.E/src
LINK_TARGET = test.out

all: $(LINK_TARGET)

test.out:	GameLoop.cpp Timer.cpp Input_System/InputSystem.cpp Ascii_Render_System/AsciiRenderer.cpp Window_System/WindowSystem.cpp Window_System/AscWindow.cpp Core/GameObject.cpp Scene_System/Scene.cpp Scene_System/SceneSystem.cpp Ship.cpp asciiShipsTest_main.cpp
	g++ -o $@ $^ -std=c++11 -lncurses
