#include<iostream>

using namespace std; 

void fun(void); 
void fun(void);
//Multiple Declaration is possible 


void fun()
{
  cout<< "Hello From  fun "<< endl; 
}

// void fun()
// {
//   cout<< "Hello From  fun "<< endl; 
// }

//Multiple definition is not possible 

class MyClass
{
  public: 
    MyClass() = default; 
    
    void print(){
      cout<<"datas = "<< datas<< endl; 
    }

      int datas{199}; 
}; 


int main()
{
  MyClass obj1; 
  obj1.print(); 

  // fun(); 

  return 0; 
}