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

SRC  := ft_prompt.c \
ft_strncmp.c \
echo.c \

OBJ = $(SRC:%.c=%.o)
DEPS = $(OBJ:%.o=%.d)

##### RULES #####
all: $(NAME)

$(NAME) : $(OBJ)
	@echo
	@echo -e "${YELLOW} ----- compile -----${NC}"
	@echo
	$(CC) $(OBJ) -lreadline -o $(NAME) 

%.o : %.c Makefile
	$(CC) -c $< -o $@

clean:
	@echo
	@echo -e "${YELLOW} ----- clean...  -----${NC}"
	@echo
	rm -f $(OBJ)
	rm -f $(DEPS)
	@echo
	@echo -e "${YELLOW} ----- ✅ clean done -----${NC}"
	@echo

fclean :
	@echo
	@echo -e "${YELLOW} ----- clean...  -----${NC}"
	@echo
	make clean --no-print-directory
	rm -f $(NAME)
	@echo
	@echo -e "${YELLOW} ----- ✅ fclean done -----${NC}"
	@echo

re : fclean all 

# -include ${DEPS}

.PHONY: clean fclean all re
