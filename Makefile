
NAME = ft_retro

CXX = @clang++

CXXFLAGS = -Wall -Wextra -Werror

LINKER = -lncurses

SRC = main.cpp Enemy.cpp Missile.cpp player.cpp interfaces.cpp GameObject.cpp Astroid.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	@$(CXX) $(LINKER) $(CXXFLAGS) $(OBJ) -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
