# include "MyString.h"

void testConstructor()
{

}

void testCopyConstructor(MyString lhs)
{
    std::cout << "Testing Copy Constructor: " << std::endl;
    std::cout << "Expected: Howdy, Got: " << lhs.data() << std::endl << std::endl;
}

void testCopyConstructorFromCStr()
{

}

void testAssignmentOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Assignment Operator (=): " << std::endl;
    lhs = rhs;
    std::cout << "Expected: Aggies, Got: " << lhs.data() << std::endl << std::endl;
}

void testAppendOperator(MyString lhs, MyString rhs)
{
    // std::cout << "Testing Append Operator (+=): " << std::endl;
    // lhs += rhs;
    // std::cout << "Expected: HowdyAggies, Got: " << lhs.data();
}

void testEqualityOperator(MyString lhs, MyString rhs)
{

}

void testAdditionOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Addition Operator (+): " << std::endl;
    MyString result = lhs + rhs;
    std::cout << "Expected: HowdyAggies, Got: " << result.data() << std::endl << std::endl;
}

int main ()
{
    MyString str1 = MyString("Howdy");
    MyString str2 = MyString("Aggies");
    MyString result;

    // testConstructor()
    testCopyConstructor(str1);
    // testCopyConstructorFromCStr();
    testAssignmentOperator(str1, str2);
    testAppendOperator(str1, str2);
    // testEqualityOperator(str1, str2)
    testAdditionOperator(str1, str2);

    return 0;
}