#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

// Chase Verbout
// CS 350 Fall 2022
// HW 3

// This is my implementation of bubble sort with the specification that it alternate between left to right reads
// and right to left reads. There was a lot of integer gymnastics to be done to get the correct run throughs. 
// Through integer divison's truncation I was able to account for the alternation within my nested for-loops.

// Outputs to both the console and a file called output.txt

// CONSTANTS
const int SIZE{100};

// PROTOTYPES
int bubbleSort(char *nums, ofstream &file);



// Main function creates an array and calls bubbleSort on it;
int main(void)
{
	 char testWord[] = {'E', 'A', 'S', 'Y', 'T', 'E', 'S', 'T', '\0'};
	 ofstream file;
	 file.open ("output.txt");
	 cout << "BUBBLE SORT OUTPUT: \n\n";
	 file << "BUBBLE SORT OUTPUT: \n\n";
	 bubbleSort(testWord, file);
	 cout << endl << "EASYTEST Final: " << testWord << "\n" << endl;
	 file << endl << "EASYTEST Final: " << testWord << "\n" << endl;


	 //  TEST ANY LETTER COMBINATION 
	 /* 
		char *input = new char[SIZE];
		cout << "Sequence of letters to organize: ";
		cin.get(input, SIZE, '\n');
		cin.ignore(100, '\n');
		bubbleSort(input, file);
		cout << endl << "Input Final: " << input << "\n" << endl;
		file << endl << "Input Final: " << input << "\n" << endl;
		delete [] input;
	 */  


	 file.close();
	 return 0;
}



// BubbleSort takes in a char* and sorts it by ascii value.
// Algorithm alternates between left to righ and right to left reads narrowing down the range of positions it needs to check on each run
int bubbleSort(char *word, ofstream &file)
{
	 // Get the length of the word
	 int len = strlen(word);
	 // Loop through length times
	 for (int i = 0; i < len - 1; ++i)
	 {
		  // If this is a even iteration of i read through from left to right
		  if (i % 2 == 0)
		  {
			   for (int j = (i / 2); j < len - (i/2) - 1; ++j)
			   {
					// If the letter at j is larger than the one after it, swap them
					if (word[j] > word[j + 1])
					{
						 char temp = word[j];
						 word[j] = word[j+1];
						 word[j+1] = temp;
					}
					// Uncomment below to see which letters are being compared on each iteration
					//cout << "compare " << j << word[j] << " and " << j+1 << word[j+1] << endl;
					//file << "compare " << j << word[j] << " and " << j+1 << word[j+1] << endl;
			   }
			   cout << "left to right ";
			   file << "left to right ";
		  }
		  // If this is an odd iteration of i read through from right to left
		  else 
		  {
			   for (int j = len - (i + 1)/2 - 1; j > (i+1)/2 - 1; --j)
			   {
					// If the letter at j is smaller than the one before it, swap them
					if (word[j] < word[j-1])
					{
						 char temp = word[j];
						 word[j] = word[j-1];
						 word[j-1] = temp;
					}
					// Uncomment below to see which letters are being compared on each iteration
					//cout << "compare " << j << word[j] << " and " << j-1 << word[j-1] << endl;
					//file << "compare " << j << word[j] << " and " << j-1 << word[j-1] << endl;
			   }
			   cout << "right to left ";
			   file << "right to left ";
		  }
		  cout << "pass " << (i + 2) / 2 << ": " << word << endl;
		  file << "pass " << (i + 2) / 2 << ": " << word << endl;
	 }

	 return 1;
}

