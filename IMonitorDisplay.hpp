#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include <ncurses.h>
#include <string>
#include <vector>
#include "Item.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#define FONT_SIZE_LINE 15
#define FONT_SIZE_TITLE 30

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

class MonitorSfml : public sf::RectangleShape {

	public:
		MonitorSfml( sf::RenderWindow  &window, int height, int width, int pos_x, int pos_y );
		~MonitorSfml( void );

		void display( std::string title, std::vector<Item*> *);

		static int current_pos_x;

	private:
		MonitorSfml( void );
		MonitorSfml( const MonitorSfml &src );
		MonitorSfml &operator=( const MonitorSfml &src );

		int _height;
		int _width;
		int _pos_x;
		int _pos_y;
		sf::RenderWindow &_win;
};

#endif
