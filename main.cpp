#include "main.hpp"
#include "Info.hpp"
#include "OSModule.hpp"
#include <ncurses.h>
#include <unistd.h>
#include "IMonitorDisplay.hpp"
#include "UserModule.hpp"
#include "RamModule.hpp"
#include "CpuModule.hpp"
#include "NetworkModule.hpp"
#include <QApplication>
// #include <QWidget>

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

#define DEFAULT_WIDTH_MODULE MAIN_WIN_WIDTH - 2
#define DEFAULT_HEIGHT_MODULE 8



void terminal_display( void ) {
	OSModule os("OS");
	UserModule um("User");
	RamModule rm("Ram");
	CpuModule cpu("CPU");
	NetworkModule nt("Network");

	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);

	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);

	// MonitorNcurses main(MAIN_WIN_HEIGHT, MAIN_WIN_WIDTH, MAIN_WIN_X, MAIN_WIN_Y);

	MonitorNcurses first(os.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses second(um.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses third(rm.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses fourth(cpu.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses fifth(nt.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	// MonitorNcurses five(14, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	// MonitorNcurses six(8, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);

	nodelay(stdscr, TRUE);
	int key;
	while ((key = getch()) != KEY_ESC) {
		usleep(REFRESH);
		// main.display();
		first.display(os.title, os.items);
		second.display(um.title, um.items);
		third.display(rm.title, rm.items);
		third.display(rm.title, rm.items);
		fourth.display(cpu.title, cpu.items);
		fifth.display(nt.title, nt.items);
		os.refresh();
		um.refresh();
		rm.refresh();
		cpu.refresh();
		nt.refresh();
		// four.display();
		// five.display();
		// six.display();
	}
	endwin();
}

void graphical_display( void ) {

}

int main(int argc, char **argv)
{
	// QApplication app(argc, argv);
	//
	//
    // return app.exec();
	if (argc != 2) {
		std::cout << "Usage: Need 'Graphics' or 'Terminal' in first parameter" << std::endl;
		exit(-1);
	} else {
		if (std::strcmp(argv[1], "Terminal") == 0){
			//launch terminal display
			terminal_display();
		} else {
			graphical_display();
			//Launch graphical display
		}
	}
	return 0;
}
