#Compiler Options
C_FLAGS =
#Filenames
LIBFT_DIR := libft/
NAME := lem-in
SRCS := main_validation.c create_links.c pars_hex.c pars_utils.c structure_init.c structure_init_2.c
OBJECTS := $(SRCS:.c=.o)
HEADER = libft/libft.h
all: $(NAME)
$(NAME): $(OBJECTS)
	make -C $(LIBFT_DIR)	
	gcc -o $(NAME) $(OBJECTS) -L$(LIBFT_DIR) -lft
$(OBJECTS): %.o: %.c
	gcc $(C_FLAGS) -o $@ -c $<

clean:
	make clean -C $(LIBFT_DIR)
	/bin/rm -f $(OBJECTS)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	/bin/rm -f $(NAME)
	/bin/rm -f libft.a
re: fclean all

