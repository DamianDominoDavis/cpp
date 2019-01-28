#include "Player.hpp"

Player::Player(void) : _health(5) {}
Player::Player(int y, int x) : _health(5) {
	_y = y;
	_x = x;
}
Player::Player(Player const &copy) {
	*this = copy;
}
Player &Player::operator=(Player const &rfs) {
	_x = rfs.get_x();
	_y = rfs.get_y();
	_health = rfs.getHP();
	return (*this);
}

int		Player::getHP(void) const { return (_health); }
void 	Player::setHP(int point) {
	_health = point;
	_x = WIDTH / 2;
	_y = HEIGHT - 2;
}
void		Player::shoot(int map[HEIGHT][WIDTH]) {
	map[_y][_x] = 1;
}
int		Player::update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) {
	if (_health && map[_y][_x]) {
		map[_y][_x] = 0;
		_health--;
	}
	if (_health < 1) {
		wattron(w, COLOR_PAIR(2));
		mvwprintw(w, _y, _x, "%c", 'x');
		wattroff(w, COLOR_PAIR(2));
	}
	else {
		wattron(w, COLOR_PAIR(2));
		mvwprintw(w, _y, _x, "%c", c);
		wattroff(w, COLOR_PAIR(2));
	}
	return (0);
}
void		Player::takeDamage() {
	_health--;
	_y = HEIGHT - 2;
	_x = WIDTH / 2;
}
