#include<iostream>


/*
  A Non Member function can be friend function 
  of Multiple classes 
*/


class MyClass 
{
  public: 
    void fun (void)const 
    {
      std::cout<< "This is from MyClass \n"; 
    }
  private: 
    friend void friendFun (void) ;  
}; 

class MyClass1
{
  public: 
    void print (void) const 
    {
      std::cout<< "This is From MyClass1 \n"; 
    }
  
  private: 
    friend void friendFun (void) 
    {
      std::cout<< "This is From myClass1's Friend function "<< std::endl; 
    }
}; 

void friendFun (); 

int main()
{
  MyClass obj; 

  obj.fun();
  friendFun();  
}