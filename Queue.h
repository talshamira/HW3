//
// Created by user on 05/06/2023.
//

#ifndef HW3_QUEUE_H
#define HW3_QUEUE_H


template <class T>
class Queue
{
    class Node
    {
    public:
        T m_data;
        Node m_next;
        Node();
        ~Node() = default;
        Node(const Node& other) = default;
        Node operator=(const Node& other) = default;
        void deleteList(Node& first);
    };

public:
    Queue();

    class Iterator;
    Iterator begin(); //deleted const because the same reason with front
    Iterator end();

    class ConstIterator;
    ConstIterator begin() const;
    ConstIterator end() const;
    class EmptyQueue{};

    void pushBack(const T& element);

    T& front() const;

    const T& front() const;

    Node& popFront();

    int size() const;

    void transform(Queue<class T> queueForTrans, void (*f)(T&));

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
    const T& operator*() const;
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
Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(this->m_node->m_next == nullptr)
    {
        throw(InvalidOperation());
    }
    this->m_node = this->m_node->m_next;
    return this*;
}

template <class T>
Queue<T>::Iterator Queue<T>::Iterator::operator++(int)
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
    if(this->m_node == nullptr || it->m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return !(this->m_node == it->m_node);

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
Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(this->m_node->m_next == nullptr)
    {
        throw(InvalidOperation());
    }
    this->m_node = this->m_node->m_next;
    return this*;
}

template <class T>
Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++(int)
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
    if(this->m_node == nullptr || it->m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return !(this->m_node == it->m_node);

}
//---------------------- ConstIterator Class End -----------------------------------------------------------------------

//---------------------- Node Class Start ------------------------------------------------------------------------------

template <class T>
Queue<T>::Node::Node():

        Queue<T>::Node::m_next(nullptr)
{}

template <class T>
void Queue<T>::Node::deleteList(Node& first)
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
        Queue<T>::Node::deleteList(this->m_first);
        throw(std::bad_alloc());
    }
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        Queue<T>::Node::deleteList(this->m_first);
        Queue<T>::Node::deleteList(temp);
        throw(std::bad_alloc());
    }
    this->m_first->m_next = temp;
}

template <class T>
void Queue<T>::pushBack(const T& element)
{
    Queue<T>::Iterator endIt = this->end();
    endIt.m_node->m_data = data;
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        Queue<T>::Node::deleteList(temp);
        throw(std::bad_alloc());
    }
    // TODO: why use iterator here? this->end()->m_next = new Node (not directly)
    endIt.node->m_next = temp;
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
    for (Queue<T>::Node runner: this) {
        counter++;
    }
    return counter;
}

template<class T>
Iterator Queue<T>::begin()
{
    return this->m_first;
}

template<class T>
Iterator Queue<T>::end()
{
    int current_size = this->size();
    return Iterator(this, current_size);
}

template<class T>
ConstIterator Queue<T>::begin() const
{
    return this->m_first;
}

template<class T>
ConstIterator Queue<T>::end() const
{
    int current_size = this->size();
    return ConstIterator(this, current_size);
}

template<class T>
void Queue<T>::transform(Queue<class T> originalQueue, void (*f)(T&))
{
    for (it = originalQueue.begin(); it != originalQueue.end(); ++it)
    {
        (*f)(it->m_data);
    }
}

template<class T>
Queue<T>& filter(Queue<class T> originalQueue, bool (*f)(T&))
{
    //Iterator it = queueForTrans.begin();
    Queue<T> newQueue;
    for (it = originalQueue.begin(); it != originalQueue.end(); ++it)
    {
        if((*f)(it->m_data))
        {
            newQueue.pushBack(it->m_data);
        }
    }
    return newQueue;
}
//void transform(Queue<class T> queueForTrans, void (*f)(T&));

#endif //HW3_QUEUE_H