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

int MonitorSfml::current_pos_x = 0;

MonitorSfml::MonitorSfml( sf::RenderWindow  &window, int height, int width, int pos_x, int pos_y ) : \
_height(height), _width(width), _pos_x(pos_x), _pos_y(pos_y), _win(window) {
	this->_pos_x = MonitorSfml::current_pos_x;
	this->setSize(sf::Vector2f(this->_width, this->_height));
	this->setOutlineColor(sf::Color::Color(0, 102, 102));
	this->setFillColor(sf::Color::Color(51, 204, 204));
	this->setOutlineThickness(5);
	this->setPosition(this->_pos_y, this->_pos_x);
	MonitorSfml::current_pos_x += this->_height;
	// std::cout << MonitorSfml::current_pos_x << std::endl;
}

MonitorSfml::~MonitorSfml( void ) {
}

void MonitorSfml::display( std::string title, std::vector<Item*>* test ) {
	if (test) {
		std::vector<Item*>::iterator it = test->begin();
		std::vector<Item*>::iterator it_end = test->end();

		sf::Font font;
		font.loadFromFile("/Library/Fonts/arial.ttf");
		sf::Text text(title, font);
		text.setCharacterSize(FONT_SIZE_TITLE);
		// text.setStyle(sf::Text::Bold);
		text.setFillColor(sf::Color::Blue);
		// text.setPosition(this->_width / 2 - (std::strlen(title.c_str()) * FONT_SIZE_TITLE) / 2, this->_pos_x);
		text.setPosition(this->_width / 2 - 10, this->_pos_x);
		for (int i = 0; it != it_end; i++, it++) {
			sf::Text line((*it)->getFormat().c_str(), font);
			line.setCharacterSize(FONT_SIZE_LINE);
			line.setStyle(sf::Text::Bold);
			line.setFillColor(sf::Color::White);
			line.setPosition(5, 30 + this->_pos_x + i * FONT_SIZE_LINE);
			this->_win.draw(line);
		}
		this->_win.draw(text);
	}

}
