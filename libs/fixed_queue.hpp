#pragma once

#include <queue>
#include <deque>
#include <stack>

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

template <typename T, unsigned short int MaxLen>
class FixedDeque : public std::deque<T>
{
public:
    void push_back(const T& value)
    {
        if (this->size() == MaxLen)
        {
            this->pop_front();
        }
        std::deque<T>::push_back(value);
    }
};
