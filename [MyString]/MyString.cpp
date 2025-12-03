#include "MyString.h"

namespace assignment1
{
    MyString::MyString(const char * s)
    {
        length = 0;
        for(int i = 0; s[i] != '\0'; i++) length++;
        
        str = new char[length + 1];
        for(int i = 0; i < length; i++) str[i] = s[i];
        str[length] = '\0';
    }

    MyString::MyString(const MyString& other)
    {
        length = other.length;
        str = new char[length + 1];
        for(int i = 0; i < length; i++) str[i] = other.str[i];
        str[length] = '\0';
    }

    MyString::~MyString()
    {
        delete [] str;
    }

    unsigned int MyString::GetLength() const
    {
        return length;
    }

    const char* MyString::GetCString() const
    {
        return str;
    }

    void MyString::Append(const char * s)
    {

    }

    MyString MyString::operator+(const MyString& other) const
    {
        return MyString("temporary");
    }

    int MyString::IndexOf(const char * s)
    {
        return 0;
    }

    int MyString::LastIndexOf(const char * s)
    {
        return 0;
    }

    void MyString::Interleave(const char * s)
    {

    }

    bool MyString::RemoveAt(unsigned int i)
    {
        return false;
    }
    
    void MyString::PadLeft(unsigned int totalLenth)
    {

    }

    void MyString::PadLeft(unsigned int totalLength, const char c)
    {

    }

    void MyString::PadRight(unsigned int totalLength)
    {

    }

    void MyString::PadRight(unsigned int totalLength, const char c)
    {

    }

    void MyString::Reverse()
    {

    }

    bool MyString::operator==(const MyString& rhs) const
    {
        return false;
    }

    void MyString::ToLower()
    {

    }

    void MyString::ToUpper()
    {

    }
}
