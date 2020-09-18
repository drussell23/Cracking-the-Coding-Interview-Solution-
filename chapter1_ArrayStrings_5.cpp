// Cracking the Coding Interview - Interview Questions 
// (1.5) One Away: There are three types of edits can be performed on strings: insert a character, remove a character, 
//       remove a character, or replace a character. Given two strings, write a function to check if they are one edit 
//       (or zero edits) away.

#include <iostream>
#include <string>

using namespace std;

bool isOneAway(string s1, string s2)
{
    string a, b;
    a = s1.length() >= s2.length() ? s1 : s2;
    b = s1.length() < s2.length() ? s1 : s2;
    int len1, len2;
    len1 = a.length();
    len2 = b.length();

    if(abs(len1-len2) > 1)
    {
        return false;
    }
    
    bool flag = false;

    for(int i = 0, j = 0; i < len1 && j < len2;)
    {
        if(a[i] != b[j])
        {
            if(flag)
                return false;
            flag = true;
            if(len1 == len2)
                i++, j++;
            else 
                i++;
        }
        else
            i++, j++;
    }
    return true;
}
int main(void)
{
    stirng s1, s2;
    getline(cin, s1);
    getline(cin s2);

    if(isOneAway(s1, s2))
        cout << "One edit away." << endl;
    else
        cout << "Not one edit away." << endl;

    return 0;
}