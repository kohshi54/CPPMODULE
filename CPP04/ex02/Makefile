NAME = Animal
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 
# -fsanitize=address -g -Wshadow -Wno-shadow
DEPFLAGS = -MMD -MP -MF $(DEP_DIR)$*.d

SRC_DIR		= src/
OBJ_DIR		= obj/
DEP_DIR		= dep/
SRCS = main.cpp AAnimal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:%.cpp=%.o))
DEPS = $(addprefix $(DEP_DIR), $(SRCS:%.cpp=%.d))

INCLUDES = -I./include
vpath %.cpp $(SRC_DIR)

all :  $(OBJ_DIR) $(DEP_DIR) $(NAME)

$(OBJ_DIR) $(DEP_DIR) :
	@mkdir -p $@

ifeq ($(DEBUG),1)
$(OBJ_DIR)%.o: %.cpp
	$(CC) -DDEBUG $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
else ifeq ($(ERROR),1)
$(OBJ_DIR)%.o: %.cpp
	$(CC) -DERROR $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
else
$(OBJ_DIR)%.o: %.cpp
	$(CC) $(CXXFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@
endif

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -rf $(OBJS) $(DEPS) $(DEP_DIR) $(OBJ_DIR)
	rm -rf build

fclean : clean
	rm -f $(NAME)

re : fclean all

debug : clean
	@make DEBUG=1

error : clean
	@make ERROR=1

# test:
# 	cmake -S . -B build
# 	cmake --build build
# 	./build/DiamondTrap-googletest

-include $(DEPS)

.PHONY : clean fclean re all debug error