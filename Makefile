NAME    := libft.a
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCDIR  := inc

MAND_SRCS := \
  src/part1/ft_strlen.c \
  src/part1/ft_strchr.c \
  src/part2/ft_substr.c \
  src/part2/ft_strjoin.c \
  src/part2/ft_strtrim.c \
  src/part2/ft_putchar.fd \
  src/part2/ft_putstr.fd \
  src/part2/ft_strmapi.c \
  src/part2/ft_striteri.c \

#   src/part2/ft_strdup.c \
#   src/part1/ft_strlcpy.c \
#   src/part1/ft_strlcat.c \
#   src/part1/ft_memcpy.c \
#   src/part1/ft_memmove.c \
#   src/part1/ft_memset.c \
#   src/part1/ft_bzero.c \
#   src/part1/ft_memchr.c \
#   src/part1/ft_memcmp.c \
#   src/part1/ft_atoi.c \
#   src/part1/ft_calloc.c \

BONUS_SRCS := \
#   src/bonus/ft_lstnew_bonus.c \
#   src/bonus/ft_lstadd_front_bonus.c \
#   src/bonus/ft_lstsize_bonus.c \
#   src/bonus/ft_lstlast_bonus.c \
#   src/bonus/ft_lstadd_back_bonus.c \
#   src/bonus/ft_lstdelone_bonus.c \
#   src/bonus/ft_lstclear_bonus.c \
#   src/bonus/ft_lstiter_bonus.c \
#   src/bonus/ft_lstmap_bonus.c

OBJS       := $(MAND_SRCS:.c=.o)
BONUS_OBJS := $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus test

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

bonus: $(OBJS) $(BONUS_OBJS)
	@ar rcs $(NAME) $^

clean:
	@rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	@rm -f $(NAME) a.out

re: fclean all

test: re
	@$(CC) $(CFLAGS) -I$(INCDIR) tests/$(TEST) $(NAME) -o test_exec
	@echo "Running $(TEST)..."
	@./test_exec


