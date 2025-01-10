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
		@if ./$(NAME) er rt ty er; then \
			echo "Test 2: too many args -> FAIL"❌; \
		else \
			echo "Test 2: too many args -> OK✅"; \
		fi
		@if ./$(NAME) "no-existing-file.txt" 23 24; then \
			echo "Test 3: file not found -> FAIL❌"; \
		else \
			echo "Test 3: file not found -> OK✅"; \
		fi
		@chmod 000 test-forbidden.txt
		@if ./$(NAME) "test-forbidden.txt" 23 24; then \
			echo "Test 4: file with no permissions -> FAIL❌"; \
		else \
			echo "Test 4: file with no permissions -> OK✅"; \
		fi
		@chmod 644 test-forbidden.txt
		@if ./$(NAME) "test-empty.txt" 23 24; then \
			echo "Test 5: empty file -> OK✅"; \
		else \
			echo "Test 5: empty file -> FAIL❌"; \
		fi
		@./$(NAME) "test-ana.txt" ana fabiola
		@if diff "test-ana.txt.replace" "test-ana-sol.txt"; then \
			echo "Test 6: File content matches -> OK✅"; \
		else \
			echo "Test 6: File content matches -> FAIL❌"; \
		fi 

.PHONY: all clean fclean re test