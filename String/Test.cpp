// String.cpp : 

#include "String.h"

int main()
{
    String a;
    a.push_back('T');
    a.push_back('i');
    a.push_back('g');
    a.push_front('1');
    a.print();
    std::cout << std::endl;
    a += "Hello";
    a += 'g';
    a.print();
    String d;
    d.push_back('v');
    d.push_back('a');
    d.print();
    std::cout << std::endl;
    String c = a + d;
    c.print();
    a += d;
    std::cout << std::endl;
    a.print();       
    std::cout << std::endl;
    a.erase(2);
    a.print();  

    std::cout << std::endl << std::endl;
    char str[] = "Text";
    String b(str);
    b.print();
    std::cout << std::endl << std::endl;
    a.insert('9', 1);

    a.pop_back();
    std::cout<<std::boolalpha<<a.empty()<<std::endl;
    std::cout << a.back() << std::endl;
    std::cout << a.front() << std::endl;
    return 0;
}


