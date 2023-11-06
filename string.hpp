#pragma once
#ifndef STRING_HPP
#define STRING_HPP

class string {
private:
    char* m_str;
    unsigned int m_size;
    unsigned int m_capacity;
public:
    string();
    ~string();

    string(char* str);
    string(const char* str);
    string(void* data, unsigned int size);
    string(const char ch);

    string(const string& other);
    string(string&& other);
    string& operator=(const string& other);
    string& operator=(string&& other) noexcept;

    string& operator=(char* str);
    string& operator=(const char* str);

    const char* c_str() const;

    unsigned int size() const;
    unsigned int capacity() const;
    unsigned int max_size() const;

    void clear();
    bool empty() const;

    void reserve(unsigned int n);

    string& operator+=(const string& str);
    string& operator+=(const char* str);
    string& operator+=(const char ch);

    friend string operator+(const string& lhs, const string& rhs);
    friend string operator+(string&& lhs, string&& rhs);
    friend string operator+(string&& lhs, const string& rhs);
    friend string operator+(const string& lhs, string&& rhs);

    friend string operator+(const string& lhs, const char* rhs);
    friend string operator+(string&& lhs, const char* rhs);
    friend string operator+(const char* lhs, const string& rhs);
    friend string operator+(const char* lhs, string&& rhs);

    friend string operator+(const string& lhs, const char rhs);
    friend string operator+(string&& lhs, const char rhs);
    friend string operator+(const char lhs, const string& rhs);
    friend string operator+(const char lhs, string&& rhs);
};

string to_string(const int x);
string to_string(const unsigned int x);
string to_string(const long long x);
string to_string(const unsigned long long x);
string to_string(const float x);
string to_string(const double x);
string to_string(const long double x);

#endif