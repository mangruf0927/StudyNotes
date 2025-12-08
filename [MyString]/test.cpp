#include <iostream>
#include "MyString.h"
using namespace std;
using namespace assignment1;

int main()
{
    MyString s("Hello");
    int length = s.GetLength();
    cout << length << "\n";

    s.Append(" world");
    cout << s.GetCString() << "\n";

    MyString s1("Hello");
    MyString s2(" world");
    MyString s3 = s1 + s2;
    cout << s3.GetCString() << "\n";

    int i = s1.IndexOf("ell");
    int j = s1.IndexOf("l");
    int k = s1.IndexOf("This");
    cout << i << " " << j << " " << k << "\n";

    int x = s1.LastIndexOf("ell");
    int y = s1.LastIndexOf("l");
    int z = s1.LastIndexOf("This");
    cout << x << " " << y << " " << z << "\n";

    s1.Interleave(" world");
    cout << s1.GetCString() << "\n";

    MyString s4("Hello");
    bool b1 = s4.RemoveAt(0);
    bool b2 = s4.RemoveAt(2);
    bool b3 = s4.RemoveAt(4);
    cout << b1 << " " << b2 << " " << b3 << "\n";

    MyString s5("Hello");
    s5.PadLeft(2);
    cout << s5.GetCString() << "\n";
    s5.PadLeft(8);
    cout << s5.GetCString() << "\n";

    MyString s6("World");
    s6.PadLeft(3, '-');
    cout << s6.GetCString() << "\n";
    s6.PadLeft(7, '-');
    cout << s6.GetCString() << "\n";
    
    MyString s7("Hello");
    s7.PadRight(2);
    cout << s7.GetCString() << "\n";
    s7.PadRight(8);
    cout << s7.GetCString() << "\n";

    MyString s8("World");
    s8.PadRight(3, '-');
    cout << s8.GetCString() << "\n";
    s8.PadRight(7, '-');
    cout << s8.GetCString() << "\n";

    MyString s9("Hello");
    s9.Reverse();
    cout << s9.GetCString() << "\n";

    MyString str1("Hello");
    MyString str2("Hello");
    MyString str3("World");
    bool b4 = (str1 == str2); 
    bool b5 = (str2 == str3); 
    cout << b4 << " " << b5 << "\n";

    MyString str4("HEllo 123k");
    str4.ToLower();
    cout << str4.GetCString() << "\n";

    str4.ToUpper();
    cout << str4.GetCString() << "\n";

    return 0;
}