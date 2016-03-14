/*********************************************************************
** Program Filename: main.cpp
** Author: Giovanni Rosati
** email: rosatig@oregonstate.edu
** Date: 2016-03-11
** Description: File with main() for CS199_400 Lab 10
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <sstream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostringstream;
using std::setprecision;

//function prototypes
//displays user options to console
void displayMenu();

//gets user input
int getInput();

//binary search iteration algorithm modified from
//http://stackoverflow.com/questions/24011645/binary-search-algorithms-using-iterative-and-recursive
bool binarySearch(int* tempArray, int size, int value);

//binary search recursive algorithm modified from
//http://stackoverflow.com/questions/2648084/recursive-function-for-a-binary-search
bool binarySearchRecursive(int* tempArray, int value, int low, int high);

//iteration factorial function modified from
//https://www.daniweb.com/programming/software-development/threads/261972/factorial-using-iteration
long fact(int num);

//from OSU Professor Rooker
//Not Tail Recursive factorial function
long rfactorial(int num);

//creates and returns a string with commas for displaying large numbers
string addCommas(long n);

int main() {
	srand(time(0));				//seed random number generator
	bool done = false;			//for menu
	clock_t t1;					//used to capture time for first test
	clock_t t2;					//used to capture time for second test

	while (done != true)
	{
		displayMenu();
		int menuChoice = 0;			//for menu/user inputs
		menuChoice = getInput();
		switch (menuChoice) {
		case 1:		//binary search tests
		{
			int arraySize = -1;						//user choice for size of array
			int loops = -1;							//user choice for # of loops to run in test
			cout << "This program will compare the amount of time it takes" << endl;
			cout << "to perform a binary search using iterative and " << endl;
			cout << "recursive algorithms. You will enter the size of the" << endl;
			cout << "array (10 to 100,000,000) to be searched and the number of" << endl;
			cout << "times (1 to 100,000,000) to run the search. Using the maximum" << endl;
			cout << "values for both size and # of loops will take almost 4 minutes" << endl;
			cout << "to complete." << endl;
			cout << endl;
			//get size of array from user
			while (arraySize < 10 || arraySize > 100000000)
			{
				cout << "Enter a positive integer for the number of elements in" << endl;
				cout << "the array (greater than 10 and no more than 100,000,000)." << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> arraySize;
				if (arraySize < 10 || arraySize > 100000000)
				{
					cout << "Invalid entry..." << endl;
					arraySize = -1;
					cout << endl;
				}
			}
			cout << endl;
			//create the dynamic array
			int* tempArray = new int[arraySize] {0};
			
			//populate the array
			for (int i = 0; i <= arraySize; i++)
			{
				tempArray[i] = i;
			}

			//get number of loops from user
			while (loops < 1 || loops > 100000000)
			{
				cout << "Enter a positive integer for the number of loops to run" << endl;
				cout << "the search (greater than 0 and no more than 100,000,000)." << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> loops;
				if (loops < 1 || loops > 100000000)
				{
					cout << "Invalid entry..." << endl;
					loops = -1;
					cout << endl;
				}
			}
			//iterative binary search
			cout << endl;
			cout << endl;
			cout << "Beginning tests." << endl;
			cout << "Now running iterative binary searches...please wait..." << endl;

			t1 = clock();	//get starting time
			for (int i = 0; i < loops; i++)
			{
				int searchValue = rand() % arraySize + 1;  //generates random int between 1 and size of array
				binarySearch(tempArray, arraySize, searchValue);
			}
			t1 = clock() - t1;	//calculate time elapsed
			cout << endl;

			//recursive binary search
			cout << "Now running recursive binary searches...please wait..." << endl;
			t2 = clock();
			for (int i = 0; i < loops; i++)
			{
				int searchValue = rand() % arraySize + 1;  //generates random int between 1 and size of array
				binarySearchRecursive(tempArray, searchValue, 0, arraySize);
			}
			t2 = clock() - t2;

			//delete the array
			delete[] tempArray;
			tempArray = NULL;
			
			//output results
			cout << endl;
			cout << endl;
			cout << "RESULTS---------------------------------------------------" << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to run " << addCommas(loops) << " iterative binary search(es)." << endl;
			cout << endl;
			cout << "It took " << addCommas(t2) << " clicks (" << setprecision(9) << ((float)t2) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to run " << addCommas(loops) << " recursive binary search(es)." << endl;
			cout << endl;
			cout << endl;
			cout << "Tests complete." << endl;
			cout << endl;
			cout << endl;
		}
		break;

		case 2:		//factorial tests
		{
			long loops = -1;	//user choice for # of loops to run in test

			cout << "This program will compare the amount of time it takes" << endl;
			cout << "to calculate factorials using iterative and " << endl;
			cout << "recursive algorithms. You will enter the number of" << endl;
			cout << "times (loops) the program will calculate a factorial." << endl;
			cout << "Choosing 1,000,000,000 (maximum) may take more than 10 seconds. " << endl;
			cout << endl;

			//get number of loops from user
			while (loops < 1 || loops > 1000000000)
			{
				cout << "Enter a positive integer for the number of loops to run" << endl;
				cout << "(greater than 0 but no more than 1,000,000,000)." << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> loops;
				if (loops < 1 || loops > 1000000000)
				{
					cout << "Invalid entry..." << endl;
					loops = -1;
					cout << endl;
				}
			}

			//iterative factorial test
			cout << endl;
			cout << endl;
			cout << "Beginning tests." << endl;
			cout << "Now running iterative factorial function...please wait..." << endl;

			t1 = clock();	//get starting time
			for (long i = 0; i < loops; i++)
			{
				int num = rand() % 16;  //generates a random int between 0 and 15
				fact(num);
			}
			t1 = clock() - t1;	//calculate time elapsed
			cout << endl;

			//recursive factorial test
			cout << "Now running recursive factorial function...please wait..." << endl;
			t2 = clock();
			for (long i = 0; i < loops; i++)
			{
				int num = rand() % 16;  //generates a random int between 0 and 15
				rfactorial(num);
			}
			t2 = clock() - t2;
			cout << endl;
			cout << "RESULTS---------------------------------------------------" << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to calculate " << addCommas(loops) << " factorial(s) using iteration." << endl;
			cout << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to calculate " << addCommas(loops) << " factorial(s) recursively." << endl;
			cout << endl;
			cout << endl;
			cout << "Tests complete." << endl;
			cout << endl;
			cout << endl;
		}
		break;

		case 3:
			done = true;
			break;

		default:
			std::cout << "Not a valid choice" << std::endl;
			break;
		}
	}
	return 0;
}

//displays user options to console
void displayMenu()
{
	cout << endl;
	cout << "Choose option and press enter" << endl;
	cout << "*****************************" << endl;
	cout << "  1) Run the binary search tests" << endl;
	cout << "  2) Run the factorial tests" << endl;
	cout << "  3) Exit" << endl;
	cout << endl;
}

int getInput() {	//to collect user responses to menu
	int choice;
	cout << "Choice: ";
	cin >> choice;
	return choice;
}

//binary search iteration algorithm modified from
//http://stackoverflow.com/questions/24011645/binary-search-algorithms-using-iterative-and-recursive
bool binarySearch(int* tempArray, int size, int value)
{
	bool result = false;
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (value < tempArray[mid])
			high = mid - 1;
		else if (value > tempArray[mid])
			low = mid + 1;
		else
			return true;
	}
	return false;
}

//binary search recursive algorithm from
//http://stackoverflow.com/questions/2648084/recursive-function-for-a-binary-search
bool binarySearchRecursive(int* tempArray, int value, int low, int high)
{
	if (high < low) return false; // not found
	int mid = low + ((high - low) / 2);
	if (tempArray[mid] > value)
		return binarySearchRecursive(tempArray, value, low, mid - 1);
	else if (tempArray[mid] < value)
		return binarySearchRecursive(tempArray, value, mid + 1, high);
	else
		return true; // found
}

//iteration factorial function modified from
//https://www.daniweb.com/programming/software-development/threads/261972/factorial-using-iteration
long fact(int num)
{
	int factorial = 1;
	for (int i = 1; i <= num; i++)
	{
		factorial *= i;
	}
	return factorial;
}

//from OSU Professor Rooker, modified
//Not Tail Recursive factorial function
long rfactorial(int num)
{
	if (num == 0) return 0;
	else if (num == 1) return 1;
	else
		return num* rfactorial(num - 1);
}

//creates and returns a string with commas for displaying large numbers
string addCommas(long n)
{
	ostringstream ss;
	ss << n;
	string output = ss.str();
	int commaPlace = output.length() - 3;
	while (commaPlace > 0)
	{
		output.insert(commaPlace, ",");
		commaPlace -= 3;
	}
	return output;
}