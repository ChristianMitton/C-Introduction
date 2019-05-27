#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isAVowel(char);

int main(int argc, char** argv) {
	
	char result[500] = "";

	for(int i = 1; i < argc; i++ ) {
		char temp[500] = "";
		int lengthOfWord = strlen(argv[i]);
		
		strcat(temp, argv[i]);
		//temp[0] gives the first letter of the word
		//printf("TEMP IS: %s\n",temp);	
		
		if(isAVowel(temp[0]) == 1) {
			strcat(temp, "yay");
			strcat(result, temp);
		
		} else { //if its not a vowel
			char lettersBeforeVowel[500] = "";
			int positionOfVowel = lengthOfWord; //MAY BE BUG HERE
			char lettersAfterVowel[500] = "";
			//printf("LENGTH OF WORD: %d\n",lengthOfWord);
			for(int j = 0; j < lengthOfWord; j++) {
		
				//printf("inspecting temp[%d] which is %c...\n",j,temp[j]);
				if(isAVowel(temp[j]) == 0) { //if letter is not a vweol
					//char letter[10] = "";
					lettersBeforeVowel[strlen(lettersBeforeVowel) + 1] = '\0';
					lettersBeforeVowel[strlen(lettersBeforeVowel)] = temp[j];				
					//printf("Letter wasnt a vowel, adding it to %s\n", lettersBeforeVowel);
					//strcat(lettersBeforeVowel, temp[j]); didn't work
				} else {
					//printf("Letter is a vowel\n");
					positionOfVowel = j;
					break;
				}	

			}
			//printf("Letters before Vowel: %s\n", lettersBeforeVowel);
			//printf("position of vowel = %d\n",positionOfVowel);
			//printf("Length of Word: %d\n",lengthOfWord);
			//return 0;
			for(int j = positionOfVowel; j < lengthOfWord; j++) {
				lettersAfterVowel[strlen(lettersAfterVowel) + 1] = '\0';
				lettersAfterVowel[strlen(lettersAfterVowel)] = temp[j];				
				//strcat(lettersAfterVowel, temp[j]);
			}
			//return 0;
			//printf("Letters after Vowel: %s\n", lettersAfterVowel);
			strcat(lettersAfterVowel, lettersBeforeVowel);
			strcat(result, lettersAfterVowel);
			strcat(result, "ay");
		}

		if(i + 1 == argc) {
			strcat(result, "\0");
		} else {
			strcat(result, " ");
		}
		
	}
	printf("%s\n",result);
 
	return 0;
}

int isAVowel(char letter) {
	if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
		return 1;
	}
	return 0;
}
