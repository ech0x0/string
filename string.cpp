#include "string.hpp"

#include <string.h>
#include <stdio.h>

string::string() {
    m_size = 0;
    m_capacity = 7;
    m_str = new char[m_capacity + 1];
    m_str[0] = '\0';
    m_str[m_capacity] = '\0';
}

string::~string() {
    if (m_str) delete[] m_str;
}

string::string(char* str) {
    m_size = strlen(str);
    m_capacity = m_size;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, str, m_size + 1);
}

string::string(const char* str) {
    m_size = strlen(str);
    m_capacity = m_size;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, str, m_size + 1);
}

string::string(void* data, unsigned int size) {
    m_size = size;
    m_capacity = m_size;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, data, m_size);
    m_str[m_size] = '\0';
}

string::string(const char ch) {
    m_size = 1;
    m_capacity = 1;
    m_str = new char[2];
    m_str[0] = ch;
    m_str[1] = '\0';
}

string::string(const string& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, other.m_str, m_size + 1);
}

string::string(string&& other) {
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_str = other.m_str;
    other.m_str = nullptr;
}

string& string::operator=(const string& other) {
    if (this == &other) return *this;

    m_size = other.m_size;

    if (m_capacity != other.m_capacity) {
        if (m_str) delete[] m_str;
        m_capacity = other.m_capacity;
        m_str = new char[m_capacity + 1];
    }
    memcpy(m_str, other.m_str, m_size + 1);

    return *this;
}

string& string::operator=(string&& other) noexcept {
    if (this == &other) return *this;

    m_size = other.m_size;
    m_capacity = other.m_capacity;

    if (m_str) delete[] m_str;
    m_str = other.m_str;

    other.m_str = nullptr;
    other.m_size = 0;
    other.m_capacity = 0;

    return *this;
}

string& string::operator=(char* str) {
    m_size = strlen(str);
    m_capacity = m_size;

    if (m_str) delete[] m_str;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, str, m_size + 1);

    return *this;
}

string& string::operator=(const char* str) {
    m_size = strlen(str);
    m_capacity = m_size;

    if (m_str) delete[] m_str;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, str, m_size + 1);

    return *this;
}

const char* string::c_str() const {
    return m_str;
}

unsigned int string::size() const {
    return m_size;
}

unsigned int string::capacity() const {
    return m_capacity;
}

unsigned int string::max_size() const {
    return 4294967295;
}

void string::clear() {
    m_size = 0;
    m_capacity = 0;
    delete[] m_str;
    m_str = new char[1];
    m_str[0] = '\0';
}

bool string::empty() const {
    return (m_size == 0);
}

void string::reserve(unsigned int n) {
    m_capacity = n;
    if (m_size > m_capacity) m_size = m_capacity;

    char* tmp = m_str;
    m_str = new char[m_capacity + 1];

    memcpy(m_str, tmp, m_size);
    m_str[m_size] = '\0';

    delete[] tmp;
}

string& string::operator+=(const string& str) {
    if (m_size + str.m_size > m_capacity) reserve(m_size + str.m_size);
    memcpy(m_str + m_size, str.m_str, str.m_size + 1);
    m_size += str.m_size;
    return *this;
}

string& string::operator+=(const char* str) {
    unsigned int size = strlen(str);
    if (m_size + size > m_capacity) reserve(m_size + size);
    memcpy(m_str + m_size, str, size + 1);
    m_size += size;
    return *this;
}

string& string::operator+=(const char ch) {
    if (m_size + 1 > m_capacity) reserve(m_size + 1);
    m_str[m_size] = ch;
    m_str[++m_size] = '\0';
    return *this;
}

string operator+(const string& lhs, const string& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(string&& lhs, string&& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}
string operator+(string&& lhs, const string& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}
string operator+(const string& lhs, string&& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const string& lhs, const char* rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(string&& lhs, const char* rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const char* lhs, const string& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const char* lhs, string&& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const string& lhs, const char rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(string&& lhs, const char rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const char lhs, const string& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string operator+(const char lhs, string&& rhs) {
    string str(lhs);
    str += rhs;
    return str;
}

string to_string(const int x) {
    char buff[12];
    sprintf(buff, "%d", x);
    return string(buff);
}

string to_string(const unsigned int x) {
    char buff[11];
    sprintf(buff, "%u", x);
    return string(buff);
}

string to_string(const long long x) {
    char buff[21];
    sprintf(buff, "%lld", x);
    return string(buff);
}

string to_string(const unsigned long long x) {
    char buff[21];
    sprintf(buff, "%llu", x);
    return string(buff);
}

string to_string(const float x) {
    char buff[128];
    sprintf(buff, "%f", x);
    return string(buff);
}

string to_string(const double x) {
    char buff[256];
    sprintf(buff, "%f", x);
    return string(buff);
}

string to_string(const long double x) {
    char buff[512];
    sprintf(buff, "%Lf", x);
    return string(buff);
}
