#ifndef ENTITY_HPP
# define ENTITY_HPP
# include "ft_retro.hpp"

class 	Entity {
protected:
	int 	_y;
	int		_x;
public:
	Entity(void) {};
	Entity(int y, int x);
	Entity(const Entity &e);
	virtual ~Entity(void) {};
	Entity &operator=(const Entity &e);
	
	virtual void	mvleft(WINDOW *w, char c);
	virtual void	mvright(WINDOW *w, char c);
	virtual void	mvup(WINDOW *w, char c);
	virtual void	mvdown(WINDOW *w, char c);
	virtual int		update(WINDOW *w, char c, int map[HEIGHT][WIDTH]) = 0;
	virtual int 	get_x(void) const;
	virtual int 	get_y(void) const;
};

#endif
