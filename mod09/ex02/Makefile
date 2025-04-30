CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror 

NAME = PmergeMe

SRCS = main.cpp
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
test:
# MAC
	./PmergeMe `jot -r 30 1 100000 | tr '\n' ' '`
# LINUX
#  ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`

re: fclean all

.PHONY: all clean fclean re test
