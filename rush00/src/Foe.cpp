#include "Foe.hpp"

Foe::Foe() {
	respawn();
}
Foe::Foe(const Foe &f) {
	*this = f;
}
Foe &Foe::operator=(const Foe &f) {
 	_x = f.get_x();
 	_y = f.get_y();
 	return *this;
}
Foe::~Foe() {}

void Foe::descend(WINDOW *_w) {
	static int ticktock;
	if (_xp) {
		if (ticktock) {
			mvwprintw(_w, _y, _x, " ");
			_x %= WIDTH - 2;
            _y %= HEIGHT - 2;
            mvwprintw(_w, ++_y, ++_x, "%c", '*');
        }
        else {
            mvwprintw(_w, _y, _x--, " ");
            _x %= WIDTH - 2;
            if (_x < 1)
                _x += WIDTH - 2;
            _y %= HEIGHT - 2;
            mvwprintw(_w, ++_y, _x, "%c", '*');
        }
		if (_y == HEIGHT)
			die(_w);
		ticktock = ticktock ? 0 : 1;
	}
	else
		respawn();
}

void Foe::die(WINDOW *_w) {
	_xp = 0;
	mvwprintw(_w, _y, _x, " ");
}

void		Foe::respawn(void) {
	_y = -(rand() % HEIGHT);
	_x = 2 + rand() % (WIDTH - 4);
	_xp = 1;
}

int		Foe::update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) {
	if (_y > -1 && _xp && map[_y][_x] == 1) {
		map[_y][_x] = 0;
		die(w);
		return (1);
	}
	if (_xp) {
        wattron(w, COLOR_PAIR(1));
        mvwprintw(w, _y, _x, "%c", c);
        wattroff(w, COLOR_PAIR(1));
    }
	return (0);
}
