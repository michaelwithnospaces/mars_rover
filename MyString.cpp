# include "MyString.h"

MyString::MyString() : cstring_(new char[1]), length_(0), capacity_(0) 
{
    cstring_[0] = '\0';
};

MyString::MyString (const MyString& strToCopy) : cstring_(nullptr), length_(strToCopy.length_), capacity_(strToCopy.capacity_) 
{
    // deep copy
    cstring_ = new char[this->length_ + 1]; // +1 for null terminator

    for (size_t i = 0; i < length_; ++i)
    {
        this->cstring_[i] = strToCopy.cstring_[i];
    }
    this->cstring_[length_] = '\0'; // null terminate the string
};

MyString::MyString (const char* cstr) : cstring_(nullptr), length_(0), capacity_(0)
{
    // deep copy
    this->length_ = 0;
    // find length by iterating until not null terminator
    while (cstr[this->length_] != '\0')
    {
        ++(this->length_);
        ++(this->capacity_);
    }

    cstring_ = new char[this->length_ + 1]; // +1 for null terminator

    for (size_t i = 0; i < length_; ++i)
    {
        this->cstring_[i] = cstr[i];
    }
    this->cstring_[length_] = '\0'; // null terminate the string
}

MyString::~MyString () 
{ 
    delete [] this->cstring_; 
    this->cstring_ = nullptr; // prevents dangling pointers
};

void MyString::resize (size_t n)
{
    if (n == this->length_) return; // if resizing to same size

    // resize bigger
    if (n > this->capacity_)
    {
        // if n is greater then 2 times current capacity, change capacity to n
        // if n is less than 2 times current capacity, double capacity
        size_t newCapacity = (n > 2 * this->capacity_) ? n : 2 * this->capacity_;

        char* resizedString = new char[n + 1];

        for (size_t i = 0; i < this->length_; ++i)
        {
            resizedString[i] = this->cstring_[i];
        }
        resizedString[this->length_] = '\0';

        delete [] this->cstring_;
        this->cstring_ = resizedString;
        this->capacity_ = newCapacity;
    }
    
    // if the size is smaller, then you just move the null terminator;
    this->length_ = n;
    this->cstring_[n] = '\0';
}

void MyString::clear ()
{
    // char* emptyString = new char[1];
    // emptyString[0] = '\0';

    // this->length_ = 0;
    // delete [] this->cstring_;
    // this->cstring_ = emptyString;

    resize(0); // lol
}

const char* MyString::data () const
{
    return this->cstring_;
}

MyString& MyString::operator= (const MyString& strToAssign)
{
    if (this == &strToAssign) return *this; // self assignment

    delete [] this->cstring_;
    this->length_ = strToAssign.length_;
    this->capacity_ = strToAssign.capacity_;

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
        result.cstring_[index++] = this->cstring_[i]; // index++ specifies to use, then increment
    }

    // copy rhs to the result c-string
    for (size_t i = 0; i < rhs.length_; ++i)
    {
        result.cstring_[index++] = rhs.cstring_[i];
    }

    // after loop finishes, index incremented to result.length_
    result.cstring_[result.length_] = '\0';

    return result;
}