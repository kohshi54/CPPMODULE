NAME = ClapTrap
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
DEPFLAGS = -MMD -MP

SRCS = main.cpp ClapTrap.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

INCLUDES = -I./

all :  $(NAME)

%.o: %.cpp
	$(CC) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) $(DEPS)
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : clean fclean re all