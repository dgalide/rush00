#include "main.hpp"
#include "Info.hpp"
#include "OSModule.hpp"
#include <ncurses.h>
#include <unistd.h>
#include "IMonitorModule.hpp"

#define REFRESH 1000000 / 60
#define KEY_ESC				27
#define KEY_SPACE 			32
#define WIN_SIZE_X			200ull
#define	WIN_SIZE_Y			50ull
#define INITIAL_POS_X 		2
#define INITIAL_POS_Y 		WIN_SIZE_Y / 2

#define MAIN_WIN_WIDTH 170
#define MAIN_WIN_HEIGHT 0
#define MAIN_WIN_X 0
#define MAIN_WIN_Y 0

#define DEFAULT_WIDTH_MonitorModule MAIN_WIN_WIDTH - 2
#define DEFAULT_HEIGHT_MonitorModule 8


int main(void)
{
	OSModule os;

	std::vector<Item*>::iterator e = os.items->end();

	for (std::vector<Item*>::iterator b = os.items->begin(); b != e; b++) {
		std::cout << (*b)->getFormat() << std::endl;
	}

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	MonitorModule main(MAIN_WIN_HEIGHT, MAIN_WIN_WIDTH, MAIN_WIN_X, MAIN_WIN_Y);

	MonitorModule first(DEFAULT_HEIGHT_MonitorModule, DEFAULT_WIDTH_MonitorModule, MAIN_WIN_X + 1, MAIN_WIN_Y + 1);
	MonitorModule second(DEFAULT_HEIGHT_MonitorModule, DEFAULT_WIDTH_MonitorModule, MAIN_WIN_X + 1 + DEFAULT_HEIGHT_MonitorModule, MAIN_WIN_Y + 1);

	nodelay(stdscr, TRUE);

	while (1) {
		usleep(REFRESH);
		main.display();
		first.display();
		second.display();
	}
	endwin();
	return 0;
}
