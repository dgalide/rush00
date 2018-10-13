#ifndef MonitorModule_HPP
#define MonitorModule_HPP

#include <ncurses.h>
#include <string>


class IMonitorModule {

	public:
		virtual void display( void ) = 0;
};

class MonitorModule {

	public:
		MonitorModule( int height, int width, int pos_x, int pos_y );
		~MonitorModule( void );

		void display( void );

	private:
		MonitorModule( void );
		MonitorModule( const MonitorModule &src );
		MonitorModule &operator=( const MonitorModule &src );

		int _height;
		int _width;
		int _pos_x;
		int _pos_y;
		char *_info;
		WINDOW *_win;
};


#endif
