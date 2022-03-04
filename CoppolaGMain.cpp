//----------------------------------------------------------------------------------------------------------------------
//Lab 3 Grading Block
//Name:  Giovanni Coppola
//Lab Grade: 
//----------------------------------------------------------------------------------------------------------------------
//Total Possible Points -------------------------------------------------------------------------------------------> 200
//Total Points lost ----------------------------------------------------------------------------------------------->
//Lab Grade -------------------------------------------------------------------------------------------------------> 
//----------------------------------------------------------------------------------------------------------------------
//General Comments:
//  
//  
//  
//  
//----------------------------------------------------------------------------------------------------------------------
//Standard Requirements
//  Requirements met as specified for the
//  Which includes but not limited to:
//    Program Creation
//    File Requirements
//    Documentation
//    Documentation as required for Class Objects
//    Constants
//    Variables 
//    Code
//Comments:
//  
//  
//  
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//Program Specifications
//-Standards.h included with the preprocessor directives
//-Course Required header & CPP file
//Comments:
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//
//
//-integerClassType
//  Meets specs of the UML
//  Methods correctly named, defined, & created in header & CPP File, friends included
//  Constructor & Destructor included
//Comments:
//
//
//
//
//
//
//
//Points Lost ----------------------------------------------------------------------------------------------------->

//----------------------------------------------------------------------------------------------------------------------
//
//Main
// 3 objects instantiated, list positiveList, negativeList
// Input & Output files opened, precision set
// Course heading printed to screen & output file
// 1. list object created with data from the input file
// input file closed
// 2. Output the list with a heading formatted in columns as shown in the instructions
//    Output the count of numbers in the list
// 3. Output the position of a number as shown formatted in the instructions, testing with -1, 0, 39, 46
// 4. Find the smallest & largest values in the list
//    Output the smallest & largest with a heading formatted as shown in the instructions
//    If the list is empty, output a message that no values were found for both smallest & largest
// 5. Find an number in the list, testing with 98999 & 17
//    Output the number & the position found for each test value or a not found message
// 6. Calculate the sum & average of the list
//    Output the sum & average with a heading formatted as shown in the instructions
// 7. Create a positive & negative list from the original list if the list is not empty
//    0 is not included in either the positive or negative list
//    Output the positive list with a heading formatted as shown in the instructions
//    Output the negative list with a heading formatted as shown in the instructions
// 8. Print a list of numbers by the digits counts from 1 to largest number of digits in the list
// Close the input & output files
//Comment:
//
//
//
//
//Points Lost ----------------------------------------------------------------------------------------------------->
//----------------------------------------------------------------------------------------------------------------------

//Include the standards header file
#include "Standards.h"

//Include the integer class header file
#include "integerClass.h"

int main(void)
{

	//Instantiate an object of the type IntegerClassType for the entire list
	integerClassType list;

	//Instantiate an object of the type IntegerClassType for the positive numbers
	integerClassType positiveList;

	//Instantiate an object of the type IntegerClassType for the negative numbers
	integerClassType negativeList;

	//Create a pointer to traverse a linked list
	nodePtr tempPtr;

	//Create a node pointer for the new list
	nodePtr newPtr;

	//declare int variables
	//Integer to be the smallest number of the list
	int smallestListNum;
	//Integer to be the largest number of the list
	int largestListNum;
    //Integer variable for aNumber to be used for testing
    int aNumber;
    //Integer variable for the position of aNumber, if found
    int aNumberPosition;
    //Integer variable to be the sum of the nodes in the linked list
    int sumOfNodes = 0;
    //Integer variable to be the count for the positive and negative section
    int count = 1;

	//declare bool variables
    //Set a boolean variable to determine if aNumber was found in the list or not
    bool aNumberFound;

	//declare double variables
    //Double variable for the average of all the numbers in the linked list
    double avergeOfNodes = 0.0;

	//declare file variables
    //Declare the input file stream
	ifstream fin;
	//Declare the output file stream
	ofstream fout;
	//Set the name of the input file
	string finName = "Numbers.txt";
	//Set the name of the output file
	string foutName = "results.txt";

	//Initial set up of program & List--------------------------------------------------------------
	//Open the two files
	//Open the input file
	fin.open(finName);
	//Open the output file
	fout.open(foutName);

	//Set up fixed point output for the file
	fout << fixed << setprecision(2);

	//Output the course required header and file messages to the screen & the output file
	//Output the heading to the screen
	PrintDivider('-', 100);
	PrintCourseHeading(COLLEGE, PROGRAM, NAME, 100);
	PrintDivider('-', 100);

	//Output the heading to the output file
	PrintDivider(fout, '-', 100);
	PrintCourseHeading(fout, COLLEGE, PROGRAM, NAME, 100);
	PrintDivider(fout, '-', 100);

	//Print the name of the input file to the screen
	PrintFileName("Input file name: " + finName);

	//Print the name of the output file to the screen
	PrintFileName("Output file name: " + foutName);

	//Print the name of the input file to the output file
	PrintFileName(fout, "Input file name: " + finName);

	//Print the name of the output file to the output file
	PrintFileName(fout, "Output file name: " + foutName);

	//Fill the linked list with the numbers from the input file
	list.FillList(fin);

	//Close the input file
	fin.close();

	//Clear the input file flags
	fin.clear();

	//End of Initial set up of a program & list-----------------------------------------------------

	//Output of the Linked List read in-------------------------------------------------------------

	//Output the heading for the original link list to the output file
	//Output divider to the output file
	PrintDivider(fout, '-', 100);
	//Print the centered header to the output file
	PrintCenteredMessage(fout, "The original list as it was read in: ", 100);
	//Output divider to the output file
	PrintDivider(fout, '-', 100);
	//Output the list to the output file
	list.PrintList(fout);

	//Output to number of nodes in the original list to the output file
	list.PrintCountOfNumbersInList(fout, list.GetCountOfNumberInList());
	//Output the divider to the output file
	PrintDivider(fout, '~', 100);

	//End of Output of Linked List read in----------------------------------------------------------


	//List Print a node value in a position---------------------------------------------------------

	//Print the divider to the output file
	PrintDivider(fout, '-', 100);
	//Print the centered header to the output file
	PrintCenteredMessage(fout, "Search & Print Position of Number in List", 100);
	//Print the divider to the output file
	PrintDivider(fout, '-', 100);

	//Try to output the element at -1 position
	list.PrintNumberInAPosition(fout, -1);

	//Output the divider to the output file
	PrintDivider(fout, '-', 100);

	//Output the element at 0 position to the output file
	list.PrintNumberInAPosition(fout, 0);

	//Output the divider to the output file
	PrintDivider(fout, '-', 100);

	//Output the element at 39 position to the output file
	list.PrintNumberInAPosition(fout, 39);

	//Output the divider to the output file
	PrintDivider(fout, '-', 100);

	//Output the element at 46 position to the output file
	list.PrintNumberInAPosition(fout, 46);

	//Output the divider to the output file
	PrintDivider(fout, '-', 100);

	//End of List print of a node value in a position-----------------------------------------------


	//Smallest & Largest values in a list-----------------------------------------------------------

	//Determine smallest & smallest message based on the start pointer
    smallestListNum = list.FindSmallest();
		
	//Output the divider to the output file
	PrintDivider(fout, '-', 100);
	
	//Determine the largest & largest message based on the start of the list
    largestListNum = list.FindLargest();
	
	//Output of the Linked List after access--------------------------------------------------------

	//Output the heading for the original link list to the output file
    //Print the centered header to the output file
	PrintCenteredMessage(fout, "Smallest & largest Values", 100);
	//Print the divider to the output file
	PrintDivider(fout, '-', 100);

    //Print the smallest number
    fout << "Smallest value is " << smallestListNum << endl;
    //Print the position of the smallest number
    list.PrintPositionOfNumber(fout, smallestListNum);

    //Move the cursor down a line
    fout << endl;

    //Print the largest number
    fout << "Largest value is " << largestListNum << endl;
    //Print the position of the largest number
    list.PrintPositionOfNumber(fout, largestListNum);
	
	//Output of the Linked List after access--------------------------------------------------------

	//Output the heading for the original link list to the output file
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Linked list after smallest and largest", 100);
    PrintDivider(fout, '-', 100);

	//Output the list to the output file
    list.PrintList(fout);

	//Output the number of nodes in the original list to the output file
    list.PrintCountOfNumbersInList(fout, list.GetCountOfNumberInList());

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//End of output of the Linked List after access-------------------------------------------------	


	//Find Testing of the Linked List---------------------------------------------------------------

    //Print the header for the numbers found in the linked list
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Find Numbers in List", 100);
    PrintDivider(fout, '-', 100);

	//Set aNumber to a number not in the linked list
    aNumber = 98999;

	//Find the number in the linked list
    list.FindNumberInList(80, aNumberPosition, aNumberFound);

	//Determine message based on found
    if (aNumberFound == false)
    {

        //Print that the number was not found
        fout << "The number " << aNumber << " was not found in the linked list" << endl;

    }
    else
    {

        //Print the number was found and the position of it
        fout << "The number " << aNumber << " was found in position " << aNumberPosition <<
            "in the linked list" << endl;

    }

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//Set aNumber to a number in the linked list, 17
    aNumber = 17;

	//Find the position of the number in the linked list
    list.FindNumberInList(aNumber, aNumberPosition, aNumberFound);

	//Determine message to output based on found
    if (aNumberFound == false)
    {

        //Print that the number was not found
        fout << "The number " << aNumber << " was not found in the linked list" << endl;

    }
    else
    {

        //Print the number was found and the position of it
        fout << "The number " << aNumber << " was found in position " << aNumberPosition <<
            " in the linked list" << endl;

    }

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//End of Find Testing of the Linked List--------------------------------------------------------


	//Sum & Average of the Linked List--------------------------------------------------------------

    //Output the header for the sum and average of the nodes in the linked list
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Sum & Average of the List", 100);
    PrintDivider(fout, '-', 100);

	//Calculate the sum of all numbers in the linked list
    sumOfNodes = list.CalculateSum();

	//Output the sum of the list of numbers to the output file
    fout << "The sum of all the numbers in the list is " << sumOfNodes << endl;

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//Calculate the average of all numbers in the linked list
    avergeOfNodes = list.CalculateAverage();

	//Output the average of the list of numbers to the output file, displaying 2 decimals
    fout << "The average of all the numbers in the list is " << avergeOfNodes << endl;

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//End of Sum & average of the Linked List-------------------------------------------------------

	//Output of the Linked List after manipulation of the Linked List-------------------------------

	//Output the heading for the original link list to the output file
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Linked list after sum and average", 100);
    PrintDivider(fout, '-', 100);

	//Output the list to the output file
    list.PrintList(fout);

	//Output the number of nodes in the original list to the output file
    list.PrintCountOfNumbersInList(fout, list.GetCountOfNumberInList());

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//End of Output of Linked List after manipulation-----------------------------------------------

	//Empty the linked list
    list.FreeTheList();

	//Output the Linked List after the list is emptied----------------------------------------------

	//Output the heading for the original link list to the output file
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Linked list after freeing the list", 100);
    PrintDivider(fout, '-', 100);

	//Output the list to the output file
    list.PrintList(fout);

	//Output to number of nodes in the original list to the output file
    list.PrintCountOfNumbersInList(fout, list.GetCountOfNumberInList());

	//Output the divider to the output file
    PrintDivider(fout, '-', 100);

	//End of Output of Linked List after the list is emptied----------------------------------------


	//Fill the list again with the input data-------------------------------------------------------

	//Open the input file again
    fin.open("Numbers.txt");

	//Re - Fill the linked list with the data
    list.FillList(fin);

	//End Fill the list again with the input data---------------------------------------------------


	//Create the positive and negative linked list--------------------------------------------------

	//Determine if there is data in the original linked list based on start & create positive
	//& negative list  (0 is neither positive nor negative)

    //Set the temporary node pointer to traverse the list
    tempPtr = list.GetStart();

    //Use a while loop to loop through the whole list and find whether or not the current
    //  value of the list is positive or negative
    while (tempPtr != NULL)
    {

        //If the current node is positive
        if (tempPtr->data.numberNodeType > 0)
        {

            //Add the number to the positive list
            positiveList.AddToList(positiveList.CreateANode(tempPtr->data.numberNodeType));

        }
        else if (tempPtr->data.numberNodeType < 0)
        {

            //Add the number to the negative list
            negativeList.AddToList(negativeList.CreateANode(tempPtr->data.numberNodeType));

        }
        
        //Move the pointer along
        tempPtr = tempPtr->link;

    }


	//End of Positive List, & Negative List---------------------------------------------------------


	//Output the original linked list, the positive list & the negative list------------------------
    //Heading for the original linked list
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "Original linked list", 100);
    PrintDivider(fout, '-', 100);

    //Print the list
    list.PrintList(fout);

    //Heading to print the positive list
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "The Positive Linked List", 100);
    PrintDivider(fout, '-', 100);

    //Print the positive list
    positiveList.PrintList(fout);

    //Print the number of nodes in the list
    positiveList.PrintCountOfNumbersInList(fout, positiveList.GetCountOfNumberInList());

    //Print the divider to the output file
    PrintDivider(fout, '-', 100);

    //Move the cursor down a line
    fout << endl;

    //Heading to print the negative list
    PrintDivider(fout, '-', 100);
    PrintCenteredMessage(fout, "The Negative Linked List", 100);
    PrintDivider(fout, '-', 100);

    //Print the negative list
    negativeList.PrintList(fout);

    //Print the number of nodes in the list
    negativeList.PrintCountOfNumbersInList(fout, negativeList.GetCountOfNumberInList());

    //Print the divider to the output file
    PrintDivider(fout, '-', 100);

	//Close the files
    fin.close();
    fout.close();

	return 0;
}