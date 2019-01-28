#ifndef FOE_HPP
#define FOE_HPP
#include "ft_retro.hpp"
#include "Entity.hpp"

class Foe : public Entity {
	int		_xp;
public:
	Foe(void);
	Foe(const Foe &f);
	~Foe(void);
	Foe &operator=(const Foe &f);
	
	void	descend(WINDOW *_w);
	void	die(WINDOW *_w);
	int		update(WINDOW *w, char c, int map[HEIGHT][WIDTH]);
	void	respawn(void);
};

#endif
