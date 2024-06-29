# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srodrigo <srodrigo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/21 11:02:43 by algarrig          #+#    #+#              #
#    Updated: 2024/06/29 18:53:50 by algarrig         ###   ########.fr        #
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
  env_util.c \
  env_util2.c \
  heredoc.c \
  isses.c \
  minishell.c \
  signal_util.c \
  token.c \
  tokenizer.c \
  rules.c \
  rules2.c \
# mainfiles

cleanerfiles = \
  kvpr_cleaner.c \
  token_cleaner.c \
# cleanerfiles

tokenizerfiles = \
  tokenize_dollar.c \
  tokenize_dquote.c \
  tokenize_io_here.c \
  tokenize_opperator.c \
  tokenize_quote.c \
  tokenize_word.c \
# tokenizers

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

.PHONY: all clean fclean re debug

.SILENT:

all: $(NAME)

debug: $(DBNAME)

$(NAME): $(SRC) $(LFTDIR)/$(LFT)
	$(CC) $(CFLAGS) $^ $(LDLIB) -o $@

$(DBNAME): $(SRC) $(LFTDIR)/$(DBLFT)
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
