NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror 

MSRCS = ft_printf.c	\
		ft_print_c_type.c ft_print_s_type.c ft_print_p_type.c ft_print_di_type.c \
		ft_print_u_type.c ft_print_x_type.c \
		utils.c utils_1.c ft_print_percent_type.c

BSRCS = utils_len_bonus.c utils_bonus.c utils1_bonus.c utils2_bonus.c utils3_bonus.c utils4_bonus.c \
		utils5_bonus.c utils6_bonus.c utils7_bonus.c ft_strdup_bonus.c

MOBJS = $(MSRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

all: $(NAME) bonus

$(NAME): $(MOBJS)
	ar rc $(NAME) $(MOBJS) 

bonus: $(MOBJS) $(BOBJS)
	ar rc $(NAME) $(MOBJS) $(BOBJS)

clean:
	$(RM) $(MOBJS) $(BOBJS)

fclean:	clean
	$(RM) $(NAME) 
	
re: fclean all

test: re
	gcc MAIN.c libftprintf.a && ./a.out

.PHONY: all bonus clean fclean re