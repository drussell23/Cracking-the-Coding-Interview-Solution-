// Cracking the Coding Interview - Interview Questions 
// (1.4) - Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. 
//         A palindrome is a word or phase that is the same forwards and backwards. A permutation is a rearrangement of 
//         letters. This palindrome does not need to be limited to just dictionary words. 

// EXAMPLE 
// Input: Tact Coa
// Output: True (permutations: "taco cat", "atco cta", etc.)

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getCharNumber(const char & c)
{
    int a = (int) 'a';
    int z = (int) 'z';
    int A = (int) 'A';
    int Z = (int) 'Z';
    int val = (int) c;

    if(a <= val && val <= Z)
    {
        return val - 'A';
    }
    else if(A <= val && val <= Z)
    {
        return val - 'A';
    }
    return -1;
}
vector<int> buildCharFrequencyTable(string phase)
{
    vector<int> table(getCharNumber('z') - getCharNumber('a') + 1, 0);

    for(char &c : phrase)
    {
        int x = getCharNumber(c);
        if(x != -1)
        {
            table[x]++;
        }
    }
    return table;
}
bool checkMaxOneOdd(vector<int> &table)
{
    bool foundOdd = false;

    for(auto count : table)
    {
        if(count % 2 == 1)
        {
            if(foundOdd)
            {
                return false;
            }
            foundOdd = true;
        }
    }
    return true;
}
bool isPermutationOfPalindrome(const string &phrase)
{
    vector<int> table = buildCharFrequencyTable(phrase);
    return checkMaxOneOdd(table);
}
int main(int argc, const char *argv[])
{
    string pali = "Rats live on no evil star";
    string isPermutationOfPalindrome(pali) ? "yes" : "no";
    cout << isPermutation << endl;

    return 0;
}