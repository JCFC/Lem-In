GCC = gcc
NAME = lem-in

CFLAGS = -Wall -Wextra -Werror
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC_NAME =	ft_lem_in.c\
			ft_atoi2.c\
			ft_start_parsing_rooms.c\
			ft_nbword.c\
			ft_free.c\
			ft_push_list_end.c\
			ft_check_double.c\
			ft_parsing_link.c\
			ft_path_finding1.c\
			ft_connect_list.c\
			ft_print_way.c\
			ft_sort.c\
			ft_cleaning_way.c\
			ft_trip.c\
			ft_create_ants.c\
			ft_loop.c\
			ft_atoi3.c\

SRCDIR = SRC
OBJDIR = OBJ
INCDIR = -I INC/
INCLUDES = INC/ft_lem_in.h

LIBRARY = printf/libprintf.a
LIBRARY_L = printf/libft/libft.a

SRC = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJDIR)/, $(OBJ_NAME))

All : $(NAME)

$(NAME) : $(OBJ) $(LIBRARY)
	$(GCC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBRARY) $(LIBRARY_L)
	@echo "\033[0;32mLEM-IN EXE: DONE\033[0m"

$(LIBRARY) :
	make -C printf

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(INCLUDES)
	$(GCC) $(INCDIR) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)
	make -C printf clean

fclean : clean
	rm -rf $(NAME)
	make -C printf fclean

re : fclean All
