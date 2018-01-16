#include "WindowSystem.hpp"

namespace ASGE {

    WindowSystem::WindowSystem(){}

    void WindowSystem::_startUp()
    {
    	initscr();
        clear();
    	noecho();
    	cbreak();
        refresh();
        render_window = createWindow(100,15,0,0);
        log_window = createWindow(100,10,0,16);
    }

    void WindowSystem::_shutDown()
    {
        destroyWindow(log_window);
        destroyWindow(render_window);
    }

    WindowSystem& WindowSystem::getInstance()
    {
    	static WindowSystem *instance = new WindowSystem();
    	return *instance;
    }

    WINDOW* WindowSystem::getRenderWindow()
    {
        return render_window;
    }

    WINDOW* WindowSystem::getLogWindow()
    {
        return log_window;
    }


    WINDOW* WindowSystem::createWindow(int width, int height, int startx, int starty)
    {
        WINDOW *new_window;
        // new_window = new AscWindow(height,width,starty,startx);
        new_window = newwin(height,width,starty,startx);
        box(new_window,0,0);//Draws border
    	keypad(new_window,TRUE);
    	nodelay(new_window,TRUE);
        wrefresh(new_window);
        return new_window;
    }

    void WindowSystem::refreshWindows()
    {
        refresh();
        wresize(render_window,15,100);
        wborder(render_window, '|', '|', '-', '_', '+', '+', '+', '+');
        wrefresh(render_window);
        wborder(log_window, '|', '|', '-', '_', '+', '+', '+', '+');
        wrefresh(log_window);
    }

    void WindowSystem::destroyWindow(WINDOW* del_window)
    {
        wborder(del_window, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        wrefresh(del_window);
        delwin(del_window);
    }

    void WindowSystem::termResized() {
        wresize(render_window,15,100);
        wresize(log_window,10,100);
    }
}
