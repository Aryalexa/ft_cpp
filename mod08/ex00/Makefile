CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

NAME = containers

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=build/%.o)
DEPS = easyfind.hpp

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

build/%.o: %.cpp $(DEPS)
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
