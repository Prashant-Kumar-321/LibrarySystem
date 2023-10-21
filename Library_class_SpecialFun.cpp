#include"Library.h"

Book::Book( const Book& otherBook)
{ 
  cout<< "Book constructor \n"; 
  title = new char[strlen(otherBook.title)+1];
  strcpy(title, otherBook.title);  
}

Book& Book::operator= ( const Book& other)
{
  cout<< "Book assingment Operator \n"; 
  if( this != &other) // no self assignment
  {
    delete[] title; 

    title = new char[strlen(other.title)+1]; 
    strcpy(title, other.title); 
  }

  return *this; 
}

Author::Author ( const Author& other)
{
  cout<< "Author Constructor \n"; 
  name = new char[strlen(other.name)+1]; 
  strcpy(name, other.name); 
} 

Author& Author::operator= ( const Author& other)
{
  cout<< "Author assignment operator \n"; 
  if (this != &other) // No self Assignment
  {
    delete[] name; 
    name = new char[strlen(other.name)+1]; 
    strcpy(name, other.name); 
  }

  return *this; 
} 

Patron::Patron ( const Patron& other)
{
  name = new char[strlen(other.name)+1]; 
  strcpy(name, other.name); 
}
Patron& Patron::operator= ( const Patron& other)
{
  if ( this != &other) // no self assignment 
  {
    delete[] name; 
    name = new char[strlen(other.name)+1]; 
    strcpy(name, other.name); 
  }

  return *this; 
} 