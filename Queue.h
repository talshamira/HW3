//
// Created by user on 05/06/2023.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H
#include <iostream>
#include <new>

template <class T>
class Queue
{
    public:
    class Node
    {
    public:
        T m_data;
        Node* m_next;
        Node();
        ~Node() = default;
        Node(const Node& other) = default;
        Node& operator=(const Node& other) = default;
        void deleteList(Node* first);
    };


    Queue();

    Queue(const Queue& old);
    ~Queue();
    Queue& operator=(const Queue& old);
    class Iterator;
    Iterator begin(); //deleted const because the same reason with front
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;
    class EmptyQueue{};

    void pushBack(const T& element);

    T& front();

    const T& front() const;

    void popFront();

    int size() const;


private:
    Node* m_first;
};



//---------------------- Iterator Class Start --------------------------------------------------------------------------
template<class T>
class Queue<T>::Iterator
{
    Queue<T>::Node* m_node;
    friend class Queue;
    Iterator(Queue<T>::Node* node);
public:
    class InvalidOperation{};
    T& operator*() const;
    Iterator& operator++();
    Iterator operator++(int);
    bool operator!=(const Iterator& it) const;
    Iterator(const Iterator&) = default;
    Iterator& operator=(const Iterator&) = default;
    ~Iterator() = default;
};

template <class T>
Queue<T>::Iterator::Iterator(Queue<T>::Node* node):
        m_node(node)
{}

template <class T>
T& Queue<T>::Iterator::operator*() const
{
    if(m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return m_node->m_data;
}

template <class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_node->m_next == nullptr)
    {
        throw(InvalidOperation());
    }
    this->m_node = this->m_node->m_next;
    return *this;
}

template <class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
{
    if(this->m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    Iterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& it) const
{
    if(this->m_node == nullptr || it.m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return !(this->m_node == it.m_node);

}
//---------------------- Iterator Class End ----------------------------------------------------------------------------

//---------------------- ConstIterator Class Start ---------------------------------------------------------------------
template<class T>
class Queue<T>::ConstIterator
{
    Queue<T>::Node* m_node;
    friend class Queue;
    ConstIterator(Queue<T>::Node* node);
public:
    class InvalidOperation{};
    const T&  operator*() const;
    ConstIterator& operator++();
    ConstIterator operator++(int);
    bool operator!=(const ConstIterator& it) const;
    ConstIterator(const ConstIterator&) = default;
    ConstIterator& operator=(const ConstIterator&) = default;
    ~ConstIterator()=default;
};
template <class T>
Queue<T>::ConstIterator::ConstIterator(Queue<T>::Node* node):
        m_node(node)
{}

template <class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    if(m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return m_node->m_data;
}

template <class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(this->m_node->m_next == nullptr)
    {
        throw(InvalidOperation());
    }
    this->m_node = this->m_node->m_next;
    return *this;
}

template <class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
{
    if(this->m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    Iterator result = *this;
    ++*this;
    return result;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const ConstIterator& it) const
{
    if(this->m_node == nullptr || it.m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return !(this->m_node == it.m_node);

}
//---------------------- ConstIterator Class End -----------------------------------------------------------------------

//---------------------- Node Class Start ------------------------------------------------------------------------------

template <class T>
Queue<T>::Node::Node()
{
    this->m_next =nullptr;
}

template <class T>
void Queue<T>::Node::deleteList(Node* first)
{

    // TODO: make sure first is null in some point
    while(first != nullptr)
    {
        Node* toDelete = first;
        first = first->m_next;
        delete toDelete;
    }
}
//---------------------- Node Class End --------------------------------------------------------------------------------

//---------------------- Queue class Start -----------------------------------------------------------------------------
template <class T>
Queue<T>::Queue()
{
    try
    {
        this->m_first = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        delete this->m_first;
        throw(std::bad_alloc());
    }
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        delete this->m_first;
        delete temp;
        throw(std::bad_alloc());
    }
    this->m_first->m_next = temp;
}

template<class T>
Queue<T>::Queue(const Queue<T>& old)
{
    try
    {
        this->m_first = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        delete this->m_first;
        throw(std::bad_alloc());
    }
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        delete this->m_first;
        delete temp;
        throw(std::bad_alloc());
    }
    this->m_first->m_next = temp;
    if(old.size() != 0)
    {
        for(const T& runner : old)
        {
            try
            {
                this->pushBack(runner);
            }
            catch(const std::bad_alloc& e)
            {
                this->m_first->deleteList(m_first);
                throw(std::bad_alloc());
            }
        }
    }
}

template<class T>
Queue<T>::~Queue()
{
    this->m_first->deleteList(m_first);
}

template<class T>
typename Queue<T>::Queue& Queue<T>::operator=(const Queue<T>& old)
{
    if(this == &old)
    {
        return *this;
    }
    Queue tempQueue;
    try
    {
        tempQueue(old); //*************************************************************************************************** probably wrong if not working change
    }
    catch(const std::bad_alloc& e)
    {
        delete tempQueue;
        throw(std::bad_alloc());
    }
    Node* temp = this.m_first;
    this->m_first = tempQueue.m_first;
    tempQueue.m_first = temp;
}

template <class T>
void Queue<T>::pushBack(const T& element)
{
    Queue<T>::Iterator endIt = this->end();
    endIt.m_node->m_data = element;
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        delete temp;
        throw(std::bad_alloc());
    }
    endIt.m_node->m_next = temp;
}


template <class T>
T& Queue<T>::front()
{
    if(this->m_first->m_next->m_next == nullptr)
    {
        throw(EmptyQueue());
    }

    return this->m_first->m_next->m_data;
}

template <class T>
const T& Queue<T>::front() const
{
    if(this->m_first->m_next->m_next == nullptr)
    {
        throw(EmptyQueue());
    }

    return this->m_first->m_next->m_data;
}

template <class T>
void Queue<T>::popFront()
{
    if(this->m_first->m_next->m_next == nullptr)
    {
        throw(EmptyQueue());
    }
    this->m_first = this->m_first->m_next;
}

template<class T>
int Queue<T>::size() const {
    //set to -2 because of begging node and end node
    int counter = -2;
    Node* runner = this->m_first;
    while(runner != nullptr)
    {
        counter++;
        runner = runner->m_next;
    }
    return counter;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    Iterator first = this->m_first;
    ++first;
    return first;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    Node* runner = this->m_first;
    while(runner != nullptr)
    {
        runner = runner->m_next;
    } 
    return Iterator(runner);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    ConstIterator first = this->m_first;
    ++first;
    return first;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    Node* runner = this->m_first;
    while(runner != nullptr)
    {
        runner = runner->m_next;
    } 
    return ConstIterator(runner);
}

template<class T, typename Condition>
void transform(Queue<T> originalQueue, const Condition condition)
{
    for (T& it : originalQueue) 
    {
        condition(it);
    }
}

template<class T, typename Condition>
Queue<T> filter(const Queue<T> originalQueue, const Condition condition)
{
    if(originalQueue.size() == 0)
    {
        throw(typename Queue<T>::EmptyQueue());
    }
    Queue<T> newQueue;
    for (const T& it: originalQueue)
    {
        if(condition(it))
        {
            newQueue.pushBack(it);
        }
    }
    return newQueue;
}


#endif //HW3_QUEUE_H