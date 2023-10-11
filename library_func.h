#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::swap;


//(назва, автор, видавництво, жанр)
const int SIZE = 50;
struct Book
{
	char name[SIZE];
	char author[SIZE];
	char publisher[SIZE];
	char genre[SIZE];
};



//Друк усіх книг;

void printBooks(Book* library, int size);
void printBook(Book book, string text = "");
void editBook(Book book);
char* toLowerCase(char* line);
int searchByAuthor(Book* library, int size, char* author);
void sortByName(Book* library, int size);
int searchByName(Book* library, int size, char* name);
void sortByAuthor(Book* library, int size);
void sortByPublisher(Book* library, int size);
void addNewBook(Book* &library, int &size, Book newBook);
void delBookByName(Book* &library, int &size, char* name);