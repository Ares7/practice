#include <iostream>

using namespace std;

int main()
{
    string str;
    cout << "enter a string for which you want to swap characters:" << endl;
    getline(cin, str);//"Hello, World!";
    string tmp;

    for (int i = 0, j = str.length() - 1; i < (str.length()) / 2; ++i, j--)
    {
        tmp = str[j];
        str[j] = str[i];
        str[i] = tmp[0];
    }

    cout << str << endl;
    return 0;
}