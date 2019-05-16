#include "Missile.hpp"

Missile::Missile(int x, int y, Missile *next, Missile *prev) : GameObject(x, y, next, prev)
{
	return ;
}

Missile::~Missile() {
	return ;
}

Missile::Missile(Missile const & copy) : GameObject(copy)
{
	*this = copy;
}

Missile & Missile::operator =(Missile const & copy) {
	GameObject::operator=(copy);
	return (*this);
}

void	Missile::destroy() {
	Missile *tmp = this;
	if (tmp->_prev != NULL)
		tmp->_prev->setNext(_next);
	if (tmp->_next != NULL)
		tmp->_next->setPrev(_prev);
	if (tmp->_prev == NULL)
		tmp = NULL;
	else
		delete(tmp);

}

void	Missile::move() {
	clock_t	now = clock ();

	if (_next != NULL)
		_next->move();
	double diff = (double) now - (double) _start;
	diff /= CLOCKS_PER_SEC;
	if (diff >= 0.05)
	{
		_start = now;
		_x++;
		if (_x == 99)
		{
			destroy();
			return ;
		}
	}
}
