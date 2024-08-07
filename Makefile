# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:02:43 by algarrig          #+#    #+#              #
#    Updated: 2024/08/07 22:57:35 by srodrigo         ###   ########.fr        #
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
  arguments.c \
  builtins.c \
  command.c \
  command_line.c \
  command_name.c \
  env_util.c \
  env_util2.c \
  expander.c \
  expander_util.c \
  heredoc.c \
  isses.c \
  minishell.c \
  redirections.c \
  rules.c \
  rules2.c \
  signal_util.c \
  token.c \
  token2.c \
  tokenizer.c \
# mainfiles

cleanerfiles = \
  kvpr_cleaner.c \
  token_cleaner.c \
  command_cleaner.c \
  complete_cleaner.c \
# cleanerfiles

builtinfiles = \
  cd.c \
  env.c \
  echo.c \
  unset.c \
  export.c \
  pwd.c \
  exit.c \
# builtinfiles

SRCDIR	= src
CLNDIR	= $(SRCDIR)/cleaners
TKNDIR	= $(SRCDIR)/tokenizers
BIDIR	= $(SRCDIR)/builtins
SRC		= $(addprefix $(SRCDIR)/,$(mainfiles))
SRC		+= $(addprefix $(CLNDIR)/,$(cleanerfiles))
SRC		+= $(addprefix $(TKNDIR)/,$(tokenizerfiles))
SRC		+= $(addprefix $(BIDIR)/,$(builtinfiles))
OBJ		= $(SRC:.c=.o)

.PHONY: all clean fclean re debug

.SILENT:

all: $(NAME)

debug: $(DBNAME)

$(NAME): $(OBJ) $(LFTDIR)/$(LFT)
	$(CC) $(CFLAGS) $^ $(LDLIB) -o $@

$(DBNAME): $(SRC) $(LFTDIR)/$(DBLFT)
	$(CC) $(DBFLAGS) $^ $(LDLIB) -o $@

$(LFTDIR)/$(LFT): $(LFTDIR)
	$(MAKE) -C $(LFTDIR)

$(LFTDIR)/$(DBLFT): $(LFTDIR)
	$(MAKE) $(DBLFT) -C $(LFTDIR)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C $(LFTDIR)
	
fclean: clean
	$(MAKE) fclean -C $(LFTDIR)
	$(RM) $(NAME) $(DBNAME)

re: fclean all
