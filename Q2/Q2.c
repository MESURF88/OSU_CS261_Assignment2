/* CS261- Assignment 1 - Q. 2*/
/* Name: Kevin Hill
 * Date: 07/07/2019
 * Solution description: swaps values of integer variables using pointers
 Input: Three integers.
 Output: Values of integers before and after swap.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 /*Function: foo
  * Description: returns a decremented value of input z and swaps addresses for pointers a and b
  * Parameters: two pointers and an integer value
  * Pre-Conditions: must be integer data types and first two inpputs addresses
  * Post-Conditions: N/A
  */
int foo(int* a, int* b, int c){
    /*Swap the addresses stored in the pointer variables a and b*/
	//initialize temp pointer for swapping addresses pointed to
	int* temp = a;
	a = b;

	//set address b points to, to original address of a
	b = temp;
    
    /*Decrement the value of integer variable c*/
	c -= 1;
    
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	//seed random numbers
	srand(time(0));
	//declare variables
	int x, y, z;
	x = rand() % 11;
	y = rand() % 11;
	z = rand() % 11;
    
    /*Print the values of x, y and z*/
	printf("x: %d, y: %d, z: %d\n",x,y,z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
	//store result of function in variable
	int c_result = foo(&x, &y, z);
    
    /*Print the values of x, y and z*/
	printf("x: %d, y: %d, z: %d\n", x, y, z);

    /*Print the value returned by foo*/
	printf("foo return value: %d\n", c_result);
 
    
    return 0;
}
    
   /*4a. The return value is different than the value of integer z because the function sends the data it 
   changes to the main method (outer function) when returning.
   4b. Changing the addresses the pointer points to has no
   effect on the base address of the original variables in the main method. This is because
   the function is only swapping its own private copies of the pointers.
   */


