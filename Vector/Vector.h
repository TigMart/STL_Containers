#ifndef _VECTOR_
#define _VECTOR_

#include <iostream>

template <typename T>
class Vector
{
public:
	Vector();  // default ctor
	Vector(const Vector<T>& other); // copy ctor
	Vector<T>& operator=(const Vector<T>& rhs); // copy assignment
	Vector(Vector<T>&& rvalue)noexcept; // move ctor 
	Vector<T>& operator=(Vector<T>&& rv)noexcept; // move assignment
	Vector<T> operator+(const Vector<T>& other); // operator+
	~Vector(); // dtor
	//Methods
	void push_back(const T& elem);
	void insert(const T& elem, int index);
	T& operator[](int index)const;
	void pop_Back();
	int size()const;
	int capacity()const;
	void push_front(const T& elem);
	void erase(int index);
	T& at(int index) const;
	T& front();
	T& back();
	virtual void print();
	template <typename R>
	Vector<T>& operator=(Vector<R>& rhs);
protected:
	// for Stack
	T* get_arr();
private:
	void copy_vec(const Vector<T>& other);
	int m_capacity;
	int m_size;
	T* m_arr;
};


//Implementation

template <typename T>
Vector<T>::Vector() : m_capacity{ 0 }, m_size{ 0 }, m_arr{ nullptr }
{	
	std::cout << "default ctor " << std::endl;
}

template <typename T>
void Vector<T>::copy_vec(const Vector<T>& other)
{
	m_capacity = other.m_capacity;
	m_size = other.m_size;
	m_arr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = other.m_arr[i];
	}
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
	std::cout << "copy ctor " << std::endl;
	copy_vec(other);
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs)
{
	std::cout << "copy assignment" << std::endl;
	if (this == &rhs) {
		std::cout << "Self Attribution" << std::endl;
		return *this;
	}
	delete[] m_arr;
	m_arr = nullptr;
	copy_vec(rhs);
	return *this;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& rvalue) noexcept
{
	std::cout << "Move ctor" << std::endl;
	m_capacity = rvalue.m_capacity;
	m_size = rvalue.m_size;
	m_arr = rvalue.m_arr;
	rvalue.m_arr = nullptr;
	rvalue.m_capacity = 0;
	rvalue.m_size = 0;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rv) noexcept
{
	std::cout << "Move assignment" << std::endl;
	if (this == &rv) {
		std::cout << "Self Attribution" << std::endl;
		return *this;
	}
	delete[] this->m_arr;
	this->m_capacity = rv.m_capacity;
	this->m_size = rv.m_size;
	this->m_arr = rv.m_arr;
	rv.m_arr = nullptr;
	rv.m_capacity = 0;
	rv.m_size = 0;
	return *this;
}

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& other)
{
	std::cout << "operator + " << std::endl;
	Vector<T> result;
	result.m_capacity = m_capacity + other.m_capacity;
	result.m_size = m_size + other.m_size;
	result.m_arr = new T[result.m_capacity];
	int j = 0;
	for (int i = 0; i < result.m_size; ++i) {
		if (i < m_size) {
			result.m_arr[i] = m_arr[i];
		}
		else {
			result.m_arr[i] = other.m_arr[j];
			++j;
		}
	}
	return result;
}

template <typename T>
void Vector<T>::push_back(const T& elem)
{
	if (m_size == m_capacity) {
		m_capacity = m_capacity ? m_capacity * 2 : 1;
		T* temp = new T[m_capacity];
		for (int i = 0; i < m_size; ++i) {
			temp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = temp;
	}
	m_arr[m_size++] = elem;
}


template<typename T>
void Vector<T>::insert(const T& elem, int index)
{
	if (index >= 0 && index <= m_size) {
		if (m_size == m_capacity) {
			m_capacity = m_capacity ? m_capacity * 2 : 1;
			T* tmp = new T[m_capacity];
			for (int i = 0; i < index; ++i) {
				tmp[i] = m_arr[i];
			}
			tmp[index] = elem;
			for (int i = index + 1; i <= m_size; ++i) {
				tmp[i] = m_arr[i - 1];
			}
			delete[] m_arr;
			m_arr = tmp;
			++m_size;
		}
		else {
			for (int i = m_size; i > index; --i) {
				m_arr[i] = m_arr[i - 1];
			}
			m_arr[index] = elem;
			++m_size;
		}
	}
}

template <typename T>
T& Vector<T>::operator[](int index)const
{
	return m_arr[index];
}

template <typename T>
void Vector<T>::pop_Back()
{
	if (m_size > 0) {
		m_size--;
	}
}

template <typename T>
int Vector<T>::size() const { return m_size; }

template <typename T>
int Vector<T>::capacity() const { return m_capacity; }


template<typename T>
T& Vector<T>::front() { return m_arr[0]; }

template<typename T>
T& Vector<T>::back() { return m_arr[size() - 1]; }

template<typename T>
void Vector<T>::push_front(const T& elem) {
	if (m_size == m_capacity) {

		m_capacity = m_capacity ? m_capacity * 2 : 1;
		T* temp = new T[m_capacity];
		temp[0] = elem;
		++m_size;
		for (int i = 1; i < m_size; ++i) {
			temp[i] = m_arr[i-1];
		}
		delete[] m_arr;
		m_arr = temp;
		
	}
	else if (m_size < m_capacity) {
		for (int i = m_size; i > 0; --i) {
			m_arr[i] = m_arr[i - 1];
		}
		m_arr[0] = elem;
		++m_size;
	}
}

template <typename T>
void Vector<T>::erase(int index)
{
	if (index >= 0 && index < m_size) {
		for (int i = index; i < m_size; ++i) {
			m_arr[i] = m_arr[i + 1];		
		}
		--m_size;
	}
}

template <typename T>
T& Vector<T>::at(int index) const
{
	if (index <= m_size && index > 0)
		return m_arr[index];
	std::cout << "Out of range! " << std::endl;
	throw 0;
}

template <typename T>
void Vector<T>::print()
{
	for (int i = 0; i < m_size; ++i) {
		std::cout << m_arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
T* Vector<T>::get_arr()
{
	return m_arr;
}

template <typename T>
template <typename R>
Vector<T>& Vector<T>::operator=(Vector<R>& rhs)
{
	if (m_arr != nullptr) 
	{
		delete[] m_arr;
	}
	m_capacity = rhs.capacity();
	m_size = rhs.size();
	m_arr = new T[m_capacity];
	for (int i = 0; i < m_size; ++i) {
		m_arr[i] = rhs[i];
	}
	return *this;
}

template <typename T>
Vector<T>::~Vector()
{
	std::cout << "Dtor" << std::endl;
	delete[] m_arr;
}

#endif // _VECTOR_
