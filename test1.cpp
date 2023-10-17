#include<iostream>
#include<cstring>
#include<list>
using namespace std; 


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

int main (int argc, char** argv)
{
  // char* authorName = getString("Enter Author's name "); 
  // printf("Author name = %s \n", authorName); 
  // delete[] authorName; 

  list<char*> names; 
  names.push_back(new char[20]); 
  names.push_back(new char[20]); 
  names.push_back(new char[20]); 

  // Deallocate the char arrays 
  for (char* name: names)
    delete[] name; 

  return 0; 
}