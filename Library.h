#pragma once 

#include<iostream>
#include<cstring>
#include<list>
#include<string>
#include<algorithm>

using namespace std; 

class Patron; // Forward Declaration
class Author; // Forward Declaration 

class Book
{
  public:   
    Book() : patron(nullptr/*Book is avialable*/){ }
    bool operator== ( const Book& otherBook); 
    
  private: 
    std::string title; 
    Patron* patron; 

    ostream& printBook ( ostream&) const; 

    friend ostream& operator<< ( ostream& out, const Book& book);

    friend void aux_includeBook ( Author& authorName, Book& bookTitle); 
    // Include a Book in runTime in library 
    friend void includeBook();
    friend void includeBook( const char* authorName, const char* booktitle); 

    friend void checkOutBook(); 
    friend void returnBook(); 

    friend class CheckOutBook; 
    friend class Patron; 
}; 

class Author
{
  public: 
    bool operator== ( const Author& otherAuthor); 

  private: 
    std::string name; 
    std::list<Book> books; 

    ostream& printAuthor(ostream&) const; 

    friend ostream& operator<< (ostream& out, const Author& author); 

    friend void aux_includeBook (Author&, Book&); 
    friend void includeBook();
    friend void includeBook( const char* authorName, const char* booktitle);  
    friend void checkOutBook(); 
    friend void returnBook(); 
    
    friend class CheckOutBook; 
    friend class Patron;
};  

class CheckOutBook
{
  public:   
    CheckOutBook( list<Book>::iterator book, list<Author>::iterator author): book(book), author(author) {   }

    bool operator== (const CheckOutBook& otherCheckoutbook); 

  private: 
    std::list<Book>::iterator book; 
    std::list<Author>::iterator author; 

    friend void checkOutBook(); 
    friend void returnBook(); 

    friend Patron; 
}; 

class Patron
{
  public: 
    bool operator== (const Patron& otherPatron) const; 

  private: 
    std::string name;  
    list<CheckOutBook> books; 

    ostream& printPatron ( ostream&) const; 

    friend ostream& operator<< ( ostream& out, const Patron& patron); 
    friend void checkOutBook(); 
    friend void returnBook(); 

    friend class Book; 
}; 


// Declartion of All Friend classes 
void aux_includeBook( Author& authorName, Book& bookTitle); 
void includeBook (void);
void includeBook( const char* authorName, const char* booktitle); 
void checkOutBook (void); 
void statusOfLibrary (void); 
void returnBook (void); 

/**
 * Library system Utilities Fucntion declaration 
*/

// print all options of menu and return choosen menu  
int menu (void); 

// Add few Books and patron in the library. 
void readyLibrary (void); 