#include "IMonitorModule.hpp"

MonitorModule::MonitorModule( int height, int width, int pos_x, int pos_y ) : _height(height), \
_width(width), _pos_x(pos_x), _pos_y(pos_y) {
	this->_win = newwin(this->_height, this->_width, this->_pos_x, this->_pos_y);
	this->_info = NULL;
	box(this->_win, 0, 0);
}

MonitorModule::~MonitorModule( void ) {

}

void MonitorModule::display( void ) {
	if (this->_info) {
		mvwprintw(this->_win, this->_pos_x, this->_pos_y, this->_info);
	}
	mvwprintw(this->_win, 1, 4, "dwadwadwadaw:");
	mvwprintw(this->_win, 2, 4, "dwadwadwadaw:");
	mvwprintw(this->_win, 3, 4, "dwadwadwadaw:");
	mvwprintw(this->_win, 4, 4, "dwadwadwadaw:");
	wrefresh(this->_win);
}
