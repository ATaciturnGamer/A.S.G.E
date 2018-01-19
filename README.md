# A.S.G.E: AsciiShips Game Engine (W.I.P)

A simple Ascii-graphics game engine that runs games off the terminal

The initial idea was to create a Battleships game (AsciiShips) with Ascii Graphics.
Then it sort of took off from there.


### Current Progress:

<ul>
  <li>Game Loop</li>
  <li>Input System (Mouse works only on some terminals)</li>
  <li>AscWindow System (For implementing GUIs)</li>
</ul>

### TODO:

<ul>
  <li>Scene System</li>
  <li>Ascii Render System (With Z axis sorting)</li>
</ul>


To see a demo of current progress, compile using:<br />
<code>
g++ "A.S.G.E/src/GameLoop.cpp" "A.S.G.E/src/Timer.cpp" "A.S.G.E/src/Input_System/InputSystem.cpp" "A.S.G.E/src/Ascii_Render_System/AsciiRenderer.cpp" "A.S.G.E/src/Window_System/WindowSystem.cpp" "A.S.G.E/src/Window_System/AscWindow.cpp" -std=c++11 "MenuTest_main.cpp" -o "MenuTest_main" -lncurses -lncurses
</code><br />
It's messy, but a working prototype is what I require for now.
