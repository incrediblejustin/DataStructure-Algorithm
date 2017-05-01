#ifndef _HEAP_HPP_
#define _HEAP_HPP_

#include <vector>
#include "wrap.hpp"
using namespace std;
template<typename _Ty, typename _Comp>
class Heap
{
public:
    Heap(){}
    Heap(_Ty *arr, int size)
    {
        for(int i = 0; i < size; ++i)
        {
            m_vec.push_back(arr[i]);
        }
        make_heap();
    }
    void make_heap()
    {
        int end = m_vec.size() - 1;
        for(int start = (end - 1) / 2; start >= 0; --start)
        {
            adjust_heap(start, end);
        }
    }
    void adjust_heap(int start, int end)
    {
        _Ty tmp = m_vec[start];
        for(int i = 2 * start + 1; i <= end; i = i * 2 + 1)
        {
            if((i + 1 <= end) && comp(m_vec[i],m_vec[i + 1]))
                ++i;
            if(comp(tmp, m_vec[i]))
            {
                m_vec[start] = m_vec[i];
                start = i;
            }
            else return;
        }
        m_vec[start] = tmp;
    }
    bool insert_heap(_Ty value)
    {
        m_vec.push_back(value);
        push_heap();
        return true;
    }
    bool remove_heap(_Ty &ref)
    {
        if(!m_vec.empty())
        {
            ref = m_vec.front();
            pop_heap();
            m_vec.pop_back();
            return true;
        }
        return false;
    }
    void push_heap()
    {
        make_heap();
    }
    void pop_heap()
    {
        Swap(m_vec[0], m_vec[m_vec.size() - 1]);
        adjust_heap(0, m_vec.size() - 2);
    }
private:
    vector<_Ty> m_vec;
    _Comp comp;
};


#endif
