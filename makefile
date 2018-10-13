export LD_LIBRARY_PATH=~/.brew/lib/

NAME = ft_gkrellm

SRC = main.cpp
SRC += Info.cpp
SRC += OSModule.cpp
SRC += Item.cpp
SRC += IMonitorDisplay.cpp
SRC += UserModule.cpp
SRC += RamModule.cpp
SRC += CpuModule.cpp
SRC += NetworkModule.cpp

CLANG_FLAGS = -Werror -Wall -Wextra -g

CLANG = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) -I ~/.brew/include/ $(CLANG_FLAGS) -o $(NAME) $(OBJ) -lncurses  -L ~/.brew/lib/ -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CLANG) -I ~/.brew/include/ $(CLANG_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
