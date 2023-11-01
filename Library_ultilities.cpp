#include<iostream>
#include"Library_utilities.hpp"
using std::cout, std::cin; 

int menu (void)
{
  int option; 

  cout<< "\nEnter one of the following options: "<< endl; 
  cout<< "1. Include a Book in the catalog\n"; 
  cout<< "2. Check out a Book \n"; 
  cout<< "3. Return a Book \n"; 
  cout<< "4. Library Status \n"; 
  cout<< "5. Exit the Program \n"; 

  cin>> option; 
  cin.get(); // discard '\n'

  return option; 
}

void readyLibrary (void)
{
  includeBook("Agatha Christie", "Death on the Nile"); 

  includeBook("Arthur Koestler", "Darkness at noon"); 
  includeBook("Arthur Koestler", "Arrow in the Blue"); 
  includeBook("Arthur Koestler", "The invisible Writing");

  includeBook("Charles Dickens", "Great Expectations");  
  includeBook("Charles Dickens", "A Tale of Two Cities");   
  includeBook("Charles Dickens", "Oliver Twist");   
  
  
  includeBook("Dr. Seuss", "The cat in the hat");   
  includeBook("Dr. Seuss", "Green Eggs and Ham");   
  includeBook("Dr. Seuss", "One fish two fish red fish blue fish");

  includeBook("E_Author", "Book1"); 
  includeBook("E_Author", "Book2"); 

  includeBook("Emily Dickinson", "Numerous Poems"); 

  includeBook("Ernest Hemingway", "The old man and the sea"); 
  includeBook("Ernest Hemingway", "A farewell to arms"); 

  includeBook("J_Author", "Book1"); 

  includeBook("J.k. Rowling", "Harry Potter and the sorcerer's stone");    
  includeBook("J.k. Rowling", "Harry Potter and the the Chamber of secrets");    
  includeBook("J.k. Rowling", "Harry Potter and the prisoner of azkaban");    

  includeBook("J.R.R Tolkien", "The lord of the rings"); 
  includeBook("j.r.r Tolkien", "The Hobbit"); 

  includeBook("Jane Austen", "Pride and prejudice"); 
  includeBook("Jane Austen", "of mice and men"); 
  includeBook("Jane Austen", "East of Eden"); 

  includeBook("M_Author", "Book0"); 
  includeBook("M_Author", "Book1"); 
  includeBook("M_Author", "Book2"); 
  includeBook("M_Author", "Book3"); 

  includeBook("Mark Twain", "The Adventures of tom sawyer"); 
  includeBook("Mark Twain", "The prince and pauper"); 
  includeBook("Mark Twain", "The mysterious stranger"); 

  includeBook("Maya Angelou", "I know why the caged bird sings"); 
  includeBook("Maya Angelou", "The heart of the women"); 
  includeBook("Maya Angelou", "And still i rise"); 

  includeBook("Oscar Wilde", "The Picture of Dorain Gray"); 
  includeBook("Oscar Wilde", "An Ideal Husband"); 
  includeBook("Oscar Wilde", "De Profundis"); 

} 
