#include<iostream>
#include<cstring>

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
  // MyClass obj1; 
  // obj1.print(); 

  // fun(); 

  // char message[20] = "12345";
  // while( std::cin.get(message[0]).get() && printf("%d \n", message[0]) && message[0] != '\n' ); 
  // for ( int i=0; message[i]; ++i){
  //   cout<< (int)message[i]<< endl; 
  // }

  // cout<< (int)'\n'<< endl; 

  // cin.get(message[0]); 

  // cout<< "Enter your messge : \n"; 
  // cin.get(message, 9); 
  // cout<< "\n\nYou have this message : "<< endl; 
  // cout<< message<< endl; 


  char message[20] = "12345";
  cin.get(message, 18); 

  while( cin.get(message[19]) && message[19] != '\n'); 

  for(int i=0; i<20; ++i)
    printf("%c ==> %d \n", message[i], message[i]); 
  
  cout<< strlen(message); 







  return 0; 
}