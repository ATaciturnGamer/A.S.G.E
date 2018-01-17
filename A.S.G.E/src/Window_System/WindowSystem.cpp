#include "WindowSystem.hpp"

namespace ASGE {

    WindowSystem::WindowSystem(){}

    void WindowSystem::_startUp()
    {
    	initscr();
    	noecho();
    	cbreak();
        refresh();
        render_window = createWindow(100,25,0,0);
        log_window = createWindow(100,5,0,26);
        start_color();
        init_color(COLOR_RED, 700, 0, 0);
    	init_pair(1, COLOR_RED, COLOR_BLACK);
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

    AscWindow* WindowSystem::getRenderWindow()
    {
        return render_window;
    }

    AscWindow* WindowSystem::getLogWindow()
    {
        return log_window;
    }


    AscWindow* WindowSystem::createWindow(int width, int height, int startx, int starty)
    {
        AscWindow *new_window;
        new_window = new AscWindow(width,height,startx,starty);
        box(new_window->getNcursesWin(),0,0);//Draws border
    	keypad(new_window->getNcursesWin(),TRUE);
    	nodelay(new_window->getNcursesWin(),TRUE);
        wrefresh(new_window->getNcursesWin());
        return new_window;
    }

    void WindowSystem::refreshWindows()
    {
        refresh();
        // wresize(render_window->getNcursesWin(),15,100);
        wborder(render_window->getNcursesWin(), '|', '|', '-', '_', '+', '+', '+', '+');
        wrefresh(render_window->getNcursesWin());
        wborder(log_window->getNcursesWin(), '|', '|', '-', '_', '+', '+', '+', '+');
        wrefresh(log_window->getNcursesWin());
    }

    void WindowSystem::destroyWindow(AscWindow* del_window)
    {
        wborder(del_window->getNcursesWin(), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
        wrefresh(del_window->getNcursesWin());
        delete del_window;
        // delwin(del_window->getNcursesWin());
        del_window = NULL;
    }

    void WindowSystem::termResized() {
        log_window->rebuild();
        render_window->rebuild();
        // render_window = createWindow(100,15,0,0);
        // log_window = createWindow(100,10,0,16);
        // wresize(render_window->getNcursesWin(),render_window->getSize()[1],render_window->getSize()[0]);
        // wresize(log_window->getNcursesWin(),log_window->getSize()[1],log_window->getSize()[0]);
    }
}
