CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

NAME = sedIsStreamEditor

SRCS = main.cpp
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

# tests ???
test:	$(NAME)
		echo "Running tests..."
		@if ./$(NAME); then \
			echo "Test 1: no args -> FAIL"❌; \
		else \
			echo "Test 1: no args -> OK✅"; \
		fi
		@if ./$(NAME) "no-existing-file.txt" 23 24; then \
			echo "Test 2: file not found -> FAIL❌"; \
		else \
			echo "Test 2: file not found -> OK✅"; \
		fi

		@./$(NAME) "test-ana.txt" ana fabiola
		@if diff "test-ana.txt.replace" "test-ana-sol.txt"; then \
			echo "Test 3: File content matches -> OK✅"; \
		else \
			echo "Test 3: File content matches -> FAIL❌"; \
		fi 

.PHONY: all clean fclean re test