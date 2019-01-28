#ifndef GAME_HPP
# define GAME_HPP
# include "ft_retro.hpp"
# include "Entity.hpp"
# include "Player.hpp"
# include "Foe.hpp"

class Entity;
class Player;
class Game {
private:
	WINDOW		*_w;
	WINDOW		*_s;
	int 		_score;
	int 		_bestScore;
	Player		*player;
	Foe			*enemies;
	int			map[HEIGHT][WIDTH];
	char		bg[HEIGHT][WIDTH];
	int			input(void);
	void		tick(void);
	void		fillInts(int arr[HEIGHT][WIDTH], int c);
	void		fillChars(char arr[HEIGHT][WIDTH], char c);
	void		doBullets(void);
	void		restart(void);
	void		fly(void);
public:
	Game(void);
	Game(Game const &copy);
	~Game(void);
	Game		&operator=(Game const & rfs);

	WINDOW		*getWindow(void) const;
	void		start(void);
};
static int 		max_score;

#endif
