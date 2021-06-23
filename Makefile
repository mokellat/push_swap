FLAGS = -Wall -Wextra -Werror
DFLAGS = -fsanitize=address
NAME = push_swap
CHECKER = checker

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
	  sort_three_num.c\
	  sort_five_num.c\
	  sort_hundred_num.c\
	  sort_five_hund_num.c\
	  sort_others.c\
	  utils.c\
	  utils1.c\
	  errors_check.c\
	  get_next_line.c\

all : $(NAME) $(CHECKER)

$(NAME): $(SRC) push_swap.c
	gcc -D DISPLAY=1 $(FLAGS) -o $(NAME) push_swap.c $(SRC) -g

$(CHECKER): $(SRC) checker.c
	gcc -D DISPLAY=0 $(FLAGS) -o $(CHECKER) checker.c $(SRC) -g

ARG100 = 0 6 5 4 7

run: all
	./push_swap $(ARG100)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap
	rm -rf $(CHECKER)
	rm -rf checker

re : fclean all
