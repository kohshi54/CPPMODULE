NAME = phonebook
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address
SRCS = main.cpp phonebook.cpp contact.cpp

OBJS = $(SRCS:%.cpp=%.o)

INCLUDES = phonebook.hpp

all : $(NAME)

$(NAME) : $(OBJS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re all
