CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

NAME = materia

SRCS = main.cpp AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp
OBJS = $(SRCS:%.cpp=build/%.o)

all: $(NAME)

$(NAME): $(OBJS)
			$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: %.cpp
			@mkdir -p build
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			rm -rf build

fclean: clean
			rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
