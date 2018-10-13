NAME = ft_gkrellm

SRC = main.cpp
SRC += Info.cpp
SRC += OSModule.cpp
SRC += IMonitorModule.cpp

CLANG_FLAGS = -Wall -Wextra -Werror -g

CLANG = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(CLANG_FLAGS) -o $(NAME) $(OBJ) -lncurses

%.o: %.cpp
	$(CLANG) $(CLANG_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all

.PHONY: all re clean fclean
