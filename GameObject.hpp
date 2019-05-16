#ifndef GAMEOBJECT_HPP
# define GAMEOBJECT_HPP

#include <ctime>

class GameObject {

	public:
		GameObject(int, int, GameObject *, GameObject *);
		virtual ~GameObject(void);
		GameObject(GameObject const & src);
		GameObject & operator=(GameObject const & rhs);
		int			getX() const;
		int			getY() const;

		GameObject	*getNext() const;
		GameObject	*getPrev() const;
		void	setNext(GameObject *next);
		void	setPrev(GameObject *prev);
		virtual void		move() = 0;
	protected:
		int			_x;
		int			_y;
		GameObject *_next;
		GameObject *_prev;
		GameObject(void);
		clock_t _start;


};

#endif
