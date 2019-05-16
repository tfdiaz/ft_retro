#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "GameObject.hpp"
# include <ctime>

class   Enemy : public GameObject
{
	public:
		Enemy(int, int, Enemy*, Enemy*);
		~Enemy();
		Enemy(Enemy const & copy);
		using GameObject::operator=;
		void	move();
		void	setHit();
		int		getHit();
		void	destroy();

	private:
		int             _hit;
		int             _mX;
		int             _mY;
		static int		_number;
		Enemy();
};

#endif
