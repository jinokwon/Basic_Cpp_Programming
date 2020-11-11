// 2020-09-16 creating sets of random numbers
// Ex. 9-15
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int *getRandomNumbers(int);

int main()
{
  int *numbers = nullptr;
  const int NUM_OF_ELEMENTS = 6;

  for (int i=0; i < 3; i++)
    numbers = getRandomNumbers(NUM_OF_ELEMENTS);
    srand( time(0) );

  delete [] numbers;
  numbers = nullptr;
  return 0; 
}

int *getRandomNumbers(int num)
{
  int *arr = nullptr;
  if(num <= 0)
    return nullptr;

  arr = new int[num];

  for (int count = 0; count < num; count++)
   arr[count] = rand() % 60 + 1; // we added 1 to avoid '0'
  
  for (int count = 0; count < num; count++)
    cout << arr[count] << " ";
  cout << endl;


  return arr;
}
// ---------------------------------------------------------
// Ex. 9-17
#include <iostream>
#include <memory>
using namespace std;

int main ()
{
    unique_ptr<int> ptr (new int);
    *ptr = 99;

    cout << *ptr << endl;
    return 0;
}

// ---------------------------------------------------------
// Programming Challenge Q1. Array Allocator

#include <iostream>
using namespace std;

// Function Prototype
int* arrayAllocator(int);

int main()
{
	int numElements;			// To hold the number of elements to allocate
	int *pointer = nullptr;     // A pointer to the array
	int i;            			// A loop counter

	// Get the array size.
	cout << "\nEnter an array size: ";
	cin >> numElements;
   
	// Allocate the array.
	pointer = arrayAllocator(numElements);

	// Fill the array with values.
	for (i = 0; i < numElements; i++)
		pointer[i] = i;

	// Display the values.
	cout << "Here are the values in the array:\n";
	for (i = 0; i < numElements; i++)
		cout << "Element " << i << " has the value " 
		     << pointer[i] << endl;

	// Deallocate the array.
	delete [] pointer;
	pointer = nullptr;

	return 0;
}

// ********************************************************
// The arrayAllocator function dynamically allocates an   *
// array of ints. The number of elements is passed as an  *
// argument into the parameter num. The function returns  *
// a pointer to the array.                                *
// ********************************************************
int* arrayAllocator(int num)
{
	int *arrPtr = nullptr;
   
	// Allocate space for the array.
	arrPtr = new int[num];
   
	// Return the address of the allocated memory.
	return arrPtr;
}
// ---------------------------------------------------------
// Program Challenge #3 Drop Lowest Score

#include <iostream>
#include <iomanip>
using namespace std;
// Function prototypes
void sort(double*, int);  
double averageDropLowest(double*, int); 
int main()
{
	int numTestScores = 0;		// To hold the number of test scores
	double *pointer = nullptr;	// To point to the dynamically allocated array
	double testAverage = 0;		// To hold the test score average

	// Get the number of test scores.
	cout << "\nHow many test scores will you enter? ";
	cin >> numTestScores;
   
	// Validate the number of scores.
	while (numTestScores < 0)
	{
		cout << "The number cannot be negative.\n";
		cout << "Enter another number:  ";
		cin >> numTestScores;
	}

	// Allocate an array to hold the test scores.
	pointer = new double[numTestScores];

	// Get the test scores.
	for (int i = 0; i < numTestScores; i++)
	{
		// Get a test score.
		cout << "Enter test score " << (i+1) << ":  ";
		cin >> pointer[i];
      
		// Validate the input. No negative scores allowed.
		while (pointer[i] < 0)
		{
			cout << "Negative scores are not allowed.\n";
			cout << "Enter another score for this test:  ";
			cin >> pointer[i];
		}
	}

	// Sort the test scores.
	sort(pointer, numTestScores);

	// Get the average of the test scores.
	testAverage = averageDropLowest(pointer, numTestScores);

	// Display the resulting data.
	cout << "\nThe test scores in ascending order, ";
	cout << "and their average,\n";
	cout << "(with the lowest score dropped) are:\n\n";
	cout << " Score" << endl;
	cout << " -----" << endl;

	for (int j = 0; j < numTestScores; j++)
	{
		cout << "\n" << fixed << setprecision(2)
		     << setw(6) << pointer[j];
	}
   
	cout << "\n\nAverage score:  " << setprecision(2)
	     << fixed << testAverage << endl << endl;

	// Free the dynamically-allocated memory.
	delete [] pointer;
	pointer = nullptr;

	return 0;
}

// ********************************************************
// The sort function performs a selection sort on the     *
// array pointed to by the score parameter into ascending *
// order. The size parameter holds the number of elements.*
// ********************************************************
void sort(double* score, int size)
{
	int startScan, minIndex; 
	double minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = score[startScan];

		for(int index = startScan + 1; index < size; index++)
		{
			if (score[index] < minValue) // try to get the lowest score
			{
				minValue = score[index];
				minIndex = index;
			}
		}

		score[minIndex] = score[startScan];
		score[startScan] = minValue;
	}
}

// ********************************************************
// The averageDropLowest function calculates and returns  *
// the average of the values stored in the array passed   *
// into the scores parameter, with the lowest score       *
// dropped. Because the array must already be sorted in   *
// ascending order, the first element is not included in  *
// the calculations. The parameter numScores holds the    *
// the number of elmeents in the array.
// ********************************************************

double averageDropLowest(double* score, int numScores)  
{
	double total = 0;

	for (int k = 1; k < numScores; k++) // Start at 1 instead of 0.
	{
		total += score[k];
	}

	return (total / (numScores - 1));  // Remember that you dropped one.
}
