# include "Entity.hpp"

Entity::Entity(int y, int x) : _y(y), _x(x) {}
Entity::Entity(Entity const &copy) {
	*this = copy;
}
Entity& Entity::operator=(Entity const &e) {
	_x = e.get_x();
	_y = e.get_y();
	return (*this);
}

int		Entity::get_x(void) const { return (_x); }
int		Entity::get_y(void) const { return (_y); }

void        Entity::mvleft(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	--_x %= WIDTH - 2;
	if (_x < 1)
		_x += WIDTH - 2;
	mvwprintw(w, _y, _x, "%c", c);
}
void        Entity::mvright(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_x %= WIDTH - 2;
	_x++;
	mvwprintw(w, _y, _x, "%c", c);
}
void        Entity::mvup(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_y--;
	_y %= HEIGHT - 2;
	if (_y < 1)
		_y += HEIGHT - 2;
	mvwprintw(w, _y, _x, "%c", c);
}
void		Entity::mvdown(WINDOW *w, char c) {
	mvwprintw(w, _y, _x, " ");
	_y %= HEIGHT - 2;
	_y++;
	mvwprintw(w, _y, _x, "%c", c);
}
