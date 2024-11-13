# include "MyString.h"

MyString::MyString() : cstring_(new char[1]), length_(1) 
{
    cstring_[0] = '\0';
};

MyString::MyString (const MyString& strToCopy) : cstring_(nullptr), length_(strToCopy.length_) 
{
    // deep copy
    // if cstr is non empty
    if (strToCopy.cstring_ != nullptr)
    {
        cstring_ = new char[this->length_ + 1]; // +1 for null terminator

        for (size_t i = 0; i < length_; ++i)
        {
            this->cstring_[i] = strToCopy.cstring_[i];
        }
        this->cstring_[length_] = '\0'; // null terminate the string
    }
    else
    {
        this->length_ = 0;
        this->cstring_ = new char[1];
        this->cstring_[0] = '\0';
    }
};

MyString::MyString (const char* cstr) : cstring_(nullptr), length_(0)
{
    // deep copy
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
    // abuses already made overloaded addition operator
    *this = *this + str;
    return *this;
}

bool MyString::operator== (const MyString& rhs)
{
    if (this->length_ != rhs.length_) return false;

    for (size_t i = 0; i < this->length_; ++i)
    {
        if (this->cstring_[i] != rhs.cstring_[i]) return false;
    }

    return true;
}

MyString MyString::operator+ (const MyString& rhs)
{
    MyString result = MyString();

    delete [] result.cstring_; // free existing memory

    result.length_ = this->length_ + rhs.length_;
    result.cstring_ = new char[result.length_ + 1];

    size_t index = 0;
    // copy lhs to the result c-string
    for (size_t i = 0; i < this->length_; ++i)
    {
        result.cstring_[index] = this->cstring_[i];
        ++index;
    }

    // copy rhs to the result c-string
    for (size_t i = 0; i < rhs.length_; ++i)
    {
        result.cstring_[index] = rhs.cstring_[i];
        ++index;
    }

    // after loop finishes, index incremented to result.length_
    result.cstring_[index] = '\0';

    return result;
}