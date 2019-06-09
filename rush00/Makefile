NAME     := ft_retro

SRCS     := main.cpp player.cpp enemy.cpp
HDRS     := enemy.hpp player.hpp
OBJS     := $(SRCS:.cpp=.o)

CXX      := clang++
CXXFLAGS := -std=c++98 -Wall -Werror -Wextra -g


all: $(NAME)


$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@ -lncurses 


%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -o $@ -c $<
	@echo "BUILT OBJECTS"

clean:
	@rm -f $(OBJS)
	@echo "OBJECTS REMOVED"

fclean: clean
	@rm -f $(NAME)
	@echo "FILE REMOVED"

re:     fclean all

.PHONY: all clean fclean format re