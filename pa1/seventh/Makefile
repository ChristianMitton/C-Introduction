all: seven

seven: seventh.c
	gcc -Wall -Werror -fsanitize=address -std=c99 seventh.c -o seventh

clean:
	rm -rf seventh
