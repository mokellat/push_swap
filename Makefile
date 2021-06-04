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

ARG100 = 17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44 36 72 18 73 16 64 47 90 65 87 77 59 61 45 30 53 54 66 76 28 37 95 70 91 27 6 50 43 81 3 46 13 31 89 88 96 38 62 33 10 15 79 20 42 40 85 26 34 71 49 32 22 58 56

run: all
	./push_swap $(ARG100) 

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap

re : fclean all