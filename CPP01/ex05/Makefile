NAME = Harl
CC = c++
CFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++98 -fsanitize=address -g

SRC_DIR		= src/
OBJ_DIR		= obj/
DEP_DIR		= dep/
SRCS = main.cpp Harl.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.cpp=%.o))
DEPS = $(addprefix $(DEP_DIR), $(SRCS:%.cpp=%.d))

INCLUDES = -I./include
vpath %.cpp $(SRC_DIR)

all :  $(OBJ_DIR) $(DEP_DIR) $(NAME)

$(OBJ_DIR) $(DEP_DIR) :
	@mkdir -p $@

$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ -MF $(DEP_DIR)$*.d

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) $(DEPS) $(DEP_DIR) $(OBJ_DIR)
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

-include $(DEPS)

.PHONY : clean fclean re all test
