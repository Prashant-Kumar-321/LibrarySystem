#include<cctype>
#include<conio.h>
#include"Library.h"

// Create an Array 
std::list<Author> catalog[26]; //Array of list of Author //Size 26
std::list<Patron> people[26];  //Array of list of Patron //size 26

// comparing equality of Books 
bool Book::operator== ( const Book& otherBook){
  return this->title == otherBook.title; 
}

// Print a Book 
ostream& operator<< ( ostream& out, const Book& book) {
  return book.printBook(out); 
}

ostream& Book::printBook(ostream& out) const 
{
  out<< "       * "<< title; 

  if ( patron != nullptr)  // Book is being checking out by someone 
    out<< " - Checked out to "<< "\""<< patron->name<< "\""; //overloaded << 
  out<< endl; 

  return out; 
}

// compare Authors 
bool Author::operator== ( const Author& otherAuthor){
  return this->name == otherAuthor.name; 
}

// print Author and all its Book 
ostream& operator<< ( ostream& out, const Author& author){
  return author.printAuthor(out); 
}

ostream& Author::printAuthor( ostream& out) const 
{
  out<< name<< endl; // Author name 

  auto book = books.cbegin(); 
  for ( ; book != books.cend(); ++book)
    std::cout<< *book ; // operator<< knows how to print a book  
  
  return out; 
}

bool CheckOutBook::operator== ( const CheckOutBook& otherCheckout){
  return ( *book == *otherCheckout.book && 
            *author == *otherCheckout.author ); 
}

// Compare two Patrons
bool Patron::operator== (const Patron& otherPatron)const {
  return name == otherPatron.name;
}

ostream& operator<< ( ostream& out, const Patron& patron){
  return patron.printPatron(out); 
}

// print a patron name and books being checkingOut 
ostream& Patron::printPatron ( ostream& out) const 
{
  out<< "\""<< name << "\""; 
  
  if( !books.empty() ) // He has checked out some book 
  {
    out<< " :- Has the follwing books: "<< std::endl; 

    // print all books that he is checking out 
    for( auto& checkedBook: books) { 
      out<< "    * "<< checkedBook.author->name<< "--> "
         << checkedBook.book->title<< endl; 
    }

  }
  else 
    out<< " :- Has no books \n"; 
  out<< std::endl; 
  return out; 
}

// Print all items of a list.
/**
 * All Authors of the list 
 * All Patrons of the list 
 **/ 

template< class T >
ostream& operator<< ( ostream& out, const list<T>& list ) {
  auto item = list.begin(); 
  for ( item; item != list.end(); ++item)
    cout<< *item<< endl; 

  return out; 
}

// Take string input from user and return it 
std::string getString ( const char* message) 
{
  std::string name;  

  std::cout<< message; 
  getline(std::cin, name); 

  // convert name tp Upper case 
  for ( int i=0; i<name.length(); ++i)
    name[i] = std::toupper(name[i]); 
  
  return name; 
}


// List down all books avialable in the library and 
// all peoples and their checkout books 
void statusOfLibrary (void)
{
  int i; 

  cout<< "Library has the following books: \n\n"; 
  for (i = 'A'; i<='Z'; ++i)
  {
    if ( !catalog[i-'A'].empty())
      std::cout<< catalog[i-'A'];// above overloaded operator<< will be called  
  }
  cout<< endl; 

  std::cout<< "The following people are using the library: \n\n"; 
  for (i='A'; i<='Z'; ++i)
  {
    if ( !people[i-'A'].empty() )
      cout<< people[i]; // above overloaded operator<< will be called 
  }

  cout<< endl; 
}

void aux_includeBook (Author& newAuthor, Book& newBook)
{
  list<Author>& curr_authors = catalog[newAuthor.name[0]-'A']; // list of author whose name starts with the same letter as newAuthor.  

  // searching the autor in the author list whose name starts with the same letter as new Author
  list<Author>::iterator oldAuthor = std::find(curr_authors.begin(), curr_authors.end(), newAuthor); 

  if ( oldAuthor == curr_authors.end()) // new Author does not already exist in the list
  {
    newAuthor.books.push_back(newBook); 
    curr_authors.push_back(newAuthor); 
  }
  else  // Author already exist in the list of authors 
  {
    list<Book>::iterator oldBook = std::find(oldAuthor->books.begin(), oldAuthor->books.end(), 
    newBook); 
    if ( oldBook == oldAuthor->books.end() ) // new Books doesn't exist 
      oldAuthor->books.push_back(newBook); 
  }
} 

std::string  TO_upper (const char* str)
{
  std::string upperStr(str); 
  for( int i=0; i< upperStr.length(); ++i)
    upperStr[i] = std::toupper(upperStr[i]); 
  
  return upperStr; 
}

void includeBook (void) 
{
  Author newAuthor; 
  Book   newBook; 

  newAuthor.name = getString("Enter the Author name : "); 
  newBook.title = getString("Enter title of the book : "); 

  aux_includeBook(newAuthor, newBook); 
}

void includeBook( const char* authorname, const char* booktitle)
{
  Author newAuthor; 
  Book newBook; 

  newAuthor.name = TO_upper(authorname); 
  newBook.title = TO_upper(booktitle);

  aux_includeBook(newAuthor, newBook); 
}


void checkOutBook (void)
{
  Author author; 
  Patron patron; 
  Book book; 

  patron.name = getString("Enter name of Patron: "); 
  book.title = getString("Enter title of book: ");

  while (true)
  {
    author.name = getString("Eneter Author name :");
    auto& authors = catalog[author.name[0]-'A']; 
    auto availableAuthor = std::find(authors.begin(), authors.end(), author); 

    if ( availableAuthor != authors.end() ) // got the author in the list 
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
          availableBook->patron = &(*patrons.begin()); 
        }

        cout<<"Patron name = "<< patron.name << endl;
        cout<< "Books is being checking out"<< *availableBook<< endl; 
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
