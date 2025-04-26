#include <stdio.h>
#include <stdlib.h>
#include "route-records.h"


int main( int argc, char *argv[] )
{
    /* 1. Declare variables here */
    RouteRecord* recArr = NULL;
    int recordCT = 0;
    char userInput[40];
     
    /* 2. Check command line arguments here. If a command line argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
    if (argc != 2) {
      printf("Missing file name.");
      return 0;
    }

    /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
    FILE* fptr = fopen(argv[1], "r"); 

    /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
    if (fptr == NULL) {
      printf("Could not open file.");
      return 0;
    }

    // 5. Do the following to load the records into an array of RouteRecords
  
   	//5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count, to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer.
    recArr = createRecords(fptr);
    rewind(fptr);

  	//5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. Recall that not all records in the original CSV file will be entered into the array. Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
    recordCT = fillRecords(recArr, fptr); 

   	//5.3 Close the the file.
    fclose(fptr);
    
    //GRADER!!! Look here for example of working recusrive call.    
    //printf("\n%d\n", findAirlineRoute(recArr, recordCT, "TPA", "ZRH", "8R", 0));

    // 6. Create an infinite loop that will do the following:
    for(;;) {
      //6.1 Call printMenu()
      printMenu();
      //6.2 Ask the user to input a value for the menu
      for (;;) {
        scanf("%s", userInput); 
        int inputCheck = atoi(userInput); 
        if (inputCheck != 0) {
          break;
        }
        // 	6.3 Handle the case in which a non-integer value is entered
        printf("Please enter a valid input\n");
      }
      
      // 	6.4 Create a switch/case statement to handle all the menu options
      //  6.4.1 Each option requires the user to enter a search key
      switch(atoi(userInput) - 1) {
        char key1[5];
        char key2[5];

        case ROUTE:
          printf("Enter origin: ");
          scanf("%s", key1);
          printf("Enter destintion: ");
          scanf("%s", key2);
          printf("Searching by route...\n");
          searchRecords(recArr, recordCT, key1, key2, atoi(userInput) - 1);
          break;

        case ORIGIN:
          printf("Enter origin: ");
          scanf("%s", key1);
          printf("Searching by origin...\n");
          searchRecords(recArr, recordCT, key1, key2, atoi(userInput) - 1);
          break;

        case DESTINATION:
          printf("Enter destintion: ");
          scanf("%s", key1);
          printf("Searching by destination...\n");
          searchRecords(recArr, recordCT, key1, key2, atoi(userInput) - 1);
          break;

        case AIRLINE:
          printf("Enter airline: ");
          scanf("%s", key1);
          printf("Searching by airline...\n");
          searchRecords(recArr, recordCT, key1, key2, atoi(userInput) - 1);
          break;
        case 4:
        //	6.4.2 Quit needs to free the array
          printf("Good Bye!");
          free(recArr);
          return 0;
    }
  } 
}
