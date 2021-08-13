#ifndef _STRING_
#define _STRING_

#include <iostream>

class String
{
public:
	String(); // Default ctor
	String(char* ch); // ctor with parametr
	String(const String& rhs); // copy ctor
	String& operator=(const String& rhs); // copy assingment
	String(String&& rhs)noexcept; // move ctor 
	String& operator=(String&& rhs)noexcept; // move assignment
	String operator+(const String& other); // operator+
	String& operator+=(const String& rhs);
	String& operator+=(const char* rhs);
	String& operator+=(char symbol);
	char& operator[](int index); // subscript
	~String(); // dtor
public:
	// Methods
	void push_back(const char ch);
	void push_front(const char ch);
	void pop_back();
	void insert(const char ch, int index);
	void erase(int index);;
	bool empty() const;
	int size() const;
	char& back();
	char& front();
	void print();
	static int getsize(char* str);
private:
	char* m_data;
	int m_size;
	int m_capacity;
};

#endif // _STRING_