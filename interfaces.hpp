#ifndef INTERFACES_HPP
# define INTERFACES_HPP
# include <ncurses.h>
# include <cstdlib>
# include "player.hpp"
# include "Astroid.hpp"
# include "Enemy.hpp"

# define UP 0
# define DOWN 1
# define RIGHT 2
# define LEFT 3

class	Interfaces
{
	public:
		Interfaces();
		Interfaces(int maxX, int maxY, int posX, int posY);
		~Interfaces();
		Interfaces(Interfaces const & copy);
		Interfaces & operator=(Interfaces const & copy);

		void	startMessage();
		void	endMessage();
		int		getMaxX() const;
		int		getMaxY() const;
		int		getPosX() const;
		int		getPosY() const;
		void	setEnd(bool);
		bool	getEnd() const;
		void	gameWin(WINDOW *);
		void	infoWindow(WINDOW *);
		void	moveMissile();
		void	moveAstroid();
		void	moveEnemy();
		void	gameControl(WINDOW *, WINDOW *);
		void	print(WINDOW *);
		void	collision(Enemy *enemy);

	private:
		int		_maxX;
		int		_maxY;
		int		_posX;
		int		_posY;
		bool	_end;
		Player	*_player;
		Astroid	*_astroid;
		Enemy	*_enemy;
};

#endif
