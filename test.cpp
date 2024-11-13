# include "MyString.h"
# include "Rover.h"

void testAssignmentOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Assignment Operator (=): " << std::endl;
    MyString result = lhs + rhs;
    std::cout << "Expected: HowdyAggies, Got: " << result.data();
}

void testAppendOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Append Operator (+=): " << std::endl;
    lhs += rhs;
    std::cout << "Expected: HowdyAggies, Got: " << lhs.data();
}

void testEqualityOperator(MyString lhs, MyString rhs)
{

}

void testAdditionOperator(MyString lhs, MyString rhs)
{

}

int main ()
{
    MyString str1 = MyString("Howdy");
    MyString str2 = MyString("Aggies");
    MyString result;

    testAssignmentOperator(str1, str2);
    testAppendOperator(str1, str2);

    return 0;
}