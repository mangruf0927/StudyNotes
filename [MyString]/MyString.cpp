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
        int len = 0;
        for(int i = 0; s[i] != '\0'; i++) len++;
        
        char * newStr = new char[length + len + 1];
        
        for(int i = 0; i < length; i++) newStr[i] = str[i];
        for(int i = 0; i < len; i++) newStr[length + i] = s[i];
        
        length += len;
        newStr[length] = '\0';

        delete [] str;
        str = newStr;
    }

    MyString MyString::operator+(const MyString& other) const
    {
        MyString myStr(*this);
        myStr.Append(other.str);
        return myStr;
    }

    int MyString::IndexOf(const char * s)
    {
        int len = 0;
        for(int i = 0; s[i] != '\0'; i++) len++;

        if(len <= 0) return -1;

        for(int i = 0; i <= length - len; i++)
        {
            bool isEqual = true;
            for(int j = 0; j < len; j++)
            {
                if(str[i + j] != s[j])
                {
                    isEqual = false;
                    break;
                }
            }
            if(isEqual) return i;
        }
        return -1;
    }

    int MyString::LastIndexOf(const char * s)
    {
        int len = 0;
        for(int i = 0; s[i] != '\0'; i++) len++;

        if(len <= 0) return -1;

        int idx = -1;
        for(int i = 0; i <= length - len; i++)
        {
            bool isEqual = true;
            for(int j = 0; j < len; j++)
            {
                if(str[i + j] != s[j])
                {
                    isEqual = false;
                    break;
                }
            }
            if(isEqual) idx = i;
        }
        return idx;
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
        for(int i = 0; i < length / 2; i++)
        {
            char temp = str[i];
            str[i] = str[length - 1 - i];
            str[length - 1 - i] = temp;
        }
    }

    bool MyString::operator==(const MyString& rhs) const
    {
        if(length != rhs.length) return false;

        for(int i = 0; i < length; i++)
        {
            if(str[i] != rhs.str[i]) return false;
        }
        return true;
    }

    void MyString::ToLower()
    {
        for(int i = 0; i < length; i++)
        {
            if('A' <= str[i] && str[i] <= 'Z') str[i] += 32;
        }
    }

    void MyString::ToUpper()
    {
        for(int i = 0; i < length; i++)
        {
            if('a' <= str[i] && str[i] <= 'z') str[i] -= 32;
        }
    }
}
