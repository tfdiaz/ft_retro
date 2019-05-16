#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <iostream>
# include "Missile.hpp"

class	Player
{
	public:
		Player();
		Player(int, int, int, int);
		virtual ~Player();
		Player(Player const & copy);
		Player & operator =(Player const & copy);
		int			getHealth() const;
		int			getX() const;
		int			getY() const;
		int			getMX() const;
		int			getMY() const;
		Missile*	getMissile() const;
		void		move(int direction);
		void		shoot();
		void		takeDamage();
		int			getScore() const;
		void		addScore();

	private:
		int			_health;
		int			_x;
		int			_y;
		int			_mX;
		int			_mY;
		Missile*	_missile;
		int			_score;
};

#endif
