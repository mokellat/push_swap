CC = gcc
AR = ar
NAME = libft.a
LIB = libft.h
flags = -Wall -Wextra -Werror
FILES =    ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c  ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcat.c ft_split.c put_split.c

all: $(NAME)
	    @echo "Creating the library . . . . ."
$(NAME):
	    @$(CC) $(flags) -c $(FILES) -I $(LIB)
		    @$(AR) rc $(NAME) *.o
			    @ranlib $(NAME)
clean:
	    @echo "Cleaning *.o files . . . . ."
		    @rm -rf *.o
fclean: clean
	    @echo "Cleaning all files . . . . ."
		    @rm -rf *.a
bonus:
		@echo "don't exist . . . . ."

re: fclean all
	    @echo "Recreating the library . . . . ."
