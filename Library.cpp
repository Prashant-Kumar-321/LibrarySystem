#include<cctype>

#include"Library.h"

#define MAX_ALPHABET 26


list<Author> catalog[MAX_ALPHABET]; //Array of list of Author //Size 91
list<Patron> people[MAX_ALPHABET];  //Array of list of Patron //size 91


ostream& Book::printBook(ostream& out) const 
{
  out<< "       * "<< title; 

  if(patron != nullptr)    // if book is checkOut by someone print his name
    out<< " - Checked out to "<< patron->name; //overloaded << 
  
  out<< endl; 
  return out; 
}

ostream& Author::printAuthor(ostream& out)const 
{
  out<< name<< endl; //Author name 

  for( auto book: books ) // print all books of that author
    out<< book;  
  
  return out; 
}

ostream& Patron::printPatron( ostream& out) const 
{
  out<< name<< " :- "; 
  
  if( !books.empty() )
  {
    out<< "has the follwing books: \n"; 

    for(auto checkedBook: books) {                       //print all books that has been checked out by the patron 
      out<< "    * "<< checkedBook.author->name<< ", "
         << checkedBook.book->title<< endl; 
    }

  }
  else 
    out<< "has no books \n"; 
  
  return out; 
}

template< typename T >
ostream& operator<< ( ostream& out, const list<T>& list ){

  for (T item: list)
    out<< item; 

  return out; 
}

char* getString ( char* message) 
{
  char s[82]; 
  char* destin; 

  std::cout<< message; 
  std::cin.get(s, 80); 

  while ( std::cin.get(s[81]) && s[81] != '\n');  // Discard overflow 
  destin = new char[strlen(s)+1];                 // Characters 

  for ( int i = 0; destin[i] = toupper(s[i]); ++i);    // copy string to destination

  return destin;  
}

