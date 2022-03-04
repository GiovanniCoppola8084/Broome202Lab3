//-------------------------------------------------------------------------------------------------
//File Name: 
//Associated file: 
//Members:
//  1 Constructor : Default
//  Friends: PrintDivider and PrintCenteredMessage
//  Destructor : Free's the list to open the memory back up
//-------------------------------------------------------------------------------------------------

#ifndef integerClass_h
#define integerClass_h

//Include the standards header file
#include "Standards.h"

//Create the structure for nodeType
struct nodeType
{

	//Create an integer number
	int numberNodeType;

	//Create an integer count of the digits
	int countNodeType = 0;

};

//Create the structure for node
struct node
{

	//Create an instance of nodeType
	nodeType data;

	//Create a link to the node
	node* link;

};

//Create a typedef for a node
typedef node* nodePtr;

//Create the integerClassType class
class integerClassType
{

public:

	//Constructor - calls CreateList method
	integerClassType() { CreateList(); }

	/*Getter methods*/
	//GetStart method
	nodePtr GetStart();
	//GetNodeValue method
	nodeType GetNodeValue(nodePtr node);
	//GetNextPointer method
	nodePtr GetNextPointer(nodePtr node);
	//GetCountOfNumberInList method
	int GetCountOfNumberInList();

	//CreateANode method
	nodePtr CreateANode(int aNumber);

	//AddToList method
	void AddToList(nodePtr ptr);

	//IsEmpty method
	bool IsEmpty();

	//FillList method
	void FillList(ifstream& fin);

	//PrintList method
	void PrintList(ofstream& fout);

	//PrintCountOfNumebrsInList method
	void PrintCountOfNumbersInList(ofstream& fout, int aNumber);

	//PrintPositionOfNumber method
	void PrintPositionOfNumber(ofstream& fout, int aNumber);

	//FindSmallest method
	int FindSmallest();

	//FindLargest method
	int FindLargest();

	//PrintNumberInAPosition method
	void PrintNumberInAPosition(ofstream& fout, int position);

	//FindNumberInList method
	void FindNumberInList(int searchNumber, int& position, bool& found);

	//CalculateSum method
	int CalculateSum();

	//CalculateAverage method
	double CalculateAverage();

	//PrintByDigitCount method
	void PrintByDigitCount(ofstream& fout);

	//FreeTheList method
	void FreeTheList();

	//Friend function for PrintDivider
	friend void PrintDivider(ofstream& fout, char symbol, int width);

	//Friend function for PrintCenteredMessage 
	friend void PrintCenteredMessage(ofstream& fout, string message, int width);

	//Destructor - calls FreeTheList method
	~integerClassType() { FreeTheList(); }

private:

	//Start node of the linked list
	nodePtr start;

	//Integer for the count of the numbers in the list
	int countOfNumberList;

	//CreateList method
	void CreateList();

	//SetCountOfDigits method
	int SetCountOfDigits(int aNumber);

	//FindPtrAtEndOfList method
	nodePtr FindPtrAtEndOfList();

	//FindLargestDigitCount method
	int FindLargestDigitCount();

};

#endif // !1
