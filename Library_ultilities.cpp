#include<iostream>
#include"Library_utilities.hpp"
using namespace std; 

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
} 
