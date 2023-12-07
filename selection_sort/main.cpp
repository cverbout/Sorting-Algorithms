#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Chase Verbout
// CS 350 Fall 2022
// Programming Assignment 1

// This is my implementation of selection sort.
// This is a stable sort. Explanaition is in main and selection.txt.

// Outputs to both the console and a file called selection.txt

// CONSTANTS
const int SIZE{100};

// PROTOTYPES
int selectionSort(char *word);

// GLOBAL FILE
ofstream file;

// Main function creates an array and calls selectionSort on it;
int main(void)
{
	 char testWord[] = {'E', 'A', 'S', 'Y', 'T', 'E', 'S', 'T', '\0'};

	 file.open ("selection.txt");
	 cout << "SELECTION SORT OUTPUT: \n\n";
	 file << "SELECTION SORT OUTPUT: \n\n";

	 selectionSort(testWord);

	 cout << endl << "EASYTEST Final: " << testWord << "\n" << endl;
	 file << endl << "EASYTEST Final: " << testWord << "\n" << endl;


	 //  UNCOMMENT TO TEST ANY LETTER COMBINATION 
	 /*
		char *input = new char[SIZE];
		cout << "Sequence of letters to organize: ";
		cin.get(input, SIZE, '\n');
		cin.ignore(100, '\n');
		selectionSort(input, file);
		cout << endl << "Input Final: " << input << "\n" << endl;
		file << endl << "Input Final: " << input << "\n" << endl;
		delete [] input;
	 */

	 file << "As you can see Selection sort is in fact a stable sorting method." << endl;
     file << "This can be seen above in the instances where a character is compared to the same character." << endl;
     file << "The algorithm never swaps a character with the same character. And this algorithm will always choose the first instance of a character as the smallest."  << endl;
	 file << "This preserves the order by giving priority to the first discovered and locking all characters already sorted on the left." << endl;
	 file << "Therefore the left array character will always be the one that came first in the original string." << endl;
	 file << "And as we know a stable sort is a sort that maintains the original ordering among characters or numbers of same value." << endl;


	 file.close();
	 return 0;
}



// SelectionSort takes in a char* and sorts it by ascii value.
int selectionSort(char *word)
{
	int len = strlen(word);
	// Loop through n - 1 times because we don't need to compare the last char to itself
	for (int i = 0; i < len - 1; ++i)
	{	
		// Set smallest index
		int smallestInd = i;
		
		cout << "Beginning index " << i << ": " << word << endl;
		file << "Beginning index " << i << ": " << word << endl;
		cout << "Beginning Smallest char: " << word[smallestInd] << endl << endl;
		file << "Beginning Smallest char: " << word[smallestInd] << endl << endl;
		// Loop through from i to n
		for (int j = i; j < len; ++j)
		{
			// If this char is smaller set new index
			if (word[j] < word[smallestInd])
			{
				smallestInd = j;	
				cout << "Smallest char changed to: " << word[smallestInd] << endl;
				file << "Smallest char changed to: " << word[smallestInd] << endl;
			}
		}
		// Exit for-loop -> check that there is a different char at smallest index before swapping otherwise keep current at word[i]
		if (word[smallestInd] != word[i])
		{
			cout << "Swapping left " << word[i] << " and right " << word[smallestInd] << endl << endl;
			file << "Swapping left " << word[i] << " and right " << word[smallestInd] << endl << endl;
			char temp = word[i];
			word[i] = word[smallestInd];
			word[smallestInd] = temp;
		}
		else
		{
			cout << "---Not swapping left " << word[i] << " and right " << word[smallestInd] << "---" << endl << endl;
			file << "---Not swapping left " << word[i] << " and right " << word[smallestInd] << "---" << endl << endl;
		}

		cout << "After index " << i << ": " << word << endl << endl;
		file << "After index " << i << ": " << word << endl << endl;
	}	
			
	return 0;
}
	
