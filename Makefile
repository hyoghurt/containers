INCLUDE			= include
NAME			= a.out
SRC				= main_vector.cpp

SRCDIR			= src
OBJDIR			= obj
OBJ				= $(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))
CC				= clang++
CFLAGS			= -Wall -Wextra -Werror

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME) 

$(OBJDIR):			
				mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.cpp | $(OBJDIR)
				$(CC) -std=c++98 -I$(INCLUDE) -c -MD $< -o $@

include $(wildcard $(OBJDIR)/*.d)

all:			$(NAME)

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME) test

test:
				bash ./test.sh

re:				fclean all

.PHONY:			all clean fclean re
