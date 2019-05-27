all: four

four: fourth.c
	gcc -Wall -Werror -fsanitize=address -std=c99 fourth.c -o fourth

clean:
	rm -rf fourth

