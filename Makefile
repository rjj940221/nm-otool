NAME_NM		=	ft_nm
NAME_OTOOL  =   ft_otool
INC			=	-I ./libft -I Includes
LIBS		=	-L libft -lft
CFLAGS		=	-Wall -Wextra -Werror -g3 $(INC)
LFLAGS		=	$(INC) $(LIBS)
CC			=	gcc
LD			=	gcc

SRC_NM			=	fat.c ft_extract_file.c ft_nm.c ft_read_mach_32.c ft_read_mach_64.c mach.c \
					revirce_fat.c revirce_mach_32.c revirce_mach_64.c

OBJ_NM			=	./build/fat.o  ./build/ft_extract_file.o ./build/ft_nm.o \
					./build/ft_read_mach_32.o ./build/ft_read_mach_64.o ./build/mach.o ./build/revirce_fat.o \
					./build/revirce_mach_32.o ./build/revirce_mach_64.o

SRC_OTOOL		=	fat.c ft_extract_file.c ft_otool.c ft_read_mach_32.c ft_read_mach_64.c mach.c \
					revirce_fat.c revirce_mach_32.c revirce_mach_64.c

OBJ_OTOOL		=	./build/fat.o ./build/ft_extract_file.o ./build/ft_otool.o \
					./build/ft_read_mach_32.o ./build/ft_read_mach_64.o ./build/mach.o ./build/revirce_fat.o \
					./build/revirce_mach_32.o ./build/revirce_mach_64.o

all: lft $(NAME_NM) $(NAME_OTOOL)

./build/fat.o : fat.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c fat.c -o ./build/fat.o

./build/ft_extract_file.o : ft_extract_file.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c ft_extract_file.c -o ./build/ft_extract_file.o

./build/ft_nm.o : ft_nm.c
	@mkdir -p  build
	$(CC) $(CFLAGS) -c ft_nm.c -o ./build/ft_nm.o

./build/ft_otool.o : ft_otool.c
	@mkdir -p  build
	$(CC) $(CFLAGS) -c ft_otool.c -o ./build/ft_otool.o

./build/ft_read_mach_32.o : ft_read_mach_32.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c ft_read_mach_32.c -o ./build/ft_read_mach_32.o

./build/ft_read_mach_64.o : ft_read_mach_64.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c ft_read_mach_64.c -o ./build/ft_read_mach_64.o

./build/mach.o : mach.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c mach.c -o ./build/mach.o

./build/revirce_fat.o : revirce_fat.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c revirce_fat.c -o ./build/revirce_fat.o

./build/revirce_mach_32.o : revirce_mach_32.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c revirce_mach_32.c -o ./build/revirce_mach_32.o

./build/revirce_mach_64.o : revirce_mach_64.c
	@mkdir -p build
	$(CC) $(CFLAGS) -c revirce_mach_64.c -o ./build/revirce_mach_64.o


$(NAME_NM): $(OBJ_NM)
	@echo "\033[92m    LD    $(NAME_NM)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME_NM)

$(NAME_OTOOL): $(OBJ_OTOOL)
	@echo "\033[92m    LD    $(NAME_OTOOL)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME_OTOOL)

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
