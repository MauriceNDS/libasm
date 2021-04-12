NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_read.s \
		ft_write.s \
		ft_list_size_bonus.s \
		ft_list_push_front_bonus.s \
		ft_list_remove_if_bonus.s \
		ft_list_sort_bonus.s

OBJS = $(SRCS:.s=.o)

%.o	: %.s
	nasm/nasm -f macho64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

try: all
	gcc -g -Wall -Wextra -Werror libasm.a main.c -o try_libasm

fclean: clean
	rm -f $(NAME)
	rm -f try_libasm
	rm -f test

re: fclean all