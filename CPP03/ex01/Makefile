NAME = ScavTrap
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g
DEPFLAGS = -MMD -MP -MF $(DEP_DIR)$*.d

SRC_DIR		= src/
OBJ_DIR		= obj/
DEP_DIR		= dep/
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.cpp=%.o))
DEPS = $(addprefix $(DEP_DIR), $(SRCS:%.cpp=%.d))

INCLUDES = -I./include
vpath %.cpp $(SRC_DIR)

all :  $(OBJ_DIR) $(DEP_DIR) $(NAME)

$(OBJ_DIR) $(DEP_DIR) :
	@mkdir -p $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) $(DEPS) $(DEP_DIR) $(OBJ_DIR)
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

test:
	cmake -S . -B build
	cmake --build build
	./build/ScavTrap-googletest

-include $(DEPS)

.PHONY : clean fclean re all test