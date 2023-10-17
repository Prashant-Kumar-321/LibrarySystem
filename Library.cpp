#include<cctype>

#include"Library.h"

#define MAX_ALPHABET 26


list<Author> catalog[MAX_ALPHABET]; //Array of list of Author //Size 26
list<Patron> people[MAX_ALPHABET];  //Array of list of Patron //size 26


ostream& Book::printBook(ostream& out) const 
{
  out<< "       * "<< title; 

  if( patron != nullptr)    // if book is checkOut by someone print his name
    out<< " - Checked out to "<< patron->name; //overloaded << 
  
  out<< endl; 
  return out; 
}

ostream& Author::printAuthor(ostream& out) const 
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

template< class T >
ostream& operator<< ( ostream& out, const list<T>& list ){

  for (T item: list)
    out<< item; 

  return out; 
}

char* getString ( const char* message) 
{
  char name[82]; 
  char* destin; 

  std::cout<< message; 
  std::cin.get(name, 80); 

  while ( std::cin.get(name[81]) && name[81] != '\n');  // Discard overflow 
  destin = new char[strlen(name)+1];                 // Characters 

  for ( int i = 0; destin[i] = toupper(name[i]); ++i);    // copy string to destination

  return destin;  
}

// List down all books avialable in the library and 
// all peoples and checkout books 
void statusOfLibrary (void)
{
  register int i; 

  cout<< "Library has the following books: \n\n"; 
  for (i = 'A'; i<='Z'; ++i)
  {
    if (!catalog[i-'A'].empty())
      std::cout<< catalog[i]; 
  }
  cout<< endl; 

  std::cout<< "The following people are using the library: \n\n"; 
  for (i='A'; i<='Z'; ++i)
  {
    if ( !people[i-'A'].empty() )
      cout<< people[i]; 
  }
  cout<< endl; 
}

void includeBook (void) 
{
  Author newAuthor; 
  Book   newBook; 

  newAuthor.name = getString("Enter the Author name : "); 
  newBook.title = getString("Enter title of the book : "); 

  list<Author>& authors = catalog[newAuthor.name[0]-'A']; // list of author whose name starts with the same letter as newAuthor.  

  // searching the autor in the author list whose name starts with the same letter as new Author
  list<Author>::iterator oldAuthor = std::find(authors.begin(), authors.end(), newAuthor); 

  if (oldAuthor == authors.end()) // new Author does not already exist in the list
  {
    newAuthor.books.push_back(newBook); 
    authors.push_front(newAuthor); 
  }
  else  // Author already exist in the list of authors 
  {
    list<Book>::iterator oldBook = std::find(oldAuthor->books.begin(), oldAuthor->books.end(), 
    newBook); 

    if ( oldBook == oldAuthor->books.end() ) // new Books doesn't exist 
        oldAuthor->books.push_front(newBook); 
  }
}

