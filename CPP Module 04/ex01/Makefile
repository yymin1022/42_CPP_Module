CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Animal
SRC = main.cpp Brain.cpp Animal.cpp Cat.cpp Dog.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $(<) -o $(@)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
