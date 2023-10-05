NAME	= megaphone
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -std=c++98 -fsanitize=address

SRCS = megaphone.cpp
OBJS = $(SRCS:%.cpp=%.o)
DEPS = $(SRCS:%.cpp=%.d)

INCLUDES = -I./

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
	rm -f $(OBJS) $(DEPS)
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	cmake -DTEST=1 -S . -B build
	cmake --build build
	./build/megaphone-googletest
	# @mkdir build
	# cd build && cmake .. && make && ./megaphone-googletest

-include $(DEPS)

.PHONY: clean fclean re all test
