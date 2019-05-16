#include "GameObject.hpp"

GameObject::GameObject(int x, int y, GameObject *next, GameObject *prev) : _x(x), _y(y), _next(next), _prev(prev)
{
	_start = clock();
	return;
}

GameObject::~GameObject(void)
{
	return;
}
		
		
GameObject::GameObject(GameObject const & src)
{
	*this = src;
	return;
}
		
GameObject & GameObject::operator=(GameObject const & rhs)
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_next = rhs._next;
	this->_prev = rhs._prev;
	return (*this);
}

int		GameObject::getX() const {
	return (_x);
}

int		GameObject::getY() const {
	return (_y);
}

void	GameObject::setNext(GameObject *next) {
	_next = next;
}

void	GameObject::setPrev(GameObject *prev) {
	_prev = prev;
}

GameObject*	GameObject::getNext() const {
	return (_next);
} 

GameObject*	GameObject::getPrev() const {
	return (_prev);
}
