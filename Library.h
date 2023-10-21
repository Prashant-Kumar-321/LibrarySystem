#pragma once 

#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>

using namespace std; 

class Patron; // Forward Declaration
class Author; // Forward Declaration 

class Book
{
  public:   
    Book(): patron(nullptr/*Book is avialable*/){ }
    Book( const Book& other); 
    Book& operator= ( const Book& other); 
    ~Book() { delete[] title; }

    bool operator== ( const Book& otherBook); 
    
  private: 
    char* title; 
    Patron* patron; 

    ostream& printBook (ostream&) const; 

    friend ostream& operator<< ( ostream& out, const Book& book); 

    friend void aux_includeBook ( Author& authorName, Book& bookTitle); 
    friend void includeBook();
    friend void includeBook( const char* authorName, const char* booktitle); 

    friend class CheckOutBook; 
    friend class Patron; 

    friend void checkOutBook(); 
    friend void returnBook(); 
}; 

class Author
{
  public: 
    Author() = default; 
    Author ( const Author& other); 
    Author& operator= ( const Author& other); 
    ~Author(){delete[] name;}

    bool operator== (const Author& otherAuthor); 
  private: 
    char* name; 
    list<Book> books; 

    ostream& printAuthor(ostream&) const; 

    friend ostream& operator<< (ostream& out, const Author& author); 

    friend void includeBook();
    friend void aux_includeBook (Author&, Book&); 
    friend void includeBook( const char* authorName, const char* booktitle);  
    friend class CheckOutBook; 
    friend class Patron;

    friend void checkOutBook(); 
    friend void returnBook(); 
};  

class CheckOutBook
{
  public:   
    CheckOutBook(list<Book>::iterator book, list<Author>::iterator author): book(book), author(author) {   }

    bool operator== (const CheckOutBook& checkoutbook); 
  private: 
    list<Book>::iterator book; 
    list<Author>::iterator author; 

    friend Patron; 
  
    friend void checkOutBook(); 
    friend void returnBook(); 
}; 

class Patron
{
  public: 
    Patron() = default;
    Patron ( const Patron& other); 
    Patron& operator= ( const Patron& other); 
    ~Patron() {delete[] name;} 

    bool operator== (const Patron& otherPatron); 

  private: 
    char* name; 
    list<CheckOutBook> books; 

    ostream& printPatron ( ostream&) const; 

    friend ostream& operator<< ( ostream& out, const Patron& patron); 

    friend Book; 

    friend void checkOutBook(); 
    friend void returnBook(); 
}; 
