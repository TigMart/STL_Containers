#include "String.h"

String::String() : m_data{ nullptr }, m_size{ 0 }, m_capacity{0}
{
	std::cout << "default ctor " << std::endl; 
}

String::String(char* ch)
{
	std::cout << " ctor with parametr " << std::endl;
	int lenght = getsize(ch);
	m_data = new char[lenght + 1];
		for (int i = 0; i < lenght; ++i) {
			m_data[i] = ch[i];
		}
		m_data[lenght] = '\0';
}

String::String(const String& rhs) 
{
	std::cout << "copy assignment" << std::endl;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_data = new char[m_capacity];
	for (int i = 0; i <= m_size; i++)
	{
		m_data[i] = rhs.m_data[i];
	}
}

String& String::operator=(const String& rhs)
{
	std::cout << "copy assignment" << std::endl;
	if (this == &rhs) {
		std::cout << "Self Attribution";
		return *this;
	}	
		
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	delete[]m_data;
	m_data = new char[m_capacity];
	for (int i = 0; i <= m_size; i++)
	{
		m_data[i] = rhs.m_data[i];
	}
	return *this;
}

String::String(String&& rhs) noexcept
{
	std::cout << "Move ctor" << std::endl;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_data = rhs.m_data;
	rhs.m_capacity = 0;
	rhs.m_size = 0;
	rhs.m_data = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
	std::cout << "Move assignment" << std::endl;
	if (this == &rhs) {
		std::cout << "inqnaveragrum" << std::endl;
		return *this;
	}
	delete[] this->m_data;
	m_capacity = rhs.m_capacity;
	m_size = rhs.m_size;
	m_data = rhs.m_data;
	rhs.m_data = nullptr;
	rhs.m_capacity = 0;
	rhs.m_size = 0;
	return *this;	
}

String String::operator+(const String& rhs) {

	std::cout << "operator + " << std::endl;
	String tmp;
	tmp.m_size = rhs.m_size + m_size;
	tmp.m_capacity = rhs.m_capacity + m_capacity;
	tmp.m_data = new char[tmp.m_capacity+1];
	for (int i = 0; i < m_size; i++)
	{
		tmp.m_data[i] = m_data[i];
	}
	for (int i = m_size; i <= tmp.m_size; i++)
	{
		tmp.m_data[i] = rhs.m_data[i - m_size];
	}
	return tmp;
}

String& String::operator+=(const String& rhs)
{
	std::cout << "operator += " << std::endl;
	String tmp;
	tmp.m_size = rhs.m_size + m_size;
	tmp.m_capacity = rhs.m_capacity + m_capacity;
	tmp.m_data = new char[tmp.m_capacity+1];
	for (int i = 0; i < m_size; i++)
	{
		tmp.m_data[i] = m_data[i];
		
	}
	for (int i = m_size; i <= tmp.m_size; ++i)
	{
		tmp.m_data[i] = rhs.m_data[i - m_size];
		
	}
	delete[] m_data;
	m_data = tmp.m_data;
	m_capacity = tmp.m_capacity;
	m_size = tmp.m_size;
	tmp.m_data = nullptr;
	return *this;
}

String& String::operator+=(const char* rhs)
{
	std::cout << "operator += char* " << std::endl;
	char* tmp;
	int tmp_capacity = m_capacity + strlen(rhs);
	int tmp_size = m_size + strlen(rhs);
	tmp = new char[tmp_size+1];
	for (int i = 0; i < m_size; ++i) {
		tmp[i] = m_data[i];
	}
	for (int i = m_size,j=0; i < tmp_size; ++i,++j)
	{
		tmp[i] = rhs[j];
	}
	delete[] m_data;
	m_data = tmp;
	tmp = nullptr;
	m_capacity = tmp_capacity;
	m_size = tmp_size;
	m_data[m_size] = '\0';
	return *this;
}

String& String::operator+=(char symbol)
{
	std::cout << "operator += char " << std::endl;
	this->push_back(symbol);
	return *this;
}


char& String::operator[](int index) { return m_data[index]; }

void String::push_back(const char ch)
{
	if (m_size == m_capacity) {
		m_capacity = m_capacity ? m_capacity * 2: 1;
		char* temp = new char[m_capacity+1];
		for (int i = 0; i < m_size; ++i) {
			temp[i] = m_data[i];
		}
		delete[] m_data;
		m_data = temp;
	}
	m_data[m_size++] = ch;
	m_data[m_size] = '\0';
}

void String::push_front(const char ch)
{
	if (m_size == m_capacity) {
		m_capacity = m_capacity ? m_capacity * 2: 1;
		char* temp = new char[m_capacity+1];
		temp[0] = ch;
		++m_size;
		for (int i = 1; i < m_size; ++i) {
			temp[i] = m_data[i-1];
		}
	
		delete[] m_data;
		m_data = temp;
		
	}
	else if (m_size < m_capacity) {
		for (int i = m_size; i > 0; --i) {
			m_data[i] = m_data[i - 1];
		}
		m_data[0] = ch;
		++m_size;
	}
	m_data[m_size] = '\0';
}	
void String::pop_back()
{
	if (m_size > 0) {
		m_size--;
	}
	m_data[m_size] = '\0';
}

void String::insert(const char ch, int index)
{
	if (index >= 0 && index <= m_size) {
		if (m_size == m_capacity) {
			m_capacity = m_capacity ? m_capacity * 2 : 1;
			char* tmp = new char[m_capacity];
			for (int i = 0; i < index; ++i) {
				tmp[i] = m_data[i];
			}
			tmp[index] = ch;
			for (int i = index + 1; i <= m_size; ++i) {
				tmp[i] = m_data[i - 1];
			}
			delete[] m_data;
			m_data = tmp;
			++m_size;
			m_data[m_size] = '\0';
		}
		else {
			for (int i = m_size; i > index; --i) {
				m_data[i] = m_data[i - 1];
			}
			m_data[index] = ch;
			++m_size;
		}
		m_data[m_size] = '\0';
	}
}

void String::erase(int index)
{
	if (index >= 0 && index < m_size) {
		for (int i = index; i < m_size; ++i) {
			m_data[i] = m_data[i + 1];
		}
		--m_size;
	}
	m_data[m_size] = '\0';
}

bool String::empty() const {
	if (m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int String::size() const { return m_size; }

char& String::front() { return m_data[0]; }

char& String::back() { return m_data[size() - 1]; }

void String::print() { std::cout << m_data; }

int String::getsize(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}
	return count;
}

String::~String() {	delete[] m_data; }
