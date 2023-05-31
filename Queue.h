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

        void pushBack(const T& element);

        const T& front() const;

        class Iterator;
        Iterator begin() const;
        Iterator end() const;

        class ConstIterator;
        ConstIterator begin() const;
        ConstIterator end() const;
        class EmptyQueue{};
    private:
        Node* m_current;
};
template<class T>
class Queue<T>::Iterator
{
    Queue<T>::Node* m_node;
    friend class Queue<T>;
    Iterator(Queue<T>::Node* node);
    public:
        class InvalidOperation{};
        const T& operator*();
        Iterator& operator++();
        Iterator operator++(T& element);
        bool operator!=(const Iterator& it) const;
        Iterator(const Iterator&) = default;
        Iterator& operator=(const Iterator&) = default;
};

//---------------------- Iterator Class Start --------------------------------------------------------------------------
template <class T>
Queue<T>::Iterator::Iterator(Queue<T>::Node* node):
    m_node(node)
{}

template <class T>
const T& Queue<T>::Iterator::operator*()
{
    assert(m_node != nullptr);
    if(m_node == nullptr)
    {
        throw(InvalidOperation());
    }
    return m_node->m_data;
}

template <class T>
Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    assert(m_node->m_next != nullptr)
    if(m_node->m_next == nullptr)
    {
        throw(InvalidOperation());
    }
    m_node = m_node->m_next;
    return this*;
}

template <class T>
Queue<T>::Iterator Queue<T>::Iterator::operator++(T& element)
{
    
}

//---------------------- Node Class Start ------------------------------------------------------------------------------ 

template <class T>
Queue<T>::Node::Node():
Queue<T>::Node::m_next(nullptr)
{}

template <class T>
void Queue<T>::Node::deleteList(Node& first)
{
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
        this->m_current = new Node;        
    }
    catch(const std::bad_alloc& e)
    {
        Queue<T>::Node::deleteList(this->m_current);
        throw(std::bad_alloc());
    }
    Node* temp;
    try
    {
        temp = new Node;
    }
    catch(const std::bad_alloc& e)
    {
        Queue<T>::Node::deleteList(this->m_current);
        Queue<T>::Node::deleteList(temp);
        throw(std::bad_alloc());
    }
    this->m_current->m_next = temp;
}

template <class T>
void Queue<T>::pushBack(const T& element)
{
    Queue<T>::Iterator endIt = this->end();
    endIt.m_node = data;
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
    endIt.node->m_next = temp;
}


template <class T>
const T& Queue<T>::front()const
{
    Queue<T>::Iterator beginIt = this.begin();
    if(beginIt.queue)
    return beginIt.m_current->m_data;
}




