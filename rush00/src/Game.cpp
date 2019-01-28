#include "Game.hpp"

Game::Game() : _score(0), _bestScore(0) {
	// curses
	initscr();
	noecho();
	curs_set(0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, 24, COLOR_BLACK);
	_w = newwin(HEIGHT, WIDTH, 0, 0);
	keypad(_w, true);
	nodelay(_w, true);
	_s = newwin(8, 20, 0, WIDTH + 1);
	keypad(_s, true);
	nodelay(_s, true);

	// assets
	fillChars(bg, ' ');
	fillInts(map, 0);
	player = new Player(HEIGHT - 2, WIDTH / 2);
	mvwprintw(_w, HEIGHT - 2, WIDTH / 2, SHIP_STR);
	enemies = new Foe[HEIGHT];
	tick();
}
Game::Game(const Game &g) {
	*this = g;
}
Game	&Game::operator=(const Game &g) {
	_w = g.getWindow();
	return (*this);
}
Game::~Game() {
	delete player;
	delete [] enemies;
	endwin();
}

WINDOW	*Game::getWindow() const { return _w; }

void	Game::fillInts(int arr[HEIGHT][WIDTH], int c) {
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			arr[i][j] = c;
}
void	Game::fillChars(char arr[HEIGHT][WIDTH], char c) {
	for (int i = 0; i < HEIGHT; ++i)
		for (int j = 0; j < WIDTH; ++j)
			arr[i][j] = c;
}
void	Game::doBullets() {
	for (int i = 0; i < HEIGHT - 1; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			if (map[i + 1][j] == 1) {
				mvwprintw(_w, i + 1, j, " ");
				map[i][j] = map[i + 1][j];
				map[i + 1][j] = 0;
				mvwprintw(_w, i, j, BULLET);
			}
		}
	}
	for (int i = 0; i < HEIGHT; ++i) {
		if (enemies[i].get_x() == player->get_x()
			&& enemies[i].get_y() == player->get_y()) {
			enemies[i].die(_w);
			player->takeDamage();
		}
	}
}
void			Game::tick(void) {
	fly();
    wattron(_w, COLOR_PAIR(3));
	mvwprintw(_w, 0, 0, "%s", bg);
    wattroff(_w, COLOR_PAIR(3));
	doBullets();
	player->update(_w, SHIP_CHR, map);
	for (int i = 0; i < HEIGHT; ++i)
		_score += enemies[i].update(_w, DUDE, map);
	box(_w, 0, 0);
	wrefresh(_w);
	mvwprintw(_s, 1, 1, "HP: %i", player->getHP());
	mvwprintw(_s, 2, 1, "%i", _score);
	if (_score > _bestScore)
		_bestScore = _score;
	mvwprintw(_s, 3, 1, "Top: %i", _bestScore);
	box(_s, 0, 0);
	wrefresh(_s);
}

int			Game::input() {
	int c = 0;
	switch ((c = wgetch(_w))) {
		case KEY_LEFT:
			player->mvleft(_w, SHIP_CHR);
			break;
		case KEY_RIGHT:
			player->mvright(_w, SHIP_CHR);
			break;
		case KEY_UP:
			player->mvup(_w, SHIP_CHR);
			break;
		case KEY_DOWN:
			player->mvdown(_w, SHIP_CHR);
			break;
		case 32:
			player->shoot(map);
			break;
	}
	return (c);
}

void		Game::restart() {
	player->setHP(0);
	mvwprintw(_s, 4, 1, "Game over!");
	mvwprintw(_s, 5, 1, "Space: restart");
	mvwprintw(_s, 6, 1, "Ecs: exit");
	for (int i = 0; i < HEIGHT; ++i)
		enemies[i].respawn();
	_score = 0;
	tick();
}


void			Game::start() {
	int c = 0;

	while (c != 27) {
		int count = 0;
		while (c != 27 && player->getHP()) {
			c = input();
			if ((count % 5) == 0)
				for (int i = 0; i < HEIGHT; ++i)
					enemies[i].descend(_w);
			tick();
			usleep(50000);
			count++;
		}
		restart();
		switch ((c = wgetch(_w)) ) {
			case 32:
				player->setHP(5);
				_score = 0;
				wclear(_w);
				tick();
				wclear(_s);
				box(_s, 0, 0);
				fillInts(map, 0);
				break;
			case 27:
				return ;
				break;
		}
	}
}

void	Game::fly(void) {
	for (int i = HEIGHT - 1; i != -1 ; i--)
		for (int j = 0; j < WIDTH; j++)
			if (i != 0)
				bg[i][j] = bg[i - 1][j];
	for (int i = 0; i < WIDTH; ++i)
		bg[0][i] = (rand() % 50 == 0) ? STAR : ' ';
}
