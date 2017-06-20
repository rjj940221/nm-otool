NAME_NM		=	ft_nm
INC			=	-I ./libft -I Includes
LIBS		=	-L libft -lft
CFLAGS		=	-Wall -Wextra -Werror -g3 $(INC)
LFLAGS		=	$(INC) $(LIBS)
CC			=	gcc
LD			=	gcc

SRC			=	ft_nm.c ft_extract_file.c ft_read_mach.c
OBJ			=	./build/ft_nm.o ./build/ft_extract_file.o ./build/ft_read_mach.o

all: lft $(NAME_NM)

./build/ft_nm.o : ft_nm.c
	@mkdir -p  build
	$(CC) $(CFLAGS) -c ft_nm.c -o ./build/ft_nm.o

./build/ft_extract_file.o : ft_extract_file.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c ft_extract_file.c -o ./build/ft_extract_file.o

./build/ft_read_mach.o : ft_read_mach.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c ft_read_mach.c -o ./build/ft_read_mach.o

$(NAME_NM): $(OBJ)
	@echo "\033[92m    LD    $(NAME_NM)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME_NM)
	@rm -f libft_malloc.so

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -rf build
	@make -s -C libft clean

fclean: clean
	@echo "\033[92m    RM    $(NAME_NM)\033[0m"
	@rm -f $(NAME_NM)
	@rm -rf $(NAME_NM).dSYM
	@make -s -C libft fclean

re: fclean all

lft:
	@make -s -C libft all
