/* CS261- Assignment 1 - Q. 3*/
/*Name: Kevin Hill
 * Date: 07/07/2019
 * Solution description: converts input string of two spaced words into camel case, checks if at least one space 
 * between word combinations or if all a number and symbol combination then validates and prints out "invalid input string".
 * Input: string of at least two distinct letter combinations
 * Output: camel case word combination or if not valid prints "invalid input string"
 */

#include <stdio.h>
#include <stdlib.h>


 /*Function: toUpperCase
  * Description: makes a character to upper case
  * Parameters: char value
  * Pre-Conditions: must be a lower case char value initially and within ascii range
  * Post-Conditions: N/A
  */
char toUpperCase(char ch){
  /*Convert ch to upper case, assuming it is in lower case currently*/
	return ch - 32;

}

/*Function: toLowerCase
 * Description: makes a character to lower case
 * Parameters: char value
 * Pre-Conditions: must be a upper case char value initially and within ascii range
 * Post-Conditions: N/A
 */
char toLowerCase(char ch){
  /*Convert ch to lower case, assuming it is in upper case currently*/  
	return ch + 32;

}

/*Function: stringLength
 * Description: returns a strings length not including null terminator
 * Parameters: string array
 * Pre-Conditions: must be a character array
 * Post-Conditions: N/A
 */
int stringLength(char s[]) {
   /*Return the length of the string*/
	int size_num = 0;
	//loop until reach null-terminator
	while (s[size_num]!='\0')
	{
		size_num++;
	}
	return size_num;
}

/*Function: camelCase
 * Description: changes the input string to camelCase and validates input
 * Parameters: pointer to array of characters
 * Pre-Conditions: must be a pointer to a char
 * Post-Conditions: N/A
 */
void camelCase(char* word){
	/*Convert to camelCase*/
	//initialize skip analysis variables
	int skip = 0;
	//initialize ascii starting point variables
	int uppera = 65;
	int lowera = 97;
	//initialize change char, letter total and letter amount variable
	int change_c = 0;
	int letter_total = 0;
	int letter_num = 0;
	char letter;
	
	//initialize starting string value
	int size = stringLength(word);

	//remove spaces, numbers and symbols and replace with underscores
	for (int i = 0; i < size; i++)
	{
		//initialize letter variable
		letter = word[i];
		//reset change char and ascii starting points
		uppera = 65;
		lowera = 97;
		change_c = 0;
		for (int j = 0; j < 25; j++)
		{
			if (letter + 0 == uppera || letter + 0 == lowera)
			{
				change_c++;
				letter_total++;
				//convert capital letters to lowercase
				if (letter + 0 < 91)
				{
					word[i] = toLowerCase(word[i]);
				}
			}
			uppera++;
			lowera++;
		}
		//if not a letter change to an underscore
		if (change_c == 0)
		{
			word[i] = '_';
		}
		if (word[i] == '_' && letter_total == 0)
		{//remove leading underscores
			//move the next index back to first index
			for (int j = 0; j < size-1; j++)
			{
				word[j] = word[j + 1];
			}
			i--;
			word[size - 1] = '\0';
			size = stringLength(word);//get new string size
		}

	}
	//additional modifications if extra underscores at end
	for (int i = 0; i < size; i++)
	{
		if (letter_num >= letter_total)
		{//remove trailing underscores
			word[size - 1] = '\0';
			i--;
			size = stringLength(word);//get new string size
		}
		if (word[i] != '_')
		{
			letter_num++;
		}
	}
	
	//validate input, if all underscores or no underscores or single letter then invalid
	int under_count = 0;
	for (int i = 0; i < size; i++)
	{
		if (word[i] == '_')
		{
			under_count++;
		}
	}
	if (under_count == 0 || under_count == size || letter_total == 1)
	{
		//remove all characters from ouput string and print invalid input
		printf("\ninvalid input string\n");
		int index = 0;
		while (word[index] != '\0')
		{
			word[index] = ' ';
			index++;
		}
		skip = 1;
	}

	//if valid input continue and remove underscores and convert to camelcase
	if (skip == 0)
	{
		int j;//declare iterator j
		//Make into camel case
		for (int i = 0; i < size; i++)
		{
			if (word[i] == '_' && word[i + 1] != '_')
			{//if next character letter, capitalize
				//move the next index back to current index
				j = i;//initialize current index
				while (word[j]!='\0')
				{
					word[j] = word[j + 1];
					j++;
				}
				i--;
				word[size - 1] = '\0';
				size = stringLength(word);//get new string size
				
				//capitalize letter
				word[i+1] = toUpperCase(word[i+1]);
			}
			else if (word[i] == '_')
			{//remove redundant underscore
				//move the next index back to current index
				j = i;//initialize current index
				while (word[j] != '\0')
				{
					word[j] = word[j+1];
					j++;
				}
				i--;
				word[size - 1] = '\0';
				size = stringLength(word);//get new string size
			}
		}
	}
	
}

int main(){
	//Initialize string variable
	char input[40];

	/*Read the string from the keyboard*/
	printf("Enter a string to be analyzed (max 40 characters including null-terminator):\n");
	scanf("%[^\n]", input);
	
	/*Call camelCase*/
	camelCase(&input);
	
	
	/*Print the new string*/
	printf("\nOutput string below:\n%s\n", input);
	
	
	return 0;
}

