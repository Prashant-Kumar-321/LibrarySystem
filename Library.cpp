#include<cctype>

#include"Library.h"

/*There are 26 letter in english Alphabet*/
list<Author> catalog[26]; //Array of list of Author //Size 26
list<Patron> people[26];  //Array of list of Patron //size 26


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

void checkOutBook (void)
{
  Author author; 
  Patron patron; 
  Book book; 

  patron.name = getString("Enter name of Patron: "); 
  book.title = getString("Enter title of book: ");

  auto& authors = catalog[author.name[0]-'A']; 
  auto availableAuthor = std::find(authors.begin(), authors.end(), author); 


  while (true)
  {
    author.name = getString("Eneter Author name :");

    if ( availableAuthor != authors.end()) // got the author in the list 
    {
      // check if book is available or not 
      auto availableBook = std::find(availableAuthor->books.begin(), availableAuthor->books.end(), book);

      
      if ( availableBook != availableAuthor->books.end() && availableBook->patron == nullptr ) // Book is available for checking out
      {
        CheckOutBook checkoutbook(availableBook, availableAuthor);

        // availableBook->patron = &patron;  

        auto& patrons = people[patron.name[0]-'A']; 
        auto oldPatron = std::find(patrons.begin(), patrons.end(), patron);  

        if ( oldPatron != patrons.end() ) // oldPatron already exist in the list of patrons whose name starts with same leter as patorn
        {
          oldPatron->books.push_front(checkoutbook); 
          availableBook->patron = &(*oldPatron); 
        }
        else  // A new patron in the library 
        {
          patron.books.push_back(checkoutbook);
          patrons.push_front(patron); 
          availableBook->patron = &*(patrons.begin()); 
        }
      }
      else   // book is already being checking out by someone or that books does not exits  
      {
        if ( availableBook == availableAuthor->books.end()) // book does not exist 
          cout<< book.title<< " does not exist "<< endl; 
        else  // checking out by someone 
          std::cout<< availableBook->patron->name<< " is Checking out the \""<< availableBook->title<< "\""<< endl; 
      }

      break; 
    }
    else // Miss Spelling of author name 
    {
      cout<< "Author spelling is wrong "<< endl; 
      cout<< "Enter Correct spelling "<< endl; 
    }
  }
}

void returnBook()
{
  Author author; 
  Book book; 
  Patron patron; 


  std::list<Author>::iterator authorRef; 
  std::list<Book>::iterator bookRef;
  std::list<Patron>::iterator patronRef; 

  // getting the Reference of patron 
  while (true)
  {
   patron.name = getString("Enter patron's name: "); 
   std::list<Patron>& patrons = people[patron.name[0]-'A']; 

    patronRef = std::find(patrons.begin(), patrons.end(), patron); 

    if( patronRef == patrons.end()) 
      std::cout<< "MissSpelled Patron's name "<< std::endl; 
    
    else break;  
  }

  // Getting the Ref of Author
  while ( true)
  {
    author.name = getString("Enter author's name: ");
    std::list<Author>& authors = catalog[author.name[0]-'A']; 
    authorRef = std::find(authors.begin(), authors.end(), author); 

    if( authorRef == authors.end())
      cout<< "MissSpelled Author's Name: "<< std::endl;
    
    else break;  
  }

  // Getting the Reference of Book
  while ( true)
  {
    book.title = getString("Enter book's title: "); 
    bookRef = std::find(authorRef->books.begin(), authorRef->books.end(), book); 
    
    if( bookRef == authorRef->books.end() )
      cout<< "MissSpelled the Book's titile "<< endl; 
    
    else break; 
  }

  CheckOutBook returnedBook(bookRef, authorRef); 

  // auto checkoutBookRef = std::find(patronRef->books.begin(), patronRef->books.end(), returnedBook);

  bookRef->patron = nullptr; // now can be checked out 
  patronRef->books.remove(returnedBook); 

}
 