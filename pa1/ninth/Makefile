all: nine

nine: ninth.c
	gcc -Wall -Werror -fsanitize=address -std=c99 ninth.c -o ninth

clean:
	rm -rf ninth
