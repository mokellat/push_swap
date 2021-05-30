CC = gcc -Wall -Werror -Wextra -o push_swap
DFLAGS = -fsanitize=address
NAME = push_swap

SRC = pa.c\
	  pb.c\
	  ra.c\
	  rb.c\
	  rr.c\
	  rra.c\
	  rrb.c\
	  rrr.c\
	  sa.c\
	  sb.c\
	  ss.c\
	  push_swap.c\
	  sort_three_num.c\
	  sort_five_num.c\
	  sort_hundred_num.c\

all : $(NAME)

$(NAME): $(SRC) push_swap.h
	cd Libft; make;
	$(CC) -g $(SRC) ./Libft/libft.a

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap

re : fclean all