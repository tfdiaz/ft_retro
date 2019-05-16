#ifndef ASTROID_HPP
# define ASTROID_HPP

# include "GameObject.hpp"
# include <ctime>

class	Astroid : public GameObject
{
	public:
		Astroid(int, int, Astroid*, Astroid*);
		~Astroid();
		Astroid(Astroid const & copy);
		Astroid & operator=(Astroid const & copy);
		void	move();
		void	setHit();
		int		getHit();

	private:
		int		_hit;
		int		_mX;
		int		_mY;
		static int	_number;
		Astroid();
};

#endif
