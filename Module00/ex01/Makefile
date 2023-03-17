# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 20:24:45 by iamongeo          #+#    #+#              #
#    Updated: 2023/03/16 20:24:52 by iamongeo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	main.cpp

CLS	=	PhoneBook.cpp Contact.cpp

OBJS	=	$(SRCS:.cpp=.o) $(CLS:.cpp=.o)

CPPSTD	=	-std=c++98

CPPFLGS	=	$(CPPSTD) -Wall -Werror -Wextra

NAME	=	phonebook

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
