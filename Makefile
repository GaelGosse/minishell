##### COLOR #####
BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

##### VAR #####
NAME   = minishell
CC     = gcc -Wall -Werror -Wextra -g3 
# -MMD -MP

SRC  := main_mael.c \
lib/ft_strncmp.c \
built_in/echo.c \

SRC_MAEL  := main_mael.c \
lib/ft_strncmp.c \
built_in/echo.c \

OBJ = $(SRC:%.c=%.o)
OBJS_MAEL = $(SRC_MAEL:%.c=%.o)
DEPS = $(OBJ:%.o=%.d)

OBJ_DIR := objs_mael/
OBJ_MAEL = $(addprefix $(OBJ_DIR), ${SRC_MAEL:.c=.o})

##### RULES #####
all: $(NAME)

$(NAME) : $(OBJ)
	@echo
	@echo -e "${CYAN} ----- compile -----${NC}"
	@echo
	$(CC) $(OBJ) -lreadline -o $(NAME) 

# ${OBJ_DIR}%.o : %.c

${OBJ_DIR}%.o : %.c Makefile
	$(CC) -c $< -o $@

test_mael:
	@echo
	@echo -e "${CYAN} ----- compile -----${NC}"
	@echo
	$(CC) $(OBJ_MAEL) -lreadline -o $(NAME)

clean:
	@echo
	@echo -e "${CYAN} ----- clean...  -----${NC}"
	@echo
	rm -f $(OBJ_MAEL)
	rm -f $(OBJ)
	rm -f $(DEPS)
	@echo
	@echo -e "${CYAN} ----- ✅ clean done -----${NC}"
	@echo

fclean :
	@echo
	@echo -e "${CYAN} ----- clean...  -----${NC}"
	@echo
	make clean --no-print-directory
	rm -f $(NAME)
	@echo
	@echo -e "${CYAN} ----- ✅ fclean done -----${NC}"
	@echo

re : fclean all 

# -include ${DEPS}

.PHONY: clean fclean all re
