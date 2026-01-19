
SRC_FILES = main.c \
 
BONUS_FILES =

SRC = $(addprefix src/, ${SRC_FILES})
BONUS_SRC = $(addprefix src/, ${BONUS_FILES})

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror -ggdb

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}
TEST_OBJ = ${TEST_SRC:.c=.o}

NAME = cub3D

LIB_DIRS = 
LIB_NAMES = 

LIB_PATHS = $(addprefix -L, $(LIB_DIRS))
LIB_FLAGS = $(addprefix -l, $(LIB_NAMES))

LDFLAGS = $(LIB_PATHS) $(LIB_FLAGS)

.PHONY: all clean fclean re

.c.o:
	${COMPILER} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all: ${NAME}

${NAME}: ${OBJ}
	$(foreach dir, ${LIB_DIRS}, ${MAKE} -C ${dir};)
	${COMPILER} ${CFLAGS} -o ${NAME} ${OBJ} ${LDFLAGS}

bonus: ${OBJ} ${BONUS_OBJ}
	$(foreach dir, ${LIB_DIRS}, ${MAKE} -C ${dir} bonus;)
	${COMPILER} ${CFLAGS} -o ${NAME} ${OBJ} ${BONUS_OBJ} ${LDFLAGS}

clean_self:
	rm -f ${OBJ} ${BONUS_OBJ}

clean: clean_self
	$(foreach dir, ${LIB_DIRS}, ${MAKE} -C ${dir} clean;)

fclean: clean_self
	$(foreach dir, ${LIB_DIRS}, ${MAKE} -C ${dir} fclean;)
	rm -f ${NAME}
