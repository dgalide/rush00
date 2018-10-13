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

QTPATH       = -I ~/Qt/5.4/clang_64/lib/QtWidgets.framework/Versions/5/Headers \
				-I ~/Qt/5.4/clang_64/lib/QtGui.framework/Versions/5/Headers \
				-I ~/Qt/5.4/clang_64/lib/QtCore.framework/Versions/5/Headers \
				-I. -F ~/Qt/5.4/clang_64/lib

CLANG = clang++

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CLANG) $(QTPATH) $(CLANG_FLAGS) -o $(NAME) $(OBJ) -lncurses -framework QtWidgets -framework QtGui -framework QtCore

%.o: %.cpp
	$(CLANG) $(QTPATH) $(CLANG_FLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
