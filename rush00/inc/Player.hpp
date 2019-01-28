#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Entity.hpp"

class Player : public Entity {
private:
	int 	lives_point;
public:
	Player(void);
	Player(int y, int x);
	Player(Player const &copy);
	~Player(void) {};
	Player &operator=(Player const & rfs);

	void 	setHP(int point);
	int		getHP() const;
	void	shoot(int map[HEIGHT][WIDTH]);
	int		update(WINDOW *w, char c, int map[HEIGHT][WIDTH]);
	void	takeDamage();
};

#endif
