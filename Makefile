SRCNAME 	=	srcs/main.c						\
				srcs/parser.c					\
				srcs/philo_id.c					\
				srcs/philo.c					\
				srcs/time_routine.c				\
				srcs/utils.c					\
				srcs/philo_action/eating.c		\
				srcs/philo_action/thinking.c	\
				srcs/philo_action/sleeping.c

SRCS 		= ${SRCNAME}

OBJS 		= ${SRCS:.c=.o}

NAME		= philo

CC 			= gcc -g
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

fclean:		clean
		@echo "$(CYELLOW)Deleting .o files and philo$(CEND)"
		@echo "$(CGREY)"
		${RM} ${NAME}
		@echo "$(CEND)"
		@echo "$(CGREEN)Deleting done !$(CEND)"
		@echo

re: 		fclean all

c: 			all clean

.PHONY: 	clean fclean all re
