# include "MyString.h"

MyString::MyString() : cstring_("") {};

MyString::MyString (const MyString& strToCopy) : cstring_(strToCopy.cstring_) {};

MyString::MyString (const char* cstr)
{
    // if cstr is non empty
    if (cstr != nullptr)
    {
        this->length_ = 0;
        // find length by iterating until not null terminator
        while (cstr[this->length_] != '\0')
        {
            ++(this->length_);
        }

        cstring_ = new char[this->length_ + 1]; // +1 for null terminator

        for (int i = 0; i < length_; ++i)
        {
            this->cstring_[i] = cstr[i];
        }
        this->cstring_[length_] = '\0'; // null terminate the string
    }
    else
    {
        this->length_ = 0;
        this->cstring_ = new char[1];
        this->cstring_[0] = '\0';
    }
}
