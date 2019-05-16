#include "Enemy.hpp"
#include <cstdlib>

int		Enemy::_number = 0;
Enemy::Enemy(int x, int y, Enemy *next, Enemy *prev) : GameObject(x, y, next, prev) {
	_mX = 98;
	_mY = 28;
	_hit = 0;
	_number++;
	return ;
}

Enemy::~Enemy() {
	return ;
}

Enemy::Enemy(Enemy const & copy) : GameObject(copy) {
	*this = copy;
}

void	Enemy::setHit() {
	_hit = 1;
}

int		Enemy::getHit() {
	return (_hit);
}

void	Enemy::destroy() {
	Enemy	*tmp = this;
	if (tmp->_prev != NULL)
		tmp->_prev->setNext(_next);
	if (tmp->_next != NULL)
		tmp->_next->setPrev(_prev);
	if (tmp->_prev == NULL)
		tmp = NULL;
	else
		delete(tmp);
	if (_number - 1 >= 0)
		_number -= 1;

}

void	Enemy::move() {
	clock_t	now = clock ();
	int		arr[3] = {-1, 0, 1};

	if (_next != NULL)
		_next->move();
	double diff = (double) now - (double) _start;
	diff /= CLOCKS_PER_SEC;
	if (diff >= 0.10) {
		_start = now;
		_x += arr[rand() % 2];
		_y += arr[rand() % 3];
		if (_x == 0)
		{
			destroy();
			return ;
		}
	}
	if (_next == NULL && _number < 10) {
		setNext(new Enemy(_mX - 1, rand() % _mY + 1, NULL, this));
	}
}
