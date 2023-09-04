#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <fstream>
#include <tuple>
#include <limits>
#include <stdexcept>

class MyString{
    public:
        MyString();
        MyString(const MyString& source);
        MyString(const char* s);
        ~MyString();
        const char* data() const;
        unsigned int size() const;
        unsigned int length() const;
        char at(unsigned int index) const;
        char front() const;
        bool empty() const;
        size_t find(const MyString& search) const;
        size_t find(const MyString& search, size_t n) const;
        void clear();
        MyString& operator=(const MyString& rhs);
        MyString& operator+=(const MyString& rhs);
    private:
        char* str;
        unsigned int len;
        unsigned int capacity;
};
bool operator==(const MyString& lhs,const MyString& rhs);
MyString& operator+(const MyString& lhs,const MyString& rhs);
std::ostream& operator<<(std::ostream& os,const MyString& obj);
unsigned int get_length_char_arr(const char char_arr[]);
unsigned int get_length_char_ptr(const char* char_ptr);

#endif