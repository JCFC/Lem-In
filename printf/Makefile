CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_NAME =	ft_j.c ft_l.c ft_h.c ft_z.c ft_modify.c ft_dm.c\
			ft_modify_unsigned.c ft_free_lst.c\
			ft_d.c ft_c.c ft_p.c ft_om.c ft_u.c ft_um.c ft_x.c ft_xm.c\
			ft_percent.c ft_cm.c ft_write_u.c \
			ft_reset_flags.c ft_strchr_p.c ft_fill_lst.c\
			ft_sm.c ft_modify_unsigned_dm.c\
			ft_hash.c ft_check_va.c ft_printf.c ft_llitoa_base.c\
			ft_ullitoa_base.c ft_create_wo_l.c\
			ft_less.c ft_number.c ft_plus.c ft_precision.c ft_space.c\
			ft_fill_conv.c ft_s.c ft_o.c\

OBJET_NAME = $(SRC_NAME:.c=.o)

LIBRARY = libprintf.a
NAME = libftprintf.a
LIBFT = libft.a

SRCDIR = SRC
OBJDIR = OBJ
HEADDIR = INC

SRC = $(addprefix $(SRCDIR)/, $(SRC_NAME))
OBJ = $(addprefix $(OBJDIR)/, $(OBJET_NAME))

all : $(LIBFT) $(LIBRARY)

$(NAME) : $(LIBFT) $(LIBRARY)
	@libtool -static -o $(NAME) libft/$(LIBFT) $(LIBRARY)

$(LIBFT) :
	@make -C libft

$(LIBRARY) : $(OBJ)
	@ar rc $(LIBRARY) $(OBJ)
	@echo "\033[0;32mLIBRARY PRINTF: DONE\033[0m"

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CLFAGS) -o $@ -c $<

clean :
	@rm -rf $(OBJ)
	@make -C libft/ clean
	@echo "\033[0;31mDELETE OBJETS: DONE\033[0m"

fclean :
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@rm -rf $(LIBRARY)
	@make -C libft/ fclean
	@echo "\033[0;31mDELETE OBJETS AND LIBS: DONE\033[0m"

re : fclean all
