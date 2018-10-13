#include "IMonitorDisplay.hpp"

int MonitorNcurses::current_pos_x = 1;

MonitorNcurses::MonitorNcurses( int height, int width, int pos_x, int pos_y ) : _height(height), \
_width(width), _pos_x(pos_x), _pos_y(pos_y) {
	this->_win = newwin(this->_height, this->_width, MonitorNcurses::current_pos_x, this->_pos_y);
	MonitorNcurses::current_pos_x += this->_height;
	box(this->_win, 0, 0);
}

MonitorNcurses::~MonitorNcurses( void ) {

}

void MonitorNcurses::display( std::string title, std::vector<Item*>* test ) {
	if (test) {
		std::vector<Item*>::iterator it = test->begin();
		std::vector<Item*>::iterator it_end = test->end();
		wattron(this->_win, COLOR_PAIR(6) | A_BOLD | A_UNDERLINE);
		mvwprintw(this->_win, 1, this->_width / 2 - title.length() / 2, title.c_str());
		wattroff(this->_win, COLOR_PAIR(6) | A_BOLD | A_UNDERLINE);
		for (int i = 0; it != it_end; i++, it++) {
			// wattron(this->_win, COLOR_PAIR(i) | A_BOLD);
			wattron(this->_win, COLOR_PAIR(i));
			mvwprintw(this->_win, i + 2, 10, (*it)->getFormat().c_str());
			wattroff(this->_win, COLOR_PAIR(i));
		}
		wrefresh(this->_win);
	}
}
