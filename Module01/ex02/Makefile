SRCS	=	main.cpp

OBJS	=	$(SRCS:.cpp=.o)

CPPSTD	=	-std=c++98

CPPFLGS	=	$(CPPSTD) -Wall -Werror -Wextra -g

NAME	=	BonjourCerveau

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
