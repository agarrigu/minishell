# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: algarrig <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:02:43 by algarrig          #+#    #+#              #
#    Updated: 2024/04/21 21:09:05 by algarrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
DBNAME	= db_$(NAME)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DBFLAGS	= $(CFLAGS) -ggdb3
LFT		= libft.a
DBLFT	= dblibft.a
LFTDIR	= libft
LDLIB	= -lft -lreadline -L$(LFTDIR)
MAKE 	= make --no-print-directory

mainfiles = \
  cleaners/kvpr_cleaner.c \
  cleaners/token_cleaner.c \
  heredoc.c \
  env_util.c \
  isses.c \
  minishell.c \
  signal_util.c \
  token.c \
  tokenizer.c \
  tokenizers.c \
# mainfiles

builtinfiles = \
  cd.c \
  env.c \
  echo.c \
  unset.c \
  export.c \
  pwd.c \
# builtinfiles

SRCDIR		= src
BISRCDIR	= $(SRCDIR)/builtins
SRC			= $(addprefix $(SRCDIR)/,$(mainfiles))
BISRC		= $(addprefix $(BISRCDIR)/,$(builtinfiles))

.PHONY: all clean fclean re debug

.SILENT:

all: $(NAME)

debug: $(DBNAME)

$(NAME): $(SRC) $(BISRC) $(LFTDIR)/$(LFT)
	$(CC) $(CFLAGS) $^ $(LDLIB) -o $@

$(DBNAME): $(SRC) $(BISRC) $(LFTDIR)/$(DBLFT)
	$(CC) $(DBFLAGS) $^ $(LDLIB) -o $@

$(LFTDIR)/$(LFT): $(LFTDIR)
	$(MAKE) -C $(LFTDIR)

$(LFTDIR)/$(DBLFT): $(LFTDIR)
	$(MAKE) $(DBLFT) -C $(LFTDIR)

clean:
	$(MAKE) clean -C $(LFTDIR)
	
fclean: clean
	$(MAKE) fclean -C $(LFTDIR)
	$(RM) $(NAME) $(DBNAME)

re: fclean all
