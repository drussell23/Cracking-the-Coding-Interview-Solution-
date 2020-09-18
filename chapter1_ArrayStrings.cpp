// Cracking the Coding Interview - Interview Questions 
// (1.1) - Is Unique: Implement an algorithm to determine if a string has all unique characters. 
//         What if you cannot use additional data structures?

// Solution - You should first ask your interviewer if the string is an ASCII string or a Unicode string.
//            Asking this question will show an eye for detail and a solid foundatioon in computer science. 
//            We'll assume for simplicity the character set is ASCII. If this assumption is not valid, we would
//            need to increase the storage size. 

//            One solution is to create an array of boolean values, where the flag at index i indicates whether
//            character i in the alphabet is contained in the string. The second time you see this character you 
//            can immediately return false.

//            We can also immediately reutrn false if the string length exceeds the number of unique characters in 
//            the alphabet. After all, you can't form a string of 280 unique characters out of a 128-character 
//            alphabet.

/*
    - It's also okay to assume 256 characters. This would be the case in extended ASCII. You should 
      clarify your assumptions with your interviewer.

      The code below implements this algorithm.
        bool isUniqueChars(string str)
        {
             if(str.length() > 128)
            return false;
    
            bool[] char_set = new bool[128];
            for(int i = 0; i < str.length(); i++)
            {
                int val = str.charAt(i);
                if(char_set[val])
                {
                    // Already found this char in string. 
                    return false;
                }
                char_set[val] = true;
            }
            return true;
        }
    
    - The time complexity for this code is O(n), where n is the length of the string. The space complexity is O(1).
      (You could also argue the time complexity is O(1), since the for loop will never iterate through more than 
      128 characters.) If you didn't want to assume the character set is fixed, you could express the complexity as
      O(c) space and O(min(c, n)) or O(c) time, where c is the size of the character set.
    
    - We can reduce our space usage by a factor of eight by using a bit vector. We will assume, in the below code, 
      that the string only uses the lowercase letters a through z. This will allow us to use just a single list.

      bool isUniqueChars(string str)
      {
        int checker = 0; 
        for(int i = 0; i < str.length(); i++)
        {
            int val = str.charAt(i) - 'a';
            if((checker & (1 << val)) > 0)
            {
                return false;
            }
            checker |= (1 << val);
        }
        return true;
      }
*/




#include <iostream>
#include <vector>
#include <string>
#include <bitset>

bool isUniqueChars(const string &str)
{
    if(str.length() > 128)
    {
        return false;
    }
    vector<bool> char_set(128);
    for(int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if(char_set[val])
        {
            return false;
        }
        char_set[val] = true;
    }
    return true;
}
bool isUniqueChars_bitvector(const & str)
{
    // Reduce space usage by a factor of 8 using bitvector.
    // Each boolean otherwise occupies a size of 8 bits.
    bitset<256> bits(0);
    for(int i = 0; i < str.length(); i++)
    {
        int val = str[i];
        if(bits.test(val) > 0)
        {
            return false;
        }
        bits.set(val);
    }
    return true;
}
bool isUniqueChars_noDS(cosnt string & str)
{
    for(int i = 0; i < str.length()-1; i++)
    {
        for(int j = i+1; j < str.length(); j++)
        {
            if(str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    vector<string> words = {"abcde", "hello", "apple", "kite", "padle"};   

    for(auto word : words)
    {
        cout << word << string(": ") << isUniqueChars(word) << endl;
    }
    cout << endl << "Using bit vector" << endl;

    for(auto word : words)
    {
        cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) << endl;
    }
    cout << endl << "Using no Data Structures" << endl;
    
    for(auto word : words)
    {
        cout << word << string(": ") << boolalpha << isUniqueChars_bitvector(word) << endl;
    }
    
    retirn 0;
}