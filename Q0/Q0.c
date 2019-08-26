/* CS261- Assignment 1 - Q. 0*/
/*Name: Kevin Hill
 * Date: 07/07/2019
 * Solution description: prints values and address of specific variables.
 Input: Random value of an integer between 0 and 10.
 Output: Literal values of variables in integers and their addresses.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 /*Function: fooA
  * Description: prints out addresses of pointers and value
  * Parameters: pointer to value
  * Pre-Conditions: must be pointer
  * Post-Conditions: N/A
  */
void fooA(int* iptr) {

	/*Print the value and address of the integer pointed to by iptr*/
	printf("\n\nThe value pointed to by iptr is: %d", *iptr);
	printf("\nThe address pointed to by iptr: %p", iptr);

	/*Increment the value of the integer pointed to by iptr by 5*/
	*iptr += 5;

	/*Print the address of iptr itself*/
	printf("\nThe address of iptr itself: %p", &iptr);

	/*Dummy variable, ignore the warning*/
	int c = 5;
}

/*Function: fooB
 * Description: prints out addresses of pointers and value
 * Parameters: pointer to value
 * Pre-Conditions: must be pointer
 * Post-Conditions: N/A
 */
void fooB(int* jptr) {

	/*Print the value and address of the integer pointed to by jptr*/
	printf("\n\nThe value pointed to by jptr is: %d", *jptr);
	printf("\nThe address pointed to by jptr: %p", jptr);

	/*Decrement the address by 1 pointed to by jptr using jptr */
	jptr = jptr - 1;

	/*Print the address of jptr itself*/
	printf("\nThe address of jptr itself is: %p", &jptr);
}


int main() {

	//seed random number
	srand(time(0));

	/*Declare an integer x and initialize it randomly to a value in [0,10] */
	int x;
	x = rand() % 11;

	/*Print the value and address of x*/
	printf("\nThe value of x is: %d", x);
	printf("\nThe address of x is: %p", &x);

	/*Call fooA() with the address of x*/
	fooA(&x);

	/*Print the value of x*/
	printf("\n\nThe value of x now is: %d", x);
	/*value of integer x, was changed because the address where the original value of x was passed to the function and the the value at the address was changed using the indiection operator on its pointer.*/

	/*Call fooB() with the address of x*/
	fooB(&x);

	/*Print the value and address of x*/
	printf("\n\nThe value of x now is: %d", x);
	printf("\nThe address of x now is: %p", &x);
	printf("\n");
	/*value of integer x, was not changed because the address where the pointer pointed to was decremented instead of the actual integer's address itself. The integer x's value at its original address was not modified.*/

	return 0;
}


