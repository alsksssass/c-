NAME = a.out
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror
ADFLAG = -std=c++98
DFLAG = -MMD -MP
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
DBJ = $(SRC:.cpp=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(DFLAG) $(ADFLAG) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(ADFLAG) $(DFLAG) -c $< -o $@

clean:
	rm -f $(OBJ) $(DBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DBJ)

.PHONY: all clean fclean re

