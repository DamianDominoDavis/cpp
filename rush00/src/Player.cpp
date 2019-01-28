#include "Player.hpp"

Player::Player(void) : lives_point(5) {}
Player::Player(int y, int x) : lives_point(5) {
	_y = y;
	_x = x;
}
Player::Player(Player const &copy) {
	*this = copy;
}
Player &Player::operator=(Player const &rfs) {
	_x = rfs.get_x();
	_y = rfs.get_y();
	lives_point = rfs.getHP();
	return (*this);
}

int		Player::getHP() const { return (lives_point); }
void 	Player::setHP(int point) {
	lives_point = point;
	_x = WIDTH / 2;
	_y = HEIGHT - 2;
}
void		Player::shoot(int map[HEIGHT][WIDTH]) {
	map[_y][_x] = 1;
}
int		Player::update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) {
	if (lives_point && map[_y][_x]) {
		map[_y][_x] = 0;
		lives_point--;
	}
	if (lives_point < 1) {
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
	lives_point--;
	_y = HEIGHT - 2;
	_x = WIDTH / 2;
}
