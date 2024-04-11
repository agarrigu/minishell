CFLAGS	= -Wall -Wextra -Werror
DBCFLAGS= $(CFLAGS) -O0 -ggdb3
ARFLAGS	= rc
NAME	= libft.a
DBNAME	= dblibft.a
htfts	= \
  ft_hash_key \
  ft_htabclear \
  ft_htabgetval \
  ft_htabnew \
  ft_htabset \
# htfts
fts		= \
  ft_atoi \
  ft_atol \
  ft_bzero \
  ft_calloc \
  ft_concat \
  ft_dlstadd_back \
  ft_dlstadd_cond \
  ft_dlstadd_front \
  ft_dlstclear \
  ft_dlstdelone \
  ft_dlstiter \
  ft_dlstlast \
  ft_dlstmap \
  ft_dlstnew \
  ft_dlstsize \
  ft_freesplit \
  ft_isalnum \
  ft_isalpha \
  ft_isascii \
  ft_isdigit \
  ft_isprint \
  ft_itoa \
  ft_lstadd_back \
  ft_lstadd_front \
  ft_lstclear \
  ft_lstdelone \
  ft_lstiter \
  ft_lstlast \
  ft_lstmap \
  ft_lstnew \
  ft_memchr \
  ft_memcmp \
  ft_memcpy \
  ft_memmove \
  ft_memset \
  ft_printchar \
  ft_printf \
  ft_printnbr \
  ft_printptr \
  ft_printstr \
  ft_printubase \
  ft_putchar_fd \
  ft_putendl_fd \
  ft_putnbr_fd \
  ft_putstr_fd \
  ft_removedlst \
  ft_split \
  ft_strchr \
  ft_strcmp \
  ft_strcpy \
  ft_strdup \
  ft_stris \
  ft_striteri \
  ft_strjoin \
  ft_strlcat \
  ft_strlcpy \
  ft_strlen \
  ft_strmapi \
  ft_strncmp \
  ft_strnstr \
  ft_strrchr \
  ft_strtrim \
  ft_substr \
  ft_tolower \
  ft_toupper \
# fts
OBJ		= $(addsuffix .o,$(fts))
DBOBJ	= $(addsuffix db.o,$(fts))

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(DBNAME): $(DBOBJ)
	$(AR) $(ARFLAGS) $@ $^

%db.o : %.c
	$(CC) -c $(DBCFLAGS) $< -o $@

clean:
	$(RM) $(OBJ) $(DBOBJ)

fclean: clean
	$(RM) $(NAME) $(DBNAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
