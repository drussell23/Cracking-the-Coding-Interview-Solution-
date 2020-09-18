// Cracking the Coding Interview - Interview Questions 
// (1.3) - URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
//         has sufficient space at the end to hold the additional characters, and that you are given the "true"
//         length of the string. (Note: If implementing in Java, please use a character array so that you can 
//         perform this operation in place.)

// EXAMPLE 
// Input:   "Mr John Smith    ", 13
// Output:  "Mr%20John%20Smith"

#include <iostream>
#include <cstring>

using namespace std;

void urlify(char *str, int len)
{
    int numOfSpaces = 0;
    int i = 0, j = 0;

    for(i = 0; i < len; ++i)
    {
        if(str[i] == '')
        {
            ++numOfSpaces;
        }
    }

    int extendedLen = len + 2 * numOfSpaces;
    i = extendedLen - 1;

    for(j = len - 1; j >= 0; --j)
    {
        if(str[j] != '')
        {
            str[i--] = str[j];
        }
        else
        {
            str[i--] = '0';
            str[i--] = '2';
            str[i--] = '%';
        }
    }
}
int main()
{
    char str[] = "Mr. John Smith    ";
    
    cout << "Actual string  : " << str << endl;
    
    urlify(str, 13);

    cout << "URLified string : " << str << endl;

    return 0;
}