#pragma once

#include <queue>

template <typename T, unsigned short int MaxLen, class Container = std::deque<T>>
class FixedQueue : public std::queue<T, Container>
{
public:
    void push(const T& value)
    {
        if (this->size() == MaxLen)
        {
            this->c.pop_front();
        }
        std::queue<T>::push(value);
    }
};

template <typename T, unsigned short int MaxLen, class Container = std::deque<T>>
class FixedStack : public std::queue<T, Container>
{
public:
    void push(const T& value)
    {
        if (this->size() == MaxLen)
        {
            this->c.pop_front();
        }
        std::queue<T>::push(value);
    }
};
