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
#include "DateModule.hpp"

#define REFRESH 1000000 / 60
#define KEY_ESC				27
#define KEY_SPACE 			32
#define WIN_SIZE_X			200ull
#define	WIN_SIZE_Y			50ull
#define INITIAL_POS_X 		2
#define INITIAL_POS_Y 		WIN_SIZE_Y / 2
#define SFML_WIDTH 1000
#define SFML_HEIGHT 650

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
	DateModule 	date("Date");

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

	MonitorNcurses first(os.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses second(um.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses third(rm.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses fourth(cpu.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses fifth(nt.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);
	MonitorNcurses sixth(date.items->size() + 3, DEFAULT_WIDTH_MODULE, 0, MAIN_WIN_Y + 1);

	nodelay(stdscr, TRUE);
	int key;
	while ((key = getch()) != KEY_ESC) {
		usleep(REFRESH);
		sixth.display(date.title, date.items);
		first.display(os.title, os.items);
		second.display(um.title, um.items);
		third.display(rm.title, rm.items);
		fourth.display(cpu.title, cpu.items);
		fifth.display(nt.title, nt.items);
		
		os.refresh();
		um.refresh();
		rm.refresh();
		cpu.refresh();
		nt.refresh();
		date.refresh();
	}
	endwin();
}

void graphical_display( void ) {
	sf::RenderWindow window(sf::VideoMode(SFML_WIDTH, SFML_HEIGHT), "ft_gkrellm");
	OSModule os("OS");
	UserModule um("User");
	RamModule rm("Ram");
	CpuModule cpu("CPU");
	NetworkModule nt("Network");
	DateModule 	date("Date");

	MonitorSfml first(window, (os.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);
	MonitorSfml second(window, (um.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);
	MonitorSfml third(window, (rm.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);
	MonitorSfml fourth(window, (cpu.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);
	MonitorSfml fifth(window, (nt.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);
	MonitorSfml sixth(window, (date.items->size() + 3) * FONT_SIZE_LINE, SFML_WIDTH, 0, MAIN_WIN_Y);

	while (window.isOpen())
    {
        sf::Event event;
	    while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        window.clear(sf::Color::Color(51, 204, 204));

		window.draw(first);
		window.draw(second);
		window.draw(third);
		window.draw(fourth);
		window.draw(fifth);
		window.draw(sixth);

		sixth.display(date.title, date.items);
		first.display(os.title, os.items);
		second.display(um.title, um.items);
		third.display(rm.title, rm.items);
		fourth.display(cpu.title, cpu.items);
		fifth.display(nt.title, nt.items);
		
		os.refresh();
		um.refresh();
		rm.refresh();
		cpu.refresh();
		nt.refresh();
		date.refresh();
        window.display();
    }
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: Need 'Graphics' or 'Terminal' in first parameter" << std::endl;
		exit(-1);
	} else {
		if (std::strcmp(argv[1], "Terminal") == 0){
			terminal_display();
		} else if (std::strcmp(argv[1], "Graphics") == 0) {
			graphical_display();
		} else {
			std::cout << "Usage: Need 'Graphics' or 'Terminal' in first parameter" << std::endl;
		}
	}
	return 0;
}
