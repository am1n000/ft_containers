CPP=C++
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98
NAME=Containers
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	@$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CPP) $(CFLAGS) $^ -o $@
	@echo "\033[32m Compilation success\033[0m"

clean:
	@rm -rf *.o
	@echo "\033[31m object files deleted\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31m program terminated\033[0m"

re: fclean all
