#include<iostream>
#include"Library.h"

using std::cout; 

int main (int argc, char** argv)
{
  readyLibrary();
  while (true)
  {
    int userChoice = display_menu_takeUserChoice(); 
    performAction(userChoice); 
  }
  cin.get(); 
  return 0; 
}