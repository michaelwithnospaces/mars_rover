// TODO: Implement this header file
# ifndef MY_STRING_H
# define MY_STRING_H

class MyString
{
private:

public:
    MyString ();                          // Constructor
    MyString (const MyString& strToCopy); // Copy Constructor
    MyString (const char* cstr);          // From C-String: Accept a C-string as input and convert to MyString
    ~MyString ();                         // Destructor

    void resize (size_t n);               // Resizes the string to a length of n characters
    void clear ();                        // Clears contents of string

    size_t capacity () const;             // Returns size of storage space currently allocated for string (bytes)
    size_t size () const;                 // Returns current number of elements in the array
    size_t length () const;               // Returns length of the string (bytes)
    size_t find (const MyString& str,    // Searches string for first occurrence of sequence specified by arguments
                 size_t pos = 0) const; 

    bool empty () const;                  // Returns whether string is empty

    const char* data () const;            // convenient way to access internal string in c-string format
    const char& front () const;           // A reference to first character in the string
    const char& at (size_t pos) const;    // Returns reference to character at position pos in string

    MyString& operator= (const MyString& strToAssign); // Assignment operator
    MyString& operator+= (const MyString& str);        // Extends string
    bool operator== (const MyString& rhs);
    MyString operator+ (const MyString& rhs);

    // operator<< can’t be member of MyString because std::ostream (like std::cout) needs to be on left.
    // Defining operator<< as non-member friend function allows it to interact with MyString class 
    // while maintaining compatibility with C++’s stream operators.
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);

    // comparison operation between the string objects lhs and rhs.
    // friend bool operator== (const MyString& lhs, const MyString& rhs);    // non-member

    // friend MyString operator+ (const MyString& lhs, const MyString& rhs); // non-member
};

# endif