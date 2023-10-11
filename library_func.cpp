#include "library_func.h"

using namespace std;

void printBooks(Book* library, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		printBook(library[i], "Book " + to_string(i + 1));
	}
}

void printBook(Book book, string text)
{
	cout << "\n\n================== " << text << " ====================" << endl;
	cout << "\t\t Name      :: " << book.name << endl;
	cout << "\t\t Author    :: " << book.author << endl;
	cout << "\t\t Publisher :: " << book.publisher << endl;
	cout << "\t\t Genre     :: " << book.genre << endl;
}

void editBook(Book book)
{
	cout << "\t\t Name      :: "; cin.getline(book.name, SIZE);
	cout << "\t\t Author    :: "; cin.getline(book.name, SIZE);
	cout << "\t\t Publisher :: "; cin.getline(book.name, SIZE);
	cout << "\t\t Genre     :: "; cin.getline(book.name, SIZE);
}

char* toLowerCase(char* line) {
	char* newLine = new char[strlen(line) + 1];
	for (size_t i = 0; i < strlen(line); i++)
	{
		newLine[i] = tolower(line[i]);
	}
	newLine[strlen(line)] = '\0';
	return newLine;
}

int searchByAuthor(Book* library, int size, char* author)
{	
	for (int i = 0; i < size; i++) {
		if (strcmp(toLowerCase(library[i].author), toLowerCase(author)) == 0) {
			return i;
		}
	}

	return -1;
}

void sortByName(Book* library, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1; j++) {
			if (strcmp(toLowerCase(library[j].name), toLowerCase(library[j+1].name)) > 0) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}

int searchByName(Book* library, int size, char* name)
{
	for (int i = 0; i < size; i++) {
		if (strcmp(toLowerCase(library[i].name), toLowerCase(name)) == 0) {
			return i;
		}
	}

	return -1;
}

void sortByAuthor(Book* library, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1; j++) {
			if (strcmp(toLowerCase(library[j].author), toLowerCase(library[j + 1].author)) > 0) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}

void sortByPublisher(Book* library, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1; j++) {
			if (strcmp(toLowerCase(library[j].publisher), toLowerCase(library[j + 1].publisher)) > 0) {
				swap(library[j], library[j + 1]);
			}
		}
	}
}



void addNewBook(Book* &library, int &size, Book newBook)
{
	Book* tmp = new Book[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		tmp[i] = library[i];
	}
	tmp[size] = newBook;
	size++;
	delete[] library;
	library = tmp;
}

void delBookByName(Book* &library, int& size, char* name)
{
	int index = searchByName(library, size, name);
	if (index == -1) {
		cout << "Not Found" << endl;
		return;
	}
	Book* tmp = new Book[size--];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index) {
			tmp[i] = library[i];
		}
		else {
			tmp[i] = library[i + 1];
		}
	}
	delete[] library;
	library = tmp;
}