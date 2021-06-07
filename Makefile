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

all : $(NAME)

$(NAME): $(SRC) push_swap.h
	cd Libft; make;
	$(CC) -g $(SRC) ./Libft/libft.a

ARG100 = -57 -96 -87 -92 38 590 88 41 20 68 58 48 2 5 64 39 76 16 51 14 61 90 83 32 3 79 80 1 8 91 22 29 47 17 31 23 44 82 78 55 93 86 84 99 37 73 72 24 12 9 36 30 62 33 26 69 28 97 75 25 15 89 85 70 19 66 45 67 49 11 54 4 40 77 81 42 63 18 35 46 34 10 56 74 50 13 95 7 6 100 65 21 94 71 53 27 52 60 43 98

run: all
	./push_swap $(ARG100)

clean :
	rm -rf $(OBJECT)

fclean : clean
	rm -rf $(NAME)
	rm -rf push_swap

re : fclean all