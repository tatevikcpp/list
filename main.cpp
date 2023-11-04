#include <iostream>
#include "List.hpp"
// #include "iterator.hpp"

// int main()
// {
//     // int arr[] = { ')', '('};
//     // List stack;
//     // for (unsigned int i = 0; i < (sizeof(arr) / sizeof(int)); ++i)
//     // {
//     //     stack.push_front(arr[i]);
//     // }


//     // int a[] = {'1'};

//     // List obj;
//     // for (unsigned int i = 0; i < (sizeof(a) / sizeof(int)); ++i)
//     // {
//     //     obj.push_front(a[i]);
//     // }


//     // std::cout << stack.size() << std::endl;
//     // std::cout << stack.front() << std::endl;
//     // std::cout << stack.back() << std::endl;
//     // // List obj = stack;
//     // // List obj;
//     //  std::cout << std::endl;

//     // obj = stack;
//     // obj.push_back('2');
//     // std::cout << obj.size() << std::endl;
//     // std::cout << obj.front() << std::endl;
//     // std::cout << obj.back() << std::endl;
//     // std::cout << "verj\n";

//     // while (stack.empty() != true)
//     // {
//     //     std::cout << (char)stack.pop_back();
//     // }

//     // std::cout << std::endl;
    
//     // while (obj.empty() != true)
//     // {
//     //     std::cout << (char)obj.pop_back();
//     // }
//     // std::cout << std::endl;


// }

// #include <iostream>

// template <typename T>
// void func(T arg) {
//     (void)arg;
//     return;
// }

// void func(char arg) {
//     (void)arg;
//     return;
// }


// void func(int arg) {
//     std::cout << "void func(int arg) {\n";
//     (void)arg;
//     return;
// }

// void func(char arg) {
//     (void)arg;
//     return;
// }

// int main()
// {
//     const int n = 7;
//     func<char>(n);

//     // func(7);
//     // func('a');
// }
#include <list>

// int main()
// {
//     // Iterator<int> it;
//     std::list<std::string> stdobj;
//     List<std::string> obj;
//     std::list<std::string>::iterator it = stdobj.begin();
//     List<std::string>::iterator itList = obj.begin();
    
//     // itList  = obj.begin();
//     std::string str = "lalala";
//     obj.push_back(str);
//     obj.front() = "urish ban";
//     std::cout << obj.front() << std::endl;

//     std::cout << std::endl;
//     stdobj.push_back(str);
//     stdobj.front() = "urish ban";
//     std::cout << stdobj.front() << std::endl;

//     std::cout << std::endl;
// }

int main()
{
    try
    {
        List<int> obj;
        obj.push_front(12);
        obj.push_front(2);
        obj.push_front(0);
        List<int>::iterator it = obj.begin();
        while (it != obj.end())
        {
           std::cout << *it << std::endl;
           it++;
        }
           it--;
        // it--;
        // std::cout << *it << std::endl;
        // while (it != obj.begin()) {
        //    std::cout << *it << std::endl;
        //     it--;
        // }
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}


