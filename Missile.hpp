#ifndef MISSILE_HPP
# define MISSILE_HPP

# include <ctime>
# include "GameObject.hpp"

class	Missile : public GameObject
{
	public:
		Missile(int, int, Missile*, Missile*);
		~Missile();
		Missile(Missile const & copy);
		Missile & operator=(Missile const & copy);
		void	destroy();
		void	move();
	private:
		Missile();
} ;

#endif
