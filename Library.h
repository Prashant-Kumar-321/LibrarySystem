#pragma once 

#include<iostream>
#include<string>
#include<cstring>
#include<list>
#include<algorithm>

using namespace std; 

class Patron; //Forward Declaration

class Book
{
  public:   
    Book(): patron(nullptr/*Book is avialable*/){ }

    bool operator==(const Book& otherBook){
      return strcmp(title, otherBook.title) == 0; 
    }

  private: 
    char* title; 
    Patron* patron; 

    ostream& printBook (ostream&) const; 

    friend ostream& operator<< (ostream& out, const Book& book){
      return book.printBook(out); 
    }

    friend class CheckOutBook; 
    friend class Patron; 

    friend void includeBook(); 
    friend void checkOutBook(); 
    friend void returnBook(); 
}; 


class Author
{
  public: 
    Author() = default; 

    bool operator==(const Author& otherAuthor){
      return strcmp(name, otherAuthor.name) == 0; 
    }

  private: 
    char* name; 
    list<Book> books; 

    ostream& printAuthor(ostream&) const; 

    friend ostream& operator<< (ostream& out, const Author& author) {
      return author.printAuthor(out); 
    }

    friend class CheckOutBook; 
    friend class Patron;

    friend void includeBook(); 
    friend void checkOutBook(); 
    friend void returnBook(); 
};  


class CheckOutBook
{
  public:   
    CheckOutBook(list<Book>::iterator book, list<Author>::iterator author): book(book), author(author) {   }

    bool operator== (const CheckOutBook& checkoutbook){
      strcmp(author->name, checkoutbook.author->name) == 0 &&  strcmp(book->title, checkoutbook.book->title) == 0; 
    }

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

    bool operator== (const Patron& otherPatron){
      return strcmp(name, otherPatron.name) == 0;
    }

  private: 
    char* name; 
    list<CheckOutBook> books; 

    ostream& printPatron (ostream&) const; 

    friend ostream& operator<< (ostream& out, const Patron& patron){
      return patron.printPatron(out); 
    }

    friend Book; 

    friend void checkOutBook(); 
    friend void returnBook(); 
}; 