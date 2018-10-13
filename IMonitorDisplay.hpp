#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <ncurses.h>
#include <string>
#include <vector>
#include "Item.hpp"


class IMonitorDisplay {

	public:
		virtual void display( void ) = 0;
};

class MonitorNcurses {

	public:
		MonitorNcurses( int height, int width, int pos_x, int pos_y );
		~MonitorNcurses( void );

		void display( std::string title, std::vector<Item*> *);

		static int current_pos_x;

	private:
		MonitorNcurses( void );
		MonitorNcurses( const MonitorNcurses &src );
		MonitorNcurses &operator=( const MonitorNcurses &src );

		int _height;
		int _width;
		int _pos_x;
		int _pos_y;
		WINDOW *_win;
};

#endif
