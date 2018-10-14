export LD_LIBRARY_PATH=~/.brew/lib/
export LD_LIBRARY_PATH=/usr/local/lib

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
SRC += DateModule.cpp

#LIB = -I ~/.brew/include/ 
LIB = -I /usr/local/include/ 

#LIB_SRC = -L ~/.brew/lib/
LIB_SRC = -L /usr/local/lib/

CLANG_FLAGS = -Werror -Wall -Wextra -g

CLANG = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(LIB) $(CLANG_FLAGS) -o $(NAME) $(OBJ) -lncurses $(LIB_SRC) -lsfml-graphics -lsfml-window -lsfml-system

%.o: %.cpp
	$(CLANG) $(LIB) $(CLANG_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
