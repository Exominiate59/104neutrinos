##
## EPITECH PROJECT, 2024
## B-MAT-100-LIL-1-1-104neutrinos-remi.deroussent
## File description:
## Makefile
##

CXX = g++

CXXFLAGS = -Wall -Wextra -O2

SRC = src/main.cpp

OBJ = $(SRC:.cpp=.o)

NAME = 104neutrinos

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
