#include <iostream>

template <typename T> 
class Stack
{
    public:
        Stack();
        ~Stack();
        int size();
        T& top();
        void pop();
        void push(const T&);
        bool empty();
    
    private:
        T* m_array;
        int m_size;
        int m_capacity;
};

template <typename T> 
Stack<T>::Stack()
{
    m_size = 0;
    m_capacity = 0;
    m_array = new T[m_size];
}

template <typename T> 
Stack<T>::~Stack()
{
    delete [] m_array;
}

template <typename T> 
int Stack<T>::size()
{
    return m_size;
}

template <typename T> 
T& Stack<T>::top()
{
     if (m_size < 1){
         std::cerr << "Warning stack is empty" << std::endl;
     }
    return m_array[m_size - 1];
}

template <typename T> 
void Stack<T>::pop()
{
    if (m_size == 0){
        std::cerr << "Warning: stack is empty: " << std::endl;
        return ;
    }
    --m_size;
}

template <typename T> 
void Stack<T>::push(const T& elem)
{
    if(this->m_size == this->m_capacity){
        T* temp = new T[2 * (m_size + 1)];

    for(int i=0; i < this->m_size; ++i){
        temp[i] = this->m_array[i];
    }

    delete [] m_array;
    if(this->m_capacity == 0)
        this->m_capacity ++;

    this->m_capacity *= 2;
    this->m_array = temp;
    }

    this->m_size ++;
    this->m_array[m_size - 1] = elem;
}

template <typename T> 
bool Stack<T>::empty()
{
    if(this->m_size == 0)
        return true;
    return false;
}

int main ()
{
    Stack<int> st;
    st.push(1);
    st.push(2);
    st.push(12);

    std::cout << "st.empty()  ::: " << st.empty() << std::endl;
    std::cout << "st.size() ::: " << st.size() << std::endl;
    std::cout << std::endl;
    std::cout << "st elemets: ";

    while(!st.empty()){
        std::cout << st.top() << " ";
        st.pop();
    }

    std::cout << std::endl;
    std::cout << "st.empty()  ::: " << st.empty() << std::endl;
    std::cout << "st.size() ::: " << st.size() << std::endl;

    st.push(20);
    st.push(30);
    st.push(40);
    std::cout << "calling pop() function..." << std::endl;
    std::cout << "st.top() before pop() ::: " << st.top() << std::endl;
    st.pop();
    std::cout << "st.top() after pop() ::: " << st.top() << std::endl;

    Stack<std::string> st_str;
    st_str.push("Nothing 1");
    st_str.push("Nothing 2");
    st_str.push("Nothing 3");

    std::cout << "st_str elemets: ";

    while(!st_str.empty()){
        std::cout << st_str.top() << " ";
        st_str.pop();
    }

    std::cout << std::endl;
    std::cout << "st_str.empty()  ::: " << st_str.empty() << std::endl;
    std::cout << "st_str.size() ::: " << st_str.size() << std::endl;;

    st_str.push("Nothing 1");
    st_str.push("Nothing 2");
    st_str.push("Nothing 3");

    std::cout << "st_str.size() before calling pop()  " << st_str.size() << std::endl;
    std::cout << std::endl;

    std::cout << "calling pop() function..." << std::endl;
    std::cout << "st_str.top() before pop() ::: " << st_str.top() << std::endl;
    st_str.pop();
    std::cout << "st_str.top() after pop() ::: " << st_str.top() << std::endl;
    std::cout << "st_str.size() after calling pop() " << st_str.size() << std::endl;
}