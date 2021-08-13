#ifndef _MYLIST_
#define _MYLIST_

#include <iostream>
#include <string>
#include <initializer_list>


template <typename T>
class MyList
{
public:
	//Constructors
	MyList();
	MyList(const MyList<T>& other);
	MyList(std::initializer_list<T> init);
	//Destructor
	~MyList();
	//operator=
	MyList<T>& operator=(const MyList<T>& other);
	MyList<T>& operator=(std::initializer_list<T> ilist);
	//assign
	void assign(int count, const T& value);
	//Element access
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	//Capacity
	bool empty() const;
	int size() const;
	//Modifiers
	void clear();
	void insert(int pos, const T& value);
	void insert(int pos, int count, const T& value);
	void erase(int pos);
	void push_back(const T& value);
	void pop_back();
	void push_front(const T& value);
	void pop_front();
	void resize(int count);
	void swap(MyList<T>& other);
	T& operator[](const int index);
	//Operations
	void remove(const T& value);
	void remove_duplicates();
	void reverse();
	//cout
	void print();
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node(T data = T(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	int m_size;
	Node* head;
}; 

template <typename T>
MyList<T>::MyList() : m_size{ 0 }, head{ nullptr } { }

template<typename T>
MyList<T>::MyList(const MyList<T>& other)
{
	if (other.head == nullptr) {
		return;
	}
	else
	{
		Node* objHead = other.head;
		head = new Node;
		head->data = objHead->data;
		head->next = nullptr;
		Node* current = head;
		objHead = objHead->next;
		while (objHead != nullptr)
		{
			current->next = new Node;
			current = current->next;
			current->data = objHead->data;
			current->next=nullptr;
			objHead = objHead->next;
		}

	}
}

template<typename T>
MyList<T>::MyList(std::initializer_list<T> init)
{
	Node* curr = new Node;
	Node* tmp = curr;
	
	typename std::initializer_list<T>::iterator it = init.begin();
	m_size = init.size();
	while (it != init.end()-1)
	{
		curr->data = *it;
		curr->next = new Node;
		curr = curr->next;
		++it;
	}
	curr->data = *it;
	curr->next = nullptr;
	head = tmp;
}

template <typename T>
MyList<T>::~MyList()
{
	Node* current = head;
	while (current != NULL) {
		current = current->next;
		delete head;
		head = current;
	}
}

template <typename T>
MyList<T>& MyList<T>::operator=(const MyList<T>& other)
{
	if (this == &other) {
		std::cout << "self-attribution";
		return *this;
	}
	if (other.head == nullptr) {
		head = nullptr;
		return *this;
	}
	else
	{
		Node* objHead = other.head;
		head = new Node;
		head->data = objHead->data;
		head->next = nullptr;
		Node* current = head;
		objHead = objHead->next;
		while (objHead != nullptr)
		{
			current->next = new Node;
			current = current->next;
			current->data = objHead->data;
			current->next = nullptr;
			objHead = objHead->next;
		}
		return *this;
	}
}

template <typename T>
MyList<T>& MyList<T>::operator=(std::initializer_list<T> ilist)
{
	Node* curr = new Node;
	Node* tmp = curr;
	typename std::initializer_list<T>::iterator it = ilist.begin();
	m_size = ilist.size();
	while (it != ilist.end() - 1)
	{
		curr->data = *it;
		curr->next = new Node;
		curr = curr->next;
		++it;
	}
	curr->data = *it;
	curr->next = nullptr;
	head = tmp;
	return *this;
}

template <typename T>
void MyList<T>::assign(int count, const T& value)
{
	if (count <= 0)
	{
		std::cout << "error";
		exit(1);
	}
	this->clear();
	for (int i = 0; i < count; ++i)
	{
		this->push_back(value);
	}
}

template <typename T>
T& MyList<T>::front()
{
	if (head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	return head->data;
}

template <typename T>
const T& MyList<T>::front() const
{
	if (head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	return head->data;
}

template <typename T>
T& MyList<T>::back()
{
	if (head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	else 
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->data;
	}
}

template <typename T>
const T& MyList<T>::back() const
{
	if (head == nullptr)
	{
		std::cout << "You dont have elemenets: ";
		exit(1);
	}
	else
	{
		Node* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		return current->data;
	}
}

template <typename T>
bool MyList<T>::empty() const
{
	return !m_size;
}

template <typename T>
int MyList<T>::size() const
{
	return this->m_size;
}

template <typename T>
void MyList<T>::clear()
{
	Node* current = head;
	Node* next = nullptr;
	while (current != nullptr)
	{
		next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
}

template <typename T>
void MyList<T>::insert(int pos, const T& value)
{
	if ((pos > -1) && (pos <= m_size))
	{
		Node* tmp = new Node(value);
		Node* tmp2 = head;
		for (int i = 1; i < pos; ++i)
		{
			tmp2 = tmp2->next;
		}
		if (tmp2->next == nullptr)
		{
			tmp->next = tmp2;
		}
		tmp->next = tmp2->next;
		tmp2->next = tmp;
		tmp = nullptr;
	}
	else
	{
		std::cout << "out of range" << std::endl;
		exit(1);
	}
}

template<typename T>
void MyList<T>::insert(int pos, int count, const T& value)
{
	if (pos > 0 && pos <= m_size+1 && count > 0)
	{
		if (pos == 1)
		{
			for (int i = 0; i < count; ++i)
			{
				this->push_front(value);
			}
			return;
		}
		if (pos == m_size + 1)
		{
			for (int i = 0; i < count; ++i)
			{
				this->push_back(value);
			}
			return;
		}
		Node* L1 = this->head;
		Node* temp = new Node(value);
		Node* cur = temp;
		for (int i = 1; i < count; ++i) 
		{
			cur->next = new Node(value);
			cur = cur->next;
			
		}
		for(int i = 2;i<pos;++i)
		{
			L1 = L1->next;
		}
		Node* f = temp;
		for (int i = 1; i < count; ++i)
		{
			f = f->next;
		}
		f->next = L1->next;
		L1->next = temp;
		m_size += count;
	}
	else
	{
		std::cout << "out of range" << std::endl;
		exit(1);
	}
}

template <typename T>
void MyList<T>::erase(int pos)
{
	if (pos > 0 && pos <= m_size)
	{
		if (pos == 1)
		{
			Node* tmp = head;
			head = head->next;
			delete tmp;
			--m_size;
			return;
		}
		if (pos == m_size)
		{
			this->pop_back();
			return;
		}
		Node* tmp = head;
		Node* tmp2 = head->next;
		for (int i = 2; i < pos; ++i)
		{
			tmp = tmp->next;
			tmp2 = tmp2->next;
		}
		tmp->next = tmp2->next;
		delete tmp2;
	}
	else
	{
		std::cout << "out of range" << std::endl;
		exit(1);
	} 
}

template<typename T>
void MyList<T>::push_back(const T& value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}
	else
	{
		Node* current = this->head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = new Node(value);
	}
	++m_size;
}

template <typename T>
void MyList<T>::pop_back()
{
	if (m_size == 1)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node* tmp = head;
	Node* tmp2 = head->next;
	while (tmp2->next != nullptr)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	delete tmp2;
	tmp->next = nullptr;
	--m_size;
}

template <typename T>
void MyList<T>::push_front(const T& value)
{
	Node* tmp = new Node;
	tmp->data = value;
	if (m_size == 0) {
		head = tmp;
		++m_size;
		return;
	}
	Node* cur = head;
	tmp->next = cur;
	head = tmp;
	++m_size;
}

template <typename T>
void MyList<T>::pop_front()
{	 
	if (m_size == 1)
	{
		delete head;
		head = nullptr;
		return;
	}
	Node* tmp = head;
	head = head->next;
	delete tmp;
	--m_size;

}

template <typename T>
void MyList<T>::resize(int count)
{
	if (count < 0)
	{
		std::cout << "Out_of_range! ";
		exit(1);
	}
	int i = m_size - count;
	for (; i < 0; ++i)
	{
		push_back(T());
	}
	for (; i > 0; --i)
	{
		pop_back();
	}
}

template <typename T>
void MyList<T>::swap(MyList<T>& other)
{
	int ob_size = other.m_size;
	other.m_size = m_size;
	m_size = ob_size;
	Node* tmp = head;  
	head = other.head;
	other.head = tmp;
	tmp = nullptr;
}

template <typename T>
T& MyList<T>::operator[](const int index)
{
	int counter = 0;
	Node* current = this->head;
	while (current == index)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		++current;
	}
}

template <typename T>
void MyList<T>::remove(const T& value)
{
	Node* tmp = head;
	while (tmp != nullptr && tmp->data == value)
	{
		head = head->next;
		delete tmp;
		tmp = head;
		--m_size;
	}
	if (m_size == 0)
	{
		return;
	}
	Node* tmp2 = tmp->next;
	while (tmp2!=nullptr)
	{
		if (tmp2->data == value)
		{
			tmp->next = tmp2->next;
			delete tmp2;
			tmp2 = tmp->next;
			--m_size;
		}
		else
		{
			tmp = tmp2;
			tmp2 = tmp2->next;
		}
	}
}

template<typename T>
void MyList<T>::remove_duplicates()
{
	if (head == nullptr)
	{
		std::cout << "No element!!!";
		return;
	}
	Node* tmp = head;
	Node* dup;
	while (tmp != nullptr && tmp->next != nullptr)
	{
		Node* tmp1 = tmp;
		while (tmp1->next)
		{
			if (tmp->data == tmp1->next->data)
			{
				dup = tmp1->next;
				tmp1->next = tmp1->next->next;
				delete(dup);
			}
			else {
				tmp1 = tmp1->next;
			}
		}
		tmp = tmp->next;
	}	
}

template <typename T>
void MyList<T>::reverse()
{
	Node* previous = nullptr;
	Node* curr = head;
	while (curr != nullptr) {
		Node* tmp = curr->next;
		curr->next = previous;
		previous = curr;
		curr = tmp;
		
	}
	Node* tmp = previous;
	while (tmp!=nullptr)
	{
		std::cout<<tmp->data<<" ";
		tmp = tmp->next;
	}
}

template <typename T>
void MyList<T>::print()
{
	Node* tmp = head;
	while (tmp != nullptr) {
		std::cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

#endif // !_MYLIST_
