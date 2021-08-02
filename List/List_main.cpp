// MyList.cpp :

#include <iostream>
#include <string>
#include "MyList.h"


int main()
{
    MyList<int> list;
    list.push_back(5);
    list.push_back(6);
    list.print();
    std::cout << std::endl <<"Copy ctor"<< std::endl;
    MyList<int> l2(list);
    l2.print();
    std::cout << std::endl << "initializer_list" << std::endl;
    MyList<int> l3{ 2,1,2,4,1 };
    l3.print();
    l3.remove_duplicates();
    l3.print();
    std::cout << std::endl <<"operator= "<< std::endl;
    MyList<int> l4;
    l4 = l3;
    l4.print();
    std::cout << std::endl << "operator= initializer_list " << std::endl;
    MyList<std::string> l5;
    l5 = { "abc","abc","abc" };
    l5.print();
    std::cout << std::endl << "assign" << std::endl;
    l5.assign(2, "tt");   
    l5.print();
    std::cout << std::endl <<"front "<< std::endl;
    std::cout<<l5.front();
    std::cout << std::endl <<"back" << std::endl;
    std::cout<<l3.back();
    std::cout << std::endl <<"empty"<< std::endl;
    std::cout  <<std::boolalpha<< l3.empty();
    std::cout << std::endl <<"size"<< std::endl;
    std::cout << l3.size();
    std::cout << std::endl << "Clear" << std::endl;
    MyList<int> l6;
    l6.push_back(8);
    l6.push_front(9);
    l6.clear();
    l6.print(); 
    std::cout << std::endl << "insert" << std::endl;
    MyList<int> l7;
    l7.push_back(8);
    l7.push_back(9);
    l7.push_back(10);
    l7.insert(2, 99);
    l7.print();
    std::cout << std::endl << "insert" << std::endl;
    l7.insert(3, 5, 99);
    l7.print();
    std::cout << std::endl << "erase" << std::endl;
    l7.erase(2);
    l7.print();
    std::cout << std::endl << "pop_back" << std::endl;
    l7.pop_back();
    l7.print();
    std::cout << std::endl << "pop_front" << std::endl;
    l7.pop_front();
    l7.print();
    std::cout << std::endl << "resize" << std::endl;;
    l3.resize(7);
    l3.print();
    std::cout << "before swap list:"; list.print();
    std::cout << std::endl << "swap" << std::endl;
    l3.swap(list);
    l3.print();
    std::cout << "after swap list:" << std::endl;
    list.print();
    std::cout <<"remove" << std::endl;
    list.remove(4);
    list.print();
    std::cout << "reverse" << std::endl;
    list.reverse();
    return 0;
}
