SRCS	=	main.cpp

CLS	=	ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJS	=	$(SRCS:.cpp=.o) $(CLS:.cpp=.o)

CPPSTD	=	-std=c++98

CPPFLGS	=	$(CPPSTD) -Wall -Werror -Wextra

NAME	=	FragTrapAttack

.c.o:
	c++ $(CPPFLGS) -o $< -c $@

$(NAME):	$(OBJS)
	c++ $(CPPFLGS) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	rm $(OBJS)

fclean:	clean
	rm $(NAME)

re:	fclean all
