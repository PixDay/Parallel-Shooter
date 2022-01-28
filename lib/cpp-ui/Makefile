##
## File name :
## Makefile
## File creator :
## Adrien Colombier
##

CC 		=	g++

SRCS	=	src/ui.cpp

OBJ	=	${SRCS:.cpp=.o}

%.o:	%.cpp
	@echo -e "\e[0;94mCompiled\t\e[0;95m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@${CC} -c $< -o $@ -I./include

NAME	=	libcpp-ui.a

all:	${NAME}

$(NAME):	${OBJ}
	@ar rc ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}
	@echo -e "\e[38;5;208mObjects:\e[38;5;124m\tDeleted\e[0m"

fclean:	clean
	@rm -f ${NAME}
	@echo -e "\e[0;92mEngine:\e[38;5;124m\t\tDeleted\e[0m"

re:	fclean all

.PHONY:	all clean fclean re