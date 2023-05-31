template <class T>
class Queue
{
    class Node
    {
        private:
            T m_data;
            Node m_next;
        public:
            Node();
            /*void setData(const T data);
            T getData() const;
            void setNext(const Node& next);
            Node& getNext() const;
            */
            ~Node() = default;
            Node(const Node& other) = default;
            Node operator=(const Node& other) = default;
            void deleteList(Node& first);
    };
    public:
        Queue();

        void pushBack(const T& element);
    private:
        Node* m_first;
};

//---------------------- Node Class Start ------------------------------------------------------------------------------ 

template <class T>
Queue<T>::Node::Node():
Queue<T>::Node::m_next(nullptr)
{}

/*template <class T>
T Queue<T>::Node::getData() const
{
    return this->m_data;
}

template <class T>
Queue<T>::Node& Queue<T>::Node::getNext() const
{
    return this->m_next;
}

template <class T>
void Queue<T>::Node::setData(const T data)
{
    this->m_data = data;
}

template <class T>
void Queue<T>::Node::setNext(const Node& next)
{
    this->m_next = next;
}
*/
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
    this->m_first = nullptr;
}

template <class T>
void Queue<T>::pushBack(const T& element)
{
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
    temp->m_data = element;
    if(this->m_first == nullptr)
    {
        this->m_first = temp;
    }
    Node* last = getLastIndex(m_first);
}


