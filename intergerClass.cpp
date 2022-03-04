//-------------------------------------------------------------------------------------------------
//File Name: 
//Associated file: 
//Members:
//  1 Constructor : Default
//  Destructor : Free's the list to open memory back up
//-------------------------------------------------------------------------------------------------

//Include the header file for the integerClass
#include "integerClass.h"

//-------------------------------------------------------------------------------------------------
//CreateList - Creates an empty linked list
//-------------------------------------------------------------------------------------------------
void integerClassType::CreateList(void)
{

	//Create an empty list
	start = NULL;

}

//-------------------------------------------------------------------------------------------------
//SetCountOfDigits - determine how many digits are in a number
//-------------------------------------------------------------------------------------------------
int integerClassType::SetCountOfDigits(int aNumber)
{

	//Create an integer value for the count of digits
	int countOfDigits = 1;

	//Take the absolute value of the number
	aNumber = abs(aNumber);

	//While loop to continue dividing until there are no more digits
	while (aNumber >= 10)
	{

		//Divide the number by 10 again
		aNumber /= 10;

		//Increment the count
		countOfDigits++;

	}

	//Return the count
	return countOfDigits;

}

//-------------------------------------------------------------------------------------------------
//FindPtrAtEndOFList - finds the last pointer in the list
//-------------------------------------------------------------------------------------------------
nodePtr integerClassType::FindPtrAtEndOfList()
{

    //Create a node pointer
    nodePtr aNode;

    //Assign node to a value
    aNode = start;

    //While loop to find the end of the list
    while (aNode != NULL)
    {

        //Assign aNode to the next pointer
        aNode = aNode->link;

    }

    //Return the last pointer in the list
    return aNode;

}

//-------------------------------------------------------------------------------------------------
//FindLargestDigitCount - finds the largest digit count in the list out of all the numbers
//-------------------------------------------------------------------------------------------------
int integerClassType::FindLargestDigitCount()
{

    //Create a node pointer
    nodePtr aNode = start;

    //Create a variable to hold the highest digit count
    int count = 0;

    //While loop to loop through every node and find the largest digit count
    while (aNode != NULL)
    {

        //Compare the digit count to the other highest count
        if (aNode->data.countNodeType > count)
        {

            //Set the new count
            count = aNode->data.countNodeType;

        }

        //Assign aNode to the next pointer
        aNode = aNode->link;

    }

    //Return the highest digit count
    return count;

}

//-------------------------------------------------------------------------------------------------
//GetStart - returns the start pointer value
//-------------------------------------------------------------------------------------------------
nodePtr integerClassType::GetStart()
{

    //Return the starting pointer
    return start;

}

//-------------------------------------------------------------------------------------------------
//GetNodeValue - return the data from the nodeType pointer passed in
//-------------------------------------------------------------------------------------------------
nodeType integerClassType::GetNodeValue(nodePtr node)
{

    //Return the data from the pointer passed in
    return node->data;

}

//-------------------------------------------------------------------------------------------------
//GetNextPointer - returns the pointer to the next node in the list
//-------------------------------------------------------------------------------------------------
nodePtr integerClassType::GetNextPointer(nodePtr node)
{

    //If the value of node is not NULL
    if (node != NULL)
    {

        //Return the link to the next node
        return node->link;

    }
    else
    {

        //Return NULL
        return NULL;

    }

}

//-------------------------------------------------------------------------------------------------
//GetCountOfNumbersInList - returns the count of the numbers in the list
//-------------------------------------------------------------------------------------------------
int integerClassType::GetCountOfNumberInList()
{

	//Pointer to loop through the list to print out all nodes
	nodePtr aNode = start;

	//Set the count of the numbers in the list to 0
	countOfNumberList = 0;

	//Loop through all of the nodes to find the count
	while (aNode != NULL)
	{

		//Increment the count
		countOfNumberList++;

		//Move the pointer along
		aNode = aNode->link;

	}

    //Return the count of the numbers in the list
    return countOfNumberList;

}

//-------------------------------------------------------------------------------------------------
//CreateANode - create a new node in the list
//-------------------------------------------------------------------------------------------------
nodePtr integerClassType::CreateANode(int aNumber)
{

    //Create a node
    nodePtr ptr = new node;

    //Assign an integer number
    ptr->data.numberNodeType = aNumber;

    //Assign the count of the digits of that number
    ptr->data.countNodeType = SetCountOfDigits(aNumber);

    //Set the link to null
    ptr->link = NULL;

    //Return the pointer
    return ptr;

}

//-------------------------------------------------------------------------------------------------
//AddToList - add a new node to the end of the linked list
//-------------------------------------------------------------------------------------------------
void integerClassType::AddToList(nodePtr ptr)
{

	//Create a pointer to keep track as the previous
	nodePtr previous = NULL;

    //Create a pointer to be the end of the list
    nodePtr endOfList = start;

    //Determine if the linked list is empty first
    if (IsEmpty())
    {

        //Set the pointer to be the starting node
        start = ptr;

    }
    else
    {

        //Go to the end of the list and add the node
        while (endOfList != NULL)
        {

			//Set the previous to the current node
			previous = endOfList;

            //Move the pointer along
            endOfList = endOfList->link;

        }

		if (previous != NULL)
		{

			//Add the pointer
			previous->link = ptr;

		}
		else
		{

			//Set the start link to the pointer
			start->link = ptr;

		}

    }

}

//-------------------------------------------------------------------------------------------------
//IsEmpty - returns if the linked list in empty or not
//-------------------------------------------------------------------------------------------------
bool integerClassType::IsEmpty()
{

    //Return if the linked list is empty based on the start value
    return (start == NULL);

}

//-------------------------------------------------------------------------------------------------
//FillList - reads in the integer values from the input file and inserts at the end of the list
//-------------------------------------------------------------------------------------------------
void integerClassType::FillList(ifstream& fin)
{

    //Create a temporary integer number variable
    int tempInt;

    //Input the first value (primer)
    fin >> tempInt;

    //While loop to go to the end of the input file
    while (fin)
    {

        //Add the number to the end of the linked list
        AddToList(CreateANode(tempInt));

        //Scan in the next number (changer)
        fin >> tempInt;

    }

}

//-------------------------------------------------------------------------------------------------
//PrintList - print the list to the output file
//-------------------------------------------------------------------------------------------------
void integerClassType::PrintList(ofstream& fout)
{

    //Pointer to loop through the list to print out all nodes
    nodePtr aNode = start;

    //If the list is not empty
    if (!(IsEmpty()))
    {

         //Output divider to the output file
        PrintDivider(fout, '~', 100);

        //For loop to print the header for the digit
        for (int index = 0; index < 5; index++)
        {

            //Print the header for 5 different digits
            fout << right << setfill(' ') << setw(20) << "Digit";

        }

	    //Move the cursor down a line
	    fout << endl;

	    //Print the header for the number and count
	    for (int index = 0; index < 5; index++)
	    {

		    //Print the header for 5 different numbers and counts
		    fout << setw(10) << "number" << setw(10) << "Count";

	    }

	    //Move the cursor down a line
	    fout << endl;

        //Output divider to the output file
        PrintDivider(fout, '~', 100);

        //While not at the end of the linked list
        while (aNode != NULL)
        {

            //For loop to print 5 numbers and digit counts per line
            for (int index = 0; index < 5; index++)
            {

                //Print the number with its digit count
                fout << setw(10) << aNode->data.numberNodeType << setw(10) 
                    << SetCountOfDigits(aNode->data.numberNodeType);

                //Increment the count of the numbers in the list
                aNode->data.countNodeType;

			    //Set the pointer to the next node
			    aNode = aNode->link;

			    //If the list is at it's end
			    if (aNode == NULL)
			    {

				    //Pop out of the for loop
				    index = 5;

				    //Move the cursor to the next line
				    fout << endl;

				    //Output divider to the output file
				    PrintDivider(fout, '~', 100);

			    }

            }
       
            //Move the cursor to the next line
            fout << endl;

        }

    }

}

//-------------------------------------------------------------------------------------------------
//PrintCountOfNUmbersInList - print the cunt of the numbers to the output file
//-------------------------------------------------------------------------------------------------
void integerClassType::PrintCountOfNumbersInList(ofstream& fout, int aNumber)
{

    //Print the count of the numbers in the list
    fout << "The number of nodes in the list is: " << aNumber << endl;

}

//-------------------------------------------------------------------------------------------------
//PrintNumberInAPosition - print a number found in a certain position
//-------------------------------------------------------------------------------------------------
void integerClassType::PrintNumberInAPosition(ofstream& fout, int position)
{

    //Pointer to be used to find the position
    nodePtr aNode = start;

	//Create an integer count variable
	int count = 0;

	//Create a boolean variable for if the number was found
	bool found = false;

    //If the list is empty
    if (IsEmpty())
    {

        //Print an error message
        fout << "The list is empty and therefore cannot be printed" << endl;

    }
    else if (position < 1)
    {

        //Print an error message
        fout << "Position " << position << " does not exists in the list, no number to print" 
            << endl;

    }
    else
    {

        //While loop to loop through the linked list and find the number at a given position
		while (aNode != NULL && found == false)
		{

			//If the count is equal to the position
			if (count == position)
			{

				//Print the number at the position
				fout << "In the linked list at position " << position << " the number " 
					<< aNode->data.numberNodeType << " was found" << endl;

				//Set found to true
				found = true;

			}
			else
			{

				//Increment the count
				count++;
				
				//Move the pointer along
				aNode = aNode->link;

			}

		}

    }

}

//-------------------------------------------------------------------------------------------------
//FindSmallest - find the smallest value in the linked list
//-------------------------------------------------------------------------------------------------
int integerClassType::FindSmallest()
{

    //Create a pointer for the linked list being used to find the smallest number
    nodePtr aNode = start;

    //Create a number that will hold the value of the smallest number in the linked list
    int smallestNum = 1000;

    //While loop to loop through all of the nodes linked list
    while (aNode != NULL)
    {

        //If there is a new smallest number found
        if (aNode->data.numberNodeType < smallestNum)
        {

            //Set the new smallest number 
            smallestNum = aNode->data.numberNodeType;

        }

        //Move the pointer along
        aNode = aNode->link;

    }

    //Return the smallest number
    return smallestNum;

}

//-------------------------------------------------------------------------------------------------
//FindLargest - find the largest value in the linked list
//-------------------------------------------------------------------------------------------------
int integerClassType::FindLargest()
{

    //Create a pointer for the linked list being used to find the largest number
    nodePtr aNode = start;

    //Create a number that will hold the value of the largest number in the linked list
    int largestNum = -10000;

    //While loop to loop through all of the nodes linked list
    while (aNode != NULL)
    {

        //If there is a new largest number found
        if (aNode->data.numberNodeType > largestNum)
        {

            //Set the new largest number 
            largestNum = aNode->data.numberNodeType;

        }

        //Move the pointer along
        aNode = aNode->link;

    }

    //Return the smallest number
    return largestNum;

}

//-------------------------------------------------------------------------------------------------
//PrintPositionOfNumber - print the position of the smallest and largest numbers
//-------------------------------------------------------------------------------------------------
void integerClassType::PrintPositionOfNumber(ofstream& fout, int aNumber)
{

	//Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode = start;

    //Create an integer for the count
    int count = 0;

    //While loop to loop through the linked list
    while (aNode != NULL)
    {

        //If statement to find the largest number
	    if (aNode->data.numberNodeType == aNumber && aNumber > 0)
	    {

		    //Print the largest number
            fout << "The number " << aNumber << " was found in position " << count << endl;

	    }
        else if (aNode->data.numberNodeType == aNumber && aNumber < 0)
	    {

		    //Print the smallest number
		    fout << "The number " << aNumber << " was found in position " << count << endl;
				 
	    }

        //Increment the count
        count++;

        //Move the pointer along
        aNode = aNode->link;

    }

}

//-------------------------------------------------------------------------------------------------
//FindNumberInList - finds the position of a number in the list and returns if it was found
//-------------------------------------------------------------------------------------------------
void integerClassType::FindNumberInList(int searchNumber, int& position, bool& found)
{

    //Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode = start;

    //Set the position to zero
    position = 0;

    //Set the found boolean to false
    found = false;

    //Create a count variable to be where the search number is found
    int count = 1;

    //While loop to find the first instance of a number passed in
    while (aNode != NULL && found != true)
    {

        //If the number is equal
        if (searchNumber == aNode->data.numberNodeType)
        {

            //Set the position to the current node
            position = count;

            //Set the found boolean to true
            found = true;

        }

        //Increment the count
        count++;

        //Move the pointer along
        aNode = aNode->link;

    }

}

//-------------------------------------------------------------------------------------------------
//CalculateSum - calculate the sum of the numbers in the linked list
//-------------------------------------------------------------------------------------------------
int integerClassType::CalculateSum()
{

    //Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode = start;

    //Create an integer to hold the value of the sum of the list
    int sum = 0;

    //While loop to loop through the whole linked list
    while (aNode != NULL)
    {

        //Add the current number to the sum
        sum += aNode->data.numberNodeType;

        //Move the pointer along
        aNode = aNode->link;

    }

    //Return the sum
    return sum;

}

//-------------------------------------------------------------------------------------------------
//CalculateAverage - calculate the average of the numbers in the linked list
//-------------------------------------------------------------------------------------------------
double integerClassType::CalculateAverage()
{

    //Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode = start;

    //Create an integer to hold the value of the average of the linked list numbers
    double average = 0.0;

    //While loop to loop through the whole linked list
    while (aNode != NULL)
    {

        //Add the current number to the average
        average += aNode->data.numberNodeType;

        //Move the pointer along
        aNode = aNode->link;

    }

    //Divide the average by the count of the numbers in the list
    average /= (GetCountOfNumberInList());

    //Return the average
    return average;

}

//-------------------------------------------------------------------------------------------------
//PrintByDigitCount - prints the numbers in order of the digit count
//-------------------------------------------------------------------------------------------------
void integerClassType::PrintByDigitCount(ofstream& fout)
{

	//Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode = start;

    //Print the divider to the output file 
    PrintDivider(fout, '-', 100);

    //Print the centered header to the output file
    PrintCenteredMessage(fout, "Print By Digit Count", 100);

    //Print the divider to the output file 
    PrintDivider(fout, '-', 100);

	//For loop to loop the digit by their count
	for (int index = 1; index < FindLargestDigitCount(); index++)
	{

		//Print the divider to the output file 
		PrintDivider(fout, '-', 40);

		//Print the header to the output file
		PrintCenteredMessage(fout, "Numbers with " + to_string(aNode->data.countNodeType) 
			+ " digits", 40);

		//While loop to loop through all of the nodes
		while (aNode != NULL)
		{

			//If the current digit count is equal to index
			if (aNode->data.countNodeType == index)
			{

				//Print the number
				fout << right << setfill(' ') << setw(15) << aNode->data.numberNodeType << endl;

			}

			//Move the pointer along
			aNode = aNode->link;

		}

		//Print the divider to the output file 
		PrintDivider(fout, '-', 40);

	}

}

//-------------------------------------------------------------------------------------------------
//FreeTheList - free the memory that the nodes were taking up
//-------------------------------------------------------------------------------------------------
void integerClassType::FreeTheList()
{

    //Create a pointer for the linked list to print the smallest and largest numbers
	nodePtr aNode;

    //While the list is not empty
    while (!IsEmpty())
    {

        //Assign aNode to start
        aNode = start;

        //Assign the value of start which will be the next node
        start = start->link;

        //Assign the current node a value of NULL
        aNode->link = NULL;

        //Delete the current node and free the memory allocated to it
        delete aNode;

    }

}
