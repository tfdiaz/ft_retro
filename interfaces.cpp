#include "interfaces.hpp"

Interfaces::Interfaces() {
	return ;
}

Interfaces::Interfaces(int maxX, int maxY, int posX, int posY) : _maxX(maxX), _maxY(maxY), _posX(posX), _posY(posY), _end(FALSE)
{
	_player = new Player(posX, posY, maxX, maxY);
	_astroid = NULL;
	_enemy = NULL;
	return ;
}

Interfaces::~Interfaces() {
	return ;
}

Interfaces::Interfaces (Interfaces const & copy) {
	*this = copy;
}

Interfaces & Interfaces::operator=(Interfaces const & copy) {
	this->_maxX = copy.getMaxX();
	this->_maxY = copy.getMaxY();
	this->_posX = copy.getPosX();
	this->_posY = copy.getPosY();

	return (*this);
}

void	Interfaces::startMessage () {
	mvprintw(15, 10, " .-. .--.  .    .--..---.  --.--.   ..       ..    .--. .---..--.  .-. \n");
	mvprintw(16, 10, "(   )|   )/ \\  :    |        |  |\\  | \\     // \\   |   :|    |   )(   )\n");
	mvprintw(17, 10, " `-. |--'/___\\ |    |---     |  | \\ |  \\   //___\\  |   ||--- |--'  `-. \n");
	mvprintw(18, 10, "(   )|  /     \\:    |        |  |  \\|   \\ //     \\ |   ;|    |  \\ (   )\n");
	mvprintw(19, 10, " `-' ' '       ``--''---'  --'--'   '    ''       `'--' '---''   ` `-' \n");
	attron (A_BLINK | A_BOLD);
	mvprintw (22, 30, "press 'ENTER' to start game");
	attroff (A_BLINK | A_BOLD);
	mvprintw (23, 34, "press 'q' to quit");

	refresh ();
}

void	Interfaces::endMessage () {
	mvprintw(15, 10, " .-. .--.  .    .--..---.  --.--.   ..       ..    .--. .---..--.  .-. \n");
	mvprintw(16, 10, "(   )|   )/ \\  :    |        |  |\\  | \\     // \\   |   :|    |   )(   )\n");
	mvprintw(17, 10, " `-. |--'/___\\ |    |---     |  | \\ |  \\   //___\\  |   ||--- |--'  `-. \n");
	mvprintw(18, 10, "(   )|  /     \\:    |        |  |  \\|   \\ //     \\ |   ;|    |  \\ (   )\n");
	mvprintw(19, 10, " `-' ' '       ``--''---'  --'--'   '    ''       `'--' '---''   ` `-' \n");
	attron (A_BLINK | A_BOLD);
	mvprintw (22, 30, "YOU DIED");
	attroff (A_BLINK | A_BOLD);
	mvprintw (23, 34, "press 'ENTER' to quit");

	refresh ();
}


int		Interfaces::getMaxX() const {
	return (this->_maxX);
}

int		Interfaces::getMaxY() const {
	return (this->_maxY);
}

int		Interfaces::getPosX() const {
	return (this->_posX);
}

int		Interfaces::getPosY() const {
	return (this->_posY);
}

void	Interfaces::setEnd(bool end) {
	this->_end = end;
}

bool	Interfaces::getEnd() const {
	return (this->_end);
}

void	Interfaces::infoWindow(WINDOW * window) {
	werase(window);
	box(window, '|', '-');
	mvwprintw(window, 2, 2, "HEALTH: ");
	for (int i = 0; i < _player->getHealth(); i++)
		mvwprintw(window, 2, 10 + (2 * i), "o ");
	mvwprintw(window, 2, 30, "SCORE: %d", _player->getScore());
	mvwprintw(window, 1, 80, "SPACE: Missile");
	mvwprintw(window, 2, 80, "ARROW: Move");
	mvwprintw(window, 3, 80, "  Q  : Exit");

	wrefresh(window);
}

void	Interfaces::gameWin(WINDOW * window) {
	box(window, '|', '-');
	wrefresh(window);
}


void	Interfaces::moveMissile() {
	if (_player->getMissile() == NULL)
		return ;
	Missile *tmp;
	if ((tmp = _player->getMissile()) != NULL)
		tmp->move();
}

void	Interfaces::moveAstroid() {
	if (_astroid == NULL)
		_astroid = new Astroid(rand() % _maxX, rand() % _maxY, NULL, NULL);
	Astroid	*tmp;
	if ((tmp = _astroid) != NULL)
		tmp->move();
}

void	Interfaces::moveEnemy() {
	if (_enemy == NULL)
		_enemy = new Enemy(_maxX - 1, rand() % _maxY, NULL, NULL);
	Enemy *tmp;
	if ((tmp = _enemy) != NULL)
		tmp->move();
}

void	Interfaces::gameControl(WINDOW * window, WINDOW * info) {
	int	direction = 0;

	while (this->_end != TRUE)
	{
		direction = getch();
		switch (direction)
		{
			case KEY_UP:
				_player->move(UP);
				break ;
			case KEY_DOWN:
				_player->move(DOWN);
				break ;
			case KEY_RIGHT:
				_player->move(RIGHT);
				break ;
			case KEY_LEFT:
				_player->move(LEFT);
				break ;
			case (int)' ':
				_player->shoot();
				break ;
			case (int)'q':
				_end = TRUE;
				break ;
		}
		moveMissile();
		moveAstroid();
		moveEnemy();
		print(window);
		collision(_enemy);
		if (_player->getHealth() == 0)
			_end = TRUE;
		infoWindow(info);
		wrefresh(window);
	}
}

void	Interfaces::collision(Enemy	*enemy) {
	if (enemy->getNext() != NULL)
		collision((Enemy*)enemy->getNext());
	if (_player->getX() == enemy->getX() && _player->getY() == enemy->getY() && enemy->getHit() == 0) {
		enemy->setHit();
		_player->takeDamage();
		enemy->destroy();
		return ;
	}
	Missile *tmp = (Missile*)_player->getMissile();
	while (tmp)
	{
		if (tmp->getX() == enemy->getX() && tmp->getY() == enemy->getY() && enemy->getHit() == 0)
		{
			enemy->setHit();
			_player->getMissile()->destroy();
			enemy->destroy();
			_player->addScore();
		}
		tmp = (Missile*)tmp->getNext();
	}
}

void	Interfaces::print(WINDOW * window) {
	werase (window);

	if (_astroid)
	{
		Astroid *tmp = _astroid;
		while (tmp)
		{
			mvwprintw(window, tmp->getY(), tmp->getX(), ".");
			tmp = (Astroid*)tmp->getNext();
		}
	}
	if (_enemy)
	{
		Enemy *tmp = _enemy;
		while (tmp)
		{
			attron(A_DIM);
			mvwprintw(window, tmp->getY(), tmp->getX(), "X");
			tmp = (Enemy*)tmp->getNext();
		}
	}
	if (_player->getMissile())
	{
		Missile *tmp = _player->getMissile();
		while (tmp)
		{
			mvwprintw(window, tmp->getY(), tmp->getX(), "o");
			tmp = (Missile*)tmp->getNext();
		}
	}
	box(window, '|', '-');
	mvwprintw(window, _player->getY(), _player->getX(), ">");
	mvwprintw(window, _player->getY(), _player->getX() - 1, "#");
}
