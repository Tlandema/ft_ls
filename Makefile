# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlandema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 12:04:00 by tlandema          #+#    #+#              #
#    Updated: 2019/02/27 01:20:33 by tlandema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -g -g3 -Wall -Wextra -Werror

LIB = libft.a

LIB_PATH = libft

INC = includes

SRCS_PATH = srcs

SRCS =	main.c \
		acl.c \
		error.c \
		parsing.c \
		branching.c \
		listing.c \
		printing.c \
		padding.c \
		directoring.c \

OBJS_PATH = obj

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJS_PATH)/, $(OBJS))

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

define run_and_test
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) 2> $@.log; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(BACK_COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
	elif [ -s $@.log ]; then \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
	else  \
	printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
	fi; \
	cat $@.log; \
	rm -f $@.log; \
	exit $$RESULT
endef

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

all: $(NAME)

$(NAME): $(INC) $(D_OBJS) lib
	@$(call run_and_test, $(CC) $(CFLAGS) -o $(NAME) -I$(INC) $(D_OBJS) -L./$(LIB_PATH) -lft)

$(OBJS_PATH)/%.o: $(SRCS_PATH)/%.c
	@$(call run_and_test, $(CC) $(CFLAGS) -o $@ -c $< -I$(LIB_PATH))

lib :
	@$(call run_and_test, make -C libft)

clean:
	@$(call run_and_test, rm -f $(D_OBJS) && make clean -C libft)

fclean: clean
	@$(call run_and_test, rm -f $(NAME) && rm -f libft/libft.a)

re: fclean all
