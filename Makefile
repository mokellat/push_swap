CC = gcc -o push_swap
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
	  sort_five_hund_num.c\
	  sort_others.c\
	  utils.c\

all : $(NAME)

$(NAME): $(SRC) push_swap.h
	$(CC) -g $(SRC)

ARG100 = 0 6 5 4 7

run: all
	./push_swap $(ARG100)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap

re : fclean all
