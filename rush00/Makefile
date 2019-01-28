NAME = ft_retro
CC = clang++
FLAG = -Wall -Wextra -Werror -std=c++98
SRC_DIR = ./src/
SRC_FILES = main.cpp Game.cpp Entity.cpp Player.cpp Foe.cpp
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
INC = -I./inc/
OBJ = $(SRC:.cpp=.o)
LINK = -lncurses

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAG) $(INC) $(OBJ) $(LINK) -o $(NAME)
%.o : %.cpp
	$(CC) $(FLAG) $(INC) -c $< -o $@
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
