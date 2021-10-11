SRCNAME 	=	srcs/main.c				\
				srcs/parsing.c			\
				srcs/utils_0.c			\
				srcs/philo.c

SRCS 		= ${SRCNAME}

OBJS 		= ${SRCS:.c=.o}

NAME		= philo

CC 			= gcc -g #-fsanitize=address
RM 			= rm -f
CFLAGS 		= -pthread -Wall -Wextra -Werror

CGREEN		= \033[38;2;0;153;0m
CRED		= \033[0;31m
CYELLOW		= \033[0;33m
CGREY		= \033[38;2;128;128;128m
CEND		= \033[0m


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		@echo
		@echo "$(CYELLOW)Compilation of philo$(CEND)"
		@echo "$(CGREY)"
		${CC} -o ${NAME} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Compilation done !$(CEND)"
		@echo

all:		${NAME}

clean:
		@echo
		@echo "$(CYELLOW)Deleting .o files$(CEND)"
		@echo "$(CGREY)"
		${RM} ${OBJS}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

fclean:		clean
		@echo "$(CYELLOW)Deleting .o files and philo$(CEND)"
		@echo "$(CGREY)"
		${RM} ${NAME}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re
