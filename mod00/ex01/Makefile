CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = phonebook

SRCS = main.cpp PhoneBook.cpp Contact.cpp
OBJS = $(SRCS:.cpp=.o)

all: 		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
			$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re:			fclean all

run: 		$(NAME)
			./$(NAME)

.PHONY: all clean fclean re run
