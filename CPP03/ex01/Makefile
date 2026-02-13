NAME 					= ScavTrap

C++						= c++ -std=c++98

STD_FLAGS 				= -Wall -Wextra -Werror

SRCS					= main.cpp \
						  ClapTrap.cpp \
						  ScavTrap.cpp
						  						  
OBJS					= ${SRCS:.cpp=.o}

REMOVE					= rm -f ${OBJS}

all:					${NAME}

${NAME}:
						${C++} ${SRCS} ${STD_FLAGS} -o ${NAME}

clean:					
						${REMOVE}

fclean:					clean
						rm -f ScavTrap
						
re:						fclean all

.PHONY:					all clean fclean re