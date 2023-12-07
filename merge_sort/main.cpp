#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Chase Verbout
// CS 350 Fall 2022
// Programming Assignment 1

// This is my implementation of merge sort.
// This is a stable sort. Explanation in main and merge.txt.

// Outputs to both the console and a file called merge.txt

// GLOABAL FILE
ofstream file;

// CONSTANTS
const int SIZE{100};

// PROTOTYPES
int mergeSort(char *word);
int mergeSortRec(char *word, int left, int right);
int merge(char *word, int left, int middle, int right);


// Main function creates an array and calls mergeSort on it
int main(void)
{
	 char testWord[] = {'E', 'A', 'S', 'Y', 'T', 'E', 'S', 'T', '\0'};

	 file.open ("merge.txt");
	 cout << "NOTE: The character z is used in this implementation as infinity because it is the largest ascii character value." << endl << endl;
	 file << "NOTE: The character z is used in this implementation as infinity because it is the largest ascii character value." << endl << endl;
	 cout << "MERGE SORT OUTPUT: \n\n";
	 file << "MERGE SORT OUTPUT: \n\n";

	 mergeSort(testWord);

	 cout << endl << "EASYTEST Final: " << testWord << "\n" << endl;
	 file << endl << "EASYTEST Final: " << testWord << "\n" << endl;


	 //  TEST ANY LETTER COMBINATION 
	 /*
		char *input = new char[SIZE];
		cout << "Sequence of letters to organize: ";
		cin.get(input, SIZE, '\n');
		cin.ignore(100, '\n');
		mergeSort(input);
		cout << endl << "Input Final: " << input << "\n" << endl;
		file << endl << "Input Final: " << input << "\n" << endl;
		delete [] input;

	 */

	 file << "As you can see Merge sort is in fact a stable sorting method." << endl;
     file  << "This can be seen above in the instances where a character is compared to the same character." << endl;
     file  << "The algorithm always takes the character from the left array thus preserving the order." << endl;
	 file << "This is because the left array character will always be the one that came first in the original string." << endl;
	 file << "And as we know a stable sort is a sort that maintains the original ordering among characters or numbers of same value." << endl;

	 file.close();
	 return 0;
}



// MergeSort takes in a char* and sorts it by ascii value.
// Wrapper function
int mergeSort(char *word)
{
	int len = strlen(word);
	return mergeSortRec(word, 0, len - 1);
}



// mergeSortRec Recursively splits up the word until there are two subgroups that can be compared and merged
int mergeSortRec(char *word, int left, int right)
{
	// If left is not less than right we stop dividing
	if(!(left < right))
		return 0;
	
	// Divide Left
	mergeSortRec(word, left, ((left + right) / 2));
	// Divide Right
	mergeSortRec(word, ((left + right) / 2) + 1, right);
	// Merge
	return merge(word, left, ((left + right) / 2), right);
}



// merge does the work of comparing the two subarrays and places them in the original array in correct order
int merge(char *word, int left, int middle, int right)
{
	// size of left array
	int n1 = (middle - left) + 1;
	// size of right array
	int n2 = right - middle;
	// Left container plus space for z
	char lArr[n1 + 1];
	// Right container plus space for z
	char rArr[n2 + 1];
	
	int i = 0;
	int j = 0;	
	
	// Copy subarrays
	strncpy(lArr, word + left, n1);
	strncpy(rArr, word + middle + 1, n2);
	// Assign end to z (infinity for this instance)
	lArr[n1] = 'z';	
	rArr[n2] = 'z';	

	cout << endl << "Before Merge: " << word << endl << endl;
	file << endl << "Before Merge: " << word << endl << endl;
	// Loop the amount of items we have between left and right
	for (int k = left; k < right + 1; ++k)
	{
		// If left arr is less than or equal to right arr add left arr char and increment i
		if (lArr[i] <= rArr[j])
		{
			cout << "Left " << lArr[i] << " <= " << rArr[j] << " == Adding left " << lArr[i] << endl;
			file << "Left " << lArr[i] << " <= " << rArr[j] << " == Adding left " << lArr[i] << endl;
			word[k] = lArr[i];
			++i;
		}
		else // right arr is less than left arr so add right arr char and increment j
		{
			cout << "Right " << rArr[j] << " < " << lArr[i] << " == Adding right " << rArr[j] << endl;
			file << "Right " << rArr[j] << " < " << lArr[i] << " == Adding right " << rArr[j] << endl;
			word[k] = rArr[j];
			++j;
		}
	}
	cout << endl << "After Merge: " << word << endl << endl;
	file << endl << "After Merge: " << word << endl << endl;
	return 0;
}
