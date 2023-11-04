// #pragma once
// #include  "List.hpp"


template <typename T>
class Node;

template <typename T>
class Iterator
{
    public:
        Iterator();
        Iterator(Node<T> *ptr);
        Iterator(const Iterator<T>& obj);
        Iterator(Iterator<T>&& obj);
        ~Iterator();
        T& operator*();
        T& operator->();
        Iterator& operator=(const Iterator& obj);
        Iterator<T> operator++();
        Iterator<T> operator--();
        Iterator<T> operator++(int);
        Iterator<T> operator--(int);
        bool operator==(const Iterator<T>& obj);
        bool operator!=(const Iterator<T>& obj);
        void swap(Iterator& obj);
    private:
        Node<T> *_ptr;
        // List<T> _list;
};


template <typename T>
Iterator<T>::Iterator() : _ptr(NULL)
{
    std::cout << "default= " << std::endl;
}

template <typename T>
Iterator<T>::Iterator(Node<T> *ptr) : _ptr(ptr)
{
    std::cout << "parametr= " << std::endl;
}

template <typename T>
Iterator<T>::Iterator(const Iterator<T>& obj)
{
    std::cout << "copy= " << std::endl;
    this->_ptr = obj._ptr;
}


template <typename T>
Iterator<T>::Iterator(Iterator<T>&& obj)
{
    std::cout << "move= " << std::endl;
    this->_ptr = obj._ptr;
    obj._ptr = NULL;
}

template <typename T>
Iterator<T>::~Iterator()
{
    std::cout << "destructor= " << std::endl;
}

template <typename T>
T& Iterator<T>::operator*()
{
    // if (this->_ptr == NULL)
    //     throw std::runtime_error("ptr is NULL");
    return (this->_ptr->m_data);
}

// template <typename T>
// T& Iterator<T>::operator->()
// {
//     // if (this->_ptr == NULL)
//     //     throw std::runtime_error("ptr is NULL");
//     return (this->_ptr->m_data);
// }

template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator& obj)
{
    std::cout << "operator= " << std::endl;
    // if (this != *obj)
    // {
    this->_ptr = obj._ptr;
    // }
    return (*this);
}

template <typename T>
Iterator<T> Iterator<T>::operator++()
{
    // if (this->_ptr == NULL || this->_ptr->next == NULL)
    //     throw std::runtime_error("ptr is NULL");
    this->_ptr = this->_ptr->next;
    return (*this);
}

template <typename T>
Iterator<T> Iterator<T>::operator--()
{
    // if (this->_ptr == NULL || this->_ptr->prev == NULL)
    //     throw std::runtime_error("ptr is NULL");
    this->_ptr = this->_ptr->prev;
    return (*this);
}

template <typename T>
Iterator<T> Iterator<T>::operator++(int)
{
    Iterator tmp = *this; // (*this)
    // if (this->_ptr == NULL || this->_ptr->next == NULL)
    //     throw std::runtime_error("ptr is NULL");
    this->_ptr = this->_ptr->next;
    return (tmp);
}

template <typename T>
Iterator<T> Iterator<T>::operator--(int)
{
    Iterator tmp = *this; // (*this)
    // if (this->_ptr == NULL || this->_ptr->next == NULL)
    //     throw std::runtime_error("ptr is NULL");
    this->_ptr = this->_ptr->prev;
    return (tmp);
}

template <typename T>
bool Iterator<T>::operator==(const Iterator& obj)
{
    return (this->_ptr = obj._ptr);
}

template <typename T>
bool Iterator<T>::operator!=(const Iterator& obj)
{
    return (this->_ptr != obj._ptr);
}

template <typename T>
void Iterator<T>::swap(Iterator& obj)
{
    void *ptr = this->_ptr;
    this->_ptr = obj._ptr;
    obj._ptr = ptr;
}