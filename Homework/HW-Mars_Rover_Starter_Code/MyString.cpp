#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>
#include "MyString.h"

MyString::MyString():str(),len(0), capacity(1)
{
    str = new char[1];
    str[0] = '\0';
}

MyString::MyString(const char* s):str(),len(0), capacity(1)
{
    // if(s == nullptr)
    // {
    //     len = 0;
    //     capacity = 1;
    //     str = new char[1];
    //     str[0] = '\0';
    // }
    // else
    // {
    len = get_length_char_arr(s);
    capacity = len + 1;
    str = new char[capacity];
    for (unsigned int i = 0; i < len; i++)
    {
        str[i] = s[i];
    }
    str[len] = '\0';
// }

}
MyString::MyString(const MyString& source):str(),len(0), capacity(1)
{
    len = source.size();
    capacity = len + 1;
    str = new char[capacity];
    for (unsigned int i = 0; i < len; i++)
    {
        str[i] = source.str[i];
    }
    str[len] = '\0';
}

MyString::~MyString()
{
    delete[] str;
}

unsigned int get_length_char_arr(const char char_arr[])
{
    unsigned int len = 0;
    const char* char_ptr = char_arr;
    while (*char_ptr++) { len++; }
    return len;
}

unsigned int get_length_char_ptr(const char* char_ptr)
{
    unsigned int len = 0;
    while (*char_ptr++) { len++; }
    return len;
}
const char* MyString::data() const
{
    // if(str == nullptr)
    // {
    //     str = new char[1];
    //     str[0] = '\0';
    //     return get_const_char(str);
    // }
    // else
    // {
    const char* constant_char = str;
    return constant_char;
// }

}
unsigned int MyString::size() const
{
    return len;
}
unsigned int MyString::length() const
{
    return len;
}
char MyString::front() const
{
    if (len == 0)
    {
        throw std::exception();
    }
    else
    {
        return str[0];
    }
    return '\0';

}
char MyString::at(unsigned int index) const
{
    if (index > (len - 1))
    {
        throw std::exception();
    }
    else if (len == 0)
    {
        throw std::exception();
    }
    else
    {
        return str[index];
    }
    return '\0';
}
bool MyString::empty() const
{
    if (len == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

size_t MyString::find(const MyString& search) const
{
    if (search.size() >= len)
    {
        return -1;
    }
    else
    {
        for (unsigned int this_index = 0; this_index < len; this_index++)
        {
            if((len - this_index) < search.size())
            {
                break;
            }
            for (unsigned int search_index = 0; search_index < search.size(); search_index++)
            {
                if (str[(this_index + search_index)] == search.str[search_index])
                {
                    if (search_index == (search.size() - 1))
                    {
                        return this_index;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    search_index = search.size();
                }
            }
        }
    }
    return -1;
}
size_t MyString::find(const MyString& search, size_t n) const
{
    if ((search.size()+n) >= len)
    {
        return -1;
    }

    else
    {
        for (unsigned int this_index = n; this_index < len; this_index++)
        {
            if((len - this_index) < search.size())
            {
                break;
            }
            for (unsigned int search_index = 0; search_index < search.size(); search_index++)
            {
                if (str[(this_index + search_index)] == search.str[search_index])
                {
                    if (search_index == (search.size() - 1))
                    {
                        return this_index;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    search_index = search.size();
                }
            }
        }
    }
    return -1;
}
void MyString::clear()
{
    delete[] str;
    str = new char[1];
    str[0] = '\0';
    len = 0;
    capacity = 1;
}
MyString& MyString::operator=(const MyString& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    else if (rhs.size() == 0)
    {
        delete[] str;
        str = new char[1];
        str[0] = '\0';
        len = 0;
        capacity = 1;
    }
    else
    {
        delete[] str;
        len = rhs.size();
        capacity = len + 1;
        str = new char[capacity];
        for (unsigned int i = 0; i < len; i++)
        {
            str[i] = rhs.str[i];
        }
        str[len] = '\0';
        return *this;
    }
    return *this;

}

MyString& MyString::operator+=(const MyString& rhs)
{
    if (len == 0)
    {
        delete[] str;
        len = rhs.size();
        capacity = len + 1;
        str = new char[capacity];
        for (unsigned int i = 0; i < len; i++)
        {
            str[i] = rhs.str[i];
        }
        str[len] = '\0';
        return *this;
    }
    if (rhs.size() == 0)
    {
        return *this;
    }
    else
    {
        unsigned int new_len = (len + rhs.size());
        unsigned int new_capacity = new_len + 1;

        char* buff = new char[new_capacity];
        for (unsigned int i = 0; i < len; i++)
        {
            buff[i] = str[i];
        }
        for (unsigned int i = len; i < new_len; i++)
        {
            buff[i] = rhs.str[(i - len)];
        }
        buff[new_len] = '\0';
        delete[] str;
        str = new char[new_capacity];
        for (unsigned int i = 0; i < new_len; i++)
        {
            str[i] = buff[i];
        }
        str[new_len] = '\0';
        delete[] buff;
        len = new_len;
        capacity = new_capacity;
        return *this;
    }

    return *this;

}
bool operator==(const MyString& lhs,const MyString& rhs)
{
    if(lhs.size() == rhs.size())
    {
        for(unsigned i = 0; i<rhs.size();i++)
        {
            if(!(lhs.at(i) == rhs.at(i)))
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
    return true;
}
MyString& operator+(const MyString& lhs,const MyString& rhs)
{
    if ((lhs.size() == 0)||(rhs.size() == 0))
    {
        MyString string;
        return string;
    }
    else if (rhs.size() == 0)
    {
        MyString string = MyString(lhs);
        return string;
    }
    else if(lhs.size() == 0)
    {
        MyString string = MyString(rhs);
        return string;
    }
    else
    {
        MyString string;
        unsigned int new_len = (lhs.size() + rhs.size());
        unsigned int new_capacity = new_len + 1;

        char* buff = new char[new_capacity];
        for (unsigned int i = 0; i < lhs.size(); i++)
        {
            buff[i] = lhs.at(i);
        }
        for (unsigned int i = lhs.size(); i < new_len; i++)
        {
            buff[i] = rhs.at(i - lhs.size());
        }
        buff[new_len] = '\0';
        MyString string = buff;
        return string;
        //str = new char[new_capacity];
        // for (unsigned int i = 0; i < new_len; i++)
        // {
        //     str[i] = buff[i];
        // }
        // str[new_len] = '\0';
        // delete[] buff;
        // len = new_len;
        // capacity = new_capacity;
        // return *this;
    }
    MyString string;
    return string;
}
std::ostream& operator<<(std::ostream& os, const MyString& obj)
{
    os << obj.data();
    return os;
}