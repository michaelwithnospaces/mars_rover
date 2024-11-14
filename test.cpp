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

void testResize(MyString lhs)
{
    std::cout << "Testing Resize: " << std::endl;
    lhs.resize(10);
    std::cout << "Expected: Howdy, Got: " << lhs.data() << std::endl;
    lhs.resize(3);
    std::cout << "Expected: How, Got: " << lhs.data() << std::endl << std::endl;
}

void testClear(MyString lhs)
{
    std::cout << "Testing Clear: " << std::endl;
    lhs.clear();
    std::cout << "Expected: \"\", got " << lhs.data() << std::endl << std::endl;
}

void testFind(MyString lhs)
{
    std::cout << "Testing Find: " << std::endl;
    size_t result = lhs.find("ow", 0);
    std::cout << "Expected: 1, got " << result << std::endl << std::endl;
}

void testAt(MyString lhs)
{
    std::cout << "Testing At: " << std::endl;
    std::cout << "Expected: H, got " << lhs.at(0) << std::endl;
    
    std::cout << "Testing At: " << std::endl;
    std::cout << "Expected: [throw std::out_of_range], got " << lhs.at(100) << std::endl << std::endl;
}

void testAssignmentOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Assignment Operator (=): " << std::endl;
    lhs = rhs;
    std::cout << "Expected: Aggies, Got: " << lhs.data() << std::endl << std::endl;
}

void testAppendOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Append Operator (+=): " << std::endl;
    lhs += rhs;
    std::cout << "Expected: HowdyAggies, Got: " << lhs.data() << std::endl << std::endl;
}

void testEqualityOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Equality Operator (==): " << std::endl;
    bool result = lhs == rhs;
    std::cout << "Expected: 0, Got: " << result << std::endl;
    MyString str1 = MyString("Howdy");
    result = lhs == str1;
    std::cout << "Expected: 1, Got: " << result << std::endl << std::endl;
}

void testAdditionOperator(MyString lhs, MyString rhs)
{
    std::cout << "Testing Addition Operator (+): " << std::endl;
    MyString result = lhs + rhs;
    std::cout << "Expected: HowdyAggies, Got: " << result.data() << std::endl << std::endl;
}

void testingOSStream(MyString lhs, MyString rhs)
{
    std::cout << "Testing Insertion Operator (<<): " << std::endl;
    std::cout << "Expected: Howdy Aggies, Got: ";
    std::cout << lhs << " " << rhs << std::endl;
}

int main ()
{
    MyString str1 = MyString("Howdy");
    MyString str2 = MyString("Aggies");
    MyString result;

    // testConstructor()
    testCopyConstructor(str1);
    // testCopyConstructorFromCStr();
    testResize(str1);
    testClear(str1);
    testFind(str1);
    testAt(str1);
    testAssignmentOperator(str1, str2);
    testAppendOperator(str1, str2);
    testEqualityOperator(str1, str2);
    testAdditionOperator(str1, str2);
    testingOSStream(str1, str2);

    return 0;
}