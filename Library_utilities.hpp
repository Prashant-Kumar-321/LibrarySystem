#include<iostream>
#include"Library.h"

// Definition of Each function is in the Library.cpp file 
void aux_includeBook( Author& authorName, Book& bookTitle); 
void includeBook (void);
void includeBook( const char* authorName, const char* booktitle); 
void checkOutBook (void); 
void statusOfLibrary (void); 
void returnBook (void); 

int menu (void); 
void readyLibrary (void); 
