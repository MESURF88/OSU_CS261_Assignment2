/* CS261- Assignment 1 - Q. 1*/
/* Name: Kevin Hill
 * Date: 07/07/2019
 * Solution description: uses structs to create an array of student data and prints and generates array.
 Input: Array of student objects with random values for id and score.
 Output: Array of 10 student objects and their id and scores, minimum and maximum and average scores.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>



struct student{
	int id;
	int score;
};

/*Function: allocate
 * Description: makes the array of structs for 10 students
 * Parameters: N/A
 * Pre-Conditions: struct must be defined
 * Post-Conditions: returns struct
 */
struct student* allocate(){
     /*Allocate memory for ten students*/
	struct student* record = malloc(10 * sizeof(struct student));
     /*Return the pointer*/
	return record;
}

/*Function: generate
 * Description: builds an array of students with ranom unique ids and scores
 * Parameters: array of student structs
 * Pre-Conditions: must be 10 elements long
 * Post-Conditions: N/A
 */
void generate(struct student* students){
     /*Generate random and unique IDs and random scores for ten students, 
IDs being between 1 and 10, scores between 0 and 100*/
	for (int i=0; i < 10; i++)
	{
		//variable for value that is not unique if above 0 repeat by brute force method
		int match = 0;
	
		do {
			//reset match in scope of function
			match = 0;
			//random id
			students[i].id = (rand() % 10) + 1;
			for (int j = 0; j < i; j++)
			{
				if (students[j].id == students[i].id)
				{
					match++;
				}
			}
		} while (match > 0);

		//random score
		students[i].score = rand() % 101;
	}

}

/*Function: output
 * Description: prints out each unordered student id and score
 * Parameters: array of student structs
 * Pre-Conditions: must be 10 elements long
 * Post-Conditions: N/A
 */
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
	for (int i = 0; i < 10; i++)
	{
		printf("\n%d %d", students[i].id, students[i].score); 
	}
}

/*Function: summary
 * Description: prints out minimum and maximum and average score of the ten students
 * Parameters: array of student structs
 * Pre-Conditions: must be 10 elements long
 * Post-Conditions: N/A
 */
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the 
ten students*/
	//set min and max values in scope of functions
	int max = 0;
	int min = 100;
	//set sum variables to zero initially
	int sum = 0;
	for (int i=0; i < 10; i++)
	{
		if (students[i].score > max)
		{
			max = students[i].score;
		}
		if (students[i].score <= min)
		{
			min = students[i].score;
		}
		//add up total scores
		sum += students[i].score;
	}
	printf("\nMinimum: %d Maximum: %d Average: %8f\n", min, max, (sum/10.0));
     
}

/*Function: summary
 * Description: frees up memory of student structs
 * Parameters: array of student structs
 * Pre-Conditions: must have more than one element in array of structs
 * Post-Conditions: N/A
 */
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	//check if array of student structures is not null
	if (stud != 0)
	{
		//free space on heap for array of student structures
		free(stud);
		stud = 0;
	}
}

int main(){
	//seed random numbers
	srand(time(0));

    struct student* stud = NULL;
    
    /*Call allocate*/
	stud = allocate();
    
    /*Call generate*/
	generate(stud);
    
    /*Call output*/
	output(stud);
    
    /*Call summary*/
	summary(stud);

    /*Call deallocate*/
	deallocate(stud);

    return 0;
}

