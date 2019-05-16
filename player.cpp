#include "player.hpp"
#include "interfaces.hpp"
#include "Missile.hpp"

Player::Player() {
	return ;
}

Player::Player(int x, int y, int mX, int mY) : _health(5), _x(x), _y(y), _mX(mX), _mY(mY), _missile(NULL), _score(0) {
	return ;
}

Player::~Player() {
	return ;
}

Player::Player(Player const & copy) {
	*this = copy;
}

Player & Player::operator=(Player const & copy) {
	this->_health = copy.getHealth();
	this->_x = copy.getX();
	this->_y = copy.getY();
	this->_mX = copy.getMX();
	this->_mY = copy.getMY();
	return (*this);
}

int			Player::getHealth() const {
	return (this->_health);
}

int			Player::getX() const {
	return (this->_x);
}

int			Player::getScore() const {
	return (this->_score);
}

void		Player::addScore() {
	_score++;
}

int			Player::getY() const {
	return (this->_y);
}

int			Player::getMX() const {
	return (this->_mX);
}

int			Player::getMY() const {
	return (this->_mY);
}

Missile*	Player::getMissile() const {
	return (this->_missile);
}

void		Player::move(int direction) {
	if (direction == UP && (_y - 1) > 0)
		_y -= 1;
	else if (direction == DOWN && (_y + 2) < _mY)
		_y += 1;
	else if (direction ==  RIGHT && (_x + 1) < _mX)
		_x += 1;
	else if (direction == LEFT && (_x - 2) > 0)
		_x -= 1;
}

void	Player::shoot() {
	if (_missile == NULL)
		_missile = new Missile(_x, _y, NULL, NULL);
	else {
		Missile	*tmp = _missile;
		while (tmp->getNext())
			tmp = (Missile*)tmp->getNext();
		tmp->setNext(new Missile(_x, _y, NULL, tmp));
	}
}

void	Player::takeDamage() {
	_health -= 1;
}
