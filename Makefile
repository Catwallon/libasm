NAME = libasm.a
TESTS_NAME = tests

SRCS = src/ft_strlen.s src/ft_strcpy.s src/ft_strcmp.s \
	src/ft_write.s src/ft_read.s src/ft_strdup.s
OBJS = $(SRCS:src/%.s=obj/%.o)

TESTS_SRCS = src/main.c

all: $(NAME) $(TESTS_NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(TESTS_NAME): $(TESTS_SRCS) $(NAME)
	gcc -o $@ $^

obj/%.o: src/%.s
	@mkdir -p obj
	nasm -f elf64 -o $@ $<

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME) $(TESTS_NAME)

re: fclean all

.PHONY: all clean fclean re
