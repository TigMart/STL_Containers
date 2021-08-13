#include "vector.h"
#include "Stack.h"

int main()
{
	// Stack
	Stack<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.print();
	std::cout << std::endl << "pop()-> " << s.pop() << std::endl << std::endl;

	// Vector
	Vector<int> vec;
	for (int i = 0; i < 4; ++i) {
		vec.push_back(i);
	}
	Vector<int> vec1;
	for (int i = 4; i < 8; ++i) {
		vec1.push_back(i);
	} 
	std::cout << std::endl;
	Vector<int> v(vec);
	std::cout << "Vector_1:  ";
	vec.print();
	std::cout << std::endl;
	std::cout << "Vector_2:  ";
	vec1.print();
	std::cout << std::endl;
	std::cout << "After erase 3th element vector_1: " << std::endl;
	vec.erase(3);
	vec.print();
	std::cout<<vec.at(1);

	std::cout << std::endl;
	Vector<int> vec6(vec + vec1);
	vec6.print();

	std::cout << std::endl;
	std::cout<<"vector_1 Back: "<<vec.back() << std::endl;
	std::cout<<"vector_1 Front: " <<vec.front() << std::endl;
	std::cout << std::endl;
	Vector<int> vec2;
	vec2 = vec;	
	vec2.print();

	std::cout <<std::endl<< "vector_1 size: " << vec.size() << std::endl;
	std::cout << "vector_2 size: " << vec1.size() << std::endl;

	vec.insert(100, 1);
	std::cout << std::endl << "After updating 1st index" << std::endl;

	std::cout << "vector_1 elements: ";
	vec.print();

	vec1.insert(100, 1);
	std::cout << "vector_2 elements: ";
	vec1.print();

	std::cout << "Element at 1st index: " << vec[1] << std::endl;
	std::cout << "Element at 1st index: " << vec1[1] << std::endl;
	vec.pop_Back();
	vec1.pop_Back();

	std::cout << std::endl << "After deleting last element" << std::endl;
	std::cout << "vector_1 size: " << vec.size() << std::endl;

	std::cout << "vector_2 size: " << vec1.size() << std::endl;

	std::cout << "vector_1 elements: ";
	vec.print();
	std::cout << "vector_2 elements: ";
	vec1.print();

	std::cout << std::endl << "After adding elements in front of"<<std::endl;
	std::cout << "vector_1 elements: ";
	vec.push_front(88);
	vec.print();
	vec1.push_front(77);

	std::cout << "vector_2 elements: ";
	vec1.print();

	std::cout << std::endl;
	std::cout << "vector_3 elements: " << std::endl;
	Vector<int> vec3(vec);
	vec3.print();

	std::cout << std::endl;

	Vector<int> vec4(Vector<int>::Vector());
	vec4.print();
	vec.print();
	Vector<int> vec5;
	vec5 = std::move(vec);
	vec5.print();
	vec.print();
	Vector<int> obj;
	Vector<double> obj1;
	obj.push_back(7);
	obj.push_back(8);
	obj1.push_back(1.8);
	obj1.push_back(2.9);
	obj = obj1;
	obj.print();
	return 0;
}
