#include "WindowSystem.hpp"

namespace ASGE {

    WindowSystem::WindowSystem(){}

    void WindowSystem::_startUp()
    {
    	initscr();
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
        // std::vector<int> s1(2),s2(2),p1(2),p2(2);
        // s1 = render_window->getSize();
        // s1 = log_window->getSize();
        // p1 = render_window->getPos();
        // p1 = log_window->getPos();
        // destroyWindow(log_window);
        // destroyWindow(render_window);
        // render_window = createWindow(s1[0],s1[1],p1[0],p1[1]);
        // log_window = createWindow(s2[0],s2[1],p2[0],p2[1]);
        wresize(render_window->getNcursesWin(),render_window->getSize()[1],render_window->getSize()[0]);
        wresize(log_window->getNcursesWin(),log_window->getSize()[1],log_window->getSize()[0]);
    }
}
