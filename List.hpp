#include <iostream>
#include <string>

template <typename T>
class Node
{
    public:
        // Node()
        // {

        // }
        Node(T data)
        {
            m_data = data;
            next = NULL;
            prev = NULL;
            // std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

        Node(const Node &obj)
        {
            next = NULL;
            prev = NULL;
            this->m_data = obj.m_data; // avelacnel inch vor ban
            // std::cout << __PRETTY_FUNCTION__ << std::endl;
        }

        ~Node() {};

        Node &operator=(const Node &obj)
        {
            if (this != &obj)
                this->m_data = obj.m_data;
            return (*this);
        }

        Node *next;
        Node *prev;
        T m_data;
};

template <typename T>
class List
{
    public:
        List() : m_head(NULL), m_tail(NULL), m_size(0) {}

        List(const List &obj)
        {
            // Node *tmp_obj_head = obj.m_head;
            // this->m_head = NULL;
            // this->m_tail = NULL;

            // while (tmp_obj_head)
            // {
            //     this->push_back(tmp_obj_head->m_data);
            //     tmp_obj_head = tmp_obj_head->next;
            // }

            //*********************************************************

            if (obj.m_head == NULL)
            {
                this->m_head = NULL;
                this->m_tail = NULL;
                this->m_size = 0;
                return ;
            }
            Node<T> *tmp;
            Node<T> *tmp_obj_head = obj.m_head;

            // this->m_head = new Node<T>(tmp_obj_head->m_data);
            this->m_head = new Node<T>(tmp_obj_head->m_data);
            tmp = this->m_head;
            tmp_obj_head = tmp_obj_head->next;
            while (tmp_obj_head)
            {
                tmp->next = new Node<T>(tmp_obj_head->m_data);
                tmp->next->prev = tmp;
                tmp_obj_head = tmp_obj_head->next;
                tmp = tmp->next;
            }
            this->m_tail = tmp;
            this->m_size = obj.m_size;

            // this->m_head = new Node<T>(obj.m_head->m_data);
            // this->m_head->next = new Node<T>(obj.m_head->next->m_data);
            // this->m_head->next->next = new Node<T>(obj.m_head->next->next->m_data);
        }

        ~List() {}

        List &operator=(const List &obj)
        {
            if (this != &obj)
            {
               
                this->m_size = obj.m_size;
                if (obj.m_head == NULL)
                {
                    this->m_head = NULL;
                    this->m_tail = NULL;
                    this->m_size = 0;
                    return (*this);
                }
//************************************************

//                 this->clear();
//                  Node<T> *tmp;
//                 Node<T> *tmp_obj_head = obj.m_head;

//                 // this->m_head = new Node<T>(tmp_obj_head->m_data);
//                 this->m_head = new Node<T>(tmp_obj_head->m_data);
//                 tmp = this->m_head;
//                 tmp_obj_head = tmp_obj_head->next;
//                 while (tmp_obj_head)
//                 {
//                     tmp->next = new Node<T>(tmp_obj_head->m_data);
//                     tmp->next->prev = tmp;
//                     tmp_obj_head = tmp_obj_head->next;
//                     tmp = tmp->next;
//                 }
//                 this->m_tail = tmp;
//                 this->m_size = obj.m_size;
//                 return (*this);

// ************************************************

            if (!this->m_head)
            {
                    Node<T> *tmp;
                    Node<T> *tmp_obj_head = obj.m_head;

                    // this->m_head = new Node<T>(tmp_obj_head->m_data);
                    this->m_head = new Node<T>(tmp_obj_head->m_data);
                    tmp = this->m_head;
                    tmp_obj_head = tmp_obj_head->next;
                    while (tmp_obj_head)
                    {
                        tmp->next = new Node<T>(tmp_obj_head->m_data);
                        tmp->next->prev = tmp;
                        tmp_obj_head = tmp_obj_head->next;
                        tmp = tmp->next;
                    }
                    this->m_tail = tmp;
                    this->m_size = obj.m_size;
                    return (*this);
                }


                Node<T> *tmp = this->m_head;
                Node<T> *tmp_obj_head = obj.m_head;

                while (tmp_obj_head)
                {
                    if (tmp)
                    {
                        tmp->m_data = tmp_obj_head->m_data;
                        tmp_obj_head = tmp_obj_head->next;
                        tmp = tmp->next;
                    }
                    else
                    {
                        m_tail->next = new Node<T>(tmp_obj_head->m_data);
                        m_tail->next->prev = m_tail;
                        tmp_obj_head = tmp_obj_head->next;
                        m_tail = m_tail->next;
                    }
                }
                
                // tmp = tmp->next;
                if (!tmp)
                {
                    return (*this);
                }
                tmp->prev->next = NULL;
                m_tail = tmp->prev;
                tmp = tmp->next;
                if (tmp)
                {
                    while (tmp->next)
                    {
                        delete tmp->prev;
                        tmp = tmp->next;
                    }
                }
                delete tmp;
                std::cout << "lalala0000\n";
                // this->m_tail = tmp;
            }
            return (*this);
        }

        void push_back(T a)
        {
            Node<T> *new_node = new Node<T>(a);
            // if (new_node)
            // {
                if (m_head && m_tail)
                {
                    m_tail->next = new_node;
                    new_node->prev = m_tail;
                    m_tail = new_node;
                }
                else
                {
                    m_head = new_node;
                    m_tail = new_node;
                }
                m_size++;
            // }
        }
        void push_front(T a)
        {
            Node<T> *new_node = new Node<T>(a);
            // if (new_node)
            // {
                if (m_head && m_tail)
                {
                    new_node->next = m_head;
                    m_head->prev = new_node;
                    m_head = new_node;
                }
                else
                {
                   m_head = new_node;
                   m_tail = new_node;
                }
                m_size++;
            // }
        }
        T& front() const
        {
            return (m_head->m_data);
        }

        T& back() const
        {
            return (m_tail->m_data);
        }

        T pop_back()
        {
            T res;

            // if (m_tail)
            // {
                Node<T> *tmp;

                res = m_tail->m_data;
                tmp = m_tail;
                m_tail = m_tail->prev;
                if (m_tail)
                {
                    m_tail->next = NULL;
                }
                else
                {
                    m_head = NULL;
                }
                delete tmp;
                m_size--;
                // if (m_size == 0) tox mna
                //     m_head = NULL;
            // }
            return (res);
        }

        T pop_front()
        {
            // if (m_head)
            // {
                Node<T> *tmp;

                T a = m_head->m_data;
                tmp = m_head;
                m_head = m_head->next;
                if (m_head)
                    m_head->prev = NULL;
                else
                {
                    m_tail = NULL;
                }
                delete tmp;
                m_size--;
                // if (m_size == 0)
                // {
                //     m_tail = NULL;
                // }
                // return (a);
            // }
            return (a);
        }

        size_t size() const
        {
            return (m_size);
        }

        bool empty() const
        {
            return (m_size == 0);
        }

        void clear()
        {
            if (m_head)
            {
                // Node<T> *tmp = m_head;
                // while (m_head->next)
                // {
                //     delete m_head->next;
                //     m_head = m_head->next;
                // }
                while (m_head->next)
                {
                    delete m_head->prev;
                    m_head = m_head->next;
                }
                delete m_head;
                this->m_head = NULL;
                this->m_tail = NULL;
                this->m_size = 0;
            }
        }

    private:
        Node<T> *m_head;
        Node<T> *m_tail;
        size_t m_size;
};