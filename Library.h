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
    
    friend list<Book>::iterator get_book_ref (Book&, list<Book>&);  

    friend void add_patron_in_the_mainDataBase (list<Author>::iterator, list<Book>::iterator, Patron& patron, list<Patron>&);
    // This Function will be used to manually checkout book 
    // i.e at  the starting of the program  
    friend void  manual_checkOutBook (const char* pat_name, const char* au_name, const char* bk_title); 
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
    // This Function will be used to manually checkout book 
    // i.e at  the starting of the program  
    friend void  manual_checkOutBook (const char* pat_name, const char* au_name, const char* bk_title);  
    friend void checkOutBook(); 
    friend void returnBook();

    /**
     * This function will Return iterator
     * to the author whose reference is 
     * Passed. 
     * */ 
    friend list<Author>::iterator get_author_ref (Author&); 
    
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
    // This Function will be used to manually checkout book 
    // i.e at  the starting of the program  
    friend void  manual_checkOutBook (const char* pat_name, const char* au_name, const char* bk_title);
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

    // This Function will be used to manually checkout book 
    // i.e at  the starting of the program  
    friend void  manual_checkOutBook (const char* pat_name, const char* au_name, const char* bk_title);
    friend void checkOutBook(); 
    friend void returnBook(); 
   
   /** Utilities Friend function **/

   // declared so that i can access name field of patron 
    friend list<Book>::iterator get_book_ref (Book&, list<Book>&);

    friend list<Patron>::iterator get_pat_ref (Patron&); 
    friend void add_patron_in_the_mainDataBase ( list<Author>::iterator, list<Book>::iterator, Patron& patron, list<Patron>&); 

    friend class Book; 
}; 


// Declartion of All Friend functions of classes  
void aux_includeBook( Author& authorName, Book& bookTitle); 
void includeBook (void);
void includeBook ( const char* authorName, const char* booktitle);

void add_patron_in_the_mainDataBase ( list<Author>::iterator, list<Book>::iterator,  Patron& , list<Patron>&);

void  manual_checkOutBook (const char* pat_name, const char* au_name, const char* bk_title); 

void checkOutBook (void); 
void statusOfLibrary (void); 
void returnBook (void); 

/**
 * Library system Utilities Fucntion declaration 
*/

list<Author>::iterator get_author_ref (Author&); 
list<Book>::iterator get_book_ref (Book&, list<Book>&);
// print all options of menu and return choosen menu  
int menu (void); 

// Add few Books and patron in the library. 
void readyLibrary (void); 
// Add some patrons in the main data base of libaray 
void add__some_PatronInfo_inLibrary(); 

