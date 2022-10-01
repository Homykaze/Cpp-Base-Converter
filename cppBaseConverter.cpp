#include <iostream>
#include <string>
using namespace std;

/// Prints out the result by calling its subfunctions
/// \param input: Integer input value to convert to another base
void convert(long long int input);

/// Function to convert one base number to another base number
/// \param input: Integer input value to convert
/// \param base: Base value to convert to
/// \return String representation of the desired base number
string newBase(long long int input, const short signed int &base);

/// Simple integer converter to its symbolic char representation,
/// converts integers in range [0-15]
/// \param remainder: Value to convert to char
/// \return Char symbol of the input integer
char intToChar(const short signed int &remainder);

/// Driver code
int main()
{
    long long int input;
    cout << "Enter a non-negative base ten number: ";
    // This program does not work with decimals and negative numbers (yet!)
    cin >> input;
    convert(input);
}

char intToChar(const short signed int& remainder)
{
    // Very easy to extend the list
    switch (remainder)
    {
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    default:
        return '0';
    }
}

string newBase(long long int input, const short signed int& base)
{
    if (input == 0)
        return "0";

    // output is for remainders, backwards is actual result, remainder is the remaining result of division
    string output = "";
    string backwards = "";
    short signed int remainder = 0;

    // Main loop of getting remainders from division by the given base
    while (input > 0)
    {
        remainder = input % base;
        // Using a utility function here
        output += intToChar(remainder);
        input /= base;
    }

    // Reversing the string with the loop and return statement below
    string::iterator itr = --output.end(), begin = output.begin();
    for (itr; itr > begin; --itr)
        backwards += *itr;

    return backwards + *begin;
}

void convert(long long int input)
{
    cout << "Your number in bases 2-16: " << endl;
    // Running a loop of calling the conversion function
    // This allows to easily add greater bases conversion if needed
    for (short signed int i = 2; i < 17; ++i)
        cout << input << " Base " << i << ": " << newBase(input, i) << endl;
}