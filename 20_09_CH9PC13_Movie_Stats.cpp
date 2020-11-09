// Chapter 9, Programming Challenge 13: Movie Statistics

#include <iostream>
using namespace std;

// Function prototypes
double median(int *, int);
int mode(int *, int);
int *makeArray(int);
void getMovieData(int *, int);
void selectionSort(int [], int);
double average(int *, int);

int main()
{
	int *movieData = nullptr;   // To point to an array
	int numStudents;			// Number of students
	int movieMode;				// Mode of movies seen

	// Get the number of students surveyed.
	cout << "How many students were surveyed? ";
	cin >> numStudents;
   
	while (numStudents <= 0)
	{
		// Get the number of students surveyed.
		cout << "The number of students must be greater than zero.\n";
		cout << "How many students were surveyed? ";
		cin >> numStudents;
	}

	// Allocate an array big enough for the data.
	movieData = makeArray(numStudents);
   
	// Get the movie data.
	getMovieData(movieData, numStudents);
   
	// Sort the data.
	selectionSort(movieData, numStudents);
   
	// Display the statistics.
	cout << "\nThe average number of movies seen is ";
	cout << average(movieData, numStudents) << ".\n";

	cout << "The median of the number of movies seen is ";
	cout << median(movieData, numStudents) << ".\n";

	movieMode = mode(movieData, numStudents);

	if (movieMode == -1)
	{
		cout << "The set has no mode.\n\n";
	}
	else
	{
		cout << "The mode of the number of movies seen is " 
			 << movieMode << ".\n\n";
	}

	// Deallocate the array.
	delete [] movieData;
	movieData = nullptr;

	return 0;
}

//*************************************************
// Function makeArray                             *
// This function dynamically allocates an array of*
// ints and returns a pointer to it. The parameter*
// size is the number of elements to allocate.    *
//*************************************************

int *makeArray(int size)
{
	int *ptr = nullptr;

	ptr = new int[size];

	return ptr;
}

//*************************************************
// Function getMovieData                          *
// This function gets the number of movies seen by*
// a group of students. The parameter arr is an   *
// array to store the data in. The parameter num  *
// is the number of elements in the array, and the*
// number of students.                            *
//*************************************************

void getMovieData(int arr[], int num)
{
	cout << "Enter the number of movies each student saw.\n";

	for (int count = 0; count < num; count++)
	{
		cout << "Student " << (count + 1) << ": ";
		cin >> arr[count];

		while (arr[count] <= 0)
		{
			cout << "The number of movies be greater than zero.\n";
			cout << "How many movies were seen by Student " 
				 << (count + 1) << "? ";
			cin >> arr[count];
		}
	}
}

//*************************************************
// Function selectionSort                         *
// This function performs the selection sort      *
// algorithm on array, sorting it into ascending  *
// order. The parameter size holds the number of  *
// elements in the array.                         *
//*************************************************

void selectionSort(int values[], int size)
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = values[startScan];

		for(int index = startScan + 1; index < size; index++)
		{
			if (values[index] < minValue)
			{
				minValue = values[index];
				minIndex = index;
			}
		}

		values[minIndex] = values[startScan];
		values[startScan] = minValue;
	}
}

//**************************************************
// Function median                                 *
// This function displays the median of the values *
// in the array pointed to by the parameter arr.   *
// The num parameter holds the number of elements  *
// in the array.                                   *
//**************************************************

double median(int *arr, int num)
{
	double med = 0.0;

	if (num % 2 == 0) // number of elements even?
	{
		int mid1 = num / 2, mid2 = (num / 2) - 1;
		med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
	}
	else
	{
		med = *(arr + (num / 2));
	}
		
	return med;
}

//*********************************************************
// Function mode                                          *
// This function returns the mode of the array pointed to *
// by arr. The mode is the value that appears most often. *
// The parameter num holds the number of elements in the  *
// array. If no element appears more than once, the       *
// function returns -1.                                   *
//*********************************************************

int mode(int *arr, int num)
{
	int *freq = nullptr;
	int mode = -1;
	int highest = 0;
	int elem = 0;
	int count = 0;

	// Dynamically allocate an array to hold
	// the frequencies of each element in the
	// arr array.
	freq = makeArray(num);
   
	// Store 0 in all the elements of freq.
	for (count = 0; count < num; count++)
	{
		freq[count] = 0;
	}
	
	// Find the frequency of each element in arr.
	for (int count1 = 0; count1 < num; count1++)
	{
		for (int count2 = 0; count2 < num; count2++)
		{
			if (*(arr + count2) == *(arr + count1))
			{
				(*(freq + count1))++;
			}
		}
	}

	// Find the element with the highest frequency.
	highest = *freq;
	elem = 0;

	for (count = 1; count < num; count++)
	{
		if (*(freq + count) > highest)
		{
			highest = *(freq + count);
			elem = count;
		}
	}

	// If there is no mode (no element has a frequency greater
	// than 1), then return -1. Otherwise return the element with
	// the greatest frequency.
	if (highest > 1)
	{
		mode = *(arr + elem);
	}

	return mode;
}

//**************************************************
// Function average                                *
// This function calculates and returns the average*
// of the values in the array arr. num is the      *
// number of elements in the array.                *
//**************************************************

double average(int arr[], int num)
{
	int total = 0;
	double avg;

	for (int count = 0; count < num; count++)
	{
		total += arr[count];
	}

	avg = total / static_cast<double>(num);

	return avg;
}
