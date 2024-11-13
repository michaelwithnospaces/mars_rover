# include "MyString.h"

MyString::MyString() : cstring_(new char[1]), length_(1) 
{
    cstring_[0] = '\0';
};

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

        for (size_t i = 0; i < length_; ++i)
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

MyString::~MyString () { delete [] this->cstring_; };

const char* MyString::data () const
{
    return this->cstring_;
}

MyString& MyString::operator= (const MyString& strToAssign)
{
    if (this == &strToAssign) return *this; // self assignment

    delete [] this->cstring_;
    this->length_ = strToAssign.length_;

    this->cstring_ = new char[this->length_ + 1];

    for (size_t i = 0; i < this->length_; ++i)
    {
        this->cstring_[i] = strToAssign.cstring_[i];
    }
    this->cstring_[length_] = '\0';

    return *this;
}

MyString& MyString::operator+= (const MyString& str)
{

}

bool MyString::operator== (const MyString& rhs)
{

}

MyString MyString::operator+ (const MyString& rhs)
{

}