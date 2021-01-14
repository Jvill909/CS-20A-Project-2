/* WordList source file
*
*
*	This file will contain the function definitions you will implement.
*	The function signitures may NOT be changed.  You may create your own
*	helper functions and include them in this file.
*
*	In addition to the specific instructions for each function, no function
*	should cause any memory leaks or alias m_list in any way that would result
*	in undefined behavior. 
*
*	Topics: Multilevel Pointers, Dynamic Allocation, Classes
*
*/
// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif



// Do not include any other libraries
#include"wordlist.h"
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;

/* Function: Wordlist Constructor  
*/
WordList::WordList(const int max_words) {
	if (max_words < 1)
	{
		char **m_list = nullptr;
		m_count = 0;
		m_max = 0;
	}
	else 
	{
		m_count = 0;
		m_max = max_words;
		char **m_list = new char*[max_words];
		for (int i = 0; i < max_words; i++)
		{
			m_list[i] = new char[19];
		}
			
	}
}

/* Function: Wordlist Copy Constructor
*/
WordList::WordList(const WordList &other) {
	m_count = other.m_count;
	m_max = other.m_max;

	**m_list = *new char[m_max];
	for (unsigned int i = 0; i < m_max; i++)
		m_list[i] = other.m_list[i];
	
}


/* Function: Wordlist Destructor
*/
WordList::~WordList() {

	for (unsigned int i = 0; i < m_max; i++)
		delete[] m_list[i];
	delete[] m_list;

}

/* Function: printList
*/
int	WordList::print() const {
	if (m_list == nullptr)
		return -1;
	else
	{
		for (unsigned int i = 0; i < m_count; i++)
		{
			if (i == (m_count - 1))
				cout << *m_list[i] << endl;
			else
				cout << *m_list[i] << " ";
		}
	}
	return -1;
}



/* Function: at
*/
char* WordList::at(const int index) const {
	char *word = m_list[index];
	if (word != nullptr)
		return word;
	else
		return nullptr;
}


/* Function: count
*/
int	WordList::count() const {
	int count = 0;
	for(unsigned int i = 0; i < m_max; i++)
	{
		if (strlen(m_list[i]) == 0)
			count++;
		else
			continue;
	}
	return count;

}


/* Function: add
*/
int	WordList::add(const char word[]) {
		
	int returnNum; // variable for the return value
	
	if (m_count == m_max) // sets the variable that will set the return value
	{
		returnNum = 1;
	}
	else if (m_count < m_max)
	{
		returnNum = 0;
	}
	else
	{
		returnNum = -2;
	}

	m_max++;
	char **templist = new char*[m_max];

	switch (returnNum)
	{
		case -2:
		case 1:	// both cases will create a temp n_list to expand the maximum
				// of the word list
			cout << "case 1 or 2: " << returnNum << endl;
			for (unsigned int i = 0; i < m_max; i++)
			{
				templist[i] = new char[19];
			}
			if(m_count > 0) // a m_list w/ at least 1 word will copy its contents
							// onto the temp list, m_list will then copy the address
							//  templist is holding.
			{
				for (unsigned int i = 0; i < m_count; i++)
				{
					strcpy (templist[i], m_list[i]);
				}
				strcpy (templist[m_count], word);
				m_list = templist;
				m_count++;

				return returnNum;
			}
			else  // if m_list holds no words then it only expands m_list
					// copies the word into it
			{
				strcpy(templist[m_count], word);
				m_list = templist;
				m_count++;

				return returnNum;
			}
		break;
		case 0:	// if m_list has room will just copy the word into it
			cout << "case 0" << endl;

			strcpy(m_list[m_count], word);
			m_count++;

			return returnNum;
		default:
			cout << "i am borked" << endl;

	}
		
		return 3;
}


/* Funtion: remove
*/
int	WordList::remove(const char word[]) {
	if (m_list == nullptr) 
	{
		return -1;
	}
	else  // if m_list is not nullptr, then will compare each word
	{
		for (unsigned int i = 0; i < m_count; i++)  // loops through each element
		{
			if (strcmp(m_list[i], word) == 0)  // checks if current element is same as word
			{
				for (unsigned int j = i; j < m_count; j++)  // if word is same will proceed to move the remaining list onto its place
				{
					strcpy(m_list[i], m_list[i + 1]);
				}
			}
		}
	}
	// TODO:
	return -1;
}


/* Funtion: append
*/
int	WordList::append(const WordList* other) {

	// TODO:
	return -2;

}


/* Funtion: search
*/
int WordList::search(const char word[]) const {

	if (m_list == nullptr)
	{
		return -1;
	}
	else
	{
		for (unsigned int i = 0; i < m_count; i++) // loops through elements
		{
			if (strcmp(m_list[i], word) == 0) // if a match if found will return i, otherwise will continue through for loop
			{
				return i;
			}
			else
			{
				continue;
			}
		}
		return -1;
	}
}


/* Funtion: sort
*/
int	WordList::sort() {
	if (m_list == nullptr)
	{
		return -1;
	}
	else if(m_count == 1)  // no need to sort if m_list is null or has only one word stored
	{
		return 1;
	}
	else
	{
		bool swap = true;
		char* temp;

		while (swap = true) // uses the swap bool to determine if further swaps need to be made
		{
			swap = false;

			for(unsigned int i = 0; i < m_count; i++)
				if (m_list[i] > m_list[i + 1])
				{
					temp = m_list[i];
					m_list[i] = m_list[i + 1];
					m_list[i + 1] = temp;
					swap = true;
				}
		}

		return 0;
	}
	// TODO:
	return -1;

}


/* Funtion: Assignment Operator  
*/
WordList& WordList::operator=(const WordList &other) {

	// TODO:
	return *this;
}
	// GET RID OF THIS BEFORE TURNING IN!!!!!!!!!!!!!!!!
int WordList::getCount() 
{
	return m_count;
}

int WordList::getMax()
{
	return m_max;
}

int WordList::getWord()
{
	return *m_list[0];
}

void WordList::setWord(char name, int wordRow, char word)
{
	//strcpy(name[wordRow], word);
}