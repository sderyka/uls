SRC = binary_search \
bubble_sort \
count_substr \
count_words \
del_strarr \
foreach \
get_char_index \
get_substr_index \
hex_to_nbr \
itoa \
nbr_to_hex \
pow \
sqrt \
print_strarr \
printchar \
print_unicode \
printint \
printstr \
\
\
str_reverse \
strcat \
strcmp \
strcpy \
strdel \
strdup \
strndup \
strlen \
\
strncpy \
strnew \
strstr \
strtrim \
swap_char \
del_extra_spaces \
strsplit \
strjoin \
file_to_str \
quicksort \
replace_substr \
read_line \
\
memset \
memcpy \
memccpy \
memcmp \
memchr \
memrchr \
memmem \
memmove \
realloc \
\
create_node \
pop_back \
pop_front \
push_back \
push_front \
list_size \
sort_list \
\
isspace \
isalpha \
isdigit \
swap_str \
add_char \
print_error \
atoi \
count_char \
char_in_str \
arrchar_new \
count_arr_el \
get_arr_index \


SRCS = $(addsuffix .c, $(addprefix mx_, $(SRC)))
OBJS = $(SRCS:.c=.o)
INC = libmx.h
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic


all: install clean

install:
	@cp $(addprefix src/, $(SRCS)) .
	@cp $(addprefix inc/, $(INC)) .
	@mkdir obj
	@clang $(CFLAGS) -c $(SRCS)
	@ar -rc libmx.a $(OBJS)
	@mv $(OBJS) ./obj

uninstall: clean
	@rm -rf libmx.a

clean:
	@rm -rf $(SRCS)
	@rm -rf $(INC)
	@rm -rf ./obj

reinstall: uninstall install

