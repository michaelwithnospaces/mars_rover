# include "MyString.h"

MyString::MyString() : string("") {};

MyString::MyString (const MyString& strToCopy) : string(strToCopy.string) {};

MyString::MyString (const char* cstr)
{
    
}