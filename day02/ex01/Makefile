<<<<<<< HEAD
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ofedorov <ofedorov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/03 10:23:53 by ofedorov          #+#    #+#              #
#    Updated: 2017/07/05 17:03:38 by ofedorov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fixed

SRCS =	Fixed.class.cpp \
		main.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean all
=======
NAME = fixed
all:
	clang++ -Wall -Wextra -Werror -std=c++98 *.cpp -I. -o $(NAME)
clean:
	rm -f $(NAME)
>>>>>>> 4ad56b74fd7b019472b40effc2995309ed75fa15
