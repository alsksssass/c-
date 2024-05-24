NAME = a.out
CC = c++
CFLAGS = -Wall -Wextra -Werror
ADFLAG = -std=c++98
DFLAG = -MMD -MP
SRC = main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SRC:.cpp=.o)
DBJ = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(DFLAG) $(ADFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(ADFLAG) $(DFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(DBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DBJ)

.PHONY: all clean fclean re

