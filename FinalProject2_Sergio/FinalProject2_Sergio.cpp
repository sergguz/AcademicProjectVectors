// FinalProject2_Sergio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Book
{
	int code;
	string isbn;
	string title;
	string author;
	int year;
	double price;
	string genre;
};

//Prototypes
void load_data(vector<Book> &);
void display_data(vector<Book> &);
void search_year(vector<Book> &);
void search_isbn(vector<Book> &);
void sort_year(vector<Book> &);
void sort_isbn(vector<Book> &);
void old_books(vector<Book> &, vector<Book> &);

int searchYear = 0;
string searchISBN = " ";

int Menu();

void searchYearBook(Book &book);

struct SortByYear
{
	bool operator() (const Book& b1, const Book& b2) const
	{
		return b1.year < b2.year;
	}
};

struct SortByISBN
{
	SortByISBN() {};
	bool operator() (const Book& b1, const Book& b2) const
	{
		return b1.isbn < b2.isbn;
	}
};

int main()
{
	char answer = ' ';
	int option;
	vector<Book> books;
	vector<Book> oldBooks;
	load_data(books);
	do
	{
		option = Menu();
		switch (option)
		{
		case 1:
			display_data(books);
			cout << endl << endl;
			break;
		case 2:
			cin.ignore();
			cout << "Please enter the ISBN you want to search: ";
			getline(cin, searchISBN);
			search_isbn(books);
			cout << endl << endl;
			break;
		case 3:
			cout << "Please enter the Year you want to search: ";
			cin >> searchYear;
			search_year(books);
			cout << endl << endl;
			break;
		case 4:
			cout << "SORT BOOKS BY YEAR" << endl;
			sort_year(books);
			display_data(books);
			cout << endl << endl;
			break;
		case 5:
			cout << "SORT BOOKS BY ISBN" << endl;
			sort_isbn(books);
			display_data(books);
			cout << endl << endl;
			break;
		case 6:
			cout << "PUT OLDER BOOKS SEPARATELY" << endl;
			old_books(books, oldBooks);
			display_data(oldBooks);
			cout << endl << endl;
			break;
		default:
			break;
		}
		cout << "Do you wish to continue? (Type 'y' or 'Y') ";
		cin >> answer;
	} while (answer=='y' || answer=='Y');

	system("pause");
    return 0;
}
int Menu()
{
	int option = 0;
	cout << "MAIN MENU" << endl;
	cout << "=========" << endl;
	cout << "1. Display the vector of books" << endl;
	cout << "2. Search a book by ISBN" << endl;
	cout << "3. Search books by Year" << endl;
	cout << "4. Sort books by Year" << endl;
	cout << "5. Sort books by ISBN" << endl;
	cout << "6. Put old books in another place (2014 and older)" << endl;
	cout << "What option do you want to choose? ";
	cin >> option;
	return option;
}

void load_data(vector<Book> &books)
{
	char option = ' ';
	Book listB;
	cout << "Please enter the books you want to register" << endl;
	do
	{
		cout << "Code: ";
		cin >> listB.code;
		cout << endl;
		cin.ignore();
		cout << "ISBN: ";
		getline(cin, listB.isbn);
		cout << endl;
		cout << "Title: ";
		getline(cin, listB.title);
		cout << endl;
		cout << "Author: ";
		getline(cin, listB.author);
		cout << endl;
		cout << "Year: ";
		cin >> listB.year;
		cout << endl;
		cout << "Price: ";
		cin >> listB.price;
		cout << endl;
		cin.ignore();
		cout << "Genre: ";
		getline(cin, listB.genre);
		books.push_back(listB);

		cout << "Do you wish to continue? ";
		cin >> option;
	} while (option=='y' || option=='Y');
}
std::ostream& operator << (std::ostream& Stream, const Book & book)
{
	return Stream << book.code << "   " << book.isbn << " " << book.title << " " << book.author << " " << book.year << " " << book.price << " " << book.genre;
}
void displayElement(const Book & book)
{
	std::cout << book;    
	std::cout << endl;
}
void display_data(vector<Book> &books)
{
	for_each(books.begin(), books.end(), displayElement);

	/*vector<Book>::const_iterator itr;
	for (itr = books.begin(); itr != books.end(); itr++)
		cout << *itr << endl;*/

	/*for (vector<Book>::iterator yourIt = books.begin(); yourIt != books.end(); yourIt++)
	{
		cout << "Code: " << yourIt->code << endl;
		cout << "ISBN: " << yourIt->isbn << endl;
		cout << "Title: " << yourIt->title << endl;
		cout << "Author: " << yourIt->author << endl;
		cout << "Year: " << yourIt->year << endl;
		cout << "Price: " << yourIt->price << endl;
		cout << "Genre: " << yourIt->genre << endl;
	}*/

	/*for each (Book book in books)
	{
		cout << "Code: " << book.code;
	}*/
}
void searchISBNBook(Book &book)
{
	if (book.isbn == searchISBN)
	{
		cout << book;
		cout << endl;
	}
}
void search_isbn(vector<Book> &books)
{
	for_each(books.begin(), books.end(), searchISBNBook);
}
void searchYearBook(Book &book)
{
	if (book.year == searchYear)
	{
		cout << book;
		cout << endl;
	}
}
void search_year(vector<Book> &books)
{
	for_each(books.begin(), books.end(), searchYearBook);
}
void sort_year(vector<Book> &books)
{
	sort(books.begin(), books.end(), SortByYear());
}
void sort_isbn(vector<Book> &books)
{
	sort(books.begin(), books.end(), SortByISBN());
}
void old_books(vector<Book> &books, vector<Book> &oldBooks)
{
	for (int i = 0; i < books.size(); i++)
	{
		if (books[i].year <= 2014)
		{
			oldBooks.push_back(books[i]);
		}
	}
}
