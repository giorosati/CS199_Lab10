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

//binary search iteration algorithm from
//
bool binarySearch(int arrayIn[], int size, int value);

//binary search recursive algorithm from
//http://stackoverflow.com/questions/2648084/recursive-function-for-a-binary-search
bool binarySearchRecursive(int arrayIn[], int value, int low, int high);

//factorial iteration function from
//

//from OSU Professor Rooker
//Not Tail Recursive factorial function
long rfactorial(int n);

//creates and returns a string with commas for displaying large numbers
string addCommas(long n);

int main() {
	srand(time(0));				//seed random number generator
	bool done = false;			//for menu
	clock_t t1;					//used to capture time at start of test
	clock_t t2;					//used to capture time as end of test
	long fact;					//used for factorial result

	while (done != true)
	{
		displayMenu();
		int menuChoice = 0;			//for menu/user inputs
		menuChoice = getInput();
		switch (menuChoice) {
		case 1:		//binary search test
		{
			int array[10000]{ 0 };					//create an array, poplulate with zeros
			int arraySize = -1;						//user choice for size of array
			int loops = -1;							//user choice for # of loops to run in test
			cout << "This program will compare the amount of time it takes" << endl;
			cout << "to perform a binary search, using iterative and " << endl;
			cout << "recursive algorithms. You will enter the size of the ." << endl;
			cout << "array (10 to 10,000) to be created and the number of" << endl;
			cout << "times (loops) to run the search. Using the maximum valuse for" << endl;
			cout << "both size and loops will take over 30 seconds to complete." << endl;
			cout << endl;
			while (arraySize < 10 || arraySize > 10000)
			{
				cout << "Enter a positive integer for the number of elements in" << endl;
				cout << "the array (greater than 10 and no more than 10,000)." << endl;
				cout << "Your entry: ";
				cin.ignore();
				cin >> arraySize;
				if (arraySize < 10 || arraySize > 10000)
				{
					cout << "Invalid entry..." << endl;
					arraySize = -1;
					cout << endl;
				}
			}
			//create the array
			//int* intArray = NULL;
			//intArray = new int[arraySize];

			//populate the correct area of the array
			for (int i = 0; i <= arraySize; i++)
			{
				array[i] = i;
			}

			while (loops < 1 || loops > 100000000)
			{
				cout << "Enter a positive integer for the number of loops to run" << endl;
				cout << "the search (greater than 0 and less than 100,000,000)." << endl;
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
			cout << "Now running iterative and recursive binary searches..." << endl;
			t1 = clock();	//get starting time
			for (int i = 0; i < loops; i++)
			{
				//generate random search value
				int searchValue = rand() % arraySize + 1;  //generates an int between 1 and size of array
				binarySearch(array, arraySize, searchValue);
			}
			t1 = clock() - t1;	//calculate time elapsed
			cout << endl;
			cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to run " << addCommas(loops) << " iterative binary search(es)." << endl;
			cout << endl;

			//recursive binary search
			t2 = clock();
			for (int i = 0; i < loops; i++)
			{
				//generate random search value
				int searchValue = rand() % arraySize + 1;  //generates an int between 1 and size of array
				binarySearchRecursive(array, searchValue, 0, arraySize);
			}
			t2 = clock() - t2;
			cout << endl;
			cout << "It took " << addCommas(t2) << " clicks (" << setprecision(9) << ((float)t2) / CLOCKS_PER_SEC << " seconds)." << endl;
			cout << "to run " << addCommas(loops) << " recursive binary search(es)." << endl;
			cout << endl;

			//delete the array
			//delete[] intArray;
		}
		break;

		//case 2:		//factorial tests

			//cout << "This program will compare the amount of time it takes" << endl;
			//cout << "to find the factorial of N, using recursive and " << endl;
			//cout << "tail recursive algorithms. You will enter N." << endl;
			//cout << endl;
			//while (n < 0)
			//{
			//	cout << "Enter a positive integer 'N' LESS THAN 17!" << endl;
			//	cout << "(over 16 will exceed program limits in a Windows 10 64 bit system" << endl;
			//	cout << "and N of 16 will require over 15 seconds to complete." << endl;
			//	cout << "Your entry: ";
			//	cin.ignore();
			//	cin >> n;
			//	if (n < 0 || n > 16)
			//	{
			//		cout << "Invalid entry..." << endl;
			//		n = -1;
			//		cout << endl;
			//	}
			//}
			////non tail recursive factorial test
			//cout << "Finding factorial of " << addCommas(n) << endl;
			//cout << "Calling non tail recursive factorial method" << endl;
			//t1 = clock();
			//for (int i = 0; i < 100000000; i++)
			//{
			//	fact = rfactorial(n);
			//}
			//t1 = clock() - t1;
			//cout << endl;
			//cout << "Value returned from rfactorial(): " << addCommas(fact);
			//cout << endl;
			//cout << "It took " << addCommas(t1) << " clicks (" << setprecision(9) << ((float)t1) / CLOCKS_PER_SEC << " seconds)." << endl;
			//cout << endl;

			////tail recursive factorial test
			//cout << "Finding factorial of " << addCommas(n) << endl;
			//cout << "Calling tail recursive factorial method" << endl;
			//t2 = clock();
			//for (int i = 0; i < 100000000; i++)
			//{
			//	fact = factorial(n);
			//}
			//t2 = clock() - t2;
			//cout << endl;
			//cout << "Value returned from factorial(): " << addCommas(fact);
			//cout << endl;
			//cout << "It took " << addCommas(t2) << " clicks (" << setprecision(9) << ((float)t2) / CLOCKS_PER_SEC << " seconds)." << endl;
			//cout << endl;
			//n = -1;		//reset n
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
bool binarySearch(int arrayIn[], int size, int value)
{
	bool result = false;
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (value < arrayIn[mid])
			high = mid - 1;
		else if (value > arrayIn[mid])
			low = mid + 1;
		else
			return true;
	}
	return false;
}

//binary search recursive algorithm
//from
//http://stackoverflow.com/questions/2648084/recursive-function-for-a-binary-search
bool binarySearchRecursive(int arrayIn[], int value, int low, int high)
{
	if (high < low) return false; // not found
	int mid = low + ((high - low) / 2);
	if (arrayIn[mid] > value)
		return binarySearchRecursive(arrayIn, value, low, mid - 1);
	else if (arrayIn[mid] < value)
		return binarySearchRecursive(arrayIn, value, mid + 1, high);
	else
		return true; // found
}

//factorial iteration function from
//from
//

//from Professor Rooker
//Not Tail Recursive factorial function
long rfactorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n* rfactorial(n - 1);
}

//from Professor Rooker
//Tail Recursive factorial function & helper function
long factorialHelper(int n, long result)
{
	if (n == 1)
		return result;
	else
		return factorialHelper(n - 1, n*result);
}

long factorial(int n)
{
	return factorialHelper(n, 1);
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