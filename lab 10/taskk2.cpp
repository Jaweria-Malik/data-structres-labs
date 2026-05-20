#include <iostream>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    if (start >= end)
        return true;

    if (str[start] != str[end])
        return false;

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    cin >> str;

    int len = str.length();

    if (isPalindrome(str, 0, len - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";

    return 0;
}