#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	
	char result[500] = "";
	
	for(int i = 1; i < argc; i++) {
		char temp[500] = "";
		int length = strlen(argv[i]);
		strcat(temp, argv[i]);
		
		char lastChar;
		char lastCharAsString[10] = "";

		for(int j = 0; j < length; j++) {
			if((length-j) == 1) {
				lastChar = temp[j];
			}
		}
		//printf("Last char: %c\n", lastChar);
		lastCharAsString[strlen(lastCharAsString) + 1] = '\0';
		lastCharAsString[strlen(lastCharAsString)] = lastChar;
		strcat(result, lastCharAsString);
		strcat(result, "\0");
	}

	printf("%s\n", result);
		
	return 0;
}
